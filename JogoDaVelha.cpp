#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

char matriz[3][3];
char jogada[1];
char jogador1[50];
char jogador2[50];
bool isVezPrimeiro = true;

void iniciaMatriz(){
  matriz[0][0] = 'a';
  matriz[0][1] = 'b';
  matriz[0][2] = 'c';

  matriz[1][0] = 'd';
  matriz[1][1] = 'e';
  matriz[1][2] = 'f';

  matriz[2][0] = 'g';
  matriz[2][1] = 'h';
  matriz[2][2] = 'i';
}
void imprimeMatriz(){
  for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  std::cout << matriz[i][j] << ' ';
	}
	std::cout << '\n';
  }
}
bool isVitoria(){
  if(((matriz[0][0] == 'O') && (matriz[0][1] == 'O') && (matriz[0][2] == 'O')) || // primeira horizontal
	 ((matriz[0][0] == 'X') && (matriz[0][1] == 'X') && (matriz[0][2] == 'X')) ||

	 ((matriz[1][0] == 'O') && (matriz[1][1] == 'O') && (matriz[1][2] == 'O')) || // segunda horizontal
	 ((matriz[1][0] == 'X') && (matriz[1][1] == 'X') && (matriz[1][2] == 'X')) ||

	 ((matriz[2][0] == 'O') && (matriz[2][1] == 'O') && (matriz[2][2] == 'O')) || // terceira horizontal
	 ((matriz[2][0] == 'X') && (matriz[2][1] == 'X') && (matriz[2][2] == 'X')) ||

	 ((matriz[0][0] == 'O') && (matriz[1][1] == 'O') && (matriz[2][2] == 'O')) || // diagonal principal
	 ((matriz[0][0] == 'X') && (matriz[1][1] == 'X') && (matriz[2][2] == 'X')) ||
	 
	 ((matriz[0][2] == 'O') && (matriz[1][1] == 'O') && (matriz[2][0] == 'O')) || // diagonal secundaria
	 ((matriz[0][2] == 'X') && (matriz[1][1] == 'X') && (matriz[2][0] == 'X')) ||

	 ((matriz[0][0] == 'O') && (matriz[1][0] == 'O') && (matriz[2][0] == 'O')) || // primeira vertical
	 ((matriz[0][0] == 'X') && (matriz[1][0] == 'X') && (matriz[2][0] == 'X')) ||

	 ((matriz[0][1] == 'O') && (matriz[1][1] == 'O') && (matriz[2][1] == 'O')) || // segunda vertical
	 ((matriz[0][1] == 'X') && (matriz[1][1] == 'X') && (matriz[2][1] == 'X')) ||

	 ((matriz[0][2] == 'O') && (matriz[1][2] == 'O') && (matriz[2][2] == 'O')) || // terceira vertical
	 ((matriz[0][2] == 'X') && (matriz[1][2] == 'X') && (matriz[2][2] == 'X')))
	 {
		return true;
	 }
	 return false;
}
void menuInicio(){
  std::cout << "Bem vindo ao jogo da Velha!" << '\n';
  
  std::cout << "Digite o nome do Jogador 1" << '\n';
  gets(jogador1);
  std::cout << "Jogador 1 joga com X" << '\n';
 
  system("clear");
  
  std::cout << "Digite o nome do Jogador 2" << '\n';
  gets(jogador2);
  std::cout << "Jogador 2 joga com O" << '\n';
  
  system("clear");

  std::cout << '\n';
  std::cout << "Estas sao as Posicoes que estao disponiveis para jogo." << '\n';
  imprimeMatriz();
}

void jogadaX(char posicao[]){
  if(posicao[0] == 'a'){
	matriz[0][0] = 'X';
  }
  if(posicao[0] == 'b'){
	matriz[0][1] = 'X';
  }
  if(posicao[0] == 'c'){
	matriz[0][2] = 'X';
  }
  if(posicao[0] == 'd'){
	matriz[1][0] = 'X';
  }
  if(posicao[0] == 'e'){
	matriz[1][1] = 'X';
  }
  if(posicao[0] == 'f'){
	matriz[1][2] = 'X';
  }
  if(posicao[0] == 'g'){
	matriz[2][0] = 'X';
  }
  if(posicao[0] == 'h'){
	matriz[2][1] = 'X';
  }
  if(posicao[0] == 'i'){
	matriz[2][2] = 'X';
  }
}

void jogadaO(char posicao[]){
  if(posicao[0] == 'a'){
	matriz[0][0] = 'O';
  }
  if(posicao[0] == 'b'){
	matriz[0][1] = 'O';
  }
  if(posicao[0] == 'c'){
	matriz[0][2] = 'O';
  }
  if(posicao[0] == 'd'){
	matriz[1][0] = 'O';
  }
  if(posicao[0] == 'e'){
	matriz[1][1] = 'O';
  }
  if(posicao[0] == 'f'){
	matriz[1][2] = 'O';
  }
  if(posicao[0] == 'g'){
	matriz[2][0] = 'O';
  }
  if(posicao[0] == 'h'){
	matriz[2][1] = 'O';
  }
  if(posicao[0] == 'i'){
	matriz[2][2] = 'O';
  }
}

int main() {
  iniciaMatriz();
  menuInicio();

  while (true) {
	if(isVezPrimeiro){

	  std::cout << "Jogador 1 escolha uma posicao para jogar." << '\n';
	  gets(jogada);
	  jogadaX(jogada);
	  
	  system("clear");

	  imprimeMatriz();
	  if(isVitoria()){
		std::cout << "Vitoria!! Jogador 1 e o Vencedor!" << '\n';
		break;
	  }
	  if(jogada[0] == 's'){
		break;
	  }
	  isVezPrimeiro = false;
	}
	else {

	  std::cout << "Jogador 2 escolha uma posicao para jogar." << '\n';
	  gets(jogada);
	  jogadaO(jogada);
	  
	  system("clear");

	  imprimeMatriz();
	  if(isVitoria()){
		std::cout << "Vitoria!! Jogador 2 e o Vencedor!" << '\n';
		break;
	  }
	  if(jogada[0] == 's'){
		break;
	  }
	  isVezPrimeiro = true;
	}
  }

  return 0;
}
