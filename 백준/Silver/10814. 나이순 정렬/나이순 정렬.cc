/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

typedef struct person{
   int age;
   string name;
   int i;
}P;

bool comp(const P &A, const P &B)
{
    if (A.age < B.age)
        return true;
    if (A.age == B.age)
        return A.i < B.i;
    return false;
}
int main()
{
    fastio();
    int N;
    cin>>N;
    vector<P> vec;
    for (int i=0;i<N;i++)
    {
        P now;
        cin>>now.age;
        cin>>now.name;
        now.i = i;
        vec.emplace_back(now);
    }
    sort(vec.begin(),vec.end(),comp);
    for (int i=0;i<N;i++)
        cout<<vec[i].age<<" "<<vec[i].name<<endl;
    return 0;
}