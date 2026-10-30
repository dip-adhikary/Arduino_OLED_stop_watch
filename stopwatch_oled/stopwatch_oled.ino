#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define width 128
#define height 64
Adafruit_SSD1306 dipoled(width,height,&Wire,-1); //Object of the OLED
int startbutton=2;
int stopbutton=12;
bool notpress=true;
unsigned long clicktime;
unsigned long start;
unsigned long current_time=0;
int i=0;
int check=0;
bool press_check=true;


void setup() {
  pinMode(startbutton,INPUT_PULLUP);
  pinMode (stopbutton,INPUT_PULLUP);
  dipoled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  Serial.begin(9600);

}

void loop() {
  //This is the starting screen
  if(check<1)
  {
    dipoled.clearDisplay();
   dipoled.setTextColor(WHITE);
   dipoled.setTextSize(2);
   dipoled.setCursor(32,10);
   dipoled.println("CLICK");
   dipoled.setCursor(48,28);
   dipoled.println("TO");
   dipoled.setCursor(35,46);
   dipoled.println("START!");
   dipoled.display();
  }
  if(!(digitalRead(startbutton)) && notpress)   //Start button
  {
    notpress=!(notpress);     //Used this to avoid button hold problem.
    check=check+1;            //Removes the "CLICK TO START!" Screen.
    clicktime=millis();       //Stores the time at which start button is clicked
  }
  Serial.println(notpress);
  if(!(digitalRead(stopbutton)) && press_check)  // Stop/Pause button
  {
    Serial.println("Clicked");                   
    notpress=!(notpress);
    current_time=start;              /*This stores the time at which timer is paused, so when
                                      it get restarted again the timer get started at the exact 
                                      time where it was paused.*/
    press_check=!(press_check);
  }
  //This part shows the actual timer
  if(!(notpress))                                 
  {                                                  
    press_check=!(press_check);
    start=millis()-(clicktime-current_time);   //Calculates the time passed after the button click 
    dipoled.clearDisplay();
    dipoled.setTextColor(WHITE);
     if(i<10){
       dipoled.setCursor(32,16);
     }
     else dipoled.setCursor(18,16);
    dipoled.setTextSize(3);
     if(millis()-(clicktime-current_time)>=1000){
       i++;
       clicktime=clicktime+1000;
    }
    dipoled.println(i);
    dipoled.setCursor(48,16);
    dipoled.println(":");
    dipoled.setCursor(64,16);
    dipoled.println(start/10);
    dipoled.display();
    
  }

}
