#include <Servo.h>

// Поворот для монет
// 1 руб: от 10 до 70
// 10 руб: от 10 до 75
// 2 руб: от 10 до 70
// 5 руб: от 10 до 80


Servo servo[4];
int servo_pins[] = {9, 10, 11, 12};
int servo_turns[] = {70, 75, 70, 80};
int btn_pins[] = {5, 6, 7, 8};


void give(int index) {
  servo[index].write(10);
  delay(100);
  servo[index].write(servo_turns[index]);
}

void setup() {
  for (int i=0; i<4; i++) {
    servo[i].attach(servo_pins[i]);
//    servo[i].write(10);
    servo[i].write(servo_turns[i]);
    pinMode(btn_pins[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i=0; i<4; i++) {
    if (not digitalRead(btn_pins[i])) { give(i); }
  }
}
