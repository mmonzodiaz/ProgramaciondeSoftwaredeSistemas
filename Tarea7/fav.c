#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "fav.h"

int favorables_par(int n, int sum, int rep, int p) {
  int fds[p][2];
  int pids[p];
  
  int  lanzamientos_core = rep/p;
  
  for(int i=0; i<p; i++){
    pipe(fds[i]);
    init_rand_seed();//REVISAR
        pids[i] = fork();

    if(pids[i] == 0){ // hijo
      close(fds[i][0]);
      if(i == p-1) lanzamientos_core+=(rep%p);
      int res = favorables(n, sum, lanzamientos_core);
      write(fds[i][1], &res, sizeof(int));
      exit(0);
    }
    else{ // padre
      close(fds[i][1]);
    }
  }

  int res = 0;
  for(int i=0; i<p; i++){
    waitpid(pids[i], NULL, 0);
    int res_hijo;
    read(fds[i][0], &res_hijo, sizeof(int));
    if(res_hijo != 0){
      res += res_hijo;
    }
  }
  return res;
}
