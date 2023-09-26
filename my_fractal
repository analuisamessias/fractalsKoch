#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITERACOES 4
#define MAX_SIMBOLOS 65536

void regra_fractal(char *simbolos, int iteracoes, const char *axioma, double angulo, const char *regraX, const char *regraY);
void fractal_proprio(const char *axioma, double angulo, const char *regraX, const char *regraY);

void regra_fractal(char *simbolos, int iteracoes, const char *axioma, double angulo, const char *regraX, const char *regraY) {
    if (iteracoes == 0) {
        strcpy(simbolos, axioma);
    } else {
        char temp[MAX_SIMBOLOS];
        regra_fractal(temp, iteracoes - 1, axioma, angulo, regraX, regraY);
        int pos = 0;

        for (int i = 0; i < strlen(temp); i++) {
            if (temp[i] == 'F') {
                simbolos[pos++] = 'F';
            } else if (temp[i] == '+') {
                simbolos[pos++] = '+';
            } else if (temp[i] == '-') {
                simbolos[pos++] = '-';
            } else if (temp[i] == 'X') {
                regra_fractal(simbolos + pos, 0, regraX, angulo, regraX, regraY);
                pos += strlen(regraX);
            } else if (temp[i] == 'Y') {
                regra_fractal(simbolos + pos, 0, regraY, angulo, regraX, regraY);
                pos += strlen(regraY);
            }
        }

        simbolos[pos] = '\0';
    }
}

void fractal_proprio(const char *axioma, double angulo, const char *regraX, const char *regraY) {
    FILE *outputFile = fopen("my_fractal.txt", "w");
    if (outputFile == NULL) {
        printf("It was not possible to create the output file.\n");
        return;
    }

    fprintf(outputFile, "My Fractal\n\n");
    fprintf(outputFile, "Axiom: %s\n", axioma);
    fprintf(outputFile, "Angle (in degrees): %.2lf\n", angulo);
    fprintf(outputFile, "Rule of X: %s\n", regraX);
    fprintf(outputFile, "Rule of Y: %s\n", regraY);

    for (int i = 1; i <= MAX_ITERACOES; i++) {
        char curva[MAX_SIMBOLOS];
        regra_fractal(curva, i, axioma, angulo, regraX, regraY);

        // Remove os símbolos X e Y da sequência
        char sequenciaF[MAX_SIMBOLOS];
        int pos = 0;
        for (int j = 0; j < strlen(curva); j++) {
            if (curva[j] == 'F' || curva[j] == '+' || curva[j] == '-') {
                sequenciaF[pos++] = curva[j];
            }
        }
        sequenciaF[pos] = '\0';

        fprintf(outputFile, "\n\nSymbol sequence in the %dº stage:\n%s\n", i, sequenciaF);
    }

    fclose(outputFile);

    printf("\n"The symbol sequence has been saved in the 'my_fractal.txt' file.\n");
}

int main() {
    char axioma[MAX_SIMBOLOS];
    double angulo;
    char regraX[MAX_SIMBOLOS];
    char regraY[MAX_SIMBOLOS];

    printf("Axiom: ");
    scanf("%s", axioma);

    printf("Angle (in degrees): ");
    scanf("%lf", &angulo);

    printf("Rule of X: ");
    scanf("%s", regraX);

    printf("Rule of Y: ");
    scanf("%s", regraY);

    fractal_proprio(axioma, angulo, regraX, regraY);

    return 0;
}
