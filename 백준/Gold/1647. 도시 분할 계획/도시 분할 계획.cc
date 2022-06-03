/**
 * @Author: Yshinobu
 * @Date:   2022-06-02 16:39:35
 * @Last Modified by:   Yshinobu
 * @Last Modified time: 2022-06-03 11:24:54
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define MAX_N 100001
using namespace std;
struct p{
    int u,v,w;
};
vector<p> roads;
int parent[MAX_N];
int answer,cnt;
bool comp(const p &a, const p &b)
{
    return a.w < b.w;
}
int find(int a)
{
    if (parent[a] == a)return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b,int w)
{
    a = find(a);
    b = find(b);
    if (a==b) return;
    parent[b] = a;
    answer += w;
    cnt++;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    for (int i=1;i<=N;i++)parent[i] = i;
    for (int i=0;i<M;i++)
    {
        p now;
        cin>>now.u>>now.v>>now.w;
        roads.push_back(now);
    }
    sort(roads.begin(),roads.end(),comp);
    for (int i = 0; i<M;i++)
    {
        p now = roads[i];
        Union(now.u,now.v,now.w);
        if (cnt == N-2) break;
    }
    cout<<answer<<endl;
    return 0;
}
