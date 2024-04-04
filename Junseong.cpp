#include <iostream>
using namespace std;
void main() {
	int N = 2, M = 3,K = 2;
	float A[2][3] = { {1,2,3},{4,5,6} }, **B, **C;
	B = new float*[M];
	for (int n = 0; n < M; n++) B[n] = new float[K];
	C = new float*[N];
	for (int n = 0; n < N; n++) C[n] = new float[K];
	B[0][0] = 7; B[0][1] = 8;
	B[1][0] = 9; B[1][1] = 10;
	B[2][0] = 11; B[2][1] = 12;
	// C = A * B
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < K; m++) {
			C[n][m] = 0;
			for (int i = 0; i < M; i++)
			{
				C[n][m] += A[n][i] * B[i][m];
			}
		}
	}
	// show results
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < K; m++) {
			cout << C[n][m] << "  ";
		}
		cout << endl;
	}
	for (int n = 0; n < N; n++) { delete[] B[n]; delete[] C[n]; }
	delete[] B;
	delete[] C;
}
