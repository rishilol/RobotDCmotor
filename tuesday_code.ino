const int DIRECTION_PIN_1 =7;
const int DIRECTION_PIN_2 =8;
const int SPEED_PIN =9;
const int CONTROL_PIN = A0;
const int MOTION_MIN = 78; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(DIRECTION_PIN_1, OUTPUT);
  pinMode(DIRECTION_PIN_2, OUTPUT);
  pinMode(SPEED_PIN, OUTPUT);

  digitalWrite(DIRECTION_PIN_1, HIGH);
  digitalWrite(DIRECTION_PIN_2, LOW);
  digitalWrite(SPEED_PIN, 0);




}

void loop()
 {
  int val, calcSpeed;

  val = analogRead(CONTROL_PIN);
  if(val > 522 && val < 1024){
    digitalWrite(DIRECTION_PIN_1, HIGH);
    digitalWrite(DIRECTION_PIN_2, LOW);
    calcSpeed = map(val, 523, 1023, MOTION_MIN, 255);

  }else if(val >= 0 && val< 502){
    digitalWrite(DIRECTION_PIN_1, LOW);
    digitalWrite(DIRECTION_PIN_2, HIGH);
    calcSpeed = map(val, 502, 0, MOTION_MIN,255);
  }
  else{
    calcSpeed =0;
  }

  analogWrite(SPEED_PIN, val);
  Serial.println(calcSpeed);

  delay(500);
}
    



