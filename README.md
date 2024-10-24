# Lab06 Memoria

Repositório do laboratório 06 da matéria de Sistemas Operacionais
## Integrantes
Carlos Eduardo Hayashi         10419790

Vinícius Oliveira Piccazzio    10419471

## Código

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

struct reg {
    int conteudo;
    struct reg *prox;
};
typedef struct reg celula;

void imprimeLista(celula *inicio) {
    celula *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->conteudo);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void removeLista(celula *inicio) {
    celula *atual = inicio;
    celula *temp;
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
}

long memoriaDisponivel() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram;
}

int main() {
    celula *c1 = (celula *)malloc(sizeof(celula));
    celula *c2 = (celula *)malloc(sizeof(celula));
    celula *c3 = (celula *)malloc(sizeof(celula));

    if (c1 == NULL || c2 == NULL || c3 == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    c1->conteudo = 10;
    c2->conteudo = 20;
    c3->conteudo = 30;

    c1->prox = c2;
    c2->prox = c3;
    c3->prox = NULL;

    printf("Lista encadeada inicial:\n");
    imprimeLista(c1);

    size_t tamanhoCelula = sizeof(celula);
    printf("\nTamanho de uma célula: %zu bytes\n", tamanhoCelula);

    long memLivre = memoriaDisponivel();
    printf("Memória disponível: %ld bytes\n", memLivre);

    long maxElementos = memLivre / tamanhoCelula;
    printf("Máximo de elementos possíveis na lista: %ld\n", maxElementos);

    removeLista(c1);
    printf("\nLista encadeada removida e memória liberada.\n");

    return 0;
}

## Print da Resolução
![image](https://github.com/user-attachments/assets/cb1d86a6-adff-4aab-9d5f-c8a9d3bac0f7)


