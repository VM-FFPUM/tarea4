/* 4862558 */

#include "../include/binario.h"
#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



struct repBinario {
  TInfo dato;
  TBinario izq;
  TBinario der;
};


/*
  Devuelve un 'TBinario' vacío (sin elementos).
  El tiempo de ejecución es O(1).
  */
// COMPLETADO
TBinario crearBinario() {
  TBinario res = new repBinario;
  res = NULL;
  return res;
}


/* ____________________Auxiliar para insertarEnBinario____________________ */

static TBinario noVacio(TInfo info);

static TBinario noVacio(TInfo info) {
  TBinario res = new repBinario;
  res->izq = res->der = NULL;
  res->dato = info;
  return res;
}

/*
  Inserta 'i' en 'b' respetando la propiedad de orden definida.
  Devuelve 'b'.
  Precondición: esVacioBinario(buscarSubarbol(natInfo(i), b).
  El tiempo de ejecución es O(log n) en promedio, siendo 'n' la cantidad de
  elementos de 'b'.
*/
// COMPLETADO
TBinario insertarEnBinario(TInfo i, TBinario b) {
  assert(esVacioBinario(buscarSubarbol(natInfo(i), b)));

  // Si b es Vacio
  if (esVacioBinario(b)) {
    TBinario resp = noVacio(i);
    b = resp;
  } else {

      if(!esVacioBinario(izquierdo(b))) {
        if (((natInfo(b->dato)) > (natInfo(i))) && ((natInfo(i)) > (natInfo(b->izq->dato)))) {
        TBinario resp = noVacio(i);
        resp->izq = b->izq;
        b->izq = resp;
        } else {
            if (natInfo(b->dato) > natInfo(i)) {
              b->izq = insertarEnBinario(i, (izquierdo(b)));
            }
          }
      } else {
          if ((natInfo(b->dato)) > (natInfo(i))) {
            TBinario resp = noVacio(i);
            b->izq = resp;
          }
        }


      if  (!esVacioBinario(derecho(b))) {
        if (((natInfo(i) > natInfo(b->dato)) ) && ( natInfo(b->der->dato) > natInfo(i))) {
          TBinario resp = noVacio(i);
          resp->der = b->der;
          b->der = resp;
        } else {
            if (natInfo(i) > natInfo(b->dato) ) {
              b->der = insertarEnBinario(i, (derecho(b)));
            }
          }
      } else {
          if (natInfo(i) > natInfo(b->dato)) {
            TBinario resp = noVacio(i);
            b->der = resp;
          }
        }
    }
  return b;
}


/*
  Devuelve el elemento mayor (según la propiedad de orden definida) de 'b'.
  Precondición: ! esVacioBinario(b).
  El tiempo de ejecución es O(log n) en promedio, siendo 'n' la cantidad de
  elementos de 'b'.
*/
// COMPLETADO
TInfo mayor(TBinario b){
  TBinario cursor = crearBinario();
  cursor = b;
  while (derecho(cursor) != NULL) {
    cursor = derecho(cursor);
  }
  TInfo resp = copiaInfo(cursor->dato);
  cursor = NULL;
  delete cursor;
  return resp;
}



/* ____________________Auxiliar para removerMayor____________________ */

static TBinario binarioMayor(TBinario b);

static TBinario binarioMayor(TBinario b){
  TBinario cursor = crearBinario();
  cursor = b;
  while (derecho(cursor) != NULL) {
    cursor = derecho(cursor);
  }
  return cursor;
}


/*
  Remueve el nodo en el que se localiza el elemento mayor de 'b'
  (libera la memoria  asignada al nodo, pero no la del elemento).
  Devuelve 'b'.
  Precondición: ! esVacioBinario(b).
  El tiempo de ejecución es O(log n) en promedio, siendo 'n' la cantidad de
  elementos de 'b'.
 */
 // COMPLETADO
