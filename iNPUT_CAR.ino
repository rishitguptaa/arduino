void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void forward();

char x;

void loop()
{
  if (Serial.available())
  {
    x = Serial.read();
    Serial.write(x);

    if (x == 'f')
    {
      forward();
      digitalRead(2, HIGH);
      digitalRead(3, LOW);
      digitalRead(4, HIGH);
      digitalRead(5, LOW);

    }
  }
}
