#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
using namespace std;

struct Vegetable{
    int num;
    string name;
    string seller;
    double price;
    double discount;
    int vcount;
    double total_price;
    int rank;
};

class DLink
{
public:
    DLink() { initBasket(); }
    ~DLink() {
        deleteBasket();
    }
    void saveBasket();
    void deleteBasket();
    void initBasket();
    void showMenu();
    void search();
    void insert();
    void remove();
    void calPrice();
    void calAll();
    void sort();
    void vswap(Vegetable& a, Vegetable& b);
    void doOp(int op);
    void showInfo(Vegetable& v);
    void showAll();
private:
    int sum_count;
    double sum_price;
    Vegetable* v;
    int members;
};

void DLink::initBasket() {
    sum_count = 0;
    sum_price = 0;
    string junk;
    ifstream input("data.dat");
    input >> junk >> members;
    v = new Vegetable[20];
    for (int i = 0; i < members; i++) {
        input >> junk >> v[i].num >> junk >> v[i].name >> junk >> v[i].seller >> junk >> v[i].price >> junk >> v[i].vcount >> junk >> v[i].discount >> junk >> v[i].total_price >> junk >> v[i].rank;
    v[i].total_price = v[i].price * v[i].vcount * (1 - v[i].discount);
    }
}

void DLink::saveBasket() {
    ofstream output("data.dat");
    output << "总数: " << members << endl << endl;
    for (int i = 0; i < members; i++) {
        output << "编号:" << v[i].num << endl;
        output << "菜名:" << v[i].name << endl;
        output << "卖菜人:" << v[i].seller << endl;
        output << "单价:" << v[i].price << endl;
        output << "数量:" << v[i].vcount << endl;
        output << "优惠折扣:" << v[i].discount << endl;
        output << "金额:" << v[i].total_price << endl;
        output << endl;
    }
}

void DLink::deleteBasket() {
    delete [] v;
}


void DLink::showMenu() {
    cout << "请输入相应的数字选项" << endl;
    cout << "-----------------------" << endl;
    cout << "(1)输入一个菜名，查询该菜名的信息并输出，若不存在显示没找到" << endl;
    cout << "(2)输入一个新菜名的信息，按编号顺序将该信息插入后输出" << endl;
    cout << "(3)输入一个已存在菜名信息，删除该菜名的信息后输出" << endl;
    cout << "(4)求每个菜名的金额" << endl;
    cout << "(5)求所有菜的总数量和总金额并输出" << endl;
    cout << "(6)对所有菜进行升序排序并输出其信息" << endl;
    cout << "(7)退出" << endl;
}

void DLink::search() {
    string sname;
    bool hasFound = false;
    cout << "请输入要查找的菜名:" << endl;
    cin >> sname;
    int i = 0;
    while (!hasFound && i < members) {
        if (v[i].name == sname) hasFound = true;
        else i++;
    }
    if (hasFound == true)
        showInfo(v[i]);
    else
        cout << "未找到" << endl;
}

void DLink::insert() {
    Vegetable tmp;
    cout << "请输入新菜名的信息:" << endl;
    cout << "编号:";
    cin >> tmp.num;
    cout << "菜名:";
    cin >> tmp.name;
    cout << "卖菜人:";
    cin >> tmp.seller;
    cout << "单价:";
    cin >> tmp.price;
    cout << "数量:";
    cin >> tmp.vcount;
    cout << "优惠折扣:";
    cin >> tmp.discount;
    cout << "金额:";
    cout << endl;
    tmp.total_price = tmp.price * tmp.vcount * (1 - tmp.discount);
    cout << tmp.total_price;
    tmp.rank = 0;
    int i;
    for (i = 0; i < members; i++) {
        if (tmp.num < v[i].num) {
            break;
        }
    }
    int j;
    for (j = members; j >= i+1; j--) {
        v[j] = v[j-1];
    }
    v[j] = tmp;
    members++;
}

void DLink::remove() {
    bool has_found = false;
    string dname;
    cout << "请输入要删除的菜名:" << endl;
    cin >> dname;
    int j;
    for (int i = 0; i < members; i++) {
        if (v[i].name == dname) {
            for (j = i; j < members-1; j++) {
                v[j] = v[j+1];
                has_found = true;
            }
        }
    }
    if (has_found) cout << "删除成功" << endl;
    else cout << "删除失败" << endl;
    members--;
}

void DLink::calPrice() {
    for (int i = 0; i < members; i++) {
        cout << v[i].name << "的金额是:" << v[i].total_price << endl;
    }
}

void DLink::calAll() {
    calPrice();
    system("cls");
    for (int i = 0; i < members; i++) {
        sum_count += v[i].vcount;
        sum_price += v[i].total_price;
    }
    cout << "总数量: " << sum_count << "总金额: " << sum_price << endl;
}

void DLink::sort() {
    int rank = 1;
    for (int i = 0; i < members; i++) {
        int min = i;
        for (int j = i; j < members; j++) {
            min = (v[j].total_price < v[min].total_price) ? j : min;
        }
        vswap(v[i], v[min]);
        v[i].rank = rank++;
    }
    showAll();
}

void DLink::vswap(Vegetable& a, Vegetable& b) {
    Vegetable t = a;
    a = b;
    b = t;
}


void DLink::showInfo(Vegetable& v) {
    cout << endl;
    cout << setw(7) << left << v.num << '|';
    cout << setw(7) << left << v.name << '|';
    cout << setw(7) << left << v.seller << '|';
    cout << setw(7) << left << v.price << '|';
    cout << setw(7) << left << v.vcount << '|';
    cout << setw(7) << left << v.discount << '|';
    cout << setw(7) << left << v.total_price << '|';
    cout << setw(7) << left << v.rank << '|';
    cout << endl;
    cout << "----------------------------------------------------------------";
}

void DLink::showAll() {
    cout << setw(7) << left << "编号" << '|';
    cout << setw(7) << left << "菜名" << '|';
    cout << setw(7) << left << "卖菜人" << '|';
    cout << setw(7) << left << "单价" << '|';
    cout << setw(7) << left << "数量" << '|';
    cout << setw(7) << left << "折扣" << '|';
    cout << setw(7) << left << "总价" << '|';
    cout << setw(7) << left << "排名" << '|';
    cout << endl << "----------------------------------------------------------------";
    for (int i = 0; i < members; i++)
        showInfo(v[i]);
}

void DLink::doOp(int op) {
    switch (op)
    {
        case 1:
            search();
            break;
        case 2:
            insert();
            system("cls");
            showAll();
            break;
        case 3:
            remove();
            break;
        case 4:
            calPrice();
            break;
        case 5:
            calAll();
            break;
        case 6:
            sort();
            break;
        default:
            cout << "error";
            break;
    }
}

int main()
{
    int op;
    DLink a;
    a.showMenu();
    while (cin >> op && op != 7) {
        // system("cls");
        a.doOp(op);
        cout << endl << endl << "按任意键继续";
        getchar();
        getchar();
        system("cls");
        a.showMenu();
    }
    a.saveBasket();
    return 0;
}