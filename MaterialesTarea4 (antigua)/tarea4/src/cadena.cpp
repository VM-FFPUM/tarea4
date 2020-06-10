/*4.862.558-1*/

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct nodo {
  TInfo dato;
  TLocalizador anterior;
  TLocalizador siguiente;
};

struct repCadena {
  TLocalizador inicio;
  TLocalizador final;
};




/*
  Devuelve 'true' si y solo si 'loc' es un 'TLocalizador' válido.
  En cadenas enlazadas un 'TLocalizador' es válido si y solo si no es 'NULL'.
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
bool esLocalizador(TLocalizador loc) { return (loc != NULL); }

/*
  Devuelve la 'TCadena' vacía (sin elementos).
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
TCadena crearCadena() {
  TCadena res = new repCadena;
  res->inicio = res->final = NULL;
  return res;
}


/*
  Libera la memoria asignada a 'cad' y la de todos sus elementos.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
  COMPLETADO/REVISADO
*/
void liberarCadena(TCadena cad) {
  TLocalizador a_borrar;
  while (cad->inicio != NULL) {
    a_borrar = cad->inicio;
    cad->inicio = cad->inicio->siguiente;
    liberarInfo(a_borrar->dato);
    delete a_borrar;
  }
  delete cad;
}

/*
  Devuelve 'true' si y solo si 'cad' es vacía (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
bool esVaciaCadena(TCadena cad) {
  assert(((cad->inicio == NULL) && (cad->final == NULL)) || ((cad->inicio !=NULL) && (cad->final != NULL)) );
  return ((cad->inicio == NULL) /* && (cad->final == NULL)*/);
}

/*
  Devuelve el 'TLocalizador' con el que se accede al inicio de 'cad'.
  Si esVaciaCadena(cad) devuelve un 'TLocalizador' no válido.
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
TLocalizador inicioCadena(TCadena cad) {
  TLocalizador res;
  if (esVaciaCadena(cad)) {
    res = NULL;
  } else {
    res = cad->inicio;
  }
  return res;
}

/*
  Devuelve el 'TLocalizador' con el que se accede al final de 'cad'.
  Si es_vacia_cadena(cad) devuelve un 'TLocalizador' no válido.
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
TLocalizador finalCadena(TCadena cad) {
  TLocalizador res;
  if (esVaciaCadena(cad)) {
    res = NULL;
  } else {
    res = cad->final;
  }
  return res;
}

/*
  Devuelve el elemento de 'cad' al que se accede con 'loc'.
  Precondición: localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
TInfo infoCadena(TLocalizador loc, TCadena cad) {
  assert(localizadorEnCadena(loc, cad));
  return (loc->dato);
}

/*
  Devuelve el 'TLocalizador' con el que se accede al elemento de 'cad'
  inmediatamente siguiente a 'loc'.
  Si esFinalCadena(loc, cad) devuelve un 'TLocalizador' no válido.
  Precondición: localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
 */
TLocalizador siguiente(TLocalizador loc, TCadena cad) {
  assert(localizadorEnCadena(loc, cad));
  TLocalizador res;
  if (esFinalCadena(loc,cad)) {
    res = NULL;
  } else {
    res = loc->siguiente;
  }
  return res;
}

/*
  Devuelve el 'TLocalizador' con el que se accede al elemento de 'cad'
  inmediatamente anterior a 'loc'.
  Si esInicioCadena(loc, cad) devuelve un 'TLocalizador' no válido.
  Precondición: localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
TLocalizador anterior(TLocalizador loc, TCadena cad) {
  assert(localizadorEnCadena(loc, cad));
  TLocalizador res;
  if (esInicioCadena(loc,cad)) {
    res = NULL;
  } else {
    res = loc->anterior;
  }
  return res;
}

/*
  Devuelve 'true' si y solo si con 'loc' se accede al último elemento de 'cad'.
  Si esVaciaCadena (cad) devuelve 'false'.
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
 */
bool esFinalCadena(TLocalizador loc, TCadena cad) {
  bool prueba;
  if (esVaciaCadena(cad)) {
    prueba = false;
  } else {
      prueba = (loc == finalCadena(cad));
  }
  return prueba;
}

/*
  Devuelve 'true' si y solo si con 'loc' se accede al primer elemento de 'cad'.
  Si esVaciaCadena (cad) devuelve 'false'.
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
 */
bool esInicioCadena(TLocalizador loc, TCadena cad) {
  bool prueba;
  if (esVaciaCadena(cad)) {
    prueba = false;
  } else {
      prueba = (loc == inicioCadena(cad));
  }
  return prueba;
}

