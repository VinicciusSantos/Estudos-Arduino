//  Link: https://www.tinkercad.com/things/4xG2Xh4RZvF-ex001/

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void color(int num)
{
  digitalWrite(num, HIGH);
  delay(1000);
  digitalWrite(num, LOW); 
}

void loop()
{
  color(13);
  color(12);
  color(11);  
}
