const int sensorT = A0;  //Sensor de Tensao
const int sensorC = A1; //Sensor de Corrente

float Tensao = 0;              // Variavel que guarda os Valores convertidos de Tensao
float Corrente = 0;            // Variavel que guarda os valores convertidos de Corrente
float LeituraTensao = 0;       // Variavel que guarda os valores lidos de Tensao
float LeituraCorrente = 0;     // Variavel que guarda os valores lidos de Corrente


unsigned long  tempoAnterior = 0;
const long intervalo = 67;                //  Pode ser alterado para 65.75

int    ROW           = 0;       // VARIÃ�VEL QUE SE REFERE AS LINHAS DO EXCEL
int    LABEL         = 1;       //



void setup()
{


  pinMode( sensorT, INPUT);              //  Inicia os Sensores
  pinMode( sensorC, INPUT);             //      como Entrada
  
  
  Serial.begin(9600);                               // AJUSTO A VELOCIDADE DA PORTA DE COMUNICAÃ‡ÃƒO EM 9600
  Serial.println("CLEARDATA");                                    // LIMPO DADOS ENVIADOS PELA SERIAL
  Serial.println("LABEL,Time,Tensao,Corrente"); // PREPARO A FORMAÃ‡ÃƒO DE COMO DEVO ENVIAR ISSO PARA A PORTA COM
  
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
  Serial.print("DATA,TIME,");  
  Serial.print(Tensao);  
  Serial.print(","); 
  Serial.println(Corrente); 

    
  ROW++;                            //  INCREMENTA A LINHA DO EXCEL
  if (ROW > 121)                   //  LAÃ‡O PARA LIMITAR A QUANTIDADE DE DADOS ENVIADOS, SERVE PARA LIMITAR O GRÃ�FICO (2000)
  {
    ROW = 0;                        //  RESET DA LINHA
    Serial.println("ROW,SET");    //  ALIMENTAÃ‡ÃƒO DAS LINHAS COM OS DADOS, INICIANDO DA LINHA 2
  }


  tempoAnterior = tempoAtual;
}



  


  delay(65.75);                      // TEMPO DE ESPERA PARA OBTER NOVA LEITURA ( UM CICLO DA ONDA Ã‰ DA ORDEM DE 200ms PARA 60HZ
       
  //delay(650.750);                                   
}






