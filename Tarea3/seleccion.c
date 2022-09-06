#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "seleccion.h"
//La función selprim retorna el número de nodos que construyó
int selprim(Nodo **pa, int k){
  Nodo *a = *pa;
  if(a== NULL){
    return 0;
  }

  int cnt_left = selprim(&a->izq, k);  
  if(cnt_left >k){
    *pa = a-> izq;
  }
  if(cnt_left == k){
    selprim(&a->der,0);
    *pa = a-> izq;
    free(a);
    return k;
  }
  
  int cnt_right = selprim(&a->der, k-cnt_left-1);
  return cnt_left+cnt_right+1;
}

Nodo *ultimos(Nodo *a, int *pk) {
  if(a== NULL){
    *pk=0;
    return NULL;
  }
  
  int cnt_right = *pk;
  Nodo *copiader = ultimos(a->der, &cnt_right);
  
  if(cnt_right == *pk){
    return copiader;
  }

  else{
    Nodo *copia = malloc(sizeof(Nodo));
    copia->x = a->x;
    copia->der = copiader;
    int left = *pk-cnt_right-1;
    copia->izq=ultimos(a->izq,&left);
    *pk = cnt_right+left+1;
    return copia;
  }
}
