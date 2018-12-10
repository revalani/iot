#include <Time.h.>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
}

void loop() {
  time = setTime("7","0","0","15","3","2018");
  //Serial.print(time);
  //Serial.print(timeStatus ( )) ;

  delay(1000);
}
