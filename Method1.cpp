#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a = 1234;
    int b = 1000;
    float c= -0.5;
    int cc[5];
    float dd[3];

    for (int i = 0; i < 5; i++) {
        cc[i] = b * 5;
        b += 1000;
    }

    for (int i = 0; i < 3; i++) {
        dd[i] = c * c;
        c += 0.5;
    }
    ofstream xx;
    xx.open("mybin1.dat", ios::binary | ios::out);
    xx.write((char*)&a, 4);
    xx.write((char*)&cc, sizeof(cc));
    xx.write((char*)&dd, sizeof(dd));
    xx.close();
    int d;
    int ee[5];
    float ff[3];
    ifstream yy;
    yy.open("mybin.dat", ios::binary | ios::in);
    yy.read((char*)&d, sizeof(d)); 
    yy.read((char*)&ee, sizeof(ee));
    yy.read((char*)&ff, sizeof(ff));

    cout << d << endl;
    for (int i = 0; i < 5; i++) {
        cout << ee[i] << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << ff[i] << endl;
    }
}

