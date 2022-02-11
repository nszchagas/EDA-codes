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

  int getPosicaoInserido(T value) {
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
        int i = getPosicaoInserido(value);
        shift(i);
        vetor[i] = value;
      }
    }


  }

  void print() {
    // printf("Quantidade usada: %d", qtdUsada);
    std::cout << "\n(";

    for (int i = 0; i < qtdUsada - 1; i++) {
      cout << vetor[i] << ", ";
    }
    cout << vetor[qtdUsada - 1] << ")\n";
  }
};

int main() {
  Vetor<int> *vetorInt = new Vetor<int>(5);
  vetorInt->insertOrdenado(1);
  vetorInt->insertOrdenado(9);
  vetorInt->insertOrdenado(3);
  vetorInt->insertOrdenado(4);
  vetorInt->insertOrdenado(10);

  vetorInt->print();
}
