#ifndef SEMAFORO_H_
#define SEMAFORO_H_

	struct SemaforoStruct{
		int luces[3];
		int indice;
	};
	typedef struct SemaforoStruct Semaforo;

	Semaforo* inicializar();
	void prenderLuz(Semaforo* semaforo);
	void apagarLuz(Semaforo* semaforo);
	void cambiarLuz(Semaforo* semaforo);

#endif /* SEMAFORO_H_ */
