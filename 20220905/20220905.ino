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
unsigned long past = 0;
int pre_charging = 0;
int ori_val, cur_charging;

int init_conn = 0; //입차및출차시 주소, 포트 연결하여 In,Out으로 로그인

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
int kjh = 0;
  /*
void loop(){
  
  while(aasdasdasd){
    pArray[0] == block --> mode =1; // 차 들어갑니다.
    pArray[0] == Jetson1 --> mode = 2;// 충전 시작해주세요 .
    pArray[0] == admin --> mode =3;
  }
  
  if(mode ==1){
    distasfadfasfdas
    유도. dis(
  }

  else if(mode ==2){
    충전관련
  }

  else if(mode ==3){
    원격제어 관련.
  }
  
  mode = -1;
}
*/



void loop() {
  char ch[30] = {0};
  int index = 0;
  int str_len;
  char *pToken;
  char *pArray[2] = {0};



  if ((WiFiMulti.run() == WL_CONNECTED))
  {
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
        MsgSend_adm(1);
        delay(10);
        MsgSend_Jes("1");
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
          //ledcontrol(pArray[1]);
          if (strcmp(pArray[1], "5") == 0)
          {
            abc = 1;
          }
          for (int i = 0; i <= str_len; i++)
          {
            ch[i] = 0;
            index = 0;
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
      flag = 1;
    }

    else if (dis > 40 )
    {
      if (flag == 1) {
        MsgSend_adm(0);
        delay(10);
        MsgSend_Jes("0");
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

void MsgSend_adm(int msg_RevData)
{
  sprintf(msg1, "[admin]%d\n", msg_RevData);
  Serial.println(msg1);
  client.print(msg1);
}
void MsgSend_Jes(char* msg_RevData)
{
  sprintf(msg, "[Jetson1]%s\n", msg_RevData);
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
