/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");

	double *C = malloc(N * N * sizeof(double));
	double *D = malloc(N * N * sizeof(double));
	int i, j, k;

	for (i = 0 ; i < N ; i++) {
		for (j = 0 ; j < N ; j++) {
			C[i * N + j] = 0.0;
			for (k = 0 ; k < N ; k++) {
				if(i > j)
					C[i * N + j] = 0.0;
				else
					C[i * N + j] += ((A[k * N + i] * B[k * N + j]) + (B[k * N + i] * A[k * N + j])); 
			}
		}
	}

	for (i = 0 ; i < N ; i++) {
		for (j = 0 ; j < N ; j++) {
			for (k = 0 ; k < N ; k++) {
				D[i * N + j] += C[i * N + k] * C[k * N + j];
			}
		}
	}
	return D;
}
