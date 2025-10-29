#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}


void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM) {
        printf("ERRO: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            printf("ERRO: Sobreposição detectada no navio horizontal!\n");
            return 0;
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    return 1;
}

int posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM) {
        printf("ERRO: Navio vertical ultrapassa os limites do tabuleiro!\n");
        return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            printf("ERRO: Sobreposição detectada no navio vertical!\n");
            return 0;
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }

    return 1;
}

int main() {
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);


    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 1;

    if (posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal))
        printf("Navio horizontal posicionado com sucesso!\n");

    if (posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical))
        printf("Navio vertical posicionado com sucesso!\n");

    exibirTabuleiro(tabuleiro);

    return 0;
}
