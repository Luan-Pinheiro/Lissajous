//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

//Definição da consstante PI
#define PI 3.14159265358979323846

//Protótipos das funções
double* calculaPontoTangenteLissajous(double);
double calculaCoeficienteAngularTangenteLissajous(double);
double* calculaEquacaoRetaTangenteLissajous(double, double);
//Função Main
int main(){
    //Setando idioma pra protuguês
    setlocale(LC_ALL,"Portuguese");
    setlocale(LC_ALL,"pt_BR.UTF-8");

    char selecao;

    //Exibição do menu
    printf("\n\t|**************************************************************************|\n\t|\t\t\t\tMENU\t\t\t\t\t   |");
    printf("\n\t|**************************************************************************|\n");
    printf("\t|OBTENDO A TANGENTE DA LISSAJOUS x = sen(2t), y = cos(t), com t E [0, 2pi] |");
    printf("\n\t|a) Obter o ponto P(x,y) e equacao da reta\t\t\t\t   |");
    printf("\n\t|0) Sair\t\t\t\t\t\t\t\t   |\n\t|__________________________________________________________________________|\n");
    scanf("%c", &selecao);
    while(selecao!="-1"){
    switch (selecao){
      case 'a':{
        printf("Insira o t que deseja obter na curva:");  
        double t1, t; // 't' da curva e auxiliar t1
        scanf("%lf", &t1);
        t = t1*(PI/180); //Convertendo a entrada de graus para radianos
        printf("\nRESULTADOS EM RADIANOS:");  
        double* vetor = calculaPontoTangenteLissajous(t);
        printf("\nO ponto de tangencia P(x,y) em t = %.1lf eh: P(%.1lf ; %.1lf) \n", t1, vetor[0], vetor[1]);
        double coeficienteAngular = calculaCoeficienteAngularTangenteLissajous(t);
        printf("O coeficiente angular da reta tangente eh: %.1lf\n", coeficienteAngular);
        double* ab = calculaEquacaoRetaTangenteLissajous(t, coeficienteAngular);
        printf("Equacao da reta tangente: ft(x) = %.1lfx + %.1lf\n\n", ab[0], ab[1]);

        break;
      }
      case '0':
        return 0; //Sair
      break;

      default:
        printf("Opcao invalida! \n");//Mensagem de erro
    }
    }
    return 0;
}
//Função de obtenção do ponto P(x,y) da tangente na Lissajous,ao atribuir os valores de entrada de 't' ao x e ao y que definem 
//a cruva
double* calculaPontoTangenteLissajous(double t){
  //ENCONTRANDO O PONTO P(x,y) da TANGENTE
  double x = sin(2 * t); // obtendo termo x de t
  double y = cos(t); // obtendo termo t de t

  static double P[2]; // Vetor de respostas

  P[0] = x; //Atribuição de valores
  P[1] = y; //Atribuição de valores

  return P; //Retorno do resultado
}

//Função de obtenção do coeficiente angular da reta tangente através da divisão da derivada de y pela derivada de x -> dy/dx
double calculaCoeficienteAngularTangenteLissajous(double t){
  double mt;
  //ENCONTRANDO A INCLINACAO DA RETA TANGENTE
  double dy = (-1) * (sin(t)); // derivada de y
  double dx = cos(2 * t) * 2; // derivada de x
  mt = dy / dx; //Encontrando a inclinacao da reta

  return mt; // retorno do Coeficiente angular
}

//Função de obtenção da equação da reta, obtendo os termos 'a' e 'b' através da resolução da equação
double* calculaEquacaoRetaTangenteLissajous(double t, double cA){
  double mt = cA; // mt recebendo o valor do coeficiente angular
  double* Pt = calculaPontoTangenteLissajous(t); //pt recebendo o ponto P(x,y) da tangente na Lissajous
  //ENCONTRANDO A EQUACAO DA RETA TANGENTE -> ft(x) = ax + b
  double b = Pt[1] - mt * Pt[0]; // Termo 'b' da função
  double a = mt; //Termo 'a' da função
  static double ab[2];// Vetor de respostas

  ab[0] = a;//Atribuição de valores
  ab[1] = b;//Atribuição de valores

  return ab;//Retorno do resultado
}
