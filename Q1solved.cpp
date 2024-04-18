#include <iostream>
#include <fstream>
using namespace std;

void mul5(int n, int* x) {
	for (int i = 0; i < n; i++) {
		x[i] = 5 * (1000 * (i + 1));
	}
	return;
}
void square(int n, float* y) {
	float a = -0.5;
	for (int i = 0; i < n; i++) {
		y[i] = a * a;
		a += 0.5;
	}
	return;
}

int all() {
	int* xx;
	xx = new int[11];
	ofstream ff("mybin4.dat", ios::binary | ios::out);
	xx[0] = 1234;
	mul5(5, xx+1);
	square(3, (float*)xx+6);
	ff.write((char*)xx, sizeof(int) * 11);
	ff.close();
	for (int i = 0; i < 9; i++) {
		cout << xx[i] << endl;
	}
	return 1;

}
int main() {
	all();
	return 0;
}
