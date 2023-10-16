#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char numPalabras(char *cadena) {
	int numPalabras = 0;
	int dentroComillas = 0;
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
	
	printf("%d\n", numPalabras);
	return numPalabras;
}
char **dividirCadena(char *cadena) {
    int numPalabras = 0;
    int dentroComillas = 0;
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

    char **resultado = malloc((numPalabras + 1) * sizeof(char *));
    char *palabra = strdup(cadena);

    int i = -1;
    while (palabra[++i] != NULL) {
        if (palabra[i] == '\'') {
            char *finComillas = strchr(palabra + 1, '\'');
            while (finComillas != NULL && finComillas[1] == '\'') {
                finComillas = strchr(finComillas + 2, '\'');
            }
            if (finComillas != NULL) {
                int longitud = finComillas - palabra + 2;
                char *palabraComillas = malloc(longitud + 1);
                strncpy(palabraComillas, palabra, longitud);
                palabraComillas[longitud] = '\0';
                resultado[i++] = palabraComillas;
                palabra += longitud;
            }
        }
		else {
            resultado[i++] = strdup(palabra);
        }

    }
    resultado[i] = NULL;

    free(copiaCadena);

    return resultado;
}

int main() {
    char cadena[] = "Hola 'que tal' estas";
	numPalabras(cadena);
    char **resultado = dividirCadena(cadena);

    for (int i = 0; resultado[i] != NULL; i++) {
        printf("%s\n", resultado[i]);
        free(resultado[i]); // Free each string
    }

    free(resultado); // Free the array of strings

    return 0;
}