/*
  Se inserta 'i' como último elemento de 'cad'.
  Devuelve 'cad'.
  Si esVaciaVadena (cad) 'i' se inserta como único elemento de 'cad'.
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
*/
TCadena insertarAlFinal(TInfo i, TCadena cad) {
  TLocalizador res = new nodo;
  if (esVaciaCadena(cad)) {
    cad->inicio = cad->final = res;
    res->anterior = res->siguiente = NULL;
    cad->final->dato = i;
  } else {
      res->siguiente = NULL;
      res->anterior = cad->final;
      cad->final->siguiente=res;
      cad->final = res;
      cad->final->dato = i;
    }
  return cad;
}

/*
  Se inserta 'i' como un nuevo elemento inmediatamente antes de 'loc'.
  Devuelve 'cad'.
  Precondición: localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(1).
  COMPLETADO/REVISADO
 */
TCadena insertarAntes(TInfo i, TLocalizador loc, TCadena cad) {
  assert(localizadorEnCadena(loc, cad));
  TLocalizador res = new nodo;
  res->dato = i;
  res->siguiente = loc;
  if (loc == inicioCadena(cad)) {
    res->anterior=NULL;
    cad->inicio = res;
  } else {
    res->anterior = loc->anterior;
    loc->anterior->siguiente = res;
  }
  loc->anterior=res;
  return cad;
}

/*
  Se remueve el elemento al que se accede desde 'loc' y se libera la memoria
  asignada al mismo y al nodo apuntado por el localizador.
  Devuelve 'cad'.
  El valor de 'loc' queda indeterminado.
  Precondición: localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(1).
 */
TCadena removerDeCadena(TLocalizador loc, TCadena cad) {
  assert(localizadorEnCadena(loc, cad));
  if ((loc==inicioCadena(cad)) && (loc!=finalCadena(cad))) {
    loc->siguiente->anterior = NULL;
    cad->inicio = loc->siguiente;
  } else {
    if (loc==finalCadena(cad) && (loc!=inicioCadena(cad))) {
      loc->anterior->siguiente = NULL;
      cad->final=loc->anterior;
    } else{
      if((loc==inicioCadena(cad)) && (loc==finalCadena(cad))) {
        cad->inicio = cad->final = NULL;
      } else{
        loc->anterior->siguiente = loc->siguiente;
        loc->siguiente->anterior=loc->anterior;
        }
      }
    }
  liberarInfo(loc->dato);
  delete loc;
  return cad;
}

/*
  Imprime los elementos de 'cad' de la siguiente forma:
  (n de pos1,r de pos1)(n de pos2,r de pos2) ...
  donce 'n` es el componente natural y 'r' es el componente real.
  Antes de terminar, se debe imprimir un fin de linea.
  Si esVaciaCadena(cad) sólo se imprime el fin de línea.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
 */
 void imprimirCadena(TCadena cad) {
   TLocalizador loc = new nodo;
   loc = cad->inicio;
   while ((cad->inicio != cad->final) && (!esVaciaCadena(cad))) {
     printf("(%u,%.2lf)",natInfo(cad->inicio->dato),realInfo(cad->inicio->dato));
     cad->inicio = cad->inicio->siguiente;
   }
   if (!esVaciaCadena(cad)) {
     printf("(%u,%.2lf)",natInfo(cad->final->dato),realInfo(cad->final->dato));
   }
   printf("\n");
   cad->inicio = loc;
   loc = NULL;
   delete loc;
 }

/*
  Devuelve el 'TLocalizador' con el que se accede al k-esimo elemento de 'cad'.
  Si 'k' es 0 o mayor a la cantidad de elementos de 'cad' devuelve un
  localizador no válido.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
 */
TLocalizador kesimo(nat k, TCadena cad) {
  TLocalizador res;
  if (k==0) {
    res = NULL;
  } else {
      res=cad->inicio;
    }
  nat n = 1;
  while ((n<k) && (res != NULL)) {
    n++;
    res=res->siguiente;
  }
  return res;
}

/*
  Devuelve 'true' si y solo si con 'loc' se accede a un elemento de 'cad',
  (o sea, si apunta a un nodo de 'cad').
  Si esVaciaCadena (cad) devuelve 'false'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
 */
bool localizadorEnCadena(TLocalizador loc, TCadena cad) {
  TLocalizador cursor = inicioCadena(cad);
  while (esLocalizador(cursor) && (cursor != loc)) {
    cursor = siguiente(cursor,cad);
  }
  return esLocalizador(cursor);
}

