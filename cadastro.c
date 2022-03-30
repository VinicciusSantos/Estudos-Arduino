// Link do tinkerkad: https://www.tinkercad.com/things/2AneXGtOJ3F-tremendous-robo

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Se adm == 0 -> completo
// Se adm == 1 -> Selecionar Idade
// Se adm == 2 -> Selecionar Nome
int adm = 2;
char alpha[] = "abcdefghijklmnopqrstuvwxyz";

int dia_hoje = 30;
int mes_hoje = 03;
int ano_hoje = 2022;

int bt_voltar = 7;
int bt_mais = 8;
int bt_menos = 9;
int bt_enter = 10;
  
void setup() {  
  pinMode(bt_mais, INPUT);
  pinMode(bt_menos, INPUT);
  pinMode(bt_enter, INPUT);
  pinMode(bt_voltar, INPUT);
 
  lcd.begin(16, 2);
  lcd.print("-- Desafio 01 --");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando");
  for (int i = 0; i < 3; i++)
  {
  	lcd.print(".");
    delay(600);
  }
  delay(200);
  lcd.clear();
}

void loop() {
  int editando = 1;
  int dia_evento = dia_hoje;
  int mes_evento = mes_hoje;
  int ano_evento = ano_hoje;
 
  while(1) // Recebendo a data do evento
  {
    if (adm >= 1) break;
    delay(250);
    lcd.clear();
    lcd.setCursor(0, 0);
  	lcd.print("Dia do Evento:");
    lcd.setCursor(0, 1);
    
    // Lendo os Imputs dos botões
    int bmais = digitalRead(bt_mais);
    int bmenos = digitalRead(bt_menos);
    int benter = digitalRead(bt_enter);
    int bvoltar = digitalRead(bt_voltar);
    
    // Configurando os botões de voltar e avançar
    if (bvoltar == 1 && editando != 1) editando--;
    if (benter == 1) editando++;
    if (editando > 3) break;
    
    
	if (editando == 1) // editar dia
    {
      if (bmais == 1) dia_evento++;
      if (bmenos == 1) dia_evento--;
      
      if (dia_evento > 30) dia_evento = 1;
      if (dia_evento < 1) dia_evento = 30;
    }
    
    if (editando == 2) // editar mês
    {
      if (bmais == 1) mes_evento++;
      if (bmenos == 1) mes_evento--;
      
      if (mes_evento > 12) mes_evento = 1;
      if (mes_evento < 1) mes_evento = 12;
    }
    
    if (editando == 3) // editar ano
    {
      if (bmais == 1) ano_evento++;
      if (bmenos == 1) ano_evento--;
    }
    
   	// Imprimindo o dia
    lcd.print(" ");  
    if (editando == 1) lcd.print("<");
    else lcd.print(" ");
    if (dia_evento < 10) lcd.print("0");
    lcd.print(dia_evento);
    if (editando == 1) lcd.print(">");
    else lcd.print(" ");
    
    // Imprimindo o mês
    if (editando == 2) lcd.print("<");
    else lcd.print(" ");
    if (mes_evento < 10) lcd.print("0");
    lcd.print(mes_evento);
    if (editando == 2) lcd.print(">");
    else lcd.print(" ");
    
    // Imprimindo o Ano
    if (editando == 3) lcd.print("<");     
    else lcd.print(" ");
    lcd.print(ano_evento); 
    if (editando == 3) lcd.print(">");
  } 
  
  // Testando se a data do evento é válida (posterior à atual)
  if ((ano_evento >= ano_hoje) || (ano_evento == ano_hoje && mes_evento > mes_hoje) || adm >= 1)
  {
    delay(100);
    int idade = 18;
    
    while(1) // Recebendo a idade da pessoa
    {
      if (adm >= 2) break;
      delay(250);
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("Idade:");
      
      // Recebendo os imputs
      int bmais = digitalRead(bt_mais);
      int bmenos = digitalRead(bt_menos);
      int benter = digitalRead(bt_enter);
      
      
      if (bmais == 1) idade++;
      if (bmenos == 1) idade--;
      if (benter == 1) break;
      
      lcd.setCursor(0, 1);
      lcd.print("   <");
      lcd.print(idade);
      lcd.print(" anos>");
    }
    
    // Verificando a idade da pessoa
    if (idade >= 18 || adm >= 2)
    {
        int escolha = 0;
   		int quant = 0;
        char nome[] = "aaaaaa";
      
     	while (1) // Recebendo o nome da pessoa
        {
          delay(200);
          lcd.clear();
          
          lcd.setCursor(0, 0);
          lcd.print("Digite seu Nome:");
          
          // Recebendo os imputs
          int bmais = digitalRead(bt_mais);
      	  int bmenos = digitalRead(bt_menos);
      	  int benter = digitalRead(bt_enter);
          int bvoltar = digitalRead(bt_voltar);
          
          // Configurando os botões
          if (bmais == 1) escolha++;
          
          else if (bmenos == 1) escolha--;
            
          else if (bvoltar == 1 && quant != 0)
          {
            quant--;
            for (int i = 0; i < 26; i++)
            {
              if (alpha[i] == nome[quant]) escolha = i;
            }
          }
          
          else if (benter == 1)
          {
           	quant++;
            for (int i = 0; i < 26; i++)
            {
              if (alpha[i] == nome[quant]) escolha = i;
            }
          }
          
          // Se for menor que "Z", volta para "A" e vice-versa
          if (escolha < 0) escolha = 25;
          if (escolha > 25) escolha = 0;
            
          nome[quant] = alpha[escolha];
          lcd.setCursor(0, 1);
          lcd.print(" ");
          for (int i = 0; i < 6; i++) // Imprimindo
          {
            if (quant == i) lcd.print("<");
            else lcd.print(" ");
           	lcd.print(nome[i]);
            if(quant == i) lcd.print(">");
            else lcd.print(" ");
          }
        }
    }
    
    else // Se a idade for menor que 18 anos
    {
    	lcd.clear();
      	lcd.print("IDADE INVALIDA!");
        delay(1000);
    }
  }
  
  else // Se a data for anterior que a data atual
  {
    lcd.clear();
    lcd.print("DATA INVALIDA!");
    delay(1000);
  }
}
 