#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ofstream output("data.dat");
    for (int i = 1; i <= 10; i++) {
        char c = i+96;
        double price = rand()%100 * 0.1 + 4;
        int vc = rand()%10;
        double dis = rand()%30 * 0.01;
        output << "���:" << i << endl;
        output << "����:" << "<++>" << endl;
        output << "������:" << c << endl;
        output << "����:" << price << endl;
        output << "����:" << vc << endl;
        output << "�Ż��ۿ�:" << dis << endl;
        output << "���:" << 0 << endl;
        output << "��������:" << 0 << endl;
        output << endl;
    }
}
