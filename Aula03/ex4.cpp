#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T> class Vetor {
public:
  T *vetor;
  int capacidade;
  int qtdUsada;

  Vetor(int cap) {
    vetor = new T[capacidade];
    capacidade = cap;
    qtdUsada = 0;
  }

  void insert(T value) {
    if (qtdUsada < capacidade) {
      vetor[qtdUsada] = value;
      qtdUsada++;
    }
  }

  void removeLast() { qtdUsada--; }

  int getSortedPosition(T value) {
    int i = 0;
    while (value > vetor[i] && i < qtdUsada) {
      i++;
    }
    return i;
  }

  void shift(int posicao) {
    for (int i = qtdUsada; i > posicao; i--) {
      vetor[i] = vetor[i - 1];
    }
    qtdUsada++;
  }

  void insertOrdenado(T value) {
    if (qtdUsada == 0) {
      vetor[0] = value;
      qtdUsada++;
    } else {
      if (qtdUsada < capacidade) {
        int i = getSortedPosition(value);
        shift(i);
        vetor[i] = value;
      }
    }
  }
  void remove(int index) {
    for (int i = index; i < qtdUsada; i++) {
      vetor[i] = vetor[i + 1];
    }
    qtdUsada--;
  }

  void print() {
    std::cout << "\n(";
    for (int i = 0; i < qtdUsada - 1; i++) {
      cout << vetor[i] << ", ";
    }
    cout << vetor[qtdUsada - 1] << ")\n";
  }

  bool equals(Vetor<T> vetorB) {
    if (qtdUsada == vetorB.qtdUsada) {
      for (int i = 0; i < qtdUsada; i++)
        if (vetor[i] != vetorB.vetor[i])
          return false;
    } else
      return false;
    return true;
  }
};

int main() {

  int n;
  
  printf("Quantos numeros serão digitados?\n");
  scanf("%d", &n);

  Vetor<int> *vetor = new Vetor<int>(n);
  
  printf("Digite os %d numeros separados pela tecla ENTER\n", n);

  for (int i = 0; i < n ; i ++ )
  {
    int valor;
    scanf("%d", &valor);
    vetor->insert(valor);
  }

  float somaSerie = 0;

  for (int i = 0; i < n; i++){
    printf("Vetor[%d] = %d ", i, vetor->vetor[i]);
    somaSerie += (i+1) / vetor->vetor[i]; //@TODO: ARRUMAR 
  }
  vetor->print();
  printf("%f", somaSerie);
}
