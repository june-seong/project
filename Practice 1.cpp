#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream xx("Beatles-LetItBe-wav_30s.wav", ios::binary | ios::in);
	if (!xx) return 666;
	char header[44];
	xx.read(header, 44);
	int* sampleRate = (int*)(header + 24);
	cout << "   sampleRate = " << *sampleRate << endl;
	
	short* n;   n = (short*)(header + 22);  cout << *n << endl;
	int* fs;   fs = (int*)(header + 24);  cout << *fs << endl;
	int* b;   b = (int*)(header + 28);  cout << *b << endl;

	int N = fs[0] * 10;
	short* data;
	data = new short[N];
	*n = 1;
	*b = n[0] * fs[0] * sizeof(short); // byte rate change

	xx.read((char*)data, N * sizeof(short)); // 헤더를 읽은 후 xx.close();하기 전에 10초 분량 데이터를 읽는다. 

	ofstream yy("my.wav", ios::binary | ios::out);
	if (!yy) return 666;  // 만일 파일이 열리지 않으면 프로그램을 끝낸다. 
	yy.write(header, 44 * sizeof(char)); // 헤더를 쓴다. 
	yy.write((char*)data, N * sizeof(short));    // 헤더에 이어서 10초 분량 쓴다.
	yy.close();
	cout << *b << endl;
	return 1;
}