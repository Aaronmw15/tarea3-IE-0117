#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* recibir_string(){
    char *texto = malloc(100*sizeof(char)); //reservamos memoria suficiente para el texto 

    if (texto==NULL){ //verificamos que se logro reservar memoria
        printf("Error al reservar memoria.\n");
        exit(1);//esto salde el programa y retorna 1
    }
    printf("Ingrese una palabra: ");
    scanf("%99s", texto);//esto pone un limite a scanf, lee hasta el caracter 99, ya que el 100 sería el caracter nulo

    return texto;
}

void contar_caracter(char *texto){ //void, porque la funcion imprime, no necesita retornar
    char caracter; //solicitamos el caracter al usuario
    printf("ingrese el caracter que desea buscar: ");
    scanf(" %c" , &caracter);
    printf("\n");
    int contador=0;
    for(int i=0; i<strlen(texto); i++){//para cada letra en el texto, si es el caracter buscado, se añade al contador
        if(caracter==texto[i]){
            contador++;
        }
    }
    printf("numero de caracteres [%c] encontrados: %i\n", caracter, contador);
}

void voltear_palabra(char *texto){
    char *palabra_invertida=malloc((strlen(texto)+1)*sizeof(char));//reservamos la memoria para un string del mismo tamaño del original, contando el ultimo caracter
    palabra_invertida[strlen(texto)]='\0';//definimos el ultimo elemento del string como caracter nulo, para marcar el fin
    for(int  i=0;i<strlen(texto);i++){ //iteramos sobre cada espacio en la palabra invertida y guardamos la ultima palabra de la otiginal
        palabra_invertida[i] = texto[strlen(texto) - 1 - i];
    }
    printf("palabra invertida: %s\n" , palabra_invertida);
    free(palabra_invertida); // lineramos la memoria
}

int main(){

    char *texto = recibir_string(); //pedimos el texto al usuario
        
    contar_caracter(texto);

    voltear_palabra(texto);
    free(texto);//al terminar, liberamos la memoria almacenada
    return 0;
}