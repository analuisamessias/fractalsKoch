#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITERACOES 4
#define MAX_SIMBOLOS 65536

void onda_senoidal_Koch(char *simbolos, int iteracoes, const char *axioma, double angulo, const char *regra, int numero);

void curva_Koch(char *simbolos, int iteracoes, const char *axioma, double angulo, const char *regra) {
    char temp[MAX_SIMBOLOS];
    int i, j;

    if (iteracoes == 0) {
        strcpy(simbolos, axioma);
    } else {
        curva_Koch(temp, iteracoes - 1, axioma, angulo, regra);
        simbolos[0] = '\0';

        for (i = 0, j = strlen(temp); i < j; ++i) {
            if (temp[i] == 'F') {
                strcat(simbolos, regra);
            } else {
                strncat(simbolos, &temp[i], 1);
            }
        }
    }
}

void onda_senoidal_Koch(char *simbolos, int iteracoes, const char *axioma, double angulo, const char *regra, int numero) {
    FILE *outputFile = fopen("exit_wavesinusoidal.txt", "w");
    if (outputFile == NULL) {
        printf("It was not possible to create the output file.\n");
        return;
    }

    fprintf(outputFile, "Fractal Sinusoidal Wave 2 from Koch\n\n");
    fprintf(outputFile, "Corresponding Fractal Number: %d\n", numero);
    fprintf(outputFile, "Axiom: %s\n", axioma);
    fprintf(outputFile, "Angle (in degrees): %.2lf\n", angulo);
    fprintf(outputFile, "Rule: %s\n", regra);

    for (int i = 1; i <= MAX_ITERACOES; i++) {
        char curva[MAX_SIMBOLOS];
        simbolos[0] = '\0';

        curva_Koch(curva, i, axioma, angulo, regra);
        fprintf(outputFile, "\n\nSymbol sequence in the %dº stage:\n%s\n", i, curva);
    }

    fclose(outputFile);

    printf("\nThe symbol sequence has been saved in the 'exit_wavesinusoidal.txt' file.\n");
}

int main() {
    int iteracoes;
    char axioma[MAX_SIMBOLOS];
    double angulo;
    char regra[MAX_SIMBOLOS];
    char simbolos[MAX_SIMBOLOS];
    int numero;

    printf("Corresponding Fractal Number: ");
    scanf("%i", &numero);

    printf("Axiom: ");
    scanf("%s", axioma);

    printf("Angle (in degrees): ");
    scanf("%lf", &angulo);

    printf("Rule: ");
    scanf("%s", regra);

    onda_senoidal_Koch(simbolos, MAX_ITERACOES, axioma, angulo, regra, numero);

    return 0;
}
