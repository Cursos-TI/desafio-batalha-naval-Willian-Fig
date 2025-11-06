#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHA 10
#define COLUNA 10
#define TAM_HAB 5  // tamanho das matrizes de habilidades

// Função para construir a matriz de habilidade CONE
void construirCone(int cone[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // forma triangular: se a distância da coluna até o centro for <= linha atual
            if (abs(j - centro) <= i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para construir a matriz de habilidade CRUZ
void construirCruz(int cruz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para construir a matriz de habilidade OCTAEDRO (losango)
void construirOctaedro(int octa[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    int raio = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= raio) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }
}

// Função para sobrepor uma habilidade no tabuleiro
void aplicarHabilidade(int tab[LINHA][COLUNA], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - centro + i;
                int coluna = origemColuna - centro + j;

                // Verifica limites
                if (linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA) {
                    // Não sobrescreve navios (3)
                    if (tab[linha][coluna] != 3) {
                        tab[linha][coluna] = 5; // marca área afetada
                    }
                }
            }
        }
    }
}

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

    /*// Vetores representando os navios (apenas para referência)
    int navioHorizontal[3] = {navio, navio, navio};
    int navioVertical[3] = {navio, navio, navio};
    int navioDiagonalEsquerdo[3] = {navio, navio, navio};
    int navioDiagonalDireito[3] = {navio, navio, navio};

    // Coordenadas iniciais (definidas diretamente no código)
    int linhaInicialHorizontal = 2;
    int colunaInicialHorizontal = 4;
    int linhaInicialDiagonalEsquerda = 3;
    int colunaInicialDiagonalEsquerda = 1;

    int linhaInicialVertical = 5;
    int colunaInicialVertical = 7;
    int linhaInicialDiagonalDireita = 1;
    int colunaInicialDiagonalDireita = 9;


    // Posicionando o navio horizontal no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaInicialHorizontal][colunaInicialHorizontal + i] = navio;
    }

    // Posicionando o navio diagonal esquerda no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaInicialDiagonalEsquerda + i][colunaInicialDiagonalEsquerda + i] = navio;
    }

    // Posicionando o navio vertical no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaInicialVertical + i][colunaInicialVertical] = navio;
    }

    // Posicionando o navio diagonal direita no tabuleiro
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaInicialDiagonalDireita + i][colunaInicialDiagonalDireita - i] = navio;
    }
    */
    // ===== CONSTRUÇÃO DAS HABILIDADES =====
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // ===== POSIÇÕES DAS HABILIDADES NO TABULEIRO =====
    int origemConeLinha = 2, origemConeColuna = 3;
    int origemCruzLinha = 7, origemCruzColuna = 3;
    int origemOctaLinha = 5, origemOctaColuna = 7;

    // ===== APLICAÇÃO DAS HABILIDADES =====
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaLinha, origemOctaColuna);

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
