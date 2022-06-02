/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define endl "\n"
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef long long ll;
int matrix[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    for (int i=0;i<M;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        if (matrix[u][v] != 0)
            matrix[u][v] = min(matrix[u][v],w);
        else
            matrix[u][v] = w;
    }
    for (int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if (i!=j && matrix[i][j] == 0)
                matrix[i][j] = INF;
        }
    }
    for (int k=0;k<N;k++)
    {
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                if (matrix[i][k] != INF && matrix[k][j] != INF)
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    for (int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if (matrix[i][j] == INF) matrix[i][j] = 0;
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}