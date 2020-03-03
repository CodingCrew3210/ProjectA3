/* parallelLoopChunksOf1.c
* ... illustrates how to make OpenMP map threads to
* parallel loop iterations in chunks of size 1
* (use when not accesssing memory).
*
* Joel Adams, Calvin College, November 2009.
* Hayden Kowalchuk, GSU, Spring 2020
*
* Usage: ./parallelLoopChunksOf1 [numThreads]
*
* Exercise:
* 1. Compile and run, comparing output to source code,
* and to the output of the 'equal chunks' version.
* 2. Uncomment the "commented out" code below,
* and verify that both loops produce the same output.
* The first loop is simpler but more restrictive;
* the second loop is more complex but less restrictive.
*/

/*
  This program instead of assiging a "chunk" each of the entire loop to a thread breaks up the job into single items.
  This means that each thread is given a single iteration of the loop and then it passes onto the next thread, with 2 threads one thread will get all even iterations and one will receive all odd iterations.
  
*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  const int REPS = 16;
  printf("\n");

  if (argc > 1) {
    omp_set_num_threads(atoi(argv[1]));
  }

#pragma omp parallel for schedule(dynamic, 1)
  for (int i = 0; i < REPS; i++) {
    int id = omp_get_thread_num();
    printf("Thread %d performed iteration %d\n", id, i);
  }

/*
  printf("\n---\n\n");
#pragma omp parallel
  {
    int id = omp_get_thread_num();
    int numThreads = omp_get_num_threads();
    for (int i = id; i < REPS; i += numThreads) {
      printf("Thread %d performed iteration %d\n",
             id, i);
    }
  }
*/

  printf("\n");
  return 0;
}

