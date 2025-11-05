#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    #include <stdio.h>

    // Declaração da matriz (tabuleiro)
    int agua = 0;
    int navio = 3;
    int tabuleiro[10][10];

    // Inicialização de todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = agua;
        }
    }

    // Vetores representando os navios (apenas para referência)
    int navioHorizontal[3] = {navio, navio, navio};
    int navioVertical[3] = {navio, navio, navio};

    // Coordenadas iniciais (definidas diretamente no código)
    int linhaInicialHorizontal = 2;
    int colunaInicialHorizontal = 4;

    int linhaInicialVertical = 5;
    int colunaInicialVertical = 7;


    // Posicionando o navio horizontal no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaInicialHorizontal][colunaInicialHorizontal + i] = navio;
    }

    // Posicionando o navio vertical no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaInicialVertical + i][colunaInicialVertical] = navio;
    }

    // Exibe o tabuleiro
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
