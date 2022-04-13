// importing library from gcc
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// declaring global variable
int i, count, n;
double x,y,z,pi;
pthread_t tid;
pthread_attr_t attr;
clock_t t;

// thread void to generate random X and Y 
void *randomXY(void *param){
  count = 0;
  for(i = 0; i < n; ++i) {
    // random poin X and Y
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if( z <= 1 ) count++;
  }
  // exit pthread after this thread complete
  pthread_exit(0);
}

int main(){
  // starting point time
  t = clock();
  // get input from user input
  printf("n = ");
  scanf("%d", &n);

  // get default attribut
  pthread_attr_init(&attr);
  // create thread
  pthread_create(&tid,&attr,randomXY,NULL);
  // wait for the thread to exit
  pthread_join(tid, NULL);
  
  // calculating pi
  pi = (double) count / n * 4;
  printf("Approximate PI = %g", pi);

  // end point time
  t = clock() - t;
  // calculating time execution
  double time_exec = ((double)t)/CLOCKS_PER_SEC;
  printf("\ntime execution: %f seconds",time_exec);
  return 0;
}