/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <memory.h>
#include <limits.h>
using namespace std;
int arr[11][11];
int temp[11][11];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
int minima = INT_MAX;

void toggle(int y, int x)
{
    //y,x의 위치를 클릭하여 4분면 방향의 불들의 상태를 전환한다
    temp[y][x] = !temp[y][x];
    for (int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10)
            continue;
        temp[ny][nx] = !temp[ny][nx];
    }
}

//check every arr is off
bool isDark()
{
    for (int y=0;y<10;y++)
    {
        for (int x=0;x<10;x++)
        {
            if (temp[y][x])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int y=0;y<10;y++)
    {
        for (int x=0;x<10;x++)
        {
            char ch;
            cin>>ch;
            if (ch == 'O') arr[y][x] = 1;
            else arr[y][x] = 0;
        }
    }
    
    for (int i=0;i< (1<<10);i++)
    {
        int result = 0;
        memcpy(temp,arr,sizeof(temp));
        for (int j=0;j<10;j++)
        {
            if (i & (1<<j))
            {
                result++;
                toggle(0,j);
            }
        }
        for (int y=1;y<10;y++)
        {
            for (int x=0;x<10;x++)
            {
                if (temp[y-1][x])
                {
                    toggle(y,x);
                    result++;
                }
            }
        }
        if (isDark())
            minima = min(minima,result);
    }
    if (minima == INT_MAX)
        cout<<-1<<endl;
    else
        cout<<minima<<endl;

    return 0;
}