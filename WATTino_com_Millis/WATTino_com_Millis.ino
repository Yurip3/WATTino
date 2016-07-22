const int sensorT = A0;  //Sensor de Tensao
const int sensorC = A1; //Sensor de Corrente

float Tensao = 0;              // Variavel que guarda os Valores convertidos de Tensao
float Corrente = 0;            // Variavel que guarda os valores convertidos de Corrente
float LeituraTensao = 0;       // Variavel que guarda os valores lidos de Tensao
float LeituraCorrente = 0;     // Variavel que guarda os valores lidos de Corrente


unsigned long  tempoAnterior = 0;
const long intervalo = 67;            //Pode ser alterado para 65.75  


void setup() 
{
  Serial.begin(9600);
  pinMode( sensorT, INPUT);              //  Inicia os Sensores
  pinMode( sensorC, INPUT);             //      como Entrada
}

void loop() 
{
 unsigned long tempoAtual = millis();



 if ( tempoAtual - tempoAnterior >= intervalo)
{
  LeituraTensao = analogRead(sensorT);                                    // Faz a Leitura do Sensor de Tensao
  LeituraCorrente = analogRead(sensorC);                                  // Faz a Leitura do Sensor de Corrente
  Tensao = (((LeituraTensao - 511.5) * 1207096)/1757369.88);              // Converte os valores lidos para Tensao
  Corrente = (((LeituraCorrente - 511.5) * 5000)/511500);                 // Converte os valores lidos para Corrente                 
  Serial.print(Tensao);  
  Serial.print(" "); 
  Serial.println(Corrente); 

  tempoAnterior = tempoAtual;
}


             
                   
}
