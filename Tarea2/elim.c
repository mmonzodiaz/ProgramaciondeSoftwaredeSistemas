#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar_espacios(char *s){
    char *lect = s;
    char *escr = s;
    int cnt = 0;
    while (*lect != 0){
        if (*lect == ' '){
            cnt++;
            if (cnt == 1){
                *escr = *lect;
                escr++;
            }
            lect++;
        }
        else{
            *escr = *lect;
            escr++;
            lect++;
            cnt = 0;
        }
    }
    *escr = *lect;
}

int espacios_a_eliminar(const char *s){
    int cnt = 0;
    int tot = 0;
    while (*s != 0){
        if (*s == ' '){
            cnt++;
            if (cnt > 1){
                tot++;
            }
        }
        else{
            cnt = 0;
        }
        s++;
    }
    return tot;
}

char *eliminacion_espacios(const char *s){
    int tot = espacios_a_eliminar(s);

    char tmp[strlen(s) + 1];
    strcpy(tmp, s);
    eliminar_espacios(tmp);

    char *copia = malloc(strlen(s) - tot + 1);
    strcpy(copia, tmp);
    
    return copia;
}
