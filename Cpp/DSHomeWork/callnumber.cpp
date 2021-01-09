#include "queue_2.h"
#include <Windows.h>
using namespace std;

class Number
{
public:
    Number();
    void getNum();
    void queryNum();
    void callNum();
    void showMenu();
private:
    Myqueue<int> q;
    int idx;
};

Number::Number()
{
    idx = 1;
}


void Number::showMenu()
{
    cout << "********���нк���********" << endl;
    cout << "1)ȡ��" << endl;
    cout << "2)��ѯ" << endl;
    cout << "3)�к�" << endl;
    cout << "4)�˳�" << endl;
}

void Number::getNum()
{
    q.push(idx);
    cout << "���ĺ�����" << idx << endl;
    cout << "ǰ�滹��" << q.getLen()-1 << "��" << endl;
    idx++;
}

void Number::queryNum()
{
    int num;
    cout << "���������ĺ���(����0��ѯ�����ܳ���):" << endl;
    cin >> num;
    if (num)
        cout << "ǰ�滹��" << num - q.getHead() << "��" << endl;
    else
        cout << "�����ܹ���" << q.getLen() << "��" << endl;
}

void Number::callNum()
{
    cout << "��" << q.getHead() << "�Ű���ҵ��" << endl;
    q.pop();
}


int main()
{
    int op;
    bool flag = 1;
    Number q;
    while (flag)
    {
        system("cls");
        q.showMenu();
        cin >> op;
        cout << "-------------------" << endl;
        switch (op)
        {
        case 1:
            q.getNum();
            system("pause");
            break;
        case 2:
            q.queryNum();
            system("pause");
            break;
        case 3:
            q.callNum();
            system("pause");
            break;
        case 4:
            flag = 0;
        default:
            break;
        }
    }
    return 0;
}