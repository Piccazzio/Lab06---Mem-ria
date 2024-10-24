#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

// Definição da estrutura célula
struct reg {
    int conteudo;
    struct reg *prox;
};
typedef struct reg celula;

// Função para imprimir todos os valores da lista
void imprimeLista(celula *inicio) {
    celula *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->conteudo);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para remover todos os elementos da lista e liberar a memória
void removeLista(celula *inicio) {
    celula *atual = inicio;
    celula *temp;
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
}

// Função para calcular a memória disponível no sistema
long memoriaDisponivel() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram;
}

int main() {
    // Criando três instâncias da estrutura célula
    celula *c1 = (celula *)malloc(sizeof(celula));
    celula *c2 = (celula *)malloc(sizeof(celula));
    celula *c3 = (celula *)malloc(sizeof(celula));

    if (c1 == NULL || c2 == NULL || c3 == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Atribuindo valores para as células
    c1->conteudo = 10;
    c2->conteudo = 20;
    c3->conteudo = 30;

    // Ligando as células (construindo a lista encadeada)
    c1->prox = c2;
    c2->prox = c3;
    c3->prox = NULL;

    // Imprimindo os valores da lista
    printf("Lista encadeada inicial:\n");
    imprimeLista(c1);

    // Calculando o tamanho de uma célula
    size_t tamanhoCelula = sizeof(celula);
    printf("\nTamanho de uma célula: %zu bytes\n", tamanhoCelula);

    // Calculando a memória disponível no sistema
    long memLivre = memoriaDisponivel();
    printf("Memória disponível: %ld bytes\n", memLivre);

    // Calculando o máximo de elementos possíveis na lista
    long maxElementos = memLivre / tamanhoCelula;
    printf("Máximo de elementos possíveis na lista: %ld\n", maxElementos);

    // Removendo todos os elementos da lista e liberando a memória
    removeLista(c1);
    printf("\nLista encadeada removida e memória liberada.\n");

    return 0;
}
