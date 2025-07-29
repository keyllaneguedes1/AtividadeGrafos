#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_CIDADES 10
#define MAX_CAMINHOS 100

const char *nomes[] = {
    "Corrente", "Gilbués", "Bom Jesus", "Floriano", "Oeiras",
    "Teresina", "Campo Maior", "Piripiri", "Luís Correia", "Parnaíba"
};

typedef struct No {
    int destino;
    struct No *prox;
} No;

typedef struct {
    No *adj[NUM_CIDADES];
} Grafo;

typedef struct {
    int caminho[NUM_CIDADES];
    int tamanho;
} Caminho;

Grafo *criarGrafo() {
    Grafo *g = malloc(sizeof(Grafo));
    for (int i = 0; i < NUM_CIDADES; i++)
        g->adj[i] = NULL;
    return g;
}

void adicionarAresta(Grafo *g, int origem, int destino) {
    No *novo = malloc(sizeof(No));
    novo->destino = destino;
    novo->prox = g->adj[origem];
    g->adj[origem] = novo;
}

typedef struct {
    int cidade;
    int nivel;
    int caminho[NUM_CIDADES];
    int visitado[NUM_CIDADES];
} EstadoDFS;

int encontrarTodosCaminhos(Grafo *g, int origem, int destino, Caminho caminhos[]) {
    EstadoDFS pilha[1000];
    int topo = 0;
    int total = 0;

    pilha[topo++] = (EstadoDFS){origem, 0, {origem}, {0}};
    pilha[0].visitado[origem] = 1;

    while (topo > 0) {
        EstadoDFS atual = pilha[--topo];

        if (atual.cidade == destino) {
            Caminho c;
            memcpy(c.caminho, atual.caminho, sizeof(int) * (atual.nivel + 1));
            c.tamanho = atual.nivel + 1;
            caminhos[total++] = c;
            continue;
        }

        for (No *viz = g->adj[atual.cidade]; viz != NULL; viz = viz->prox) {
            if (!atual.visitado[viz->destino]) {
                EstadoDFS novo = atual;
                novo.nivel++;
                novo.cidade = viz->destino;
                novo.caminho[novo.nivel] = viz->destino;
                novo.visitado[viz->destino] = 1;
                pilha[topo++] = novo;
            }
        }
    }

    return total;
}

void imprimirCaminho(Caminho c) {
    for (int i = 0; i < c.tamanho; i++) {
        printf("%s", nomes[c.caminho[i]]);
        if (i < c.tamanho - 1)
            printf(" -> ");
    }
    printf("\n");
}


void montarMapa(Grafo *g) {
    adicionarAresta(g, 0, 1); 
    adicionarAresta(g, 1, 2);
    adicionarAresta(g, 2, 3);
    adicionarAresta(g, 3, 4);
    adicionarAresta(g, 4, 5);
    adicionarAresta(g, 5, 6);
    adicionarAresta(g, 6, 7);
    adicionarAresta(g, 7, 8);
    adicionarAresta(g, 8, 9); 
    adicionarAresta(g, 5, 9); 
    adicionarAresta(g, 2, 5); 
}

void imprimirGrafo(Grafo *g) {
    printf("Mapa de conexões entre cidades:\n\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("%s -> ", nomes[i]);
        No *atual = g->adj[i];
        if (!atual) {
            printf("(sem conexões)");
        } else {
            while (atual != NULL) {
                printf("%s", nomes[atual->destino]);
                if (atual->prox != NULL)
                    printf(" -> ");
                atual = atual->prox;
            }
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    Grafo *g = criarGrafo();
    montarMapa(g);
    imprimirGrafo(g);

    Caminho caminhos[MAX_CAMINHOS];
    int total = encontrarTodosCaminhos(g, 0, 9, caminhos);

    printf("Todos os caminhos de Corrente até Parnaíba:\n\n");
    for (int i = 0; i < total; i++) {
        printf("Caminho %d (%d cidades): ", i + 1, caminhos[i].tamanho);
        imprimirCaminho(caminhos[i]);
    }

    if (total > 0) {
        int menor = 0, maior = 0;
        for (int i = 1; i < total; i++) {
            if (caminhos[i].tamanho < caminhos[menor].tamanho)
                menor = i;
            if (caminhos[i].tamanho > caminhos[maior].tamanho)
                maior = i;
        }

        printf("\nMenor caminho (%d cidades): ", caminhos[menor].tamanho);
        imprimirCaminho(caminhos[menor]);

        printf("Maior caminho (%d cidades): ", caminhos[maior].tamanho);
        imprimirCaminho(caminhos[maior]);
    }

    return 0;
}
