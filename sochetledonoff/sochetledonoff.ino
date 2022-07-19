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
unsigned long past = 0;
int pre_charging = 0;

int init_conn = 0; //입차및출차시 주소, 포트 연결하여 In,Out으로 로그인
int msg_RevData; //입차시 1, 출차시 2 출력

void ClientConn();
void MsgSend();
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
void loop() {
  char ch[30] = {0};
  int index = 0;
  int str_len;
  char *pToken;
  char *pArray[2] = {0};

  if ((WiFiMulti.run() == WL_CONNECTED))
  {
    int ori_val, cur_charging;

    ori_val = analogRead(A0);
    cur_charging = map(ori_val, 0, 1023, 0, 100);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    int dis = pulseIn(echo, HIGH) * 340 / 2 / 10000;
    //Serial.println(dis);

    if (dis < 35)
    {
      if (flag == 0) {
        if (init_conn == 1) {
          ClientConn();
          client.print("[SPOT1:PASSWD]");
          init_conn = 0;

        }

        msg_RevData = 1;
        MsgSend();

      }
      if (cur_charging != pre_charging)
      {
        sprintf(msg, "[admin] %d@\n", cur_charging);
        client.print(msg);
        pre_charging = cur_charging;
        delay(100);
      }


      while (client.available()) {
        // ch = static_cast<char>(client.read());
        ch[index++] = static_cast<char>(client.read());
        if (ch[index - 1] == 'L')
        {
          ch[index - 1] = '\0';
          str_len = strlen(ch);
          //Serial.print(ch);
          pToken = strtok(ch, "]");
          int i = 0;
          while (pToken != NULL)
          {
            pArray[i] = pToken;
            if (++i > 2)
              break;
            pToken = strtok(NULL, " ");
          }

          Serial.println(pArray[1]);
          ledcontrol(pArray[1]);
          for (int i = 0; i <= str_len; i++)
          {
            ch[i] = 0;
            index = 0;
          }

          fflush(stdout);
        }

      }
      ch[index] = '\0';

      /*
        // while (client.available())
        if(client.read() ==-1)
        {

        sensing[index++] = client.read();
        Serial.println("client.read");

        delay(100);
        }
        sensing[index] = '\0';
        Serial.println(sensing);
      */
      flag = 1;
    }

    else if (dis > 40 )
    {
      if (flag == 1) {
        msg_RevData = 0;
        MsgSend();
        init_conn = 1;
        flag = 0;
        client.stop();
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

void MsgSend()
{
  sprintf(msg, "[Jetson1] %d\n", msg_RevData);
  sprintf(msg, "[admin] %d\n", msg_RevData);
  //Serial.println(msg);
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
