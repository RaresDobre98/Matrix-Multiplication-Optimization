/*
 * Tema 2 ASC
 * 2019 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");
	double *C = malloc(N * N * sizeof(double));
	double *D = malloc(N * N * sizeof(double));
	int i, j, k;

	for (i = 0 ; i < N ; i++) {
		for (j = 0 ; j < N ; j++) {
			register double suma = 0.0;
			register double inmultire1 = 0.0;
			register double inmultire2 = 0.0;
			for (k = 0 ; k < N ; k++) {
				if(i > j)
					suma = 0.0;
				else{
					inmultire1 = A[k * N + i] * B[k * N + j];
					inmultire2 = B[k * N + i] * A[k * N + j];
					suma += inmultire1 + inmultire2;
					inmultire1 = 0;
					inmultire2 = 0; 
				}
			}
			C[i * N + j] = suma;
		}
	}

	for (i = 0 ; i < N ; i++) {
		for (j = 0 ; j < N ; j++) {
			register double suma2 = 0.0;
			for (k = 0 ; k < N ; k++) {
				suma2 += C[i * N + k] * C[k * N + j];
			}
			D[i * N + j] = suma2;
		}
	}
	return D;
}
