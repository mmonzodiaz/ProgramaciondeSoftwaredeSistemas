#include <string.h>

void sort(char **noms, int n) {
  char **ult= &noms[n-1];
  char **p= noms;
  while (p<ult) {
    ////////////////////////////////////////////
    // Comienza el codigo que Ud. debe modificar
    ////////////////////////////////////////////
    char *p1 = p[0];
    char *p2 = p[1];
    int cnt1 = 0;
    int cnt2 = 0;
    
    while(*p1 != '\0'){
        if(*p1 == ' '){
            cnt1++;
        }
        p1++;
    }
    while(*p2 != '\0'){
        if(*p2 == ' '){
            cnt2++;
        }
        p2++;    
    }
    int rc = cnt1-cnt2;
        
    ////////////////////////////////////////////
    // Fin del codigo que Ud. debe modificar
    ////////////////////////////////////////////
    if (rc<=0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= noms;
    }
  }
}