TBinario removerMayor(TBinario b) {
  TBinario cursor = binarioMayor(b);
  nat elem = natInfo(cursor->dato);
  b = removerDeBinario(elem, b);
  cursor = NULL;
  delete cursor;
  return b;
}


/*
  Remueve de 'b' el nodo en el que el componente natural de su elemento es
  'elem'.
  Si los dos subárboles del nodo a remover son no vacíos, en sustitución del
  elemento removido debe quedar el que es el mayor (segun la propiedad de orden
  definida) en el subárbol izquierdo.
  Devuelve 'b'.
  Precondición: !esVacioBinario(buscarSubarbol(elem, b).
  Libera la memoria del nodo y del elemento.
  El tiempo de ejecución es O(log n) en promedio, siendo 'n' la cantidad de
  elementos de 'b'.
 */
// COMPLETADO
TBinario removerDeBinario(nat elem, TBinario b)  {
  assert(!esVacioBinario(buscarSubarbol(elem, b)));
  TBinario cursor = buscarSubarbol(elem, b);

  if (((natInfo(cursor->dato)) == elem) && (esVacioBinario(izquierdo(cursor))) && (esVacioBinario(derecho(cursor)))) {
    liberarInfo(cursor->dato);
    cursor = NULL;
  }

  if (((natInfo(cursor->dato)) == elem) && (esVacioBinario(izquierdo(cursor))) && (!esVacioBinario(derecho(cursor)))) {
    TBinario aux = crearBinario();
    aux = cursor->der;
    cursor->der = NULL;
    liberarInfo(cursor->dato);
    cursor = aux;
    aux = NULL;
    delete aux;
  }

  if (((natInfo(cursor->dato)) == elem) && (!esVacioBinario(izquierdo(cursor))) && (esVacioBinario(derecho(cursor)))) {
    TBinario aux = crearBinario();
    aux = cursor->izq;
    cursor->izq = NULL;
    liberarInfo(cursor->dato);
    cursor = aux;
    aux = NULL;
    delete aux;
  }

  if (((natInfo(cursor->dato)) == elem) && (!esVacioBinario(izquierdo(cursor))) && (!esVacioBinario(derecho(cursor)))) {
    if (!esVacioBinario(derecho(izquierdo(cursor)))) {
      TBinario aux = crearBinario();
      aux = binarioMayor(izquierdo(cursor));
      TInfo info = aux->dato;
      cursor->dato = info;
      removerDeBinario(natInfo(info), binarioMayor(izquierdo(cursor)));
      aux = NULL;
      delete aux;
    } else {
        TBinario aux = crearBinario();
        aux = izquierdo(cursor);
        aux->der = cursor->der;
        cursor->der = NULL;
        liberarInfo(cursor->dato);
        cursor = aux;
        aux = NULL;
        delete aux;
      }
  }
  return b;
}


/*
  Libera la memoria asociada a 'b' y todos sus elementos.
  El tiempo de ejecución es O(n), siendo 'n' es la cantidad de elementos de 'b'.
 */
// COMPLETADO
void liberarBinario(TBinario b) {
   if(!esVacioBinario(b)){
     if(!esVacioBinario(derecho(b))) {
       liberarBinario(derecho(b));
     }
     if (!esVacioBinario(izquierdo(b))) {
       liberarBinario(derecho(b));
     }
     liberarInfo(b->dato);
     delete b;
   }
}


/*
  Devuelve 'true' si y solo si 'b' es vacío (no tiene elementos).
  El tiempo de ejecución es O(1).
 */
 // COMPLETADO
bool esVacioBinario(TBinario b) {
  return (b == NULL);
}


/*
  Devuelve 'true' si y solo si cada nodo de 'b' cumple la condición de balanceo
  AVL. El árbol vacío cumple la condición.
  Un nodo cumple la condición de balanceo AVL si el valor absoluto de la
  diferencia de las alturas de sus subárboles izquierdo y derecho en menor o
  igual a 1.
  Cada nodo se puede visitar una sola vez.
  El tiempo de ejecución es O(n), siendo 'n' la cantidad de elementos de 'b'.
 */
 // COMPLETADO
