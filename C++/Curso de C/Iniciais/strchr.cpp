#include <stdio.h>
#include <string.h>

int main() {
    const char *texto = "Ol�, mundo!";
    char *resultado;

    // Procurar pelo caractere 'm' na string texto
    resultado = strchr(texto, 'm');

    if (resultado != NULL) {
        printf("O caractere 'm' encontrado na posi��o: %ld\n", resultado - texto);
        printf("Parte da string a partir do caractere encontrado: %s\n", resultado);
    } else {
        printf("Caractere n�o encontrado.\n");
    }

    return 0;
}
