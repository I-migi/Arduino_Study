

//흰카드 C0 DD A6 A3
//파란색 B3 7A 74 63
#include <MFRC522.h>
#include <SPI.h>


#define   SS_PIN  10  //  칩셋핀(데이터 핀)
#define   RST_PIN 9   //  리셋핀

MFRC522 mfrc522(SS_PIN, RST_PIN);




const int g_Card_UID[4] = {0xC0, 0xDD, 0xA6, 0xA3}; //  흰 카드의 UID번호

void setup() {
  pinMode(4,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();            // Init SPI bus
  mfrc522.PCD_Init();     // Init mfrc522
  mfrc522.PCD_DumpVersionToSerial();  //  RFID의 펌웨어 버전 확인

}

bool CheckCardUID()
{
  if (mfrc522.uid.uidByte[0] == g_Card_UID[0] && 
      mfrc522.uid.uidByte[1] == g_Card_UID[1] && 
      mfrc522.uid.uidByte[2] == g_Card_UID[2] &&
      mfrc522.uid.uidByte[3] == g_Card_UID[3])
      return true;

  return false;
}

void loop() {
  // put your main code here, to run repeatedly:

  //  카드가 읽혀지지 않은 상태(찍히지 않으면)이면 리턴
  if (!mfrc522.PICC_IsNewCardPresent())   return;

  if (!mfrc522.PICC_ReadCardSerial())     return;

  //  uid카드를 출력하기. 각 자리는 16진수로 출력
  Serial.println(mfrc522.uid.uidByte[0],HEX);
  Serial.println(mfrc522.uid.uidByte[1],HEX);
  Serial.println(mfrc522.uid.uidByte[2],HEX);
  Serial.println(mfrc522.uid.uidByte[3],HEX);

  if (CheckCardUID()="C0 DD A6 A3")
  {
    
    digitalWrite(4,HIGH);}
    else              {  
    digitalWrite(4,LOW); }

   
    
   

    delay(1000);
  }
  
  //  delay함수 대신에 아래의 두 함수를 호출.
  
  
  //  읽은 카드에 대한 정보를 Serial로 전송.
  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  //delay(1000);

