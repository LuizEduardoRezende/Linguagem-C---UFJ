#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar termos do polinômio
typedef struct Termo {
    double coeficiente;
    int expoente;
    struct Termo* proximo;
} Termo;

// Função para criar um novo termo
Termo* criarTermo(double coeficiente, int expoente) {
    Termo* novoTermo = (Termo*)malloc(sizeof(Termo));
    if (novoTermo == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        exit(1);
    }
    novoTermo->coeficiente = coeficiente;
    novoTermo->expoente = expoente;
    novoTermo->proximo = NULL;
    return novoTermo;
}

// Função para inserir um termo em ordem decrescente de expoente em uma lista
void inserirTermoOrdenado(Termo** lista, double coeficiente, int expoente) {
    Termo* novoTermo = criarTermo(coeficiente, expoente);

    if (*lista == NULL || expoente > (*lista)->expoente) {
        novoTermo->proximo = *lista;
        *lista = novoTermo;
    } else {
        Termo* atual = *lista;
        while (atual->proximo != NULL && expoente < atual->proximo->expoente) {
            atual = atual->proximo;
        }
        novoTermo->proximo = atual->proximo;
        atual->proximo = novoTermo;
    }
}

// Função para somar dois polinômios
Termo* somarPolinomios(Termo* polinomio1, Termo* polinomio2) {
    Termo* resultado = NULL;

    while (polinomio1 != NULL && polinomio2 != NULL) {
        if (polinomio1->expoente > polinomio2->expoente) {
            inserirTermoOrdenado(&resultado, polinomio1->coeficiente, polinomio1->expoente);
            polinomio1 = polinomio1->proximo;
        } else if (polinomio2->expoente > polinomio1->expoente) {
            inserirTermoOrdenado(&resultado, polinomio2->coeficiente, polinomio2->expoente);
            polinomio2 = polinomio2->proximo;
        } else {
            double soma = polinomio1->coeficiente + polinomio2->coeficiente;
            if (soma != 0) {
                inserirTermoOrdenado(&resultado, soma, polinomio1->expoente);
            }
            polinomio1 = polinomio1->proximo;
            polinomio2 = polinomio2->proximo;
        }
    }

    while (polinomio1 != NULL) {
        inserirTermoOrdenado(&resultado, polinomio1->coeficiente, polinomio1->expoente);
        polinomio1 = polinomio1->proximo;
    }

    while (polinomio2 != NULL) {
        inserirTermoOrdenado(&resultado, polinomio2->coeficiente, polinomio2->expoente);
        polinomio2 = polinomio2->proximo;
    }

    return resultado;
}

// Função para multiplicar dois polinômios
Termo* multiplicarPolinomios(Termo* polinomio1, Termo* polinomio2) {
    Termo* resultado = NULL;

    while (polinomio1 != NULL) {
        Termo* temp = polinomio2;
        while (temp != NULL) {
            double coeficiente = polinomio1->coeficiente * temp->coeficiente;
            int expoente = polinomio1->expoente + temp->expoente;
            inserirTermoOrdenado(&resultado, coeficiente, expoente);
            temp = temp->proximo;
        }
        polinomio1 = polinomio1->proximo;
    }

    return resultado;
}

// Função para derivar um polinômio
Termo* derivarPolinomio(Termo* polinomio) {
    Termo* resultado = NULL;

    while (polinomio != NULL) {
        if (polinomio->expoente > 0) {
            double coeficiente = polinomio->coeficiente * polinomio->expoente;
            int expoente = polinomio->expoente - 1;
            inserirTermoOrdenado(&resultado, coeficiente, expoente);
        }
        polinomio = polinomio->proximo;
    }

    return resultado;
}

// Função para imprimir um polinômio
void imprimirPolinomio(Termo* polinomio) {
    if (polinomio == NULL) {
        printf("0\n");
    } else {
        while (polinomio != NULL) {
            printf("%.2fx^%d", polinomio->coeficiente, polinomio->expoente);
            if (polinomio->proximo != NULL) {
                printf(" + ");
            }
            polinomio = polinomio->proximo;
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada para um polinômio
void liberarPolinomio(Termo* polinomio) {
    while (polinomio != NULL) {
        Termo* temp = polinomio->proximo;
        free(polinomio);
        polinomio = temp;
    }
}

int main() {
    Termo* polinomio1 = NULL;
    Termo* polinomio2 = NULL;

    // Inserir termos nos polinômios
    inserirTermoOrdenado(&polinomio1, 3.0, 2);
    inserirTermoOrdenado(&polinomio1, 2.0, 1);
    inserirTermoOrdenado(&polinomio1, 1.0, 0);

    inserirTermoOrdenado(&polinomio2, 2.0, 3);
    inserirTermoOrdenado(&polinomio2, 1.0, 2);
    inserirTermoOrdenado(&polinomio2, 4.0, 0);

    printf("Polinomio 1: ");
    imprimirPolinomio(polinomio1);
    printf("Polinomio 2: ");
    imprimirPolinomio(polinomio2);

    // Somar dois polinômios
    Termo* soma = somarPolinomios(polinomio1, polinomio2);
    printf("Soma: ");
    imprimirPolinomio(soma);

    // Multiplicar dois polinômios
    Termo* produto = multiplicarPolinomios(polinomio1, polinomio2);
    printf("Produto: ");
    imprimirPolinomio(produto);

    // Derivar um polinômio
    Termo* derivada = derivarPolinomio(polinomio1);
    printf("Derivada de Polinomio 1: ");
    imprimirPolinomio(derivada);

    // Liberar memória alocada para os polinômios
    liberarPolinomio(polinomio1);
    liberarPolinomio(polinomio2);
    liberarPolinomio(soma);
    liberarPolinomio(produto);
    liberarPolinomio(derivada);

    return 0;
}
