#include <cmath>
#include <iostream>
#include <limits>
#include <stdio.h>

using namespace std; 
template <typename T>
void operacoes(T a, T b, T *soma, T *diferenca, T *produto) {
  *soma = a + b;
  *diferenca = a - b;
  *produto = a * b;
}

template <typename T> int quociente(T a, T b, float *prazao) {
  if (b == 0) {
    return 0;
  } else {
    *prazao = (float)a / (float)b;
    return 1;
  }
}

template <typename T>
void analisaVetor(T *vetor, T *tamanhoVet, float *media, T *min, T *max) {
  T tempMin = std::numeric_limits<T>::max();
  T tempMax = std::numeric_limits<T>::min();
  float soma = 0;
  if (*tamanhoVet > 0) {
    for (int i = 0; i < *tamanhoVet; i++) {
      if (vetor[i] > tempMax)
        tempMax = vetor[i];
      if (vetor[i] < tempMin)
        tempMin = vetor[i];
      soma += vetor[i];
    }
    *media = soma / *tamanhoVet;
    *min = tempMin;
    *max = tempMax;
  }
}

void leTresNotas(float *n1, float *n2, float *n3) {
  printf("Digite tres notas, separadas por ENTER:\n");
  scanf("%f", n1);
  scanf("%f", n2);
  scanf("%f", n3);
}

void ex1() {
  int a = 5, b = 4;
  float res = 0;
  quociente(a, b, &res);
  printf("%d / %d = %f\n", a, b, res);
}
void ex2() {
  int vetor[] = {1, 2, 5, 3, 70, 0, -7, 5, -251};
  int tamanho = 9;
  float media = 0;
  int min = 0, max = 0;
  analisaVetor(vetor, &tamanho, &media, &min, &max);
  printf("media = %f\nmin = %d\nmax = %d\n", media, min, max);
}
void ex3() {
  float n1, n2, n3;
  leTresNotas(&n1, &n2, &n3);
  printf("n1 = %.2f\nn2 = %.2f\nn3 = %.2f", n1, n2, n3);
}

struct CONTATO{
  char nome[30];
  char endereco[100];
  char fone[10];
  long int CEP;

  void setNome(char *nomeR){
    
  }
  std::string toString() {
    string retorno = nome; 
    retorno += "\n"; 
    
  }
};

int main() {
  // ex1();
  // ex2();
  // ex3();
  CONTATO agenda[100];
  //agenda[1].CEP = 72520;
  //agenda[1].nome "Teste";
  //std::cout << agenda[1].toString() ;
  
}
