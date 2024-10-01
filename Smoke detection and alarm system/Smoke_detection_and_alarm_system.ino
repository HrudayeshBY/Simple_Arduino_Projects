//Declaring variables for pin
int buzzerPin = 3;
int ledPin = 4;
int greenLedPin = 5;
int sensorPin = A0;

//Declaring variables for values
int sensorValue = 0;
int thresholdValue = 500;

void setup()
{
  pinMode(buzzerPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(sensorPin,INPUT);
  pinMode(greenLedPin,OUTPUT);
  Serial.begin(9600);

  Serial.println("Initialising Sensor");
  for(int i = 0;i < 3;i++)
  {
    Serial.print("...");
    delay(1000);
  }
  Serial.println("");
  digitalWrite(greenLedPin,HIGH);
  Serial.println("Sensor Initialized");
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue > thresholdValue)
  {
    while(1)
    {
      analogWrite(buzzerPin,100);
      digitalWrite(ledPin,HIGH);
      delay(100);
      analogWrite(buzzerPin,200);
      digitalWrite(ledPin,LOW);
      delay(100);
    }
  }
  delay(1000);
}

