#include <iostream>
using namespace std;
void main() {
	int N = 2, M = 2;
	float a, b, c, d;
	cout << "a, b, c, d = ? " << endl;
	cin >> a >> b >> c >> d;
	float A[2][2] = { {a,b},{c,d} }, ** B;
	B = new float* [2];
	for (int n = 0; n < 2; n++) { B[n] = new float[2]; }
	B[0][0] = d / (a * d - b * c);
	B[0][1] = -b / (a * d - b * c);
	B[1][0] = -c / (a * d - b * c);
	B[1][1] = a / (a * d - b * c);
	// show results
	cout << "matrix A" << endl;
	for (int n = 0; n < 2; n++) {
		for (int m = 0; m < 2; m++) {
			cout << A[n][m] << "  ";
		}
		cout << endl;
	}
	cout << "matrix A^-1" << endl;
	for (int n = 0; n < 2; n++) {
		for (int m = 0; m < 2; m++) {
			cout << B[n][m] << "  ";
		}
		cout << endl;
	}
	for (int n = 0; n < N; n++) {delete[] B[n];}
	delete[] B;
}

