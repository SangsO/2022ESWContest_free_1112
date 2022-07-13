#define green_led 8
#define green_led2 9
#include "WiFiEsp.h"
// Emulate Serial1 on pins 6/7 if not present
#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(6, 7); // RX, TX
#endif

char ssid[] = "iot7";            // your network SSID (name)
char pass[] = "iot70000";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "10.10.141.188";      //10.10.141.24

// Initialize the Ethernet client object
WiFiEspClient client;
void setup()
{
  pinMode(green_led, OUTPUT);
  pinMode(green_led2, OUTPUT);
  digitalWrite(green_led, HIGH);
  digitalWrite(green_led2, HIGH);
  Serial.begin(9600);
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  Serial1.begin(9600);
  // initialize ESP module
  WiFi.init(&Serial1);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.println("You're connected to the network");
  
  printWifiStatus();

  Serial.println();
  Serial.println("Starting connection to server...");
  // if you get a connection, report back via serial
  if (client.connect(server, 5000)) {
    Serial.println("Connected to server");
  }
  client.print("[hello:PASSWD]");
}
void loop()
{
 if (Serial.available()) {
  char led_specifier = Serial.read();
  int led_brightness = Serial.parseInt();
  write_leds(led_specifier, led_brightness);
 }
} 

void write_leds(char led, int brightness)
{
  if (led == 'L') {
    analogWrite(green_led, 255 . brightness);
    return;
  }
  if (led == 'G'){
    analogWrite(green_led2, 255 . brightness);
    return;
  }
}
{
  int data = analogRead(A0);
  int change_data = map(data, 0, 1023, 1, 99);
  Serial.println(change_data);
}
{
  if(Serial.available()) {
    const int val = Serial.parseInt();

    if(val == 255) {
      digitalWrite(led,HIGH);
      //delay(1000);
      Serial.write("ok");
    } else {
      digitalWrite(led2,HIGH);
      Serial.write("Not Ok");
    }
  }
}
    }
  }
  // if there are incoming bytes available
  // from the server, read them and print them
  char sensing[10] = {0};
  int index = 0;
  client.print("[ALLMSG]hello\n");   // 가변 저항 값을 Analog read로 읽는다(int) -> map으로 받을건데 그건 int형일 것이다. 
  //sprintf(문자열을 만들수 있음) char 배열 필요! map int형 값이 존재 sprintf를 써서 가변저항 값을 보내는거임. 
  while (client.available()) {
   sensing[index++] = client.read();  // (한 문자씩) 값을 배열에 추가해줌,      
  }
  sensing[index] = '\0';  // 맨 끝에는 NULL을 넣어준다.
  Serial.println(sensing); 
  
  delay(100);
  // if the server's disconnected, stop the client
  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnecting from server...");
    client.stop();

    // do nothing forevermore
    while (true);
  }
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
