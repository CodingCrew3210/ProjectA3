/* reduction.c
* ... illustrates the OpenMP parallel-for loop's reduction clause
*
* Joel Adams, Calvin College, November 2009.
* Hayden Kowalchuk, GSU, Spring 2020
*
* Usage: ./reduction
*
* Exercise:
* - Compile and run. Note that correct output is produced.
* - Uncomment #pragma in function parallelSum(),
* but leave its reduction clause commented out
* - Recompile and rerun. Note that correct output is NOT produced.
* - Uncomment 'reduction(+:sum)' clause of #pragma in parallelSum()
* - Recompile and rerun. Note that correct output is produced again.
*/

#include <omp.h>     // OpenMP
#include <stdio.h>   // printf()
#include <stdlib.h>  // rand()

#define SIZE 1000000

/* fill array with random values */
void initialize(int* a, int n) {
  int i;

  for (i = 0; i < n; i++) {
    a[i] = rand() % 1000;
  }
}

/* sum the array sequentially */
int sequentialSum(int* a, int n) {
  int sum = 0;
  int i;

  for (i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}

/* sum the array using multiple threads */
/*
int parallelSum(int* a, int n) {
  int sum = 0;
  int i;
  
  #pragma omp parallel for reduction(+:sum)
  for (i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}
*/

/* Alternate method using critical section */
int parallelSum(int* a, int n) {
  int sum = 0;
  int i;

#pragma omp parallel for
  for (i = 0; i < n; i++) {
#pragma omp critical
    sum += a[i];
  }
  return sum;
}

int main(int argc, char** argv) {
  int array[SIZE];
  if (argc > 1) {
    omp_set_num_threads(atoi(argv[1]));
  }

  initialize(array, SIZE);

  printf("\nSequential sum:\t%d\nParallel sum: \t%d\n\n",
         sequentialSum(array, SIZE),
         parallelSum(array, SIZE));
  return 0;
}
