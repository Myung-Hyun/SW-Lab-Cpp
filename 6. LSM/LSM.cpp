// matrix_LSM.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
///
#include <iostream> // for getchar( )
#include <cstdlib>  // for rand( )
#include "myMatrix.h"
using namespace std;

int main()
{
	// data generation
	float datax[100], datay[100];
	int N = 100, i;
	for (i = 0; i < N; i++) {
		datax[i] = 300. + i + (rand() / (float)RAND_MAX - 0.5)* 10.;
		datay[i] = 1.2 * datax[i] + (rand() / (float)RAND_MAX - 0.5)* 10. + 100.;
	}
	// LSM
	float A[4], B[2], C[2];
	for (i = 0; i < 4; i++) A[i] = 0.0;
	for (i = 0; i < 2; i++) B[i] = C[i] = 0.0;
	for (i = 0; i < N; i++) {
		A[0] += datax[i];          A[1] += 1.0;      B[0] += datay[i];
		A[2] += datax[i]*datax[i]; A[3] += datax[i]; B[1] += datay[i] * datax[i];
	}

	GaussElimination(2, A, B);

	cout << "y = " << B[0] << " x + " << B[1] <<"\n";

	getchar();
    return 0;
}

