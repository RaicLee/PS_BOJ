/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int N;
int map[26][26];
bool visited[26][26];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int dfs(int y,int x)
{
    int sum = 1;
    visited[y][x] = true;
    for (int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (!map[ny][nx])
            continue;
        if (visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        sum += dfs(ny,nx);
    }
    return sum;
}
int main()
{
    cin>>N;
    for (int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            char ch;
            cin>>ch;
            (ch == '0')?map[y][x] = 0:map[y][x]=1;
        }
    }
    int result = 0;
    vector<int> res;
    for (int y=0;y<N;y++)
    {
        for (int x =0;x<N;x++)
        {
            if (map[y][x] == 1 && visited[y][x] == false)
            {
                visited[y][x] = true;
                result++;
                res.push_back(dfs(y,x));
            }
        }
    }
    sort(res.begin(),res.end());
    cout<<result<<endl;
    for (auto i:res)
        cout<<i<<endl;
    return 0;
}