#include <iostream>
#include <fstream>
using namespace std;
float num[11];
int times5();
int square2();
int main() {
    *num = 1234;
    times5();
    square2();
    for (int k = 0; k < 11; k++)
        cout << num[k] << endl;
    ofstream xx;
    xx.open("mybin3.dat", ios::binary | ios::out);
    xx.write((char*)&num, sizeof(num));
    xx.close();

    float numout[11];
    ifstream yy;
    yy.open("mybin3.dat", ios::binary | ios::in);
    yy.read((char*)&numout, sizeof(numout));
}
int times5() {
    int bb = 1000;
    for (int i = 1; i < 6; i++) {
        *(num + i) = bb * 5;
        bb += 1000;
    }
return 0;
}
int square2() {
    float aa = -0.5;
    for (int j = 0; j < 3; j++) {
        *(num + 6 + j) = aa * aa;
        aa += 0.5;
    }
    return 1;
}
