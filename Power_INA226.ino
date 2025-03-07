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
  Serial.begin(9600);
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
    INA[ID].setMaxCurrentShunt(1, 0.01);
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
 //delay(1000);
//Solar
float Current_mA =INA[0].getCurrent_mA();
if(Current_mA<0)Current_mA=0.00;
dtostrf(Current_mA, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
char string_X[50];
sprintf(string_X, "page0.t7.txt=\"%s mA\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);

float voltage = INA[0].getBusVoltage();
dtostrf(voltage, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
//string_X[50];
sprintf(string_X, "page0.t11.txt=\"%s V\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);

float Power_mW = INA[0].getPower_mW();
dtostrf(Power_mW, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
//string_X[50];
sprintf(string_X, "page0.t15.txt=\"%s mW\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);

//Battery
Current_mA =INA[1].getCurrent_mA();
if(Current_mA<0)Current_mA=0.00;
dtostrf(Current_mA, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
 //string_X[50];
sprintf(string_X, "page0.t8.txt=\"%s mA\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);
 
voltage = INA[1].getBusVoltage();
dtostrf(voltage, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
//string_X[50];
sprintf(string_X, "page0.t12.txt=\"%s V\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);

Power_mW = INA[1].getPower_mW();
dtostrf(Power_mW, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
//string_X[50];
sprintf(string_X, "page0.t16.txt=\"%s mW\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);

//LOAD1
Current_mA =INA[2].getCurrent_mA();
if(Current_mA<0)Current_mA=0.00;
dtostrf(Current_mA, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
sprintf(string_X, "page0.t9.txt=\"%s mA\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);
 
voltage = INA[2].getBusVoltage();
dtostrf(voltage, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
sprintf(string_X, "page0.t13.txt=\"%s V\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);

Power_mW = INA[2].getPower_mW();
dtostrf(Power_mW, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
sprintf(string_X, "page0.t17.txt=\"%s mW\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);



//LOAD2
Current_mA =INA[3].getCurrent_mA();
if(Current_mA<0)Current_mA=0.00;
dtostrf(Current_mA, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
sprintf(string_X, "page0.t10.txt=\"%s mA\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);
 
voltage = INA[3].getBusVoltage();
dtostrf(voltage, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
sprintf(string_X, "page0.t14.txt=\"%s V\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);

Power_mW = INA[3].getPower_mW();
dtostrf(Power_mW, 4, 3, string_V);  // 将浮点数转为字符串，保留三位小数
sprintf(string_X, "page0.t18.txt=\"%s mW\"\xff\xff\xff", string_V);  // 拼接字符串
Serial.print(string_X);
}
