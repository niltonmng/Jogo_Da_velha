#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main() {

  char matriz[3][3];

  scanf("%s", &matriz[0][0]);


  // matriz[0][0] = 'a';
  if(matriz[0][0] == 'a'){
      printf("%s\n", &matriz[0][0]);
      printf("%s\n", "nilton");
  }



  return 0;
}