bool esAvl(TBinario b) {
  bool resp = 1;
  if (!esVacioBinario(b)){
    resp = ( (alturaBinario(izquierdo(b))-alturaBinario(derecho(b))==1) ||
    (alturaBinario(derecho(b))-alturaBinario(izquierdo(b))==1) ||
    (alturaBinario(izquierdo(b))-alturaBinario(derecho(b))==0) );
  }
  return resp;
}


/*
  Devuelve el elemento asociado a la raíz de 'b'.
  Precondición: ! esVacioBinario(b).
  El tiempo de ejecución es O(1).
 */
 // COMPLETADO
TInfo raiz(TBinario b) {
  assert(!esVacioBinario(b));
  return b->dato;
}


/*
  Devuelve el subárbol izquierdo de 'b'.
  Precondición: ! esVacioBinario(b).
  El tiempo de ejecución es O(1).
 */
 // COMPLETADO
TBinario izquierdo(TBinario b) {
  assert(!esVacioBinario(b));
  return b->izq;
}


/*
  Devuelve el subárbol derecho de 'b'.
  Precondición: ! esVacioBinario(b).
  El tiempo de ejecución es O(1).
 */
 // COMPLETADO
TBinario derecho(TBinario b) {
  assert(!esVacioBinario(b));
  return b->der;
}


/*
  Devuelve el subárbol que tiene como raíz al nodo con el elemento cuyo
  componente natural es 'elem'.
  Si 'elem' no pertenece a 'b', devuelve el árbol vacío.
  El tiempo de ejecución es O(log n) en promedio, siendo 'n' la cantidad de
  elementos de 'b'.
 */
// COMPLETADO
TBinario buscarSubarbol(nat elem, TBinario b) {
  if (!esVacioBinario(b)) {
    nat resp = natInfo(b->dato);
    if (elem > resp) {
      return buscarSubarbol(elem, derecho(b));
    }
    if (resp > elem) {
      return buscarSubarbol(elem, izquierdo(b));
    }
  }
  TBinario cursor = crearBinario();
  cursor = b;
  return cursor;
}


/*
  Devuelve la altura de 'b'.
  La altura de un árbol vacío es 0.
  El tiempo de ejecución es O(n), siendo 'n' la cantidad de elementos de 'b'.
 */
// COMPLETADO
nat alturaBinario(TBinario b) {
  nat altura = 0;
  if(!esVacioBinario(b)){
    if (alturaBinario(derecho(b))>alturaBinario(izquierdo(b))){
      altura = 1 + alturaBinario(derecho(b));
    } else {
      altura = 1 + alturaBinario(izquierdo(b));
    }
  }
  return altura;
}


/*
  Devuelve la cantidad de elementos de 'b'.
  El tiempo de ejecución es O(n), siendo 'n' la cantidad de elementos de 'b'.
 */
// COMPLETADO
nat cantidadBinario(TBinario b) {
  nat resp;

  if (esVacioBinario(b)) {
    resp = 0;
  }

  if (!esVacioBinario(b)) {
    resp = 1 + cantidadBinario(izquierdo(b)) + cantidadBinario(derecho(b));
  }

  return resp;
}


/*
  Devuelve la suma de los componentes reales de los últimos 'i' elementos
  (considerados según la propiedad de orden de los árboles TBinario)
  de 'b' cuyos componentes reales sean mayores que 0.
  Si en 'b' hay menos de 'i' elementos que cumplan esa condición devuelve la
  suma de los componenetes reales de ellos.
  No se deben crear estructuras auxiliares.
  No se deben visitar nuevos nodos después que se hayan encontrado los
  'i' elementos.
  El tiempo de ejecución es O(n), siendo 'n' la cantidad de elementos de 'b'.
 */
