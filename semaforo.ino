unsigned long tempoPassado = 0; //variável que será usada para o tempo inicial
int estado = 0; //estado do led

void setup() {
  pinMode(11, OUTPUT); //vermelho
  pinMode(12, OUTPUT); //amarelo
  pinMode(13, OUTPUT); //verde
  tempoPassado = millis(); //tempo inicial
  digitalWrite(13, HIGH); //liga o verde
}

void loop() {
  unsigned long tempoAtual = millis(); //inicialização do tempo atual

  if(estado == 0 && tempoAtual - tempoPassado==6000){
    digitalWrite(13, LOW); //apaga verde
    digitalWrite(12, HIGH); //liga amarelo
    tempoPassado = tempoAtual; //define o tempo como sendo o atual
    estado = 1; //estado 1

  }else if(estado == 1 && tempoAtual - tempoPassado==2000){
    digitalWrite(12, LOW); //apaga amarelo
    digitalWrite(11, HIGH); //liga o vermelho
    tempoPassado = tempoAtual; //define o tempo como sendo o atual
    estado = 2; //estado 2

  }else if(estado == 2 && tempoAtual - tempoPassado == 5000){
    digitalWrite(11, LOW); //apaga vermelho
    digitalWrite(13, HIGH); //liga o verde
    tempoPassado = tempoAtual; //define o tempo como o atual
    estado = 0; //estado reinicia

  }
}
