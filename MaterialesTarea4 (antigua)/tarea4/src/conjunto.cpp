/* 4862558 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/conjunto.h"
#include "../include/avl.h"


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct repConjunto {
  TAvl conjunto;
};


/*
  Devuelve un 'TConjunto' vacío (sin elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
TConjunto crearConjunto(){
  TConjunto set = new repConjunto;
  set = NULL;
  return set;
}



/*
  Devuelve un 'TConjunto' cuyo único elemento es 'elem'.
  El tiempo de ejecución en el peor caso es O(1).
 */
TConjunto singleton(nat elem){
  TConjunto res = new repConjunto;
  res->izq = res->der = NULL;
  res->dato = elem;
  res->altura = 1;
  res->cantidad = 1;
  return res;
}


/* ____________________Auxiliar para siguientes funciones____________________ */

static TConjunto insertarEnConjunto(TConjunto c, nat elem);

static TConjunto insertarEnConjunto(TConjunto c, nat elem){
  return NULL;
}





/*
  Devuelve un 'TConjunto' con los elementos que pertenecen a 'c1' o 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n),
  siendo  'n' la cantidad de elementos del 'TConjunto' resultado.
 */
TConjunto unionDeConjuntos(TConjunto c1, TConjunto c2){
  TConjunto resp = crearAvl();


}

/*
  Devuelve un 'TConjunto' con los elementos de 'c1' que no pertenecen a 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n1 + n2),
  siendo 'n1' y 'n2' la cantidad de elementos de 'c1' y 'c2' respectivamente y
  'n' la del 'TConjunto' resultado.
 */
TConjunto diferenciaDeConjuntos(TConjunto c1, TConjunto c2){

}

/*
  Devuelve 'true' si y solo si 'elem' es un elemento de 'c'.
  El tiempo de ejecución en el peor caso es O(log n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
bool perteneceAConjunto(nat elem, TConjunto c){

}

/*
  Devuelve 'true' si y solo si 'c' es vacío (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVacioConjunto(TConjunto c){
  return (c == NULL);
}

/*
  Devuelve la cantidad de elementos de 'c'.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat cardinalidad(TConjunto c){
  return c->cantidad;
}

/*
  Devuelve un 'TConjunto' con los 'n' elementos que están en en el rango
  [0 .. n - 1] del arreglo 'elems'.
  Precondiciones:
  - n > 0
  - Los elementos están ordenados de manera creciente estricto
  (creciente y sin repetidos).
  El tiempo de ejecución en el peor caso es O(n).
 */
TConjunto arregloAConjunto(nat *elems, nat n){

}

/*
  Devuelve un 'TIterador' de los elementos de 'c'.
  En la recorrida del iterador devuelto los elementos aparecerán en orden
  creciente.
  El 'TIterador' resultado no comparte memoria con 'c'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
TIterador iteradorDeConjunto(TConjunto c){

}

/*
  Libera la memoria asignada a 'c' y la de todos sus elementos.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
void liberarConjunto(TConjunto c){

}