double sumaUltimosPositivos(nat i, TBinario b) {/*
  double suma[i];
  for (int n = 0; n<i; n++){
    suma[n] = 0;
  }
  if (!esVacioBinario(b)){
    TInfo mayor = mayor(b);
    nat elem = natInfo(mayor);
    TBinario cursor = buscarSubarbol(elem, b);
    nat stop1 = 0;
    nat stop2 = cantidadBinario(b) + 1;
    double real = 0;
    TInfo info;
    while ((stop1 <= i) && (stop2 !=0) && (elem != 0)){
      info = cursor->dato;
      real = realInfo(info);
      if (real>0){
        suma[stop1] = real;
        stop1 = stop1 + 1;
      }
      elem = elem - 1;
      cursor = buscarSubarbol(elem, b);
      while (esVacioBinario(cursor) || (elem !=0)){
        elem = elem - 1;
        cursor = buscarSubarbol(elem, b);
      }
      stop2 = stop2 - 1;
    }
  }
  double resp = 0;
  for (int n = 0; n<i; n++){
    resp = resp + suma[n];
  }
  return resp;
*/
  return 0.0;
}


/*
  Devuelve una 'TCadena' con los elementos de 'b' en orden creciente según
  sus componentes naturales.
  La 'TCadena' devuelta no comparte memoria con 'b'.
  El tiempo de ejecución es O(n), siendo 'n' la cantidad de elementos de 'b'.
 */
// COMPLETADO
TCadena linealizacion(TBinario b) {/*
  TCadena cad = crearCadena();
  TInfo info = copiaInfo(menor(b));
  insertarAlFinal(info, cad);
  nat elem = natInfo(info);
  TBinario cursor = buscarSubarbol(elem, b);
  while (elem <= natInfo(mayor(b))){
    elem = elem + 1;
    cursor = buscarSubarbol(elem, b);
    if (cursor != NULL){
      TInfo info = copiaInfo(cursor->dato);
      insertarAlFinal(info, cad);
    }
  }
 return cad; */
 return NULL;
}



/*
  Devuelve un árbol con copias de los elementos de 'b' que cumplen la condición
  "realInfo(elemento) < cota".
  La estructura del árbol resultado debe ser análoga a la de 'b'. Esto
  significa que dados dos nodos 'U' y 'V' de 'b' en los que se cumple la
  condición y tal que 'U' es ancestro de 'V', en el árbol resultado la copia de
  'U' debe ser ancestro de la copia de 'V' cuando sea posible. Esto no siempre
  se puede lograr y al mismo tiempo mantener la propiedad de orden del árbol
  en el caso en el que en un nodo 'V' no se cumple la condición y en sus dos
  subárboles hay nodos en los que se cumple. En este caso, la copia del nodo
  cuyo elemento es el mayor (según la propiedad de orden definida) de los que
  cumplen la condición en el subárbol izquierdo de 'V' deberá ser ancestro de
  las copias de todos los descendientes de 'V' que cumplen la condición.
  Ver ejemplos en la letra.
  El árbol resultado no comparte memoria con 'b'.
  El tiempo de ejecución es O(n), siendo 'n' es la cantidad de elementos de 'b'.
 */
TBinario menores(double cota, TBinario b) {
  /*
  TBinario resp = copia(b);
  if(!esVacioBinario(b)){
    TBinario cursor = menor(b);
    nat cant = 0;
    double marca;
    while ((cursor != mayor(b)) || (cant != cantidadBinario(b) + 1) || (cant = 0){
      marca = realInfo(cursor->dato);
      if (marca >= cota ){
        cursor = buscarSubarbol(siguienteNat(cursor),b);
        removerDeBinario(nat)
      }
    }
  }
  */
 return NULL;
}



/*
  Imprime los elementos de 'b', uno por línea, en orden descendente de la
  propiedad de orden de los árboles 'TBinario'.
  Antes del elemento imprime una cantidad de guiones igual a su profundidad.
  El elemento se imprime según la especificación dada en 'infoATexto'.
  La profundidad de la raíz es 0.
  Antes del primer elemento, se debe imprimir un fin de linea.
  Si esVacioBinario(b) solo se imprime el fin de línea.
  El tiempo de ejecución es O(n . log n) en promedio, siendo 'n' la cantidad
  de elementos de 'b'.
 */

