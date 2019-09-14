#include <stdlib.h>
#include "semaforo.h"


Semaforo* inicializar(){
	Semaforo* semaforo = malloc(sizeof(Semaforo));
	semaforo->luces[0] = 1;
	semaforo->luces[1] = 0;
	semaforo->luces[2] = 0;
	semaforo->indice=0;
	return semaforo;
}

void prenderLuz(Semaforo* semaforo){
	semaforo->luces[semaforo->indice]= 1;
}

void apagarLuz(Semaforo* semaforo){
	 semaforo->luces[semaforo->indice] = 0;
}

void cambiarLuz(Semaforo* semaforo){
	do{
		apagarLuz(semaforo);
		(semaforo->indice) +=1;

	} while (semaforo->indice > semaforo->luces);
	prenderLuz(semaforo);
}

void liberar(Semaforo* semaforo){
	free((void*)semaforo);
}

void imprimirEstado(Semaforo* semaforo){
	if(semaforo->luces[0] == 1){
		printf("La luz Roja está encendida \n");
	}else{
		printf("La luz Roja está apagada \n");
	}

	if(semaforo->luces[1] == 1){
		printf("La Luz Amarilla está encendida \n");
	}else{
		printf("La luz Amarilla está apagada \n");
	}

	if(semaforo->luces[2] == 1){
		printf("La Luz Verde está encendida \n \n");
	}else{
		printf("La luz Verde está apagada \n \n");
	}
}
