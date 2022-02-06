#include <stdio.h>

void printNumExercicio(int num) {
    printf("\n\n\nExercicio %d:\n", num);
}

void ex2() {
    printNumExercicio(2);
    int y, *p, x;
    y = 0;
    p = &y;                // p aponta para o endereço de y
    x = *p;                // x recebe o valor armazenado no endereço de p (x = y = 0)
    x = 4;                 // x recebe o valor 4
    (*p)++;                // *p = y = 0 -> (*p)++ = 1, y = 1 = *p
    x--;                   // x-- -> x = 3
    (*p) += x;             // (*p)= 1 += 3 = 4
    printf("y = %d\n", y); // y = 4
}

void ex3() {
    printNumExercicio(3);

    float vet[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for (i = 0; i < 5; i++) {
        printf("\ni = %d", i);
        printf(" vet[%d] = %.1f", i, vet[i]);
        printf(" *(f + %d) = %.1f", i, *(f + i));
        printf(" &vet[%d] = %X", i, &vet[i]);
        printf(" (f + %d) = %X", i, f + i);
    }
}

void ex4() {
    printNumExercicio(4);

    int i = 10, j = 20;
    int temp;
    int *p1, *p2;
    p1 = &i;
    p2 = &j;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("%d %d \n", i, j);
}

void ex5() {
    printNumExercicio(5);

    int QTD_EMPRESAS = 4;
    int vfat[QTD_EMPRESAS];

    for (int i = 0; i < QTD_EMPRESAS; i++) {
        printf("Digite o faturamento da empresa %d: ", i + 1);
        scanf("%d", &vfat[i]);
    }

    for (int i = QTD_EMPRESAS - 1; i >= 0; i--) {
        printf("Faturamento da empresa %d: %d\n", i + 1, vfat[i]);
    }

}

void ex6() {
    printNumExercicio(6);
    int QTD_EMPRESAS = 4;
    int vfat[QTD_EMPRESAS];
    int *ptrVetor;

    ptrVetor = vfat;

    for (int i = 0; i < QTD_EMPRESAS; i++) {
        printf("Digite o faturamento da empresa %d: ", i + 1);
        scanf("%d", &vfat[i]);
    }

    for (int i = QTD_EMPRESAS - 1; i >= 0; i--) {
        printf("Faturamento da empresa %d: %d\n", i + 1, *(ptrVetor + i));
    }
}

char *acheSobrenome(char nome[]) //retorna um ponteiro que aponta para o primeiro caractere do primeiro sobrenome
{
    char *pnome;
    int i = 0;
    while (nome[i] != ' ') {
        i++; //itera até encontrar um espaço
    }
    i++;              //pula a posição do espaço
    pnome = &nome[i]; //ponteiro aponta para o 1º char do sobrenome
    return pnome;
}

void ex7() {
    printNumExercicio(7);
    char nomeCompleto[80];
    char *p;
    puts("Entre com o seu nome e um sobrenome:");
    gets(nomeCompleto);
    p = acheSobrenome(nomeCompleto);
    puts(p);
}


void ex8a() {
    printNumExercicio(8);
    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p: %d.\n", *p);
}

void troca(int *i, int *j) {
    int temp; //variável inteira, para guardar o valor
    temp = *i; //temporário guarda o valor apontado por i
    *i = *j; //valor apontado por i recebe valor apontado por j
    *j = temp; //valor apontado por j recebe temp, que era o valor apontado por i
}

void ex8b() {

    int v[] = {1, 4, 6, 7, 10};
    printf("Antes da troca:\n");
    for (int i = 0; i < 5; i++) {
        printf("v[%d] = %d ", i, v[i]);
    }
    troca(v, v + 2);
    printf("\nDepois da troca:\n");
    for (int i = 0; i < 5; i++) {
        printf("v[%d] = %d ", i, v[i]);
    }


}


int main() {
    ex2();
    ex3();
    ex4();
    ex5();
    ex6();
    ex7();
    ex8a();
    ex8b();

    return 0;
}