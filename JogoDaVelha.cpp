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
		std::cout << "      ";
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
	
	std::cout << "Digite o nome do Jogador 2" << '\n';
	gets(jogador2);
	
	system("clear");
	
	std::cout << jogador1 << " joga com X" << '\n';	
	std::cout << jogador2 << " joga com O" << '\n';

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

bool duasPecasEmLinhaX(){

	if(matriz[0][0] == 'X' && matriz[0][2] == 'X' && matriz[2][0] == 'X'){
		std::cout << "Triangulo detectado! Possivel vitoria em b, d, e ." << '\n';
		return true;
	}
	if(matriz[0][0] == 'X' && matriz[2][0] == 'X' && matriz[2][2] == 'X'){
		std::cout << "Triangulo detectado! Possivel vitoria em d, h, e ." << '\n';
		return true;
	}
	if(matriz[0][2] == 'X' && matriz[2][0] == 'X' && matriz[2][2] == 'X'){
		std::cout << "Triangulo detectado! Possivel vitoria em f, h, e ." << '\n';
		return true;
	}
	if(matriz[0][0] == 'X' && matriz[0][2] == 'X' && matriz[2][2] == 'X'){
		std::cout << "Triangulo detectado! Possivel vitoria em f, e, b ." << '\n';
		return true;
	}

	// triangulo acima

	if(matriz[0][0] == 'X' && matriz[0][1] == 'X'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
			return true;
		}
	}
	if(matriz[1][0] == 'X' && matriz[1][1] == 'X'){
		if(matriz[1][2] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
			return true;
		}
	}
	if(matriz[2][0] == 'X' && matriz[2][1] == 'X'){
		if(matriz[2][2]){
			std::cout << "Deve jogar em i" << '\n';
			return true;
		}
	}

	if(matriz[0][1] == 'X' && matriz[0][2] == 'X'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
			return true;
		}
	}
	if(matriz[1][1] == 'X' && matriz[1][2] == 'X'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
			return true;
		}
	}
	if(matriz[2][1] == 'X' && matriz[2][2] == 'X'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
			return true;
		}
	}

	if(matriz[0][0] == 'X' && matriz[0][2] == 'X'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
			return true;
		}
	}
	if(matriz[1][0] == 'X' && matriz[1][2] == 'X'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
			return true;
		}
	}
	if(matriz[2][0] == 'X' && matriz[2][2] == 'X'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
			return true;
		}
	}



	if(matriz[0][0] == 'X' && matriz[1][0] == 'X'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
			return true;
		}
	}
	if(matriz[0][1] == 'X' && matriz[1][1] == 'X'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
			return true;
		}
	}
	if(matriz[0][2] == 'X' && matriz[1][2] == 'X'){
		if(matriz[2][2] == 'i'){
			std::cout << "Deve jogar em i" << '\n';
			return true;
		}
	}

	if(matriz[1][0] == 'X' && matriz[2][0] == 'X'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
			return true;
		}
	}
	if(matriz[1][1] == 'X' && matriz[2][1] == 'X'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
			return true;
		}
	}
	if(matriz[1][2] == 'X' && matriz[2][2] == 'X'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
			return true;
		}
	}

	if(matriz[0][0] == 'X' && matriz[2][0] == 'X'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
			return true;
		}
	}
	if(matriz[0][1] == 'X' && matriz[2][1] == 'X'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
			return true;
		}
	}
	if(matriz[0][2] == 'X' && matriz[2][2] == 'X'){
		if(matriz[2][1] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
			return true;
		}
	}

	return false;
}
bool duasPecasEmLinhaO(){

	if(matriz[0][0] == 'O' && matriz[0][2] == 'O' && matriz[2][0] == 'O'){
		std::cout << "Triangulo detectado! Possivel vitoria em b, d, e ." << '\n';
		return true;
	}
	if(matriz[0][0] == 'O' && matriz[2][0] == 'O' && matriz[2][2] == 'O'){
		std::cout << "Triangulo detectado! Possivel vitoria em d, h, e ." << '\n';
		return true;
	}
	if(matriz[0][2] == 'O' && matriz[2][0] == 'O' && matriz[2][2] == 'O'){
		std::cout << "Triangulo detectado! Possivel vitoria em f, h, e ." << '\n';
		return true;
	}
	if(matriz[0][0] == 'O' && matriz[0][2] == 'O' && matriz[2][2] == 'O'){
		std::cout << "Triangulo detectado! Possivel vitoria em f, e, b ." << '\n';
		return true;
	}

 // triangulo acima

	if(matriz[0][0] == 'O' && matriz[0][1] == 'O'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
			return true;
		}
	}
	if(matriz[1][0] == 'O' && matriz[1][1] == 'O'){
		if(matriz[1][2] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
			return true;
		}
	}
	if(matriz[2][0] == 'O' && matriz[2][1] == 'O'){
		if(matriz[2][2]){
			std::cout << "Deve jogar em i" << '\n';
			return true;
		}
	}

	if(matriz[0][1] == 'O' && matriz[0][2] == 'O'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
			return true;
		}
	}
	if(matriz[1][1] == 'O' && matriz[1][2] == 'O'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
			return true;
		}
	}
	if(matriz[2][1] == 'O' && matriz[2][2] == 'O'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
			return true;
		}
	}

	if(matriz[0][0] == 'O' && matriz[0][2] == 'O'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
			return true;
		}
	}
	if(matriz[1][0] == 'O' && matriz[1][2] == 'O'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
			return true;
		}
	}
	if(matriz[2][0] == 'O' && matriz[2][2] == 'O'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
			return true;
		}
	}



	if(matriz[0][0] == 'O' && matriz[1][0] == 'O'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
			return true;
		}
	}
	if(matriz[0][1] == 'O' && matriz[1][1] == 'O'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
			return true;
		}
	}
	if(matriz[0][2] == 'O' && matriz[1][2] == 'O'){
		if(matriz[2][2] == 'i'){
			std::cout << "Deve jogar em i" << '\n';
			return true;
		}
	}

	if(matriz[1][0] == 'O' && matriz[2][0] == 'O'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
			return true;
		}
	}
	if(matriz[1][1] == 'O' && matriz[2][1] == 'O'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
			return true;
		}
	}
	if(matriz[1][2] == 'O' && matriz[2][2] == 'O'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
			return true;
		}
	}

	if(matriz[0][0] == 'O' && matriz[2][0] == 'O'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
			return true;
		}
	}
	if(matriz[0][1] == 'O' && matriz[2][1] == 'O'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
			return true;
		}
	}
	if(matriz[0][2] == 'O' && matriz[2][2] == 'O'){
		if(matriz[2][1] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
			return true;
		}
	}

	return false;
}

