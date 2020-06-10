/* 4862558 */

#include "../include/cadena.h"
#include "../include/utils.h"
#include "../include/usoTads.h"
#include "../include/info.h"
#include "../include/binario.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* _______________________________________interseccionDeConjuntos_______________________________________ */
/*
  Devuelve un 'TConjunto' con los elementos que pertenecen a 'c1' y 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n1 + n2 + n.log n),
  siendo 'n1' y 'n2' la cantidad de elementos de 'c1' y 'c2' respectivamente y
  'n' la del 'TConjunto' resultado.
*/

TConjunto interseccionDeConjuntos(TConjunto c1, TConjunto c2){
  return NULL;
}


/* ___________________________________estaOrdenadaPorNaturales___________________________________ */
/*
  Devuelve 'true' si y solo si 'cad' está ordenada de forma no dereciente
  (creciente de manera no estricta) según las campos naturales de sus elementos.
  Si esVaciaVadena(cad) devuelve 'true'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de  elementos de 'cad'.
 */
//COMPLETADO
bool estaOrdenadaPorNaturales(TCadena cad) {
  bool resp = true;
  if (!esVaciaCadena(cad)){
    if (inicioCadena(cad) != finalCadena(cad)) {
      TLocalizador cursor = inicioCadena(cad);
      TInfo info = infoCadena(cursor, cad);
      TLocalizador cursor2 = siguiente(cursor, cad);
      TInfo info2 = infoCadena(cursor2, cad);
      while ((resp) && (!esFinalCadena(cursor2, cad)))  {
        if ((natInfo(info)) > (natInfo(info2))) {
          resp = false;
        }
        cursor = siguiente(cursor, cad);
        cursor2 = siguiente(cursor2, cad);
        info = infoCadena(cursor, cad);
        info2 = infoCadena(cursor2, cad);
      }
      if ((natInfo(info)) > (natInfo(info2))) {
        resp = false;
      }
    }
  }
  return resp;
}


/*_______________________________________ordenar_______________________________________*/
/*
  Se ordena 'cad' de manera creciente según los componentes naturales de sus
  elementos.
  Devuelve 'cad'
  Precondición: ! hayNatsRepetidos(cad)
  No se debe obtener ni devolver memoria de manera dinámica.
  Se debe mantener las relaciones de precedencia entre localizadores.
  Si esVaciaCadena(cad) no hace nada.
  El tiempo de ejecución en el peor caso es O(n^2), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
TCadena ordenar(TCadena cad) {
  assert(!hayNatsRepetidos(cad));
  if (!esVaciaCadena(cad)){
    if (inicioCadena(cad) != finalCadena(cad)) {
      TLocalizador cursor1;
      TLocalizador cursor2;
      cursor1 = inicioCadena(cad);
      cursor2 = inicioCadena(cad);
      TInfo info1;
      TInfo info2;
      nat nat1;
      nat nat2;
      for (nat inicio1 = 1; longitud(cad) >= inicio1; inicio1++) {
        info1 = infoCadena(cursor1, cad);
        nat1 = natInfo(info1);
        for (nat inicio2 = 1; longitud(cad) >= inicio2; inicio2++) {
          info2 = infoCadena(cursor2, cad);
          nat2 = natInfo(info2);
          if ((nat1 > nat2) && (cursor1 != cursor2)) {
            cambiarEnCadena(info2, cursor1, cad);
            cambiarEnCadena(info1, cursor2, cad);
          }
          if (!esFinalCadena(cursor2, cad))  {
            cursor2 = siguiente(cursor2, cad);
          }
        }
        if (!esFinalCadena(cursor1, cad))  {
          cursor1 = siguiente(cursor1, cad);
        }
        cursor2 = inicioCadena(cad);
      }
    }
  }
  return cad;
}

/*____________________________________subCadena____________________________________*/
/*
  Devuelve la 'TCadena' de elementos de 'cad' que cumplen
  "menor <= natInfo (elemento) <= mayor".
  El orden relativo de los elementos en la 'TCadena' resultado debe ser el mismo
  que en 'cad'.
  Precondición: estaOrdenadaPorNaturales (cad), 'menor' <= 'mayor',
  pertenece (menor, cad), pertenece (mayor, cad).
  La 'TCadena' resultado no comparte memoria con 'cad'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
TCadena subCadena(nat menor, nat mayor, TCadena cad) {
  assert(estaOrdenadaPorNaturales(cad) && menor<=mayor && pertenece(menor, cad) && pertenece(mayor, cad));
  TCadena resp= copiarSegmento(inicioCadena(cad), finalCadena(cad), cad);
  TLocalizador comienzo = siguienteClave(menor, inicioCadena(resp), resp);
  if (comienzo != inicioCadena(resp)) {
    resp = borrarSegmento(inicioCadena(resp), anterior(comienzo, resp), resp);
  }
  TLocalizador final = anteriorClave(mayor, finalCadena(resp), resp);
  if (final != finalCadena(resp)) {
    resp = borrarSegmento(siguiente(final, resp), finalCadena(resp), resp);
  }
  return resp;
}


/*____________________________________nivelEnBinario____________________________________*/
/*
  Devuelve una 'TCadena' con los elementos del nivel 'l' de 'b'.
  La raíz es el nivel 1.
  La 'TCadena' resultado debe estar ordenada de manera creciente según los
  componentes naturales de sus elementos.
  Precondición: l > 0.
  La 'TCadena' devuelta no comparte memoria con 'b'.
 */
