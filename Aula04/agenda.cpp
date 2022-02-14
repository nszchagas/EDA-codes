#include <bits/stdc++.h>
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

typedef struct {
  char nome[30];
  char endereco[100];
  char fone[10];
  long int CEP;

  // CONTATO(char *nomeR, char *enderecoR, char *foneR, long int CEPR) {
  //   CEP = CEPR;
  // }

  string toString(){
    string s = "Nome: ";
    s += nome;
    s += "\nEndereço";    
    // s.append(nome);
    // s.append("\nEndereço: ");
    // s.append(endereco);
    s.append("\nTelefone: ");
    s += fone;
    // s.append(fone);
    s.append("\nCEP: ");
    s += CEP;
  }
} CONTATO;

CONTATO criaContato() {
  CONTATO c;
  char nome[30];
  char endereco[100];
  char fone[10];
  long int CEP;
  printf("Digite o nome do contato: \n");
  cin.getline(nome, sizeof(nome));
  cout << "\nnome digitado: " << nome << "\n";
  printf("Digite o CEP:\n");
  scanf("%ld", &CEP);
  c.CEP = CEP;
  // c.nome = *nome;
  return c;
}

int main() {
  int tamanho = 100;
  Vetor<CONTATO> *contatos = new Vetor<CONTATO>(tamanho);
  int opcao = 0;
  while (opcao != 4) {
    printf("Escolha uma opção:\n1 - Criar um novo contato na agenda.\n2 - "
           "Visualizar todas as pessoas cadastradas.\n3 - Filtrar os contatos "
           "pela primeira letra do nome.\n4 - Sair\n");

    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      contatos->insert(criaContato());
      break;
    case 2:
      for (int i = 0; i < contatos->qtdUsada; i++) {
        cout << contatos->vetor[0].toString() << "\n";
      }

      break;
    case 3:
      break;
    default:
      printf("Saindo...\n");
    }
  }
  return 0;
}
