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
        output << "编号:" << i << endl;
        output << "菜名:" << "<++>" << endl;
        output << "卖菜人:" << c << endl;
        output << "单价:" << price << endl;
        output << "数量:" << vc << endl;
        output << "优惠折扣:" << dis << endl;
        output << "金额:" << 0 << endl;
        output << "单价排名:" << 0 << endl;
        output << endl;
    }
}
