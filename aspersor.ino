//Carrega a biblioteca do sensor ultrassônico 
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
//Inicializa o pino de controle do relê
{
  pinMode(12, OUTPUT);
}
 
void loop()
{
  digitalWrite(2, HIGH);

  // define variáveis
  float cmMsec;
  long microsec = ultrasonic.timing();
  
  //Le as informacoes do sensor
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  //compara distância e aciona motor quando está é menor que 8cm
  if (cmMsec < 8) {
    digitalWrite(12, LOW);
  
  // mantem a corrente de energia ligada por 30 segundos
    delay(3000); 
  }
  
  // espera 1 minuto até nova leitura para evitar sobrecarga no motor
  delay(60000);
}
