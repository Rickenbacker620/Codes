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
    cout << "********银行叫号器********" << endl;
    cout << "1)取号" << endl;
    cout << "2)查询" << endl;
    cout << "3)叫号" << endl;
    cout << "4)退出" << endl;
}

void Number::getNum()
{
    q.push(idx);
    cout << "您的号码是" << idx << endl;
    cout << "前面还有" << q.getLen()-1 << "人" << endl;
    idx++;
}

void Number::queryNum()
{
    int num;
    cout << "请输入您的号码(输入0查询队伍总长度):" << endl;
    cin >> num;
    if (num)
        cout << "前面还有" << num - q.getHead() << "人" << endl;
    else
        cout << "队伍总共有" << q.getLen() << "人" << endl;
}

void Number::callNum()
{
    cout << "请" << q.getHead() << "号办理业务" << endl;
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