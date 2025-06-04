#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITERACOES 4
#define MAX_SIMBOLOS 65536

void regra_hilbert(char *simbolos, int iteracoes, const char *axioma, double angulo, const char *regraX, const char *regraY);
void preenchimento_hilbert(const char *axioma, double angulo, const char *regraX, const char *regraY, int numero);

void regra_hilbert(char *simbolos, int iteracoes, const char *axioma, double angulo, const char *regraX, const char *regraY) {
    if (iteracoes == 0) {
        strcpy(simbolos, axioma);
    } else {
        char temp[MAX_SIMBOLOS];
        regra_hilbert(temp, iteracoes - 1, axioma, angulo, regraX, regraY);
        int pos = 0;

        for (int i = 0; i < strlen(temp); i++) {
            if (temp[i] == 'F') {
                simbolos[pos++] = 'F';
            } else if (temp[i] == '+') {
                simbolos[pos++] = '+';
            } else if (temp[i] == '-') {
                simbolos[pos++] = '-';
            } else if (temp[i] == 'X') {
                regra_hilbert(simbolos + pos, 0, regraX, angulo, regraX, regraY);
                pos += strlen(regraX);
            } else if (temp[i] == 'Y') {
                regra_hilbert(simbolos + pos, 0, regraY, angulo, regraX, regraY);
                pos += strlen(regraY);
            }
        }

        simbolos[pos] = '\0';
    }
}

void preenchimento_hilbert(const char *axioma, double angulo, const char *regraX, const char *regraY, int numero) {
    FILE *outputFile = fopen("exit_hilbert.txt", "w");
    if (outputFile == NULL) {
        printf("It was not possible to create the output file.\n");
        return;
    }

    fprintf(outputFile, "Fractal Hilbert\n\n");
    fprintf(outputFile, "Corresponding Fractal Number: %d\n", numero);
    fprintf(outputFile, "Axiom: %s\n", axioma);
    fprintf(outputFile, "Angle (in degrees): %.2lf\n", angulo);
    fprintf(outputFile, "Rule of X: %s\n", regraX);
    fprintf(outputFile, "Rule of Y: %s\n", regraY);

    for (int i = 1; i <= MAX_ITERACOES; i++) {
        char curva[MAX_SIMBOLOS];
        regra_hilbert(curva, i, axioma, angulo, regraX, regraY);

        // Remove symbols X and Y from sequence
        char sequenciaF[MAX_SIMBOLOS];
        int pos = 0;
        for (int j = 0; j < strlen(curva); j++) {
            if (curva[j] == 'F' || curva[j] == '+' || curva[j] == '-') {
                sequenciaF[pos++] = curva[j];
            }
        }
        sequenciaF[pos] = '\0';

        fprintf(outputFile, "\n\nSymbol sequence in the %dº stage: \n%s\n", i, sequenciaF);
    }

    fclose(outputFile);

    printf("\nThe symbol sequence has been saved in the 'exit_hilbert.txt' file.\n");
}

int main() {
    char axioma[MAX_SIMBOLOS];
    double angulo;
    char regraX[MAX_SIMBOLOS];
    char regraY[MAX_SIMBOLOS];
    int numero;

    printf("Corresponding Fractal Number: ");
    scanf("%d", &numero);

    printf("Axiom: ");
    scanf("%s", axioma);

    printf("Angle (in degrees): ");
    scanf("%lf", &angulo);

    printf("Rule of X: ");
    scanf("%s", regraX);

    printf("Rule of Y: ");
    scanf("%s", regraY);

    preenchimento_hilbert(axioma, angulo, regraX, regraY, numero);

    return 0;
}
