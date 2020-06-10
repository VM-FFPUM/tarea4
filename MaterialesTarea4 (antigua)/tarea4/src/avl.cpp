/* 4862558 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/avl.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct repAvl {
  nat dato;
  nat altura;
  nat cantidad;
  TAvl izq, der;
};

/*
  Devuelve un 'TAvl' vacío (sin elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */

// COMPLETADO
TAvl crearAvl() {
  TAvl avl = new repAvl;
  avl = NULL;
  return avl;
}

/*
  Devuelve 'true' si y solo si 'avl' es vacío (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
// COMPLETADO
bool estaVacioAvl(TAvl avl) {
  return avl==NULL;
}


/* ____________________Auxiliar para insertarEnAvl____________________ */

static void rotarDerecha (TAvl avl);

static void rotarDerecha (TAvl avl){
  TAvl y = avl->izq;
  TAvl x = y->der;

  y->der = avl;
  a->izq = x;

  a->altura = max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der)) +1;
  y->altura = max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der)) +1;

  a = y;
}

static void rotarIzquierda (TAvl avl);

static void rotarIzquierda (TAvl avl){
  TAvl y = avl->der;
  TAvl x = y->izq;

  y->izq = avl;
  a->der = x;

  a->altura = max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der)) +1;
  y->altura = max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der)) +1;

  a = y;
}


/*
  Inserta 'elem' en 'avl' respetando la propiedad de orden definida.
  Precondición: esVacioAvl(buscarEnAvl(elem, TAvl).
  Devuelve 'avl'.
  El tiempo de ejecución en el peor caso es O(log n), siendo 'n' la cantidad
  de elementos de 'avl'.
*/
// COMPLETADO
TAvl insertarEnAvl(nat elem, TAvl avl){
  if (avl == NULL){
    avl = new repAvl;
    avl->dato = elem;
    avl->izq = avl->der = NULL;
    avl->altura = 1;
    avl->cantidad = 1;
  } else {
      if (x < avl->dato){
        avl = insertarEnAvl (x, avl->izq);
        avl->cantidad = avl->cantidad +1;
        a->altura = max(alturaDeAvl(a->izq, alturaDeAvl(avl->der))) + 1;

        int fb = alturaDeAvl(avl->izq) - alturaDeAvl(a->der);
        if (fb > 1) {
          if (alturaDeAvl(avl->izq->izq) > alturaDeAvl(avl->izq>der)){
            rotarDerecha(avl);
          } else {
            rotarIzquierda(avl->izq);
            rotarDerecha(avl);
          }
        }
      } else {
        avl = insertarEnAvl (x, avl->der);
        avl->cantidad = avl->cantidad +1;
        avl->altura = max(alturaDeAvl(a->izq, alturaDeAvl(avl->der))) + 1;

        int fb = alturaDeAvl(avl->izq) - alturaDeAvl(avl->der);

        if (fb < -1) {
          if (alturaDeAvl(avl->der->der) > alturaDeAvl(avl->der->izq)){
            rotarIzquierda(avl);
          } else {
            rotarDerecha(avl->der);
            rotarIzquierda(avl);
          }
        }
      }
    }
  return avl;
}



// __________________________buscarEnAvl__________________________

/*
  Devuelve el subárbol cuya raíz es 'elem'.
  Si ningún nodo cumple esa condición devuelve el árbol vacío.
  El 'TAvl' resultado comparte memoria con el parámetro.
  El tiempo de ejecución en el peor caso es O(log n), siendo 'n' la cantidad
  de elementos de 'avl'.
 */
TAvl buscarEnAvl(nat elem, TAvl avl) {
  if (!estaVacioAvl(avl)) {
    nat resp = avl->dato;
    if (elem > resp) {
      return buscarEnAvl(elem, derecho(avl));
    }
    if (resp > elem) {
      return buscarEnAvl(elem, izquierdo(b));
    }
  }
  TAvl cursor = crearAvl();
  cursor = b;
  return cursor;
}



// __________________________raizAvl__________________________

/*
  Devuelve el elemento asociado a la raíz de 'avl'.
  Precondición: ! esVacioAvl(b).
  El tiempo de ejecución en el peor caso es O(1).
 */
