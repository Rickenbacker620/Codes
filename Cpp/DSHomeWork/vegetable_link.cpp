#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
using namespace std;

struct Vegetable {
    int num;
    string name;
    string seller;
    double price;
    double discount;
    int vcount;
    double total_price;
    int rank;
};

struct Node {
    Vegetable v;
    Node* prev;
    Node* next;
    Node(Vegetable v)
    {
        this->v = v;
    }
    Node(Vegetable v, Node* p)
    {
        this->v = v;
        this->next = p->next;
        this->prev = p;
        p->next = this;
    }
};


class DLink
{
public:
    DLink() { initialize(); }
    ~DLink() {
        savedata();
        deletedata();
    }
    void savedata();
    void deletedata();
    void initialize();
    void showMenu();
    void search();
    void insert();
    void remove();
    void calPrice();
    void calAll();
    void sort();
    void doOp(int op);
    void showInfo(Node* v);
    void showAll();
private:
    Node* head;
    int length;
    int sum_count;
    double sum_price;
};


void DLink::initialize() {
    sum_count = 0;
    sum_price = 0;
    ifstream input("data.dat");
    string junk;
    input >> junk >> length;
    Vegetable tmp;
    input >> junk >> tmp.num >> junk >> tmp.name >> junk >> tmp.seller >> junk >> tmp.price >> junk >> tmp.vcount >> junk >> tmp.discount >> junk >> tmp.total_price >> junk >> tmp.rank;
    head = new Node(tmp);
    head->v.total_price = tmp.price * tmp.vcount * (1 - tmp.discount);
    head->next = nullptr;
    head->prev = nullptr;
    Node* cur = head;
    for (int i = 0; i < length-1; i++) {
        Vegetable tmp;
        input >> junk >> tmp.num >> junk >> tmp.name >> junk >> tmp.seller >> junk >> tmp.price >> junk >> tmp.vcount >> junk >> tmp.discount >> junk >> tmp.total_price >> junk >> tmp.rank;
        Node* t = new Node(tmp, cur);
        t->v.total_price = tmp.price * tmp.vcount * (1 - tmp.discount);
        cur = t;
    }
}


void DLink::savedata() {
    ofstream output("data.dat");
    Node* cur = head;
    output << "����: " << length << endl << endl;
    while(cur != nullptr) {
        output << "���: " << cur->v.num << endl;
        output << "����: " << cur->v.name << endl;
        output << "������: " << cur->v.seller << endl;
        output << "����: " << cur->v.price << endl;
        output << "����: " << cur->v.vcount << endl;
        output << "�Ż��ۿ�: " << cur->v.discount << endl;
        output << "���: " << cur->v.total_price << endl;
        output << "��������: " << cur->v.rank << endl;
        output << endl;
        cur = cur->next;
    }
}


void DLink::deletedata() {
    Node* cur = head, *tmp = nullptr;
    while(cur != nullptr) {
        tmp = cur->next;
        delete cur;
        cur = tmp;
    }
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
    bool has_found = false;
    string sname;
    Node* cur = head;
    cout << "������Ҫ���ҵĲ���:" << endl;
    cin >> sname;
    while (!has_found && cur != nullptr) {
        if (cur->v.name == sname)
            has_found = true;
        else cur = cur->next;
    }
    if (has_found == true)
        showInfo(cur);
    else
        cout << "δ�ҵ�" << endl;
}

void DLink::insert() {
    Vegetable v;
    cout << "�������²�������Ϣ:" << endl;
    cout << "���:";
    cin >> v.num;
    cout << "����:";
    cin >> v.name;
    cout << "������:";
    cin >> v.seller;
    cout << "����:";
    cin >> v.price;
    cout << "����:";
    cin >> v.vcount;
    cout << "�Ż��ۿ�:";
    cin >> v.discount;
    v.total_price = 0;
    v.rank = 0;
    Node* cur = head;
    while (cur->v.num <= v.num) {
        if (cur->next == nullptr)
            break;
        cur = cur->next;
    }
    if (cur->next == nullptr)
        new Node(v, cur);
    else
        new Node(v, cur->prev);
    length++;
}

void DLink::remove() {
    bool has_found = false;
    string dname;
    Node* cur = head;
    cout << "������Ҫɾ���Ĳ���:" << endl;
    cin >> dname;
    while (!has_found && cur != nullptr) {
        if (cur->v.name == dname) {
            if (cur->prev == nullptr)
            {
                cur->next->prev = cur->prev;
                head = cur->next;
            }
            else if (cur->next != nullptr)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            delete cur;
            has_found = true;
        }
        else cur = cur->next;
    }
    if (has_found) cout << "ɾ���ɹ�" << endl;
    else cout << "δ�ҵ���ɾ��ʧ��" << endl;
    length--;
}

void DLink::calPrice() {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->v.name << "�Ľ����:" << cur->v.total_price << endl;
        cur = cur->next;
    }
}

void DLink::calAll() {
    Node* cur = head;
    while (cur != nullptr) {
        sum_count += cur->v.vcount;
        sum_price += cur->v.total_price;
        cur = cur->next;
    }
    cout << "������: " << sum_count << "�ܽ��: " << sum_price << endl;
}

void DLink::sort() {
    Node* cur = head;
    for (int i = 0; i < length; i++) {
        Node* minv = cur, *tmp = cur;
        for (int j = i; j < length; j++) {
            if (minv->v.price > tmp->v.price)
                minv = tmp;
            tmp = tmp->next;
        }
        swap(minv->v, cur->v);
        cur->v.rank = i+1;
        cur = cur->next;
    }
    showAll();
}

void DLink::showInfo(Node* p) {
    Vegetable v = p->v;
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
    Node* cur = head;
    while (cur != nullptr){
        showInfo(cur);
        cur = cur->next;
    }
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
            showAll();
            break;
        case 4:
            calPrice();
            break;
        case 5:
            calAll();
            break;
        case 6:
            // sort();
            showAll();
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
        system("cls");
        a.doOp(op);
        cout << endl << endl << "�����������";
        getchar();
        getchar();
        system("cls");
        a.showMenu();
    }
    return 0;
}