#include <SPI.h>
#include <mcp2515.h>

#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C (lcd(0x3F, 16, 2); 

struct can_frame canMsg;
MCP2515 mcp2515(10);

void setup() 
{
  //lcd.init();
  //lcd.backlight();
  //delay(1000);

  SPI.begin();          //Starter SPI kommunikasjon

  Serial.begin(9600);

  mcp2515.reset();

  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);  //Setter CAN speed
  mcp2515.setNormalMode();
}

void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
  {
    if(canMsg.can_id==0x036)
    {
      int x = canMsg.data[0];
      Serial.println(x);
      //lcd.setCursor(1,0);
      //lcd.print("CAN Receiver...");
      //lcd.setCursor(2,1);
      //lcd.print("pot value: ");
      //lcd.print(x);
      delay(200);
    }
  }
}
