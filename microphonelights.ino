int calib = 0;
int sensor = A0;
int led1 = 7;
int led2 = 6;
int led3 = 5;
int led4 = 4;
int num;
void setup() {
  pinMode(sensor, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(calib == 0){
    delay(1000);
    num = analogRead(sensor);
    delay(500);
    calib ++;
  }
  int value = analogRead(sensor);
  Serial.println(value);
  if(value <= (num+2)){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if((num+2)<value && value <=(num+8)){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if((num+8)<value && value <=(num+14)){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if((num+14)<value && value <=(num+20)){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if (value >(num+20)){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  delay(50);

}
