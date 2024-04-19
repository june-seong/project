#include <iostream>
#include <fstream>
using namespace std;

void mul5(int n, float* x) {
    for (int i = 0; i < n; i++) {
        x[i] = 5 * (1000 * (i + 1));}
    return;
}
void square(int n, float* y) {
    float a = -0.5;
    for (int i = 0; i < n; i++) {
       y[i] = a * a;
       a += 0.5;}
    return;
}
int all() {
    float* xx;
    xx = new float[11];
    ofstream ff("mybin4.dat", ios::binary | ios::out);
    xx[0] = 1234;
    mul5(5, xx+1);
    square(3, (float*)xx+6);
    ff.write((char*)xx, sizeof(int) * 11);
    ff.close();
    delete[] xx;
    return 1;
}
int main() {
    all();
    ifstream ss("mybin4.dat", ios::binary | ios::in);
    float ii[11];
    ss.read((char*)ii, sizeof(float) * 11);
    for (int i = 0; i < 11; i++) cout << ii[i] << endl;
    return 0;
}

