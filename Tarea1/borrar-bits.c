#include <stdio.h>
#include <stdlib.h>

#include "borrar-bits.h"

typedef unsigned int uint;

uint borrar_bits(uint x, uint pat, int len) {
	uint m=~(-1<<(len-1)<<1);
	for (int i=0; i<(sizeof(x)<<3)-len+1; i++) {
		if (((x>>i)&m)==pat){
		    x^=(pat<<i);
		    i+=len-1;
		}
	}
	return x;
}
