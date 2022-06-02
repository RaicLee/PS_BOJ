/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define endl "\n"
using namespace std;

typedef pair<int,int> pii;

int ccw(pii a, pii b, pii c)
{
    long long result = 1LL * a.first * b.second + 1LL * b.first * c.second + 1LL * c.first * a.second;
    result -= (1LL * a.second*b.first + 1LL * b.second * c.first + 1LL * c.second * a.first);
    if (result > 0)
        return 1;
    else if (result == 0)
        return 0;
    else
        return -1;
}

int main()
{
    pii a,b,c,d;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;
    cin>>d.first>>d.second;
    int r1 = ccw(a,b,c);
    int r2 = ccw(a,b,d);
    int r3 = ccw(c,d,a);
    int r4 = ccw(c,d,b);
    
    //1
    if (r1 * r2 == 0 && r3 * r4 == 0)
    {
        if (a>b) swap(a,b);
        if (c>d) swap(c,d);
        if (a <= d && c <= b)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    else
    {
        if (r1 * r2 <= 0 && r3 * r4 <= 0)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    
    
}