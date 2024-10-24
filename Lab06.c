#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

// Defini��o da estrutura c�lula
struct reg {
    int conteudo;
    struct reg *prox;
};
typedef struct reg celula;

// Fun��o para imprimir todos os valores da lista
void imprimeLista(celula *inicio) {
    celula *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->conteudo);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Fun��o para remover todos os elementos da lista e liberar a mem�ria
void removeLista(celula *inicio) {
    celula *atual = inicio;
    celula *temp;
    while (atual != NULL) {
        temp = atual->prox;
        free(atual);
        atual = temp;
    }
}

// Fun��o para calcular a mem�ria dispon�vel no sistema
long memoriaDisponivel() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram;
}

int main() {
    // Criando tr�s inst�ncias da estrutura c�lula
    celula *c1 = (celula *)malloc(sizeof(celula));
    celula *c2 = (celula *)malloc(sizeof(celula));
    celula *c3 = (celula *)malloc(sizeof(celula));

    if (c1 == NULL || c2 == NULL || c3 == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }

    // Atribuindo valores para as c�lulas
    c1->conteudo = 10;
    c2->conteudo = 20;
    c3->conteudo = 30;

    // Ligando as c�lulas (construindo a lista encadeada)
    c1->prox = c2;
    c2->prox = c3;
    c3->prox = NULL;

    // Imprimindo os valores da lista
    printf("Lista encadeada inicial:\n");
    imprimeLista(c1);

    // Calculando o tamanho de uma c�lula
    size_t tamanhoCelula = sizeof(celula);
    printf("\nTamanho de uma c�lula: %zu bytes\n", tamanhoCelula);

    // Calculando a mem�ria dispon�vel no sistema
    long memLivre = memoriaDisponivel();
    printf("Mem�ria dispon�vel: %ld bytes\n", memLivre);

    // Calculando o m�ximo de elementos poss�veis na lista
    long maxElementos = memLivre / tamanhoCelula;
    printf("M�ximo de elementos poss�veis na lista: %ld\n", maxElementos);

    // Removendo todos os elementos da lista e liberando a mem�ria
    removeLista(c1);
    printf("\nLista encadeada removida e mem�ria liberada.\n");

    return 0;
}
