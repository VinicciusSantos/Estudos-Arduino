// Link: https://www.tinkercad.com/things/9kQ4IgxRcJH-mesa-de-corte

#define bt01 0
#define bt02 1
#define bt03 2
#define bt04 3
#define bt05 4
#define bt06 5

#define led01v 13
#define led01g 12
#define led02v 11
#define led02g 10
#define led03v 9
#define led03g 8

int noar, preview, ultimo = 0;

void vermelho(int ledg, int ledv)
{
  digitalWrite(ledv, 1);
  digitalWrite(ledg, 0);
}

void verde(int ledg, int ledv)
{
  digitalWrite(ledv, 0);
  digitalWrite(ledg, 1);
}

void apagado(int ledg, int ledv)
{
  digitalWrite(ledv, 0);
  digitalWrite(ledg, 0);
}

void setup()
{
  pinMode(led01v, OUTPUT);
  pinMode(led01g, OUTPUT);
  pinMode(led02v, OUTPUT);
  pinMode(led02g, OUTPUT);
  pinMode(led03v, OUTPUT);
  pinMode(led03g, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(bt01, INPUT_PULLUP);
  pinMode(bt02, INPUT_PULLUP);
  pinMode(bt03, INPUT_PULLUP);
  pinMode(bt04, INPUT_PULLUP);
  pinMode(bt05, INPUT_PULLUP);
  pinMode(bt06, INPUT_PULLUP);
}

void loop()
{ 
  int i = analogRead(A0);
  digitalWrite(7, i);
  
  ultimo = noar; 
  if (digitalRead(bt01) == LOW)
    preview = 1;
  if (digitalRead(bt02) == LOW)
    noar = 1;
  if (digitalRead(bt03) == LOW)
    preview = 2;
  if (digitalRead(bt04) == LOW)
    noar = 2;
  if (digitalRead(bt05) == LOW)
    preview = 3;
  if (digitalRead(bt06) == LOW)
    noar = 3;
  
  switch (preview)
  {
    case 1: 
    	verde(led01g, led01v);
    	if (noar != 2)
        	apagado(led02g, led02v);
    	if (noar != 3)
        	apagado(led03g, led03v);
    	break;
    case 2: 
    	verde(led02g, led02v);
    	if (noar != 1)
        	apagado(led01g, led01v);
    	if (noar != 3)
        	apagado(led03g, led03v);
    	break;
    case 3: 
    	verde(led03g, led03v);
    	if (noar != 1)
        	apagado(led01g, led01v);
    	if (noar != 2)
        	apagado(led02g, led02v);
    	break;
  }
  
  switch (noar)
  {
    case 1: 
    	vermelho(led01g, led01v);
    	if (preview != 2)
        	apagado(led02g, led02v);
    	if (preview != 3)
        	apagado(led03g, led03v);
    	break;
    case 2: 
    	vermelho(led02g, led02v);
    	if (preview != 1)
        	apagado(led01g, led01v);
    	if (preview != 3)
        	apagado(led03g, led03v);
    	break;
    case 3: 
    	vermelho(led03g, led03v);
    	if (preview != 1)
        	apagado(led01g, led01v);
    	if (preview != 2)
        	apagado(led02g, led02v);
    	break;
  }
  
  if (noar == preview)
    preview = ultimo;
}
