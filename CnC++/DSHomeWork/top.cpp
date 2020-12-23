#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int d[N],n,m,top[N],cnt = 1;

struct node
{
    int vertex;
    node* nextarc = nullptr;
};

node g[N];

// struct hnode
// {
//     int vertex;
//     node* firstarc = nullptr;
// };


void add(int a, int b)
{
    node* tmp = new node();
    tmp->nextarc = g[a].nextarc;
    g[a].nextarc = tmp;
}


// void add(int a,int b)
// {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx ++;
// }
bool topsort(){
    queue<int> q;
    int t;
    for(int i = 1;i <= n; ++i)// 将所有入度为0的点加入队列
        if(d[i] == 0) q.push(i);
    while(q.size()){
        t = q.front();//每次取出队列的首部
        top[cnt] = t;//加入到 拓扑序列中
        cnt ++; // 序列中的元素 ++
        q.pop();
        for(int i = h[t];i != -1; i = ne[i]){
            // 遍历 t 点的出边
            int j = e[i];
            d[j] --;// j 的入度 --
            if(d[j] == 0) q.push(j); //如果 j 入度为0，加入队列当中
        }
    }
    if(cnt < n) return 0;
    else return 1;

}
int main(){
    int a,b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].vertex = i;
    while(m--){
        cin >> a >> b;
        add(a,b);
        d[b] ++;
    }
    if(topsort() == 0) cout << "-1";
    else {
        for(int i = 1;i <= n; ++i){
            cout << top[i] <<" ";
        }
    }
    return 0;
}