#include "semaforo.h"

#ifndef CONTROLADORSEMAFORO_H_
#define CONTROLADORSEMAFORO_H_

	struct ControladorSemaforoStruct{
		Semaforo semaforo;
		int tiempo[3];
		int ida;
	};
	typedef struct ControladorSemaforoStruct ControladorSemaforo;

	ControladorSemaforo* iniciarControlador();

	void secuenciaSemaforo();
	void prenderLuzC(ControladorSemaforo* semaforoC);
	void apagarLuzC(ControladorSemaforo* semaforoC);
	void cambiarLuzC(ControladorSemaforo* semaforoC);
	void liberarC(ControladorSemaforo* semaforoC);
	void imprimirEstadoC(ControladorSemaforo* semaforoC);
#endif /* CONTROLADORSEMAFORO_H_ */
