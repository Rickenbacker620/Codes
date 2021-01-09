#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;

using mymap = multimap<string, int>;

void
print(multimap<string, int> T)
{
    cout << T.size() << endl;
    for (auto &i : T)
    {
        auto [name, num] = i;
        cout << name << num << endl;
    }
}
int
main()
{
    mymap T;
    // T["red"] = 32;
    // T["blue"] = 688;
    // T["yellow"] = 122;
    // T["blue"] += 312;
    // T["blue"] = 10;

    // print(T);

    T.insert(make_pair("zebra", 101010));
    T.insert(make_pair("white", 0));
    T.insert(make_pair("zebra", 20));

    print(T);

    // pair<string, int> target = *T.find("red");
    // cout << target.first << "-->" << target.second << endl;
    return 0;
}