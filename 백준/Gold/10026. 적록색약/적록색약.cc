/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

char map[101][101];
char RGmap[101][101];
bool visitedMap[101][101];
bool visitedRGMap[101][101];

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int N;

void dfs(int y,int x,char val)
{
    visitedMap[y][x] = true;
    for (int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (visitedMap[ny][nx])
            continue;
        if (map[ny][nx] != val)
            continue;
        visitedMap[ny][nx] = true;
        dfs(ny,nx,val);
    }
}
void dfs2(int y,int x,char val)
{
    visitedRGMap[y][x] = true;
    for (int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (visitedRGMap[ny][nx])
            continue;
        if (RGmap[ny][nx] != val)
            continue;
        visitedRGMap[ny][nx] = true;
        dfs2(ny,nx,val);
    }
}
int main()
{
    cin>>N;
    for (int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            cin>>map[y][x];
            if (map[y][x] == 'R' || map[y][x] == 'G')
                RGmap[y][x] = 'R';
            else
                RGmap[y][x] = 'B';
            
        }
    }
    
    int resOrd = 0;
    int RGres = 0;
    for (int y=0;y<N;y++)
    {
        for (int x=0;x<N;x++)
        {
            if (!visitedMap[y][x])
            {
                visitedMap[y][x] = true;
                dfs(y,x,map[y][x]);
                resOrd++;
            }
            if (!visitedRGMap[y][x])//R & B
            {
                visitedRGMap[y][x] = true;
                dfs2(y,x,RGmap[y][x]);
                RGres++;
            }
            
        }
    }
    cout<<resOrd<<" "<<RGres<<endl;

    return 0;
}