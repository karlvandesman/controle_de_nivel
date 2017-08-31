#include "controle_nivel.h"

//--- INICIALIZAÇÃO DO LCD ---
// Carrega as configurações do LCD e mostra as mensagens iniciais de apresentação
void  inic_lcd(){
//Inicializar o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  //Apresentar a mensagem inicial
  lcd.print("   Baltar Tec   ");
  delay(3000);

  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print(" Lendo dados do ");
  lcd.setCursor(0, 1);  
  lcd.print("     sensor     ");
  delay(500);
    
  lcd.setCursor(11, 1);
  lcd.print(".");
  delay(500);  
  
  lcd.setCursor(12, 1);
  lcd.print(".");
  delay(500);  
  
  lcd.setCursor(13, 1);  
  lcd.print(".");    
  delay(500);
  
  Serial.println("Lendo dados do sensor...");
  
  lcd.clear();
}

//--- LEITURA DOS PARÂMETROS ---
// Faz leitura do keypad para configuração dos parâmetros do sistema (altura do sensor, altura da caixa)
 
void  inic_parametros(){   

altura_sensor= keypad();

}

//--- LEITURA DO KEYPAD ---
// Espera que seja pressionado uma tecla do keypad e retorna o caracter pressionado
int   leitura_keypad(){


}


//--- CÁLCULO DA DISTÂNCIA ---
// A partir do sensor de ultrassom, calcula o nível do líquido, considerando os parâmetros (altura do sensor, altura da caixa)

float calcula_distancia(){
  float   distancia_sensor;   // Distância entre o sensor e o nível da água, em centímetros   
  long    microsec;         // Armazena o tempo de envio/recepção do ultrassom 

  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);   //Conversão para centímetro

  nivel= altura_sensor-cmMsec;

  return nivel;
}


//--- IMPRIME RESULTADO ---
// Apresenta no LCD os resultados dos cálculos de nível e volume, a partir do nivel
void  imprime_lcd(float nivel_lcd, float volume_lcd){

  lcd.setCursor(0, 0);
  lcd.print("Nivel: ");  

  if(nivel_agua<100){ 
      lcd.print(nivel_agua, 2);
      lcd.print(" cm ");
  }
  
  else{
      lcd.print(nivel_agua/100, 2);
      lcd.print(" m   ");  
  }
  
  lcd.setCursor(0, 1);
  lcd.print("Volume: ");
  
  lcd.print(volume);

  delay(1000);
}
