//Program to demonstrate high beam assit on Arduino with ultasonic sensor

int sw1Pin = 6;
int sw2Pin = 7;
int headLightPin = 10;
int highBeamPin = 8;
int sw1PinStatus = 0;
int sw2PinStatus = 0;
int trigPin = 3;
int echoPin = 2;
int threshHoldDistance = 10;

int pingTime = 0;
int distance = 0;

void setup()
{
  pinMode(sw1Pin,INPUT);
  pinMode(sw2Pin,INPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(headLightPin,OUTPUT);
  pinMode(highBeamPin,OUTPUT);

  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime = pulseIn(echoPin,HIGH,30000);
  distance = (0.0343*pingTime)/2;

  Serial.print(distance);
  Serial.println(" cm");

  sw1PinStatus = digitalRead(sw1Pin);
  sw2PinStatus = digitalRead(sw2Pin);

  Serial.println(sw1PinStatus);
  Serial.println(sw2PinStatus);

  if((distance <= threshHoldDistance) && (sw2PinStatus == 1))
  {
    digitalWrite(highBeamPin,LOW);
    Serial.println("Vehicle Detected switched to Low Beam");
  }

  else
  {
  if(sw1PinStatus == 0)
  {
    digitalWrite(headLightPin,LOW);
    digitalWrite(highBeamPin,LOW);
  }

  if(sw1PinStatus == 1)
  {
    digitalWrite(headLightPin,HIGH);
    digitalWrite(highBeamPin,LOW);
    Serial.println("Headlight ON");
  }

  if(sw1PinStatus == 1 && sw2PinStatus == 1)
  {
    digitalWrite(headLightPin,HIGH);
    digitalWrite(highBeamPin,HIGH);
    Serial.println("High Beam ON");
  }
  }
  delay(50);
}
