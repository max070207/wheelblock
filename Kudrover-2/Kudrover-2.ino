//код для блока колеса

//порты подключения шагового двигателя
#define ENA_PORT 8
#define DIR_PORT 7
#define PUL_PORT 2

//энкодер


//джойстик
#define joyX A2
#define joyY A1

void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");
  pinMode(ENA_PORT, OUTPUT);
  pinMode(DIR_PORT, OUTPUT);
  pinMode(PUL_PORT, OUTPUT);
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  digitalWrite(ENA_PORT, 0);
  //0 - влево, 1 - вправо
}

void loop() {
  digitalWrite(DIR_PORT, 0);
  int ValX = map(analogRead(joyX), 0, 1023, 0, 255);
  int ValY = map(analogRead(joyY), 0, 1023, 0, 255);
  Serial.println(ValY);
  //поворот влево
  if (ValY < 125) {
    digitalWrite(DIR_PORT, 0);
    digitalWrite(PUL_PORT, 1);
    delay(10);
    digitalWrite(PUL_PORT, 0);
    delay(10);
  }
  if (ValY > 133) {
    digitalWrite(DIR_PORT, 1);
    digitalWrite(PUL_PORT, 1);
    delay(10);
    digitalWrite(PUL_PORT, 0);
    delay(10);
  }


}
