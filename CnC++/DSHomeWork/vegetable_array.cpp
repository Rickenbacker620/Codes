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
    output << "����: " << members << endl << endl;
    for (int i = 0; i < members; i++) {
        output << "���:" << v[i].num << endl;
        output << "����:" << v[i].name << endl;
        output << "������:" << v[i].seller << endl;
        output << "����:" << v[i].price << endl;
        output << "����:" << v[i].vcount << endl;
        output << "�Ż��ۿ�:" << v[i].discount << endl;
        output << "���:" << v[i].total_price << endl;
        output << endl;
    }
}

void DLink::deleteBasket() {
    delete [] v;
}


void DLink::showMenu() {
    cout << "��������Ӧ������ѡ��" << endl;
    cout << "-----------------------" << endl;
    cout << "(1)����һ����������ѯ�ò�������Ϣ�����������������ʾû�ҵ�" << endl;
    cout << "(2)����һ���²�������Ϣ�������˳�򽫸���Ϣ��������" << endl;
    cout << "(3)����һ���Ѵ��ڲ�����Ϣ��ɾ���ò�������Ϣ�����" << endl;
    cout << "(4)��ÿ�������Ľ��" << endl;
    cout << "(5)�����в˵����������ܽ����" << endl;
    cout << "(6)�����в˽������������������Ϣ" << endl;
    cout << "(7)�˳�" << endl;
}

void DLink::search() {
    string sname;
    bool hasFound = false;
    cout << "������Ҫ���ҵĲ���:" << endl;
    cin >> sname;
    int i = 0;
    while (!hasFound && i < members) {
        if (v[i].name == sname) hasFound = true;
        else i++;
    }
    if (hasFound == true)
        showInfo(v[i]);
    else
        cout << "δ�ҵ�" << endl;
}

void DLink::insert() {
    Vegetable tmp;
    cout << "�������²�������Ϣ:" << endl;
    cout << "���:";
    cin >> tmp.num;
    cout << "����:";
    cin >> tmp.name;
    cout << "������:";
    cin >> tmp.seller;
    cout << "����:";
    cin >> tmp.price;
    cout << "����:";
    cin >> tmp.vcount;
    cout << "�Ż��ۿ�:";
    cin >> tmp.discount;
    cout << "���:";
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
    cout << "������Ҫɾ���Ĳ���:" << endl;
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
    if (has_found) cout << "ɾ���ɹ�" << endl;
    else cout << "ɾ��ʧ��" << endl;
    members--;
}

void DLink::calPrice() {
    for (int i = 0; i < members; i++) {
        cout << v[i].name << "�Ľ����:" << v[i].total_price << endl;
    }
}

void DLink::calAll() {
    calPrice();
    system("cls");
    for (int i = 0; i < members; i++) {
        sum_count += v[i].vcount;
        sum_price += v[i].total_price;
    }
    cout << "������: " << sum_count << "�ܽ��: " << sum_price << endl;
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
    cout << setw(7) << left << "���" << '|';
    cout << setw(7) << left << "����" << '|';
    cout << setw(7) << left << "������" << '|';
    cout << setw(7) << left << "����" << '|';
    cout << setw(7) << left << "����" << '|';
    cout << setw(7) << left << "�ۿ�" << '|';
    cout << setw(7) << left << "�ܼ�" << '|';
    cout << setw(7) << left << "����" << '|';
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
        cout << endl << endl << "�����������";
        getchar();
        getchar();
        system("cls");
        a.showMenu();
    }
    a.saveBasket();
    return 0;
}