/*
  Devuelve 'true' si y solo si 'loc1' es igual o precede a 'loc2' en 'cad'.
  Si esVaciaCadena (cad) devuelve 'false'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
*/
bool precedeEnCadena(TLocalizador loc1, TLocalizador loc2, TCadena cad) {
  bool res;
  res = localizadorEnCadena(loc1, cad);
  if (res) {
    TLocalizador cursor = loc1;
    while (esLocalizador(cursor) && (cursor != loc2))
      cursor = siguiente(cursor, cad);
    res = esLocalizador(cursor);
    assert(!res || localizadorEnCadena(loc2, cad));
  }
  return res;
}

/*
  Se inserta en 'cad' la 'TCadena' 'sgm' inmediatamente después de 'loc',
  manteniendo los elementos originales y el orden relativo entre ellos.
  Devuelve 'cad'.
  No se debe obtener memoria (los nodos de 'sgm' pasan a ser parte de 'cad').
  Se libera la memoria asignada al resto de las estructuras de 'sgm'.
  El valor de 'sgm' queda indeterminado.
  Si esVaciaCadena(cad) 'loc' es ignorado y el segmento queda insertado.
  Precondición: esVaciaCadena(cad) o localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(1).
 */

 TCadena insertarSegmentoDespues(TCadena sgm, TLocalizador loc, TCadena cad) {
   assert((esVaciaCadena(cad)) || (localizadorEnCadena(loc, cad)));
   if (esVaciaCadena(sgm)) {
     delete sgm;
   } else {
     if (esVaciaCadena(cad)) {
       cad->inicio=sgm->inicio;
       cad->final=sgm->final;
       cad->inicio->anterior=cad->final->siguiente = NULL;
       sgm->inicio = sgm->final = NULL;
       delete sgm;
     } else if (esFinalCadena(loc,cad)) {
           sgm->inicio->anterior=cad->final;
           cad->final->siguiente=sgm->inicio;
           cad->final=sgm->final;
           cad->final->siguiente=NULL;
           sgm->inicio = sgm->final = NULL;
           delete sgm;
     } else if (esInicioCadena(loc,cad)) {
             sgm->inicio->anterior=cad->inicio;
             sgm->final->siguiente=cad->inicio->siguiente;
             cad->inicio->siguiente->anterior=sgm->final;
             cad->inicio->siguiente=sgm->inicio;
             sgm->inicio = sgm->final = NULL;
             delete sgm;
       } else {
               sgm->inicio->anterior=loc;
               sgm->final->siguiente=loc->siguiente;
               loc->siguiente->anterior=sgm->final;
               loc->siguiente=sgm->inicio;
               sgm->inicio = sgm->final = NULL;
               delete sgm;
         }
     }
   return cad;
 }

/*
  Devuelve una 'TCadena' con los elementos de 'cad' que se encuentran entre
  'desde' y 'hasta', incluidos.
  La 'TCadena' resultado no comparte memoria con 'cad'.
  Si esVaciaCadena(cad) devuelve la 'TCadena' vacia.
  Precondición: esVaciaCadena(cad) o precedeEnCadena(desde, hasta, cad).
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en la cadena resultado.
*/

TCadena copiarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {
  assert((esVaciaCadena(cad)) || (precedeEnCadena(desde, hasta, cad)));
  TCadena copia = crearCadena();
  if (!esVaciaCadena(cad)) {
    TLocalizador cursor = new nodo;
    TLocalizador cursor2 = new nodo;
    cursor2->dato = copiaInfo(desde->dato);
    cursor2->anterior = NULL;
    cursor2->siguiente = NULL;
    copia->inicio = cursor2;
    copia->final = cursor2;
    cursor = desde;
    if (desde!=hasta) {
      while (cursor!=hasta) {
        TLocalizador loc2 = new nodo;
        loc2->anterior = cursor2;
        cursor = cursor->siguiente;
        loc2->dato = copiaInfo(cursor->dato);
        cursor2->siguiente = loc2;
        cursor2 = loc2;
        loc2 = NULL;
        delete loc2;
      }
      cursor2->siguiente = NULL;
      copia->final = cursor2;
    }
    cursor = cursor2 = NULL;
    delete cursor;
    delete cursor2;
  }
  return copia;
}

/*
  Remueve de 'cad' los elementos que se encuentran  entre 'desde' y 'hasta',
  incluidos y libera la memoria que tenían asignada y la de sus nodos.
  Devuelve 'cad'.
  Si esVaciaCadena(cad) devuelve la 'TCadena' vacía.
  Precondición: esVaciaCadena(cad) o precedeEnCadena(desde, hasta, cad).
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en la cadena resultado.
 */
