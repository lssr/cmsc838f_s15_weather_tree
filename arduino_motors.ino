
#include <Servo.h> 
 
Servo myservo;
int SERVO_PIN = 9;
int SERVO_POS = 180;
int SERVO_POS_PREV = 180;
int SERIAL_INT = 100;
int INCOMING_POS = 0;
 
void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
} 


void loop() {
  
  if (Serial.available() > 0) {
    
    SERIAL_INT = Serial.parseInt();
            Serial.print("incoming value: ");
            Serial.println(SERIAL_INT);
    
    INCOMING_POS = map(SERIAL_INT, 0, 100, 180, 0);
    
            Serial.print("INCOMING_POS: ");
            Serial.println(INCOMING_POS);
    
    if (INCOMING_POS >= SERVO_POS_PREV) {
        for(SERVO_POS = SERVO_POS_PREV; SERVO_POS <= INCOMING_POS; SERVO_POS += 1) {
          myservo.write(SERVO_POS);
          delay(25);
        } 
    } else {
        for(SERVO_POS = SERVO_POS_PREV; SERVO_POS >= INCOMING_POS; SERVO_POS -= 1) {                                
          myservo.write(SERVO_POS); 
          delay(25);
        }
    }
    
    SERVO_POS_PREV = INCOMING_POS;
  }
}