TCadena nivelEnBinario(nat l, TBinario b) {

  return NULL;
}

/*____________________________________esCamino____________________________________*/
/*
  Devuelve 'true' si y solo si en 'b' hay un camino desde la raiz hasta una
  hoja que sea compatible con 'c'.
  Decimos que una cadena y un camino son compatibles si tienen la misma
  longitud y al recorrer la cadena desde el inicio hasta el final y el camino
  desde la raíz hasta la hoja los componentes naturales de los respectivos
  elementos son iguales.
  Ver ejemplos en la letra.
  Si 'b' y 'c' son vacíos devuelve 'true'.
  El tiempo de ejecución es O(log n) en promedio, siendo 'n' es la cantidad de
  elementos de 'b'.
 */
bool esCamino(TCadena c, TBinario b){

  return NULL;
}









/*
  Devuelve 'true' si y solo si en 'cad' hay un elemento cuyo campo natural es
  'elem'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
//COMPLETADO
bool pertenece(nat elem, TCadena cad) {
  bool resp;
  if (esVaciaCadena(cad)) {
    resp = false;
  } else {
    TCadena copia = copiarSegmento(inicioCadena(cad), finalCadena(cad), cad);
    TLocalizador cursor = inicioCadena(copia);
    TInfo info = infoCadena(cursor, copia);
    resp = (elem == natInfo(info));
    while ((!resp) && (!esFinalCadena(cursor, copia))) {
      cursor = siguiente(cursor, copia);
      info = infoCadena(cursor, copia);
      resp = (elem == natInfo(info));
    }
    liberarCadena(copia);
  }
  return resp;
}


/*
  Devuelve la cantidad de elementos de 'cad'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
//COMPLETADO
nat longitud(TCadena cad) {
  nat resp = 0;
  if (!esVaciaCadena(cad)) {
    resp = 1;
    TLocalizador cursor = inicioCadena(cad);
    while (cursor != finalCadena(cad)) {
      cursor = siguiente(cursor, cad);
      resp = resp + 1;
    }
  }
  return resp;
}


/*
  Devuelve 'true' si y solo si los componentes naturales de algún par de
  elementos de 'cad' son iguales.
  El tiempo de ejecución en el peor caso es O(n^2), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
//COMPLETADO
bool hayNatsRepetidos(TCadena cad) {
  bool resp = false;
  if (!esVaciaCadena(cad)){
    if (inicioCadena(cad) != finalCadena(cad)) {
      TLocalizador cursor1;
      TLocalizador cursor2;
      cursor1 = inicioCadena(cad);
      cursor2 = inicioCadena(cad);
      TInfo info1;
      TInfo info2;
      nat nat1;
      nat nat2;
      for (nat inicio1 = 1; longitud(cad) >= inicio1; inicio1++) {
        info1 = infoCadena(cursor1, cad);
        nat1 = natInfo(info1);
        for (nat inicio2 = 1; longitud(cad) >= inicio2; inicio2++) {
          info2 = infoCadena(cursor2, cad);
          nat2 = natInfo(info2);
          if ((nat1 == nat2) && (cursor1 != cursor2)) {
            resp = true;
          }
          if (!esFinalCadena(cursor2, cad))  {
            cursor2 = siguiente(cursor2, cad);
          }
        }
        if (!esFinalCadena(cursor1, cad))  {
          cursor1 = siguiente(cursor1, cad);
        }
        cursor2 = inicioCadena(cad);
      }
    }
  }
  return resp;
}


/*
  Devuelve 'true' si y solo si 'c1' y 'c2' son iguales (es decir, si los
  elementos son iguales y en el mismo orden).
  Si esVaciaCadena(c1) y esVaciaCadena(c2) devuelve 'true'.
  El tiempo de ejecución en el peor caso es O(n1 + n2), siendo 'n1' u 'n2' la
  cantidad de elementos de 'c1' y 'c2' respectivamente.
 */
