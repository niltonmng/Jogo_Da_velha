#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>


using namespace std;

char jogador1[50];
char jogador2[50];
char matriz[3][3];

void iniciaJogo(char jogador1[], char jogador2[]);
void exibeJogo();
bool testaVitoria();
int main() {


  iniciaJogo(jogador1, jogador2);





  exibeJogo();


  return 0;
}

bool testaVitoria(){
  if(((matriz[0][0] == "O") && (matriz[0][1] == "O") && (matriz[0][2] == "O")) || // primeira horizontal
     ((matriz[0][0] == "X") && (matriz[0][1] == "X") && (matriz[0][2] == "X")) ||

     ((matriz[1][0] == "O") && (matriz[1][1] == "O") && (matriz[1][2] == "O")) || // segunda horizontal
     ((matriz[1][0] == "X") && (matriz[1][1] == "X") && (matriz[1][2] == "X")) ||

     ((matriz[2][0] == "O") && (matriz[2][1] == "O") && (matriz[2][2] == "O")) || // terceira horizontal
     ((matriz[2][0] == "X") && (matriz[2][1] == "X") && (matriz[2][2] == "X")) ||

     ((matriz[0][0] == "O") && (matriz[1][1] == "O") && (matriz[2][2] == "O")) || // diagonal
     ((matriz[0][0] == "X") && (matriz[1][1] == "X") && (matriz[2][2] == "X")) ||

     ((matriz[0][0] == "O") && (matriz[1][0] == "O") && (matriz[2][0] == "O")) || // primeira vertical
     ((matriz[0][0] == "X") && (matriz[1][0] == "X") && (matriz[2][0] == "X")) ||

     ((matriz[0][1] == "O") && (matriz[1][1] == "O") && (matriz[2][1] == "O")) || // segunda vertical
     ((matriz[0][1] == "X") && (matriz[1][1] == "X") && (matriz[2][1] == "X")) ||

     ((matriz[0][2] == "O") && (matriz[1][2] == "O") && (matriz[2][2] == "O")) || // terceira vertical
     ((matriz[0][2] == "X") && (matriz[1][2] == "X") && (matriz[2][2] == "X")))
     {
        return true;
     }
     return false;
}


void exibeJogo(){
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << matriz[i][j];
    }
    std::cout << '\n';
  }
}

void iniciaJogo(char jogador1[], char jogador2[]){
  printf("%s\n", "Bem vindo ao jogo da Velha!");
  printf("%s\n", "Digite o nome do Jogador 1: ");
  gets(jogador1);
  printf("%s\n", "Digite o nome do Jogador 2: ");
  gets(jogador2);
}
