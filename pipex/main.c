#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int numPalabras(char *cadena) {
	int numPalabras = 0;
	bool dentroComillas = false;
	char *p = cadena;
	while (*p != '\0') {
		if (*p == '\'') {
			dentroComillas = !dentroComillas;
		} else if (*p == ' ' && !dentroComillas) {
			numPalabras++;
		}
		p++;
	}
	numPalabras++;
	return numPalabras;
}
char **divide_cadena(char *cadena) {
    bool dentro_de_comillas = false;
    char *inicio = cadena;
	char **resultado = malloc((numPalabras(cadena) + 1) * sizeof(char *));
	int i = 0;
    for (char *c = cadena; *c != '\0'; c++) {
        if (*c == '\'') {
            dentro_de_comillas = !dentro_de_comillas;
        } else if (*c == ' ' && !dentro_de_comillas) {
            *c = '\0';
			resultado[i++] = inicio;
            inicio = c + 1;
        }
    }
	resultado[i++] = inicio;
	return resultado;
}

int main() {
    char cadena1[] = "awk '{count++} END {printf count: %i, count}'";
    char cadena2[] = "./script space.sh";
    char cadena3[] = "awk david '{count++} END {printf count: %i, count}' hola";

    char **sol1 = divide_cadena(cadena1);
	char **sol2 = divide_cadena(cadena2);
	char **sol3 = divide_cadena(cadena3);
	for (int i = 0; sol1[i] != NULL; i++) {
		printf("%s\n", sol1[i]);
	}
	for (int i = 0; sol2[i] != NULL; i++) {
		printf("%s\n", sol2[i]);
	}
	for (int i = 0; sol3[i] != NULL; i++) {
		printf("%s\n", sol3[i]);
	}

    return 0;
}
