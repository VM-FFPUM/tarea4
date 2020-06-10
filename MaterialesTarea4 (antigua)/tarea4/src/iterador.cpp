/* 4862558 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/iterador.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodoIt *PNodoIt;
struct nodoIt {
  nat elem;
  PNodoIt sig;
};

struct repIterador {
  PNodoIt inicio, fin, actual;
  bool bloqueado;
};

/*
  Crea un 'TIterador' vacío (sin elementos) cuya posición actual no está
  definida.
  Se le puede agregar elementos.
  El tiempo de ejecución en el peor caso es O(1).
 */
TIterador crearIterador() {
  TIterador res = new repIterador;
  res->actual = res->inicio = res->fin = NULL;
  res->bloqueado = false;
  return res;
}

/*
  Agrega 'elem' al final de 'iter' si y solo si nunca se reinicio.
  Devuelve 'iter'.
  La posición actual sigue indefinida.
  El tiempo de ejecución en el peor caso es O(1).
 */
TIterador agregarAIterador(nat elem, TIterador iter) {
  assert(!(iter->bloqueado));
  PNodoIt nodo = new nodoIt;
  nodo->elem = elem;
  nodo->sig = NULL;
  if (iter->inicio == NULL){
    iter->inicio = nodo;
  } else {
      iter->final->siguiente = nodo;
    }
  iter->final = nodo;
  return iter;
}

/*
  Mueve la posición actual de 'iter' al primero si y solo si 'iter' tiene
  elementos.
  Devuelve 'iter'.
  No se podrán agregar más elementos (aunque no hubiera ninguno).
  El tiempo de ejecución en el peor caso es O(1).
 */
TIterador reiniciarIterador(TIterador iter) {
  assert(iter->inicio != NULL);
  iter->actual = iter->inicio;
  iter->bloqueado = true;
  return iter;
}

/*
  Avanza la posición actual de 'iter' hacia el siguiente si y solo si'
  estaDefinidaActual(iter).
  Devuelve 'iter'.
  Si la posición actual es la última posición entonces la posición actual
  queda indefinida.
  El tiempo de ejecución en el peor caso es O(1).
 */
TIterador avanzarIterador(TIterador iter) {
  assert(!estaDefinidaActual(iter));
  iter->actual = iter->actual->siguiente;
  return iter;
}

/*
  Devuelve el elemento de la posición actual de 'iter'.
  Precondición: estaDefinidaActual(iter).
  El tiempo de ejecución en el peor caso es O(1).
 */
nat actualEnIterador(TIterador iter) {
 return iter->actual->elem;
}

/*
  Devuelve 'true' si y solo si la posición actual de 'iter' está definida.
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaDefinidaActual(TIterador iter) {
 return iter->bloqueado;
}

/*
  Libera la memoria asignada a 'iter'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad
  de elementos de 'iter'.
 */
void liberarIterador(TIterador iter) {
  iter = reiniciarIterador(iter);
  while (iter->inicio == NULL){
    iter->inicio= iter->inicio->siguiente;
    delete iter->actual;
    iter->actual = iter->inicio;
  }
}
