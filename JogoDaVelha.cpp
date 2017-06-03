#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>s

using namespace std;

char jogador1[50];
char jogador2[50];
char matriz[3][3];
char jogada[1];
bool turnoPrimeiro = false;

void iniciaJogo(char jogador1[], char jogador2[]);
void exibeJogo();
bool isVitoria();
void jogaX(char posicao[]);
void jogaO(char posicao[]);
void iniciaMatriz();
int main() {


  iniciaJogo(jogador1, jogador2);


  std::cout << "a | b | c" << '\n';
  std::cout << "_________" << '\n';
  std::cout << "d | e | f" << '\n'; // apenas esqueleto do jogo de como seria
  std::cout << "_________" << '\n';
  std::cout << "g | h | i" << '\n';

  iniciaMatriz();

  while(true){
    if(turnoPrimeiro == true){
      std::cout << "Vez do Jogador 1."  << '\n';
      std::cout << "Indique onde quer jogar: " << '\n';
      gets(jogada);
      jogaX(jogada);
      turnoPrimeiro = false;
      jogada[0] = "";
      if(isVitoria()){
        std::cout << "Jogador 1 ganhou" << '\n';
      }
    }
    else {
      std::cout << "Vez do Jogador 2."  << '\n';
      std::cout << "Indique onde quer jogar: " << '\n';
      gets(jogada);
      jogaO(jogada);
      turnoPrimeiro = true;
      jogada[0] = "";
      if(isVitoria()){
        std::cout << "Jogador 2 ganhou" << '\n';
      }
    }
    exibeJogo();

  }

  exibeJogo();

  return 0;
}

bool isVitoria(){
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

void jogaX(char posicao[]){

  if(posicao == "a"){
    matriz[0][0] = "X";
  }
  if(posicao == "b"){
    matriz[0][1] = "X";
  }
  if(posicao == "c"){
    matriz[0][2] = "X";
  }
  if(posicao == "d"){
    matriz[1][0] = "X";
  }
  if(posicao == "e"){
    matriz[1][1] = "X";
  }
  if(posicao == "f"){
    matriz[1][2] = "X";
  }
  if(posicao == "g"){
    matriz[2][0] = "X";
  }
  if(posicao == "h"){
    matriz[2][1] = "X";
  }
  if(posicao == "i"){
    matriz[2][2] = "X";
  }

}

void jogaO(char posicao[]){

  if(posicao == "a"){
    matriz[0][0] = "O";
  }
  if(posicao == "b"){
    matriz[0][1] = "O";
  }
  if(posicao == "c"){
    matriz[0][2] = "O";
  }
  if(posicao == "d"){
    matriz[1][0] = "O";
  }
  if(posicao == "e"){
    matriz[1][1] = "O";
  }
  if(posicao == "f"){
    matriz[1][2] = "O";
  }
  if(posicao == "g"){
    matriz[2][0] = "O";
  }
  if(posicao == "h"){
    matriz[2][1] = "O";
  }
  if(posicao == "i"){
    matriz[2][2] = "O";
  }

}

void exibeJogo() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << matriz[i][j];
    }
    std::cout << '\n';
  }
}

void iniciaMatriz(){
  matriz[0][0] = "a";
  matriz[0][1] = "b";
  matriz[0][2] = "c";

  matriz[1][0] = "d";
  matriz[1][1] = "e";
  matriz[1][2] = "f";

  matriz[2][0] = "g";
  matriz[2][1] = "h";
  matriz[2][2] = "i";
}

void iniciaJogo(char jogador1[], char jogador2[]){
  printf("%s\n", "Bem vindo ao jogo da Velha!");
  printf("%s\n", "Digite o nome do Jogador 1: ");
  gets(jogador1);
  printf("%s\n", "Digite o nome do Jogador 2: ");
  gets(jogador2);
}
