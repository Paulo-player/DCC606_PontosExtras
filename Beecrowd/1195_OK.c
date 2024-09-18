#include <stdio.h>
#include <stdlib.h>

typedef struct noArv {
    int numero;
    struct noArv *esquerda;
    struct noArv *direita;
} noArv;

noArv* insere(noArv *arvore, int numero);
void showPre(noArv *arvore);
void showIn(noArv *arvore);
void showPost(noArv *arvore);
void erase(noArv *arvore);

int main() {
    unsigned short i;
    int numero;

    unsigned short qtsNos;
    unsigned short qtsCasos, caso = 0;

    scanf("%hu", &qtsCasos);

    while (qtsCasos--) {
        noArv *arvore = NULL;
        scanf("%hu", &qtsNos);

        for (i = 0; i < qtsNos; i++) {
            scanf("%d", &numero);
            arvore = insere(arvore, numero);
        }

        printf("Case %hu:\n", ++caso);
        printf("Pre.:");
        showPre(arvore);
        printf("\n");
        printf("In..:");
        showIn(arvore);
        printf("\n");
        printf("Post:");
        showPost(arvore);
        printf("\n\n");
        erase(arvore);
    }

    return 0;
}

noArv* insere(noArv *arvore, int numero) {
    if (arvore == NULL) {
        arvore = (noArv *) malloc(sizeof(noArv));
        if (arvore != NULL) {
            arvore->numero = numero;
            arvore->esquerda = arvore->direita = NULL;
        }
    } else if (arvore->numero > numero) {
        arvore->esquerda = insere(arvore->esquerda, numero);
    } else {
        arvore->direita = insere(arvore->direita, numero);
    }

    return arvore;
}

void showPost(noArv *arvore) {
    if (arvore != NULL) {
        showPost(arvore->esquerda);
        showPost(arvore->direita);
        printf(" %d", arvore->numero);
    }
}

void showPre(noArv *arvore) {
    if (arvore != NULL) {
        printf(" %d", arvore->numero);
        showPre(arvore->esquerda);
        showPre(arvore->direita);
    }
}

void showIn(noArv *arvore) {
    if (arvore != NULL) {
        showIn(arvore->esquerda);
        printf(" %d", arvore->numero);
        showIn(arvore->direita);
    }
}

void erase(noArv *arvore) {
    if (arvore != NULL) {
        erase(arvore->esquerda);
        erase(arvore->direita);
        free(arvore);
    }
}