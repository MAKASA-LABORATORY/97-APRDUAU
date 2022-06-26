#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16, 2);

int ss,mm,hh,MM,DD,YYYY,AP;

int ass,amm,ahh,aMM,aDD,aYYYY,aAP;

int k=0, output, plug;

void setup()

{

lcd.init();
lcd.clear();
lcd.backlight();
Serial.begin(9600);

lcd.begin(16,2);

}

void loop()

{

/*After asking for details k=1 so never asks for instructions again*/

if(k<=0)

{

/*Details() - Asks for time and date*/

Details();

}

ss=ss+1;

if(ss==60)

{

ss=0;

mm=mm+1;

if(mm==60)

{

mm=0;

hh=hh+1;

if(hh==12)

{

AP=AP+1;

printTime2();

/*Day only advances when going from PM to AM*/

if(AP%2==0)

{

DD=DD+1;

}

// assumes that all months have 28 days

if(DD==28)

{

DD=1;

MM=MM+1;

if(MM==13)

{

MM=1;

YYYY=YYYY+1;

}

}

}

if(hh==13)

{

hh=1;

}

}

}

/*printTime2 - adds one second and displays time on LCD display*/

printTime2();

}

void line()

{

Serial.println("");

}

void Details()

{
Serial.println("Set current time & date");

Serial.println("Enter current hour:");

while(Serial.available()==0);

hh=Serial.parseInt();

/*line() - inserts blank line into serial monitor to separate data*/

line();

Serial.println("Enter current minute:");

while(Serial.available()==0);

mm=Serial.parseInt();

line();

Serial.println("Enter current second:");

while(Serial.available()==0);

ss=Serial.parseInt();

line();

for(;;)
{
Serial.println("Enter AM(0) or PM(1)");

while(Serial.available()==0);

AP=Serial.parseInt();


if(AP==0)
{
  line();
  break;
}
else if(AP==1)
{
  line();
  break;
}
else Serial.println("Invalid input. Try again."); line();

}

Serial.println("Enter current month:");

while(Serial.available()==0);

MM=Serial.parseInt();

line();

Serial.println("Enter current day:");

while(Serial.available()==0);

DD=Serial.parseInt();

line();

Serial.println("Enter current year:");

while(Serial.available()==0);

YYYY=Serial.parseInt();

line();

for(;;)
{
Serial.println("Set unplug(0) or plug(1) time:");

while(Serial.available()==0);

plug=Serial.parseInt();

line();

if(plug==0)
{
  Serial.println("Unplug");
  Details2();
  line();
  break;
}
else if(plug==1)
{
  Serial.println("Plug");
  Details2();
  line();
  break;
}
else Serial.println("Invalid input. Try again."); line();

}
k=k+1;

}

void Details2()
  
{
  
Serial.println("Enter hour:");

while(Serial.available()==0);

ahh=Serial.parseInt();

line();

Serial.println("Enter minute:");

while(Serial.available()==0);

amm=Serial.parseInt();

line();

Serial.println("Enter second:");

while(Serial.available()==0);

ass=Serial.parseInt();

line();

for(;;)
{
Serial.println("Enter AM(0) or PM(1)");

while(Serial.available()==0);

aAP=Serial.parseInt();


if(aAP==0)
{
  line();
  break;
}
else if(aAP==1)
{
  line();
  break;
}
else Serial.println("Invalid input. Try again."); line();

}

Serial.println("Enter month:");

while(Serial.available()==0);

aMM=Serial.parseInt();

line();

Serial.println("Enter day:");

while(Serial.available()==0);

aDD=Serial.parseInt();

line();

Serial.println("Enter year:");

while(Serial.available()==0);

aYYYY=Serial.parseInt();

line();

lcd.setCursor(2,0);

if(plug == 0)
{
  lcd.print("Unplug at:");
}
else if(plug == 1)
{
  lcd.print("Plug at:");
}
delay(2000);

lcd.clear();

lcd.setCursor(0,0);
  
lcd.print("TIME:");

/*printTime - places "0" in front of single digit numbers*/

printTime(ahh); lcd.print(":");

printTime(amm); lcd.print(":");

printTime(ass); lcd.print(" ");

/*if aAP is odd, it reads AM

if aAP is even, it reads PM*/

if(aAP%2==0)

{lcd.print("AM");}

if(aAP%2==1)

{lcd.print("PM");}

lcd.setCursor(0,1);
  
lcd.print("DATE:");

printTime(aMM); lcd.print("/");

printTime(aDD); lcd.print("/");

printTime(aYYYY);

delay(3000);

lcd.clear();

lcd.setCursor(4,0);

lcd.print("Current");

lcd.setCursor(2,1);

lcd.print("Time & Date");

delay(2000);

lcd.clear();

}

void printTime(int x)

{

if(x<=9)

{

lcd.print("0");lcd.print(x);

}

else

{

lcd.print(x);

}

}


void printTime2()

{
  
if(hh==ahh&&mm==amm&&ss==ass&&AP==aAP&&MM==aMM&&DD==aDD&&YYYY==aYYYY)
{
  lcd.clear();
  
  lcd.setCursor(1,0);
  
  if(plug == 0)
  {
  lcd.print("The device has");
  
  lcd.setCursor(2,1);
  
  lcd.print("been unplug.");
 
  output=0;
  }
  
  else if(plug==1)
  {
  lcd.print("The device has");
  
  lcd.setCursor(2,1);
  
  lcd.print("been plug.");
 
  output=1;
  }
  
  ss += 5;
  
  delay(5000);
  
  lcd.clear();
}

else
   

 
lcd.setCursor(0,0);

lcd.print("TIME:");

/*printTime - places "0" in front of single digit numbers*/

printTime(hh); lcd.print(":");

printTime(mm); lcd.print(":");

printTime(ss); lcd.print(" ");

/*if AP is odd, it reads AM

if AP is even, it reads PM*/

if(AP%2==0)

{lcd.print("AM");}

if(AP%2==1)

{lcd.print("PM");}

lcd.setCursor(0,1);
  
lcd.print("DATE:");

printTime(MM); lcd.print("/");

printTime(DD); lcd.print("/");

printTime(YYYY);

delay(1000);
  

}
