#include <iostream>
#include <fstream>
using namespace std;

void multi5(int, ofstream&);
void sqaure(float, ofstream&);

int main() {
    int a = 1234;
    ofstream xx;
    xx.open("mybin.dat", ios::binary | ios::out);
    xx.write((char*)&a, 4);
    multi5(5, xx);
    sqaure(3, xx);
    xx.close();

    int d; int ee[5]; float ff[3];
    ifstream yy;
    yy.open("mybin.dat", ios::binary | ios::in);
    yy.read((char*)&d, sizeof(d));
    yy.read((char*)&ee, sizeof(ee));
    yy.read((char*)&ff, sizeof(ff));
    cout << d << endl;
    for (int i = 0; i < 5; i++) {
        cout << ee[i] << endl;
    }
    for (int I = 0; I < 3; i++) {
        cout << ff[i] << endl;
}
void multi5(int I, ofstream & xx) {
    int* c = new int[i];
    for (int a = 1000, b = 0; b < I; b++) {
        c[b] = a;
        a += 1000;
    }
    xx.write((char*)c, sizeof(int) * i);
    delete[] c;
}

void sqaure(float f, ofstream& xx) {
    float* c = new float[f];
    float a = -0.5;
    for (int b = 0; b < f; b++) {
        c[b] = a*a;
        a += 0.5;
    }
    xx.write((char*)c, sizeof(float) * f); 
    delete[] c;
}


