#ifndef HEADER_H_
#define HEADER_H_

#include <Arduino.h>  
#include <EEPROM.h>           //Memória EEPROM para salvar informações dos parâmetros do sistema
#include <Ultrasonic.h>       //Sensor de ultrassom para cálculo de distância
#include <LiquidCrystal.h>    //LCD para exibição das mensagens e cálculos
#include <SdFat.h>            //Cartão SD para gravação dos dados

//Define os pinos de entrada do LCD
  //Caso com o módulo LCD keypad shield
#define PINO_D4   4   //Pino 6 do atmega328P
#define PINO_D5   5   //Pino 11 do atmega328P
#define PINO_D6   6   //Pino 12 do atmega328P
#define PINO_D7   7   //Pino 13 do atmega328P
#define PINO_RS   8   //Pino 14 do atmega328P
#define PINO_ENA  9   //Pino 15 do atmega328P
   
   //Caso com módulo I2C
#define LCD_SDA   4
#define LCD_SCL   5

//Define os endereços da memória referente às alturas de cada item, para cálculo do nível e volume de água
#define ENDER_CAIXA   0
#define ENDER_SENSOR  1

// -------------------------------------------------------------
//Variáveis Globais

//--------------------------------------------------------------

void  inic_lcd();           // Carrega as configurações do LCD e mostra as mensagens iniciais de apresentação
int   leitura_keypad();     // Espera que seja pressionado uma tecla do keypad e retorna o caracter pressionado
void  inic_parametros();    // Faz leitura do keypad para configuração dos parâmetros do sistema (altura do sensor, altura da caixa)
float calcula_distancia();  // A partir do sensor de ultrassom, calcula o nível do líquido, considerando os parâmetros (altura do sensor, altura da caixa)
void  imprime_lcd(float);   // Imprime no LCD o nível e o volume do líquido, a partir do cálculo de distância do ultrassom
  
#endif /* HEADER_H_ */