void imprimirBinario(TBinario b) {/*

  TBinario copy = copia(b);
  TBinario mayor = crearBinario();
  TBinario centinela = crearBinario();
  if (!esVacioBinario(copy)){
      centinela = izquierdo(copy);
  } else {
      centinela = NULL;
  }
  printf("\n");
  while ((centinela != NULL) && (cantidadBinario(copy) != 0)) {
      mayor = binarioMayor(copy);
      for (nat n = 0; n == nivel(mayor, copy); ) {
          printf("-");
      }
      printf("(%u,%.2lf)",natInfo(mayor->dato),realInfo(mayor->dato));
      copy = removerMayor(copy);
      if (!esVacioBinario(copy)){
          centinela = izquierdo(copy);
      } else {
          centinela = NULL;
      }
      printf("\n");
  }
  delete centinela;
  delete copy;
  mayor = NULL;
  delete mayor;
  */
}




/*
_____________________Fuciones auxiliares_____________________





static TBinario binarioMenor(TBinario b);

static TBinario binarioMenor(TBinario b){
  TBinario cursor = crearBinario();
  cursor = b;
  while (izquierdo(cursor) != NULL) {
    cursor = izquierdo(cursor);
  }
  return cursor;
}


static TInfo menor(TBinario b);

static TInfo menor(TBinario b){
  TBinario cursor = crearBinario();
  cursor = b;
  while (izquierdo(cursor) != NULL) {
    cursor = izquierdo(cursor);
  }
  TInfo resp = copiaInfo(cursor->dato);
  cursor = NULL;
  delete cursor;
  return resp;
}

static nat siguienteNat(nat elem, TBinario b);

static nat siguienteNat(elem, b){
  assert(!esVacioBinario(buscarSubarbol(elem, b)));
  TInfo raiz = raiz(b);
  nat resp = natInfo(raiz);
  TBinario cursor;
  if (elem == resp) {
    cursor = derecho(buscarSubarbol(elem, b));
    resp = natInfo(cursor->dato);
  } else if (elem < resp) {
    while ((izquierdo(cursor) != buscarSubarbol(elem, b)) && (elem < resp)) {
      cursor = izquierdo(cursor);
      resp = natInfo(cursor->dato);
    }
    while (elem > resp) {


    cursor = izquierdo(buscarSubarbol(resp, b))
    while
    while (cursor != )

  } else if (elem > resp) {
      cursor = derecho(buscarSubarbol(resp, b));
      while(!esVacioBinario(izquierdo(cursor))) {
        cursor = izquierdo(cursor);
      }
      nat resp = natInfo(cursor->dato);
    }
  }
  return resp;
}



static TBinario anteriorBinario(TBinario principal, TBinario subarbol);

static TBinario anteriorBinario(TBinario principal, TBinario subarbol) {
    assert(!esVacioBinario(buscarSubarbol(natInfo(subarbol->dato), principal)));
    TBinario cursor = crearBinario();
    cursor = principal;
    TInfo infoSub = subarbol->dato;
    nat natSub = natInfo(infoSub);
    TInfo infoCursor = cursor->dato;
    nat natCursor = natInfo(infoCursor);

    if (natCursor > natSub) {
      if {
        infoResp = aux->dato;
      }
    }

    while (natInfo(subarbol->dato) > natInfo(infoResp)  ||  (aux == NULL)) {
      resp = aux;
      aux = aux->izq;
      if (aux != NULL) {
        infoResp = aux->dato;
      }
    }

    aux = NULL;
    delete aux;
    return resp;
}



static nat nivel(TBinario subarbol, TBinario principal);

static nat nivel(TBinario subarbol, TBinario principal){
  assert(!esVacioBinario(buscarSubarbol(natInfo(subarbol->dato), principal)));
  nat resp = 0;
  if (natInfo(subarbol->dato) > natInfo(principal->dato)) {
    resp = 1 + nivel(derecho(principal), principal);
  }

  if (natInfo(principal->dato) > natInfo(subarbol->dato)) {
    resp = 1 + nivel(izquierdo(principal), principal);
  }
  return resp;
}

static TBinario copia(TBinario b);

static TBinario copia(TBinario b) {

  TBinario copy;

  if (esVacioBinario(b)) {
    copy = crearBinario();
  }

  if ((!esVacioBinario(b)) && (esVacioBinario(izquierdo(b))) && (esVacioBinario(derecho(b)))) {
    copy = noVacio(b->dato);
    copy->izq = copy->der = NULL;
  }

  if ((!esVacioBinario(b)) && (!esVacioBinario(izquierdo(b))) && (esVacioBinario(derecho(b)))) {
    copy = noVacio(b->dato);
    copy->izq = copia(izquierdo(b));
    copy->der = NULL;
  }

  if ((!esVacioBinario(b)) && (esVacioBinario(izquierdo(b))) && (!esVacioBinario(derecho(b)))) {
    copy = noVacio(b->dato);
    copy->der = copia(derecho(b));
    copy->izq = NULL;
  }

  if ((!esVacioBinario(b)) && (!esVacioBinario(izquierdo(b))) && (!esVacioBinario(derecho(b)))) {
    copy = noVacio(b->dato);
    copy->izq = copia(izquierdo(b));
    copy->der = copia(derecho(b));
  }

  return copy;
}


static TBinario removerMayor2(TBinario b);

static TBinario removerMayor2(TBinario b) {
  TBinario cursor = binarioMayor(b);
  nat elem = natInfo(cursor->dato);
  b = removerDeBinario(elem, b);
  cursor = NULL;
  delete cursor;
  return b;
}


static TBinario removerDeBinario2(nat elem, TBinario b);

static TBinario removerDeBinario2(nat elem, TBinario b) {
  assert(!esVacioBinario(buscarSubarbol(elem, b)));
  TBinario cursor = buscarSubarbol(elem, b);

  if (((natInfo(cursor->dato)) == elem) && (esVacioBinario(izquierdo(cursor))) && (esVacioBinario(derecho(cursor)))) {
    liberarInfo(cursor->dato);
    cursor = NULL;
  }

  if (((natInfo(cursor->dato)) == elem) && (esVacioBinario(izquierdo(cursor))) && (!esVacioBinario(derecho(cursor)))) {
    TBinario aux = crearBinario();
    aux = cursor->der;
    cursor->der = NULL;
    liberarInfo(cursor->dato);
    cursor = aux;
    aux = NULL;
    delete aux;
  }

  if (((natInfo(cursor->dato)) == elem) && (!esVacioBinario(izquierdo(cursor))) && (esVacioBinario(derecho(cursor)))) {
    TBinario aux = crearBinario();
    aux = cursor->izq;
    cursor->izq = NULL;
    liberarInfo(cursor->dato);
    cursor = aux;
    aux = NULL;
    delete aux;
  }

  if (((natInfo(cursor->dato)) == elem) && (!esVacioBinario(izquierdo(cursor))) && (!esVacioBinario(derecho(cursor)))) {
    if (!esVacioBinario(derecho(izquierdo(cursor)))) {
      TBinario aux = crearBinario();
      aux = binarioMayor(izquierdo(cursor));
      TInfo info = aux->dato;
      cursor->dato = info;
      removerDeBinario(natInfo(info), binarioMayor(izquierdo(cursor)));
      aux = NULL;
      delete aux;
    } else {
        TBinario aux = crearBinario();
        aux = izquierdo(cursor);
        aux->der = cursor->der;
        cursor->der = NULL;
        liberarInfo(cursor->dato);
        cursor = aux;
        aux = NULL;
        delete aux;
      }
  }
  return b;
}
*/
