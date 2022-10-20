#include <Servo.h>

Servo l1;    //컵드는거
Servo l2;    //흔드는거
Servo l;     //자석

Servo m1;    //컵드는거
Servo m2;    //흔드는거
Servo m;     //자석

Servo r1;    //컵드는거
Servo r2;    //흔드는거
Servo r;     //자석

int srt;
int ranVal;

int lp1;  //position 각도
int lp2;
int lp3;

int mp1;  //position 각도
int mp2;
int mp3;

int rp1;  //position 각도
int rp2;
int rp3;

int bt1 = 42;
int bt2 = 44;
int bt3 = 46;
int b1val = 1;
int b2val = 1;
int b3val = 1;

int pAns = 3;

int buzPin = 8;
//int numtunes =
//int tones[] = {};

void shake();
void hide();
void choose();
void answer();
void result();
void reset();

void setup() {
  Serial.begin(9600);
  pinMode(22, INPUT_PULLUP);  //start button
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);


  l1.attach(24);
  l2.attach(26);
  l.attach(28);
  m1.attach(30);
  m2.attach(32);
  m.attach(34);
  r1.attach(36);
  r2.attach(38);
  r.attach(40);

  l1.write(50);
  m1.write(50);
  r1.write(50);
}

void loop() {
  srt = digitalRead(22);
  Serial.println(srt);

  if (srt == 0) {
    shake();
    delay(1000);
    l2.write(90);
    m2.write(90);
    r2.write(90);
    delay(5);


//    for (int i=0; i<100; i++) {
        choose();
        delay(50);
//    }
    answer();
    result();
    reset();
  }  
}

void shake() {
  l2.write(103);
  m2.write(103);
  r2.write(103);
  delay(5);
  l2.write(87);
  m2.write(87);
  r2.write(87);
  delay(5);
  l2.write(103);
  m2.write(103);
  r2.write(103);
  delay(5);
  l2.write(87);
  m2.write(87);
  r2.write(87);
  delay(5);

  for (int i=0; i<170; i++) {
    l.write(i);
    r.write(i);
    delay(5);
  }
  delay(1000);
  for (int j=170; j>0; j--) {
    l.write(j);
    r.write(j);
    delay(5);
  }
  delay(1000);
}

void hide() {
    ranVal = getTrueRotateRandomByte() % 3;
    if (ranVal == 0) {
        for (int i=0; i<170; i++) {
        m.write(i);
        r.write(i);
        delay(5);
        }
    }
    if (ranVal == 1) {
        for (int i=0; i<170; i++) {
        l.write(i);
        r.write(i);
        delay(5);
        }
    }
    if (ranVal == 2) {
        for (int i=0; i<170; i++) {
        l.write(i);
        m.write(i);
        delay(5);
        }
    }
}

void choose() {
    b1val = digitalRead(bt1);
    b2val = digitalRead(bt2);
    b3val = digitalRead(bt3);
}

void answer() {
    if (b1val == 0) {
        pAns = 0;
    } else if(b2val == 0) {
        pAns = 1;
    } else if (b3val == 0) {
        pAns = 2;
    } else {
        pAns = 3;
    }
}

void result() {
    if (ranVal == pAns) {
        tone(buzPin, 0);
        delay(500);
        noTone(buzPin);
        for (int j=50; j<85; j++) {
            l1.write(j);
            m1.write(j);
            r1.write(j);
            delay(5);
        }
    } else {
        tone(buzPin, 1);
        delay(500);
        noTone(buzPin);
        for (int j=50; j<85; j++) {
            l1.write(j);
            m1.write(j);
            r1.write(j);
            delay(5);
        }
    }
    delay(2000);
    for (int j=85; j<50; j--) {
        l1.write(j);
        m1.write(j);
        r1.write(j);
        delay(5);
    }
}

void reset() {
    for (int i=170; i<0; i--) {
        l.write(i);
        r.write(i);
        delay(5);
    }
    ranVal = 3;
    b1val = 1;
    b2val = 1;
    b3val = 1;
    pAns = 3;
}
