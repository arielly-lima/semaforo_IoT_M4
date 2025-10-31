## Atividade Semáforo offline
Este repositório contém a atividade ponderada do módulo 4, do Inteli, o qual refere-se à documentação do exercício do Semáforo offline construído com a utilização do Arduino Uno. <br>
### 1. Funcionamento do Semáforo:
O exercíco contempla a construção física do semáforo, que funciona conforme um semáforo convencional, alternando entre as cores verde, amarelo e vermelho, respectivamente. Além disso, também foi feito o código que contém a lógica do sistema, em C++, e testagem por meio do software Arduino IDE. Para o funcionamento das LEDs, foi estabelecido o seguinte modelo de funcionamento:
- 6 segundos no vermelho; 
- 4 segundos no verde;
- 2 segundos no amarelo.

### 2. Montagem física:
O modelo final do protótipo físico ficou da seguinte forma:
<p align = "center">Figura X - Modelo físico Semáforo online </p>
<div align = "center">
  <img src = "../assets/aaa">
 <sup>Fonte: Material produzido pelos autores (2025)</sup>
 </div>

Para essa construção, foram utilizados os seguintes componentes:
| **Componente** | **Imagem (referência na foto)** | **Função principal** | **Papel no projeto** | **Detalhes de conexão** |
| --- | --- | --- | --- | --- |
| **Arduino Uno** | Placa azul conectada ao cabo USB | Microcontrolador que executa o código e controla o circuito | Controla a sequência dos LEDs (vermelho, amarelo e verde) | Conectado ao computador via USB (fornece energia e comunicação) |
| **Protoboard (breadboard)** | Placa branca perfurada | Base para montar o circuito sem solda | Facilita conexões entre resistores, LEDs e fios | Trilhas laterais para 5V e GND; trilhas centrais para componentes |
| **LED Vermelho** | LED aceso na parte inferior da imagem | Diodo emissor de luz (cor vermelha) | Representa o sinal de **pare** | Anodo ligado a pino digital (via resistor), catodo ao GND |
| **LED Amarelo** | LED no meio (entre vermelho e verde) | Diodo emissor de luz (cor amarela) | Representa o sinal de **atenção** | Anodo ligado a pino digital (via resistor), catodo ao GND |
| **LED Verde** | LED superior (não aceso na foto) | Diodo emissor de luz (cor verde) | Representa o sinal de **siga** | Anodo ligado a pino digital (via resistor), catodo ao GND |
| **Resistores (3x)** | Peças com faixas coloridas na protoboard | Limitam a corrente elétrica | Protegem os LEDs contra queima | Ligados em série entre o pino do Arduino e o anodo de cada LED |
| **Jumpers (fios de conexão)** | Fios coloridos entre Arduino e protoboard | Conectam os componentes eletricamente | Levam os sinais e energia entre a placa e os LEDs | Ligam pinos digitais aos resistores e LEDs; GND e 5V à protoboard |
| **Cabo USB** | Cabo azul ligado ao notebook | Fonte de alimentação e comunicação | Fornece energia e envia o código ao Arduino | Conectado ao computador e à porta USB do Arduino |

### 3. Programação e Lógica do Semáforo:
O código com a lógica de funcionamento do semáforo foi feito na linguagem c++ e compilado no ambiente do Arduino IDE. Segue abaixo o código utiliado:

``` c++
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

```

### 4. Avaliação e nota da atividade:
Para critérios de avaliação dessa atividade, foi realizado a avaliação de pares, feita por outros aulos da mesma instituição. Segue abaixo as avaliações e infromações extraídas:

**Avaliadora:** Livia Oliveira Cavalcanti
| **Critério** | **Contempla (Pontos)** | **Contempla Parcialmente (Pontos)** | **Não Contempla (Pontos)** | **Observações do Avaliador** |
| --- | --- | --- | --- | --- |
| Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores | 3 | - | - | A montagem foi realizada corretamente conforme proposto. |
| Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo | 3 | - | - | O tempo está condizente de acordo com o código. |
| Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) | 3 | - | - | O código está simplificado e abrange corretamente a função de funcionamento do semáforo. |
| Ir além: Implementou um componente de extra, fez com millis() ao invés do delay() e/ou usou ponteiros no código | 0 |  | - | Apesar do código estar simples e funcional de acordo com a utilização do millis(), não houve inclusão de ferramentas além das sugeridas. |
|  |  |  |  | Pontuação Total: 9 |

**Avaliadora:** Nicolli Venino Santana
| **Critério** | **Contempla (Pontos)** | **Contempla Parcialmente (Pontos)** | **Não Contempla (Pontos)** | **Observações do Avaliador** |
| --- | --- | --- | --- | --- |
| Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores | 3 | - | - | A construção do hardware está muito boa de acordo com o sugerido. |
| Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo | 3 | - | - | A temporização está correta no que diz respeito à contagem do tempo de cada led, como também a ordem em que são acesos. |
| Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) | 3 | - | - | O código é condizente ao que foi pedido e funciona corretamente. |
| Ir além: Implementou um componente de extra, fez com millis() ao invés do delay() e/ou usou ponteiros no código | 0 | - | - | Apesar da construção correta, não houve adição de entregas além do sugerido no escopo da atividade. |
|  |  |  |  | Pontuação Total: 9 |

