/* 4862558 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/mapping.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodoMapping *TNodoMap;
struct nodoMapping {
  nat preimagen;
  double imagen;
  TNodoMap sig;
};

struct repMap {
  nodoMapping* array;
  nat tope;
  nat cota;
  nat cantidad;
};

static nat hashing(nat clave, nat cota):

static nat hashing(nat clave, nat cota){
  nat referencia = clave;
  if (clave>=cota){
    referencia = referencia%cota;
  }
  return referencia;
}



/*
  Crea un 'TMapping' vacío (sin elementos) de asociaciones nat -> double.
  Podrá haber hasta M asociaciones.
  El tiempo de ejecución en el peor caso es O(M).
 */
TMapping crearMap(nat M){
  TMapping map = new repMap;
  map->array = new nodoMapping[M];
  map->cota = M;
  for (int i=0; i<M; i++){
    map->array[i] = NULL;
  }
  map->tope = 0;
  map->cantidad = 0;
  return maps;
}

/*
  Inserta en 'map' la asociación entre 'clave' y 'valor'.
  Precondición: !estaLlenoMap(map) y !existeAsociacionEnMap(clave, map).
  Devuelve 'map'.
  El tiempo de ejecución en el peor caso es O(1).
 */
TMapping asociarEnMap(nat clave, double valor, TMapping map){
  assert((!estaLlenoMap(map)) && (existeAsociacionEnMap(clave, map)));
  nat referencia = hashing(clave, map->cota);
  TNodoMap nodo = new nodoMapping;
  nodo->preimagen = clave;
  nodo->imagen = valor;
  nodo->siguiente = map->array[referencia];
  map->array[referencia] = nodo;
  map->tope++;
  map->cantiddad++;
  return NULL;
}

/*
  Elimina de 'map' la asociación correspondiente a 'clave' y libera la
  menoria  asignada a mantener esa asociación.
  Precondición: existeAsociacionenMap(clave, h).
  Devuelve 'map'.
  El 'TMapping' resultado comparte memoria con el parámetro'.
  El tiempo de ejecución es O(1) en promedio.
 */
TMapping desasociarEnMap(nat clave, TMapping map){
  assert(existeAsociacionEnMap(clave, map));
  nat referencia = hashing(clave, map->cota);
  if (map->array[referencia]->siguiente == NULL){
    TNodoMap cursor = map->array[referencia];
    map->array[referencia] = NULL;
    delete cursor;
  } else if(map->array[referencia]->siguiente->preimagen == clave){
      TNodoMap cursor = map->array[referencia]->siguiente;
      map->array[referencia]->siguiente = cursor->siguiente;
      cursor->siguiente = NULL;
      delete cursor;
  } else {
      TNodoMap cursor1 = map->array[referencia];
      TNodoMap cursor2 = cursor1->siguiente;
      while (cursor2->preimagen != clave){
        cursor1 = cursor1->siguiente;
        cursor2 = cursor2->siguiente;
      }
      cursor1->siguiente = cursor2->siguiente;
      cursor2->siguiente = NULL;
      delete cursor2;
      cursor1 = NULL;
      delete cursor1;
  }
  return map;
}

/*
  Devuelve 'true' si y solo si en 'map' hay una asociación correspondiente
  a 'clave'.
  El tiempo de ejecución es O(1) en promedio.
 */
bool existeAsociacionEnMap(nat clave, TMapping map){
  bool resp = false;
  nat referencia = hashing(clave, map->cota)
  TNodoMap cursor = map->array[referencia];
  while ((cursor != NULL) && !resp) {
    resp = (cursor->preimagen == clave);
    cursor = cursor->siguiente;
  }
  delete cursor;
  return resp;
}

/*
  Devuelve el valor correspondiente a la asociacion de 'clave' en 'h'.
  Precondición: existeAsociacionenMap(clave, h).
  El tiempo de ejecución es O(1) en promedio.
 */
double valorEnMap(nat clave, TMapping map){
  assert(existeAsociacionEnMap(clave, map))
  nat referencia = hashing(clave, map->cota)
  TNodoMap cursor = map->array[referencia];
  while (cursor->preimagen != clave) {
    cursor = cursor->siguiente;
  }
  double resp = cursor->imagen;
  cursor = NULL;
  delete cursor;
  return resp;
}

/*
  Devuelve 'true' si y solo si 'map' tiene 'M' elementos, siendo 'M' el
  parámetro pasado en crearMap.
  El tiempo de ejecución es O(1).
 */
bool estaLlenoMap(TMapping map){
  return (map->cota == map->cantidad);
}

/*
  Libera la memoria asignada a 'map' y todos sus elementos.
  El tiempo de ejecución en el peor caso es O(M), siendo 'M' el parámetro
  pasado en crearMap.
 */
void liberarMap(TMapping map){
  for (int i=0; i<M; i++) {
    if(map->array[i]!=NULL){
      TNodoMap cursor = map->array[i];
      map->array[i] = NULL;
      while (cursor!=NULL){
        TNodoMap aux = cursor;
        cursor = cursor->siguiente;
        aux->siguiente = NULL;
        delete aux;
      }
    }
  }
}