//COMPLETADO
bool sonIgualesCadena(TCadena c1, TCadena c2) {
  bool resp = true;
  if (longitud(c1) != longitud(c2)){
    resp = false;
  } else {
      if (!esVaciaCadena(c1)) {
        TLocalizador cursor1;
        TLocalizador cursor2;
        cursor1 = inicioCadena(c1);
        cursor2 = inicioCadena(c2);
        TInfo info1;
        TInfo info2;
        nat i = 1;
        while ((longitud(c1) > i) && (resp)) {
          info1 = infoCadena(cursor1, c1);
          info2 = infoCadena(cursor2, c2);
          if (!sonIgualesInfo(info1, info2)) {
            resp = false;
          }
          cursor2 = siguiente(cursor2, c2);
          cursor1 = siguiente(cursor1, c1);
          i = i+1;
        }
        cursor1 = finalCadena(c1);
        cursor2 = finalCadena(c2);
        info1 = infoCadena(cursor1, c1);
        info2 = infoCadena(cursor2, c2);
        if (!sonIgualesInfo(info1, info2)) {
          resp = false;
        }
      }
    }
  return resp;
}


/*
  Devuelve el resultado de concatenar 'c2' después de 'c1'.
  La 'TCadena' resultado no comparte memoria ni con 'c1' ni con 'c2'.
  El tiempo de ejecución en el peor caso es O(n1 + n2), siendo 'n1' u 'n2' la
  cantidad de elementos de 'c1' y 'c2' respectivamente.
 */
//COMPLETADO
TCadena concatenar(TCadena c1, TCadena c2) {
  TCadena cad = crearCadena();
  if (esVaciaCadena(c1)) {
    cad = copiarSegmento(inicioCadena(c2), finalCadena(c2), c2);
  } else if (esVaciaCadena(c2)){
      cad = copiarSegmento(inicioCadena(c1), finalCadena(c1), c1);
    } else {
        if ((!esVaciaCadena(c2)) && (!esVaciaCadena(c2))) {
          cad = copiarSegmento(inicioCadena(c1), finalCadena(c1), c1);
          TCadena copia2 = copiarSegmento(inicioCadena(c2), finalCadena(c2), c2);
          TLocalizador loc = finalCadena(cad);
          cad = insertarSegmentoDespues(copia2, loc, cad);
        }

    }
  return cad;
}


/*
  Cambia todas las ocurrencias de 'original' por 'nuevo' en los elementos
  de 'cad'.
  Devuelve 'cad'
  No debe quedar memoria inaccesible.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
//COMPLETADO
TCadena cambiarTodos(nat original, nat nuevo, TCadena cad) {
  if (!esVaciaCadena(cad)){
    TLocalizador cursor = inicioCadena(cad);
    TInfo info = infoCadena(cursor, cad);
    while (!esFinalCadena(cursor, cad))  {
      if (natInfo(info) == original) {
        double real = realInfo(info);
        info = crearInfo(nuevo, real);
        cambiarEnCadena(info, cursor, cad);
      }
      cursor = siguiente(cursor, cad);
      info = infoCadena(cursor, cad);
    }
    if (natInfo(info) == original) {
      double real = realInfo(info);
      info = crearInfo(nuevo, real);
      cambiarEnCadena(info, cursor, cad);
    }
  }
  return cad;
}
