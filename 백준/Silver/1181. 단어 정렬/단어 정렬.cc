/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl "\n"
using namespace std;

bool comp(const string &s1, const string &s2)
{
    if (s1.length() < s2.length())
        return true;
    if (s1.length() == s2.length())
        return s1 < s2;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<string> vec;
    for (int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        vec.emplace_back(s);
    }
    sort(vec.begin(),vec.end(),comp);
    for (int i=0;i<vec.size();i++)
    {
        if (vec[i] != vec[i+1])
            cout<<vec[i]<<endl;
    }
        

    return 0;
}