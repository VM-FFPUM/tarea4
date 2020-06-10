/* 4862558 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/colaDePrioridad.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodoCP *TNodoCP;
struct nodoCP {
  TNodoCP siguiente, anterior;
  nat elem;
  double prioridad;
};

struct repCP {
  TColaDePrioridad inicio, final;
  nat cota;
};

/*
  Devuelve una 'TColaDePrioridad' vacía (sin elementos). Podrá contener
  elementos entre 1 y N.
  El tiempo de ejecución en el peor caso es O(N).
 */
TColaDePrioridad crearCP(nat N){
  return NULL;
}

/*
  Devuelve el valor máximo que puede tener un elemento de 'cp', que es el
  parámetro de crearCP.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat rangoCP(TColaDePrioridad cp){
  return 0;
}

/*
  Inserta 'elem' en 'cp'. La prioridad asociada a 'elem' es 'valor'.
  Precondición 1 <= elem <= rangoCP(cp).
  Precondición: !estaEnCp(elem, cp).
  Devuelve 'cp'.
  El tiempo de ejecución en el peor caso es O(log N), siendo 'N' el parámetro
  pasado en crearCP.
 */
TColaDePrioridad insertarEnCP(nat elem, double valor, TColaDePrioridad cp){
  return NULL;
}

/*
  Devuelve 'true' si y solo si en 'cp' no hay elementos.
  El tiempo de ejecución en el peor casos es O(1).
 */
bool estaVaciaCP(TColaDePrioridad cp){
  return 0;
}

/*
  Devuelve el elemento prioritario de 'cp'.
  Precondición: !estaVacioCP(cp).
  El tiempo de ejecución en el peor casos es O(1).
 */
nat prioritario(TColaDePrioridad cp){
  return 0;
}

/*
  Elimina de 'cp' el elemento prioritario.
  Precondición: !estaVacioCP(cp).
  Devuelve 'cp'.
  El tiempo de ejecución en el peor caso es O(log N), siendo 'N' el parámetro
  pasado en crearCP.
 */
TColaDePrioridad eliminarPrioritario(TColaDePrioridad cp){
  return NULL;
}

/*
  Devuelve 'true' si y solo si 'elem' es un elemento de 'cp'.
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaEnCP(nat elem, TColaDePrioridad cp){
  return 0;
}

/*
  Devuelve el valor de prioridad asociado a 'elem'.
  Precondición: estaEnCp(elem, cp).
  El tiempo de ejecución en el peor caso es O(1).
 */
double prioridad(nat elem, TColaDePrioridad cp){
  return 0.0;
}

/*
  Modifica el valor de la propiedad asociada a 'elem'; pasa a ser 'valor'.
  Precondición: estaEnCp(elem, cp).
  Devuelve 'cp'.
  El tiempo de ejecución en el peor caso es O(log N), siendo 'N' el parámetro
  pasado en crearCP.
 */
TColaDePrioridad actualizarEnCP(nat elem, double valor, TColaDePrioridad cp){
  return NULL;
}

/*
  Libera la menoria asignada a 'cp'.
  El tiempo de ejecución en el peor caso es O(N), siendo 'N' el parámetro
  pasado en crearCP.
 */
void liberarCP(TColaDePrioridad cp){}
