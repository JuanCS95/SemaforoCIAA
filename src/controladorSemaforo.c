#include "controladorSemaforo.h"
#include <sapi.h>

ControladorSemaforo* iniciarControlador(){
	ControladorSemaforo* cSemaforo = malloc(sizeof(ControladorSemaforo));
	cSemaforo->semaforo.luces[0] = 1;
	cSemaforo->semaforo.luces[1] = 0;
	cSemaforo->semaforo.luces[2] = 0;
	cSemaforo->semaforo.indice=0;
	cSemaforo->tiempo[0] = 0;
	cSemaforo->tiempo[1] = 0;
	cSemaforo->tiempo[2] = 0;
	cSemaforo->ida = 1;
	return cSemaforo;
}

void secuenciaSemaforo(ControladorSemaforo* cSemaforo){
	imprimirEstadoC(cSemaforo);
	cambiarLuzC(cSemaforo);
	delay(cSemaforo->tiempo[cSemaforo->semaforo.indice]);
}

void prenderLuzC(ControladorSemaforo* semaforoC){
	semaforoC->semaforo.luces[semaforoC->semaforo.indice]= 1;
}

void apagarLuzC(ControladorSemaforo* semaforoC){
	 semaforoC->semaforo.luces[semaforoC->semaforo.indice] = 0;
}

void cambiarLuzC(ControladorSemaforo* semaforoC){
	if(semaforoC->semaforo.indice == 2){
				semaforoC->ida = 0;
	}
	if(semaforoC->ida == 1) {
		apagarLuzC(semaforoC);
		(semaforoC->semaforo.indice) +=1;
		prenderLuzC(semaforoC);
	}

	if(semaforoC->ida == 0) {
		apagarLuzC(semaforoC);
		(semaforoC->semaforo.indice) -=1;
		prenderLuzC(semaforoC);
		if(semaforoC->semaforo.indice == 0){
			semaforoC->ida = 1;
		}
	}
}

void liberarC(ControladorSemaforo* semaforoC){
	free((void*)semaforoC);
}

void imprimirEstadoC(ControladorSemaforo* semaforoC){
	if(semaforoC->semaforo.luces[0] == 1){
		gpioWrite(LED2,ON);
	}else{
		gpioWrite(LED2,OFF);
	}

	if(semaforoC->semaforo.luces[1] == 1){
		gpioWrite(LED1,ON);
	}else{
		gpioWrite(LED1,OFF);
	}

	if(semaforoC->semaforo.luces[2] == 1){
		gpioWrite(LED3,ON);
	}else{
		gpioWrite(LED3,OFF);
	}
}
