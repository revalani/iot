#define THERMISTORPIN A0        // which analog pin to connect
#define THERMISTORNOMINAL 10000 // resistance at 25 degrees C
#define TEMPERATURENOMINAL 25   // temp. for nominal resistance (almost always 25 C)

// how many samples to take and average, more takes longer
#define NUMSAMPLES 5 // but is more 'smooth'
#define BCOEFFICIENT 3950     // The beta coefficient of the thermistor (usually 3000-4000)
#define SERIESRESISTOR 10000  // the value of the 'other' resistor

int samples[NUMSAMPLES];

void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  uint8_t i;
  float average;


  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
   samples[i] = analogRead(THERMISTORPIN);
   delay(50);
  }
 
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;
 
  //average=analogRead(THERMISTORPIN);
 
  // convert the value to resistance
  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;
 
  float steinhart;
  steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C
 
  Serial.print("Temperature "); 
  Serial.print(steinhart);
  Serial.println(" *C");
 
  delay(1000);
}