TCadena borrarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {
  assert((esVaciaCadena(cad)) || (precedeEnCadena(desde, hasta, cad)));
  if (!esVaciaCadena(cad)) {
    TLocalizador cursor1 = new nodo;
    cursor1 = desde->siguiente;
    cad = removerDeCadena(desde, cad);
    if (desde!=hasta) {
      while (cursor1!=hasta) {
        TLocalizador cursor2 = new nodo;
        cursor2 = cursor1;
        cursor1 = cursor1->siguiente;
        cad = removerDeCadena(cursor2, cad);
      }
      cad = removerDeCadena(hasta, cad);
    }
  }
  return cad;
}

/*
  Sustituye con 'i' el elemento de 'cad' al que se accede con 'loc'.
  Devuelve 'cad'.
  No destruye el elemento al que antes se accedía con 'loc'.
  Precondición: localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(1).
 */
TCadena cambiarEnCadena(TInfo i, TLocalizador loc, TCadena cad) {
  assert(localizadorEnCadena(loc, cad));
  loc->dato=i;
  return cad;
}

/*
  Intercambia los elementos a los que se accede con 'loc1' y 'loc2'.
  'loc1' y 'loc2' mantienen su relación de precedencia.
  Devuelve 'cad'.
  Precondición:
    localizadorEnCadena (loc1, cad)
  y localizadorEnCadena (loc2, cad).
  El tiempo de ejecución en el peor caso es O(1).
 */
TCadena intercambiar(TLocalizador loc1, TLocalizador loc2, TCadena cad){
  assert((localizadorEnCadena (loc1, cad)) && (localizadorEnCadena (loc2, cad)));
  TInfo aux;
  aux = loc1->dato;
  loc1->dato=loc2->dato;
  loc2->dato=aux;
  return cad;
}

/*
  Devuelve el primer 'TLocalizador' con el que se accede a un elemento cuyo
  componente natural es igual a 'clave', buscando desde 'loc' (inclusive) hacia
  el final de 'cad'. Si no se encuentra o 'cad' es vacía devuelve un
  'TLocalizador' no válido.
  Precondición: esVaciaCadena(cad) o localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
 */
TLocalizador siguienteClave(nat clave, TLocalizador loc, TCadena cad) {
  assert ((esVaciaCadena(cad)) || (localizadorEnCadena(loc, cad)));
  if (!esVaciaCadena(cad)) {
    TInfo info = infoCadena(loc, cad);
    nat n = natInfo(info);
    while((n != clave) && (loc !=cad->final)) {
      loc=loc->siguiente;
      info = loc->dato;
      n = natInfo(info);
    }
    if (n != clave) {
      loc = NULL;
    }
  } else {
    loc = NULL;
  }
  return loc;
}

/*
  Devuelve el primer 'TLocalizador' con el que se accede a un elemento cuyo
  componente natural es igual a 'clave', buscando desde 'loc' (inclusive) hacia
  el inicio de 'cad'. Si no se encuentra o 'cad' es vacía devuelve un
  'TLocalizador' no válido.
  Precondición: esVaciaCadena(cad) o localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
 */
TLocalizador anteriorClave(nat clave, TLocalizador loc, TCadena cad) {
  assert ((esVaciaCadena(cad)) || (localizadorEnCadena(loc, cad)));
  if (!esVaciaCadena(cad)) {
    TInfo info = infoCadena(loc, cad);
    nat n = natInfo(info);
    while((n != clave) && (loc!=cad->inicio)) {
      loc=loc->anterior;
      info = loc->dato;
      n = natInfo(info);
    }
    if (n != clave) {
      loc = NULL;
    }
  } else {
    loc = NULL;
  }
  return loc;
}

/*
  Devuelve el 'TLocalizador' con el que se accede al elemento cuyo componente
  natural es el menor en el segmento que va desde 'loc' hasta finalCadena(cad).
  Si hay más de un elemento cuyo valor es el menor el resultado accede al que
  precede a los otros.
  Precondición: localizadorEnCadena(loc, cad).
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos en 'cad'.
 */
TLocalizador menorEnCadena(TLocalizador loc, TCadena cad) {
  assert(localizadorEnCadena(loc, cad));
  TLocalizador cursor;
  TLocalizador res;
  cursor=loc;
  nat n = natInfo(cursor->dato);
  res = cursor;
  while(cursor!=cad->final) {
    if (n>natInfo(cursor->dato)){
      n = natInfo(cursor->dato);
      res = cursor;
    }
    cursor=cursor->siguiente;
  }
  if (n>natInfo(cad->final->dato)) {
    res = cad->final;
  }
  return res;
}
