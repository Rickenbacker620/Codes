#include <iostream>
#include <map>
#include <string>
using namespace std;

using mymap = map<string, int>;

void
print(map<string, int> T)
{
    cout << T.size() << endl;
    for (auto it = T.begin(); it != T.end(); it++)
    {
        pair<string, int> item = *it;
        cout << item.first << "-->" << item.second << endl;
    }
}
int
main()
{
    mymap T;
    T["red"] = 32;
    T["blue"] = 688;
    T["yellow"] = 122;
    T["blue"] += 312;

    print(T);

    T.insert(make_pair("zebra", 101010));
    T.insert(make_pair("white", 0));

    print(T);

    pair<string, int> target = *T.find("red");
    cout << target.first << "-->" << target.second << endl;
    return 0;
}