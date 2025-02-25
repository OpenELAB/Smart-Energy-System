//
//    FILE: INA226_array.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo four INA226's, adjust to your sensor count
//     URL: https://github.com/RobTillaart/INA226
//
//  not tested with HW yet


#include "INA226.h"


#define INA_COUNT  4

// IIC地址选择 
// A1 = 0  A0 = 0 ->0x40
// A1 = 0  A0 = 1 ->0x41
// A1 = 1  A0 = 0 ->0x44
// A1 = 1  A0 = 1 ->0x45
//
INA226 INA[INA_COUNT] =
{
  INA226(0x40),
  INA226(0x41),
  INA226(0x44),
  INA226(0x45)
};
  
char  string_V[10];
char string_I[10];
char string_W[10];
char string_X[10];
void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("INA226_LIB_VERSION: ");
  Serial.println(INA226_LIB_VERSION);
   
  Wire.begin();
  bool failed = false;
  for (int ID = 0; ID < INA_COUNT; ID++)
  {
    if (!INA[ID].begin() )
    {
      failed = true;
      Serial.println(ID);
    }
    INA[ID].setMaxCurrentShunt(8, 0.01);
  }
  if (failed)
  {
    Serial.println("One or more INA could not connect. Fix and Reboot");
    while (1);
  }

 Serial.println("\nID\tBUS\tSHUNT\tCURRENT\tPOWER");

 
}

void loop()
{
 
 /*
    for (int ID = 0; ID < 4; ID++)
    {
      Serial.print(ID);
      Serial.print("\t");
      Serial.print(INA[ID].getBusVoltage(), 3);
      Serial.print("\t");
      Serial.print(INA[ID].getShuntVoltage_mV(), 3);
      Serial.print("\t");
      Serial.print(INA[ID].getCurrent_mA(), 3);
      Serial.print("\t");
      Serial.print(INA[ID].getPower_mW(), 3);
      Serial.println();
      delay(1000);
    }
 

*/
 

      // Serial.print(INA[0].getBusVoltage(),3);

      //Serial.print(INA[0].getCurrent_mA(), 3);
      
     // Serial.print(INA[0].getPower_mW(), 3);
/*
     sprintf(string_V, "%f V", INA[0].getBusVoltage());
     Serial.print(INA[ID].getBusVoltage(), 3);
     Serial.println(string_V);

    sprintf(string_X,"page0.t10.txt=%s\xff\xff\xff",string_V);  
      Serial.println(string_X);
memset(string_V,0,sizeof(string_V));
memset(string_X,0,sizeof(string_X));
    delay(1000);
*/

 
float voltage = INA[0].getBusVoltage();
dtostrf(voltage, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
 char string_X[50];
 char str[50];
sprintf(string_X, "page0.t10.txt=\"%s V\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);
 Serial.print(str);

delay(1000);
 


 
}


//  -- END OF FILE --