void bloquearX(){
	if(matriz[0][0] == 'X' && matriz[0][1] == 'X'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
		}
	}
	if(matriz[1][0] == 'X' && matriz[1][1] == 'X'){
		if(matriz[1][2] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
		}
	}
	if(matriz[2][0] == 'X' && matriz[2][1] == 'X'){
		if(matriz[2][2]){
			std::cout << "Deve jogar em i" << '\n';
		}
	}

	if(matriz[0][1] == 'X' && matriz[0][2] == 'X'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
		}
	}
	if(matriz[1][1] == 'X' && matriz[1][2] == 'X'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
		}
	}
	if(matriz[2][1] == 'X' && matriz[2][2] == 'X'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
		}
	}

	if(matriz[0][0] == 'X' && matriz[0][2] == 'X'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
		}
	}
	if(matriz[1][0] == 'X' && matriz[1][2] == 'X'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
		}
	}
	if(matriz[2][0] == 'X' && matriz[2][2] == 'X'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
		}
	}



	if(matriz[0][0] == 'X' && matriz[1][0] == 'X'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
		}
	}
	if(matriz[0][1] == 'X' && matriz[1][1] == 'X'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
		}
	}
	if(matriz[0][2] == 'X' && matriz[1][2] == 'X'){
		if(matriz[2][2] == 'i'){
			std::cout << "Deve jogar em i" << '\n';
		}
	}

	if(matriz[1][0] == 'X' && matriz[2][0] == 'X'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
		}
	}
	if(matriz[1][1] == 'X' && matriz[2][1] == 'X'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
		}
	}
	if(matriz[1][2] == 'X' && matriz[2][2] == 'X'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
		}
	}

	if(matriz[0][0] == 'X' && matriz[2][0] == 'X'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
		}
	}
	if(matriz[0][1] == 'X' && matriz[2][1] == 'X'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
		}
	}
	if(matriz[0][2] == 'X' && matriz[2][2] == 'X'){
		if(matriz[2][1] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
		}
	}
}
void bloquearO(){
	if(matriz[0][0] == 'O' && matriz[0][1] == 'O'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
		}
	}
	if(matriz[1][0] == 'O' && matriz[1][1] == 'O'){
		if(matriz[1][2] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
		}
	}
	if(matriz[2][0] == 'O' && matriz[2][1] == 'O'){
		if(matriz[2][2]){
			std::cout << "Deve jogar em i" << '\n';
		}
	}

	if(matriz[0][1] == 'O' && matriz[0][2] == 'O'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
		}
	}
	if(matriz[1][1] == 'O' && matriz[1][2] == 'O'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
		}
	}
	if(matriz[2][1] == 'O' && matriz[2][2] == 'O'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
		}
	}

	if(matriz[0][0] == 'O' && matriz[0][2] == 'O'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
		}
	}
	if(matriz[1][0] == 'O' && matriz[1][2] == 'O'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
		}
	}
	if(matriz[2][0] == 'O' && matriz[2][2] == 'O'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
		}
	}



	if(matriz[0][0] == 'O' && matriz[1][0] == 'O'){
		if(matriz[2][0] == 'g'){
			std::cout << "Deve jogar em g" << '\n';
		}
	}
	if(matriz[0][1] == 'O' && matriz[1][1] == 'O'){
		if(matriz[2][1] == 'h'){
			std::cout << "Deve jogar em h" << '\n';
		}
	}
	if(matriz[0][2] == 'O' && matriz[1][2] == 'O'){
		if(matriz[2][2] == 'i'){
			std::cout << "Deve jogar em i" << '\n';
		}
	}

	if(matriz[1][0] == 'O' && matriz[2][0] == 'O'){
		if(matriz[0][0] == 'a'){
			std::cout << "Deve jogar em a" << '\n';
		}
	}
	if(matriz[1][1] == 'O' && matriz[2][1] == 'O'){
		if(matriz[0][1] == 'b'){
			std::cout << "Deve jogar em b" << '\n';
		}
	}
	if(matriz[1][2] == 'O' && matriz[2][2] == 'O'){
		if(matriz[0][2] == 'c'){
			std::cout << "Deve jogar em c" << '\n';
		}
	}

	if(matriz[0][0] == 'O' && matriz[2][0] == 'O'){
		if(matriz[1][0] == 'd'){
			std::cout << "Deve jogar em d" << '\n';
		}
	}
	if(matriz[0][1] == 'O' && matriz[2][1] == 'O'){
		if(matriz[1][1] == 'e'){
			std::cout << "Deve jogar em e" << '\n';
		}
	}
	if(matriz[0][2] == 'O' && matriz[2][2] == 'O'){
		if(matriz[2][1] == 'f'){
			std::cout << "Deve jogar em f" << '\n';
		}
	}
}

