#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <string.h>

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;
WiFiClient client;


const char * host = "10.10.141.45";
const uint16_t port = 6000;

int trig = 13;
int echo = 12;
char msg[30] = {};
char msg1[30] = {};
bool led_status = false;
unsigned long past = 0;
int pre_charging = 0;
int ori_val, cur_charging;


int init_conn = 1; //입차및출차시 주소, 포트 연결하여 In,Out으로 로그인

void ClientConn();
void MsgSend_adm(int msg_RevData);
void MsgSend_Jes(char* msg_RevData);
void ledcontrol(char *data);

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(14, OUTPUT);

  WiFi.begin("iot24kcci", "iot40000");  //WiFi 연결
  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
  }
  Serial.println("Connected to wifi successful!");
}
int flag = 0;
int abc = 0;
int smode = 0;

void loop() {
  char ch[30] = {0};
  int index = 0;
  int str_len;

  if (flag == 0) {
    ClientConn();
    client.print("[SPOT1:PASSWD]");
    flag = 1;
  }

  if ((WiFiMulti.run() == WL_CONNECTED))
  {
    char * car_info[4];
    memset(ch, 0, sizeof(ch));
    while (client.available()) {
      // ch = static_cast<char>(client.read());

      ch[index++] = static_cast<char>(client.read());
      if (ch[index - 1] == 'L')
      {
        Serial.print("first CH = ");
        Serial.println(ch);

        char *pToken;
        char *pArray[10] = {0};
        ch[index - 1] = '\0';
        ch[0] = '@';
        ch[6] = '@';
        str_len = strlen(ch);
        //Serial.print(ch);
        //pToken = strtok(ch, "@");
        pToken = strtok(ch, "@");

        int i = 0;
        while (pToken != NULL)
        {
          pArray[i] = pToken;
          Serial.print(i);
          Serial.print(" = ");
          Serial.println(pToken);

          if (++i > 5)
            break;
          pToken = strtok(NULL, "@");
        }
        Serial.println(pArray[0]);

        if (strcmp(pArray[0], "admin") == 0)
        {
          ledcontrol(pArray[1]);
          //Serial.print("receive from admin = ");
          //Serial.println("receive from admin");
        }
        else if (strcmp(pArray[0], "block") == 0)
        {
          Serial.println("receive from block");
          car_info[1] = pArray[1]; // In/Out
          car_info[2] = pArray[2]; // Car Number
          car_info[3] = pArray[3]; // Type

          if (atoi(car_info[1]) == 1)
          {
            while (1)
            {
              digitalWrite(trig, HIGH);
              delayMicroseconds(10);
              digitalWrite(trig, LOW);
              int dis = pulseIn(echo, HIGH) * 340 / 2 / 10000;
              //Serial.print("dis = ");
              //Serial.println(dis);

              if (dis <= 15 && dis != 0)
              {
                if (init_conn == 1)
                {
                  digitalWrite(14, HIGH);
                  MsgSend_adm(1);
                  delay(10);
                  MsgSend_Jes("1");
                  init_conn = 0;
                  delay(10);
                  break;
                }
                //Serial.println("들어왔다!");
              }
              else if (dis > 15) {
                if (init_conn == 0)
                {
                  MsgSend_adm(0);
                  delay(10);
                  MsgSend_Jes("0");
                  init_conn = 1;

                }
                if (led_status == false) {
                  digitalWrite(14, HIGH);
                }
                else {
                  digitalWrite(14, LOW);
                }
                led_status = !led_status;
                continue;

              }
            }
          }
          if (atoi(car_info[1]) == 0)
          {
            digitalWrite(14, LOW);

          }
        }

        else if (strcmp(pArray[0], "Jets1") == 0)
        {
          Serial.println(pArray[1]);
          if (strcmp(pArray[1], "5") == 0)
          {
            abc = 1;
          }
        }
        fflush(stdout);
      }
    }
    ch[index] = '\0';
    if (abc == 1) {
      ori_val = analogRead(A0);
      cur_charging = map(ori_val, 0, 1023, 0, 100);
      if (cur_charging != pre_charging)
      {
        sprintf(msg, "[admin] %d@\n", cur_charging);
        client.print(msg);
        pre_charging = cur_charging;
        delay(100);
      }
      if (cur_charging == 100)
      {
        MsgSend_Jes("6@");
        abc = 0;
      }
    }
    delay(10);
  }
}

void ClientConn()
{
  if (!client.connect(host, port)) {
    Serial.println("Connection to host failed");
    delay(1000);
    return;
  }
  else
    Serial.println("Connected to CarTower server successful!");
}


void MsgSend_adm(int msg_RevData)
{
  sprintf(msg1, "[admin]%d\n", msg_RevData);
  Serial.println(msg1);
  client.print(msg1);
}
void MsgSend_Jes(char* msg_RevData)
{
  sprintf(msg, "[Jets1]%s\n", msg_RevData);
  client.print(msg);
}

void ledcontrol(char *data)
{
  if (strcmp(data, "ON") == 0)
  {
    digitalWrite(14, HIGH);
  }
  else if (strcmp(data, "OFF") == 0)
  {
    digitalWrite(14, LOW);
  }
}
