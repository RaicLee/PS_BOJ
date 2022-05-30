/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define endl "\n"
#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int map[101][101];
int main()
{
    fastio();
    int N;
    cin>>N;
    for (int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>map[i][j];
        }
    }
    
    for (int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            //if (k == i) continue;
            for(int j=0;j<N;j++)
            {
                //if (k == j || i == j) continue;
                if (map[i][k] == 1 && map[k][j] == 1)
                    map[i][j] = 1;
            }
        }
    }
    for (int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}