nat raizAvl(TAvl avl) {
  assert(!estaVacioAvl(avl));
  return avl->dato;
}


// __________________________izqEnAvl__________________________

/*
  Devuelve el subárbol izquierdo de 'avl'.
  Precondición: ! esVacioAvl(TAvl).
  El 'TAvl' resultado comparte memoria con el parámetro.
  El tiempo de ejecución en el peor caso es O(1).
 */
TAvl izqAvl(TAvl avl) {
  assert(!estaVacioAvlrio(avl));
  return avl->izq;
}

// __________________________derEnAvl__________________________


/*
  Devuelve el subárbol derecho de 'avl'.
  Precondición: ! esVacioAvl(TAvl).
  El 'TAvl' resultado comparte memoria con el parámetro.
  El tiempo de ejecución en el peor caso es O(1).
 */
TAvl derAvl(TAvl avl) {
  assert(!estaVacioAvlrio(avl));
  return avl->der;
}


// __________________________cantidadEnAvl__________________________

/*
  Devuelve la cantidad de elementos en 'avl'.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat cantidadEnAvl(TAvl avl) {
  nat cant = 0;
  if (!esVacioAvl(avl)){
    cant = avl->cantidad;
  }
  return cant;
}


// __________________________alturaDeAvl__________________________

/*
  Devuelve la altura de 'avl'.
  La altura de un árbol vacío es 0.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat alturaDeAvl(TAvl avl){
  nat alt = 0;
  if (!esVacioAvl(avl)){
    alt = avl->altura;
  }
  return alt;
}


// ___________________________enOrdenAvl__________________________

/*
  Devuelve un 'TIterador' de los elementos de 'c'.
  En la recorrida del iterador devuelto los elementos aparecerán en orden
  creciente.
  El 'TIterador' resultado no comparte memoria con 'avl'.
  El tiempo de ejecución en el peor caso es O(n) siendo 'n' la cantidad de
  elementos de 'avl'.
 */
TIterador enOrdenAvl(TAvl avl){
  TIterador resp = crearIterador();


  return NULL;
}

// __________________________arregloAAvl__________________________


/*
  Devuelve un 'TAvl' con los 'n' elementos que están en el rango [0 .. n - 1]
  del arreglo 'elems'.
  Precondiciones:
  - n > 0
  - Los elementos están ordenados de manera creciente estricto
  (creciente y sin  repetidos).
  En cada nodo del árbol resultado la cantidad de elementos de su subárbol
  izquierdo es igual a, o 1 menos que, la cantidad de elementos de su subárbol
  derecho.
  El tiempo de ejecución en el peor caso es O(n).
 */
TAvl arregloAAvl(nat *elems, nat n){
  return NULL;
}

// __________________________avlMin__________________________


/*
  Devuelve un 'TAvl' de altura 'h' con 'n' nodos, siendo 'n' la mínima cantidad
  de elementos que puede tener un 'TAvl' de altura 'h'.
  Los elementos van desde 1 hasta 'n'.
  En ningún nodo puede ocurrir que el subárbol derecho tenga más nodos que el
  subárbol izquierdo.
  La altura de un árbol vacío es 0.
  El tiempo de ejecución en el peor caso es O(n).
  Ver ejemplos en la letra.
 */
TAvl avlMin(nat h){
  return NULL;
}

// __________________________imprimirAvl__________________________

/*
  Imprime los elementos de cada nivel de 'avl'.
  Imprime una línea por nivel, primero el más profundo y al final el que
  corresponde a la raíz.
  Cada nivel se imprime en orden creciente. Se debe dejar un espacio en
  blanco después de cada número.
  Se puede asumir que 0 no es ningún elemento.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'TAvl'.
  Ver ejemplos en la letra.
 */
void imprimirAvl(TAvl avl){
}

/*
  Libera la memoria asignada a 'TAvl'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'TAvl'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad
  de elementos de 'avl'.
 */
//COMPLETADO
void liberarAvl(TAvl avl) {
  if (avl != NULL) {
    liberarAvl(avl->izq);
    liberarAvl(avl->der);
    delete avl;
  }
}
