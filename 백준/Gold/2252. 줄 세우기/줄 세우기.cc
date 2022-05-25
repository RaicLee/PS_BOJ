#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

list<int> edges[33000];
int indegree[33000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    for (int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_front(b);
        indegree[b]++;
    }
    queue<int> q;
    for (int i=1;i<=N;i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int now = q.front();q.pop();
        cout<<now<<" ";
        for (auto i: edges[now])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    cout<<endl;
}