1. Se p é um ponteiro para inteiro, explique a diferença entre:
   a. p++; b. (*p)++; c.*(p++);

Resposta: A expressão p++ incrementa o endereço de memória de p, já a expressão (*p)++ recupera o valor inteiro
armazenado no endereço apontado por p, por meio do operador*, e em seguida faz o incremento desse valor, a expressão *(
p++) recupera o valor armazenado no endereço p++.

2. Qual o valor de y no final do programa? Tente primeiro descobrir e depois verifique no computador o resultado. A
   seguir, escreva um comentário em cada linha de comando em negrito explicando o que ele faz e o valor da variável após
   a execução.

```
int main()
{
int y, *p, x;
y = 0;
p = &y; // p aponta para o endereço de y
x = *p; // x recebe o valor armazenado no endereço de p (x = y = 0)
x = 4; // x recebe o valor 4
(*p)++; // *p = y = 0 -> (*p)++ = 1, y = 1 = *p
x--; // x-- -> x = 3
(*p) += x; // (*p)= 1 += 3 = 4
printf ("y = %d\n", y); // y = 4
return(0);
}
```

3. Explique o que faz o programa abaixo.

``` 
int main()
{
float vet[5] = {1.1,2.2,3.3,4.4,5.5};
float *f;
int i;
f = vet; // f aponta para a o endereço da primeira posição do vetor
printf("contador/valor/valor/endereco/endereco"); 
for(i = 0 ; i < 5 ; i++)
{
printf("\ni = %d",i);
printf(" vet[%d] = %.1f",i, vet[i]); //imprime vet[i]
printf(" *(f + %d) = %.1f",i, *(f+i)); //imprime valor armazenado no endereço de f + i, ou seja, o valor vet[i]
printf(" &vet[%d] = %X",i, &vet[i]); //imprime endereço de vet[i]
printf(" (f + %d) = %X",i, f+i); // imprime endereço de f+i = endereço de vet[i]
}
}
``` 

4. O que será impresso pelo programa abaixo?

``` 
#include < stdio.h >
#include < stdlib.h >
int main (void)
{
int i = 10, j = 20;
int temp;
int *p1 , *p2 ;
p1 = &i ; //p1 aponta para o endereço de i 
p2 = &j ; // p2 aponta para o endereço de j
temp = *p1 ; //temp = i = 10 (guarda i = 10)
*p1 = *p2 ; // valor armazenado no endereço de p1 (j) recebe o valor armazenado no endereço de p2 (20)
*p2 = temp ; // valor armazenado no endereço de p2 (i) recebe o temporário (10)
printf ( " %d %d \n" , i , j ); //i = 20, j = 10
return 0;
}
```

8. Os trechos de códigos abaixo possuem erros. Identifique-os e corrija-os.

```
void main()
{
int x, *p;
x = 100;
// p = x; ponteiro não pode receber inteiro 
p = &n;
printf(“Valor de p: %d.\n”, *p);
}
void troca (int *i, int *j)
{ //A função troca deve trocar os valores armazenados nos espaços de memória apontados
// int *temp;  A variável temp deve ser inteira, para guardar o valor apontado pelo endereço i:
int temp;
// *temp = *i; Errado, como temp é do tipo int, deve receber o valor apontado por i:
temp = *i; 
*i = *j; // certo, o valor armazenado no endereço apontado por i recebe o valor armazenado no end. apontado por j
// *j = *temp; Errado, o valor apontado por j deve receber o valor armazenado em temp:
*j = temp; 
}
```
9. Suponha que os elementos do vetor v são do tipo int e cada int ocupa 8 bytes na memória. Se o endereço de
   v[0] é 55000, qual o valor da expressão v + 3?

v + 3 = 55000 + 3 * 8 = 55024 

10. Suponha que v é um vetor. Descreva a diferença conceitual entre as expressões v[3] e v + 3.

A expressão v representa o ponteiro para a primeira posição de v, ou seja, o endereço de memória onde v[0] está armazenado. Logo, v + 3 será o ponteiro para a posição onde v[3] está armazenado. 
Já v[3] corresponde ao valor armazenado no endereço apontado por v+3. 
