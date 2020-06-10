/* 4862558 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/pila.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct nodo *TNodoPila;
struct nodo {
  nat elem;
  TNodoPila siguiente;
};


struct repPila {
  nat limite;
  nat cantidad;
  TNodoPila cima;
};

/*
  Devuelve una 'TPila' vacía (sin elementos) que puede tener hasta 'tamanio'
  elementos.
  Precondición: tamanio > 0.
 */
TPila crearPila(nat tamanio){
  TPila resp = new repPila;
  resp->cima = NULL;
  resp->cantidad=0;
  resp->limite = tamanio;
  return resp;
}

/*
  Apila 'num' en 'p'.
  Devuelve 'p'.
  Si estaLlenaPila(p) no hace nada.
  El tiempo de ejecución en el peor caso es O(1).
 */
TPila apilar(nat num, TPila p){
  if (!estaLlenaPila(p)) {
    TNodoPila nuevo = new nodo;
    nuevo->elem = num:
    nuevo->siguiente = p->cima;
    p->cima = nuevo;
    p->cantidad = p->cantidad +1;
  }
  return p;
}

/*
  Remueve de 'p' el elemento que está en la cima.
  Devuelve 'p'.
  Si estaVaciaPila(p) no hace nada.
  El tiempo de ejecución en el peor caso es O(1).
 */
TPila desapilar(TPila p){
  if(!estaVaciaPila(p)){
    TNodoPila auxiliar = p->cima;
    p->cima = p->cima->siguiente;
    delete auxiliar;
    p->cantidad = p->cantidad -1;
  }
  return p;
}

/*
  Libera la memoria asignada a 'p'.
 */
void liberarPila(TPila p){
  while(!estaVaciaPila(p)){
    p = desapilar(p);
  }
}

/*
  Devuelve 'true' si y solo si 'p' es vacía (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVaciaPila(TPila p){
  return (p->cantidad == 0);
}

/*
  Devuelve 'true' si y solo si la cantidad de elementos en 'p' es 'tamanio'
  (siendo 'tamanio' el valor del parámetro con que fue creada 'p').
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaLlenaPila(TPila p){
  return (p->cantidad == p->limite);
}


/*
  Devuelve el elemento que está en la cima de 'p'.
  Precondición: ! estaVaciaPila(p);
  El tiempo de ejecución en el peor caso es O(1).
 */
nat cima(TPila p){
  assert(!estaVaciaPila(p));
  nat resp = p->cima->elem;
  return resp;
}