bool deuVelha(bool isVitoria){
	if(matriz[0][0] != 'a' && matriz[0][1] != 'b'  && matriz[0][2] != 'c' &&
			matriz[1][0] != 'd' && matriz[1][1] != 'e'  && matriz[1][2] != 'f' &&
			matriz[2][0] != 'g' && matriz[2][1] != 'h'  && matriz[2][2] != 'i' && isVitoria == false) {
		return true;
	}
	return false;
}

int main() {
	iniciaMatriz();
	menuInicio();

	while (!deuVelha(isVitoria())) {
		if(isVezPrimeiro){

			std::cout << jogador1 << " escolha uma posicao para jogar." << '\n';

			if(duasPecasEmLinhaX()){
				// Nao faz nada!
			} else {
				bloquearO();
			}

			gets(jogada);
			jogadaX(jogada);
			
			system("clear");

			imprimeMatriz();
			if(isVitoria()){
				std::cout << "Vitoria!! " << jogador1 << " eh o Vencedor!" << '\n';
				break;
			}
			isVezPrimeiro = false;
		}
		else {

			std::cout << jogador2 << " escolha uma posicao para jogar." << '\n';

			if(duasPecasEmLinhaO()){
				// Nao faz nada!
			} else {
				bloquearX();
			}

			gets(jogada);
			jogadaO(jogada);
			
			system("clear");

			imprimeMatriz();
			if(isVitoria()){
				std::cout << "Vitoria!! " << jogador2 << " e o Vencedor!" << '\n';
				break;
			}
			isVezPrimeiro = true;
		}
	}

	if(deuVelha(isVitoria())){
	 	std::cout << "\n Deu Velha!!" << '\n';
	}
	return 0;
}
