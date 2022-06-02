/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define endl "\n"
#include <vector>
using namespace std;

typedef pair<int,int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> vec;
    for (int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        vec.emplace_back(num);
    }
    //two pointer
    int left = 0;
    int right = N - 1;
    pii ans;
    int minima = 2e9;
    while (left < right)
    {
        int sum = vec[left] + vec[right];
        if (abs(sum) < minima)
        {
            minima = abs(sum);
            ans.first = left;
            ans.second = right;
        }
        if (sum > 0)
            right--;
        else
            left++;
        
    }
    cout<<vec[ans.first]<<" "<<vec[ans.second]<<endl;
}