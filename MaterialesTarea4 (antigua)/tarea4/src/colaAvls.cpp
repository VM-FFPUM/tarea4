/* 4862558 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/colaAvls.h"
#include "../include/avl.h"


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct nodo *TNodoColaAvls;
struct nodo {
  TAvl arbol;
  Nodo siguiente, anterior;
};

struct repColaAvls {
  TNodoColaAvls inicio, final;
};

/*
  Devuelve una 'TColaAvls' vacía (sin elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
TColaAvls crearColaAvls(){
  TColaAvls resp = new repColaAvls;
  resp->inicio = resp->final = NULL;
  return ;
}

/*
  Encola 'avl' en 'c'.
  Devuelve 'c'.
  El tiempo de ejecución en el peor caso es O(1).
 */
TColaAvls encolar(TAvl avl, TColaAvls c){
  TNodoColaAvls nuevo_nodo = new nodo;
  nuevo_nodo->arbol = avl;
  if (estaVaciaColaAvls(c)){
    nuevo_nodo->siguiente = nuevo_nodo->anterior = NULL;
    c->inicio = c->final = nuevo_nodo;
  } else {
      nuevo_nodo->siguiente = c->final;
      nuevo_nodo->anterior = NULL;
      c->final->anterior = nuevo_nodo;
      c->final = nuevo_nodo
  }
  return c;
}

/*
  Remueve de 'c' el elemento que está en el frente.
  Si estaVaciaColaAvls(c) no hace nada.
  Devuelve 'c'.
  NO libera la memoria del elemento removido.
  El tiempo de ejecución en el peor caso es O(1).
 */
TColaAvls desencolar(TColaAvls c){
  if(!estaVaciaColaAvls(c)){
    c->inicio = c->inicio->anterior;
    TNodoColaAvls aux = c->inicio->siguiente;
    c->inicio->siguiente = NULL;
    delete aux;
  }
  return c;
}

/*
  Libera la memoria asignada a 'c', pero NO la de sus elementos.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad
  de elementos de 'c'.
 */
void liberarColaAvls(TColaAvls c){
  while(estaVaciaColaAvls(c)){
    c = desencolar(c);
  }
}

/*
  Devuelve 'true' si y solo si 'c' es vacía (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVaciaColaAvls(TColaAvls c){
  return ((c->inicio == NULL) && (c->final == NULL));
}

/*
  Devuelve el elemento que está en el frente de 'c'.
  Precondición: ! estaVaciaColaAvls(c);
  El tiempo de ejecución en el peor caso es O(1).
 */
TAvl frente(TColaAvls c){
  return (c->inicio->arbol);
}
