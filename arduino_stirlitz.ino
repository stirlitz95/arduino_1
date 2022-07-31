
#define d_2 (783)
#define d_3 (354)
#define d_4 (998)

#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 11);

class Diode {
  private:
    int pin;
    int interval;
    int state;
    unsigned long tm;
  public:
    Diode(int p, int i) {
      pin=p;
      interval=i;
      state=LOW;
      tm=millis(); 
    }
    void run() {
      unsigned long t=millis();
      if (t >= tm+interval) {
        if (state == LOW) state=HIGH;
        else state=LOW;
        digitalWrite(pin,state);
        tm=t;
      }
    }
};

Diode d2(2, d_2);
Diode d3(3, d_3);
Diode d4(4, d_4);
//
Diode d13(13, 123);

void setup() {
  for (int i=2; i<=4; i++) pinMode(i, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  d2.run();
  d3.run();
  d4.run();
  d13.run();
  // unsigned int dist=ultrasonic.read();
}
