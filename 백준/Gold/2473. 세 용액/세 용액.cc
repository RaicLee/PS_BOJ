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
using namespace std;

typedef long long ll;

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
    sort(vec.begin(),vec.end());
    //two pointer
    ll answer[3];
    ll minima = 4e10;
    for (int i=0;i<N-2;i++)
    {
        ll left = i+1;
        ll right = N-1;
        
        
        while (left < right)
        {
            ll sum = 1LL * vec[i] + vec[left] + vec[right];
            if (abs(sum) < minima)
            {
                minima = abs(sum);
                answer[0] = vec[i];
                answer[1] = vec[left];
                answer[2] = vec[right];
            }
            if (sum > 0)
                right--;
            else if (sum < 0)
                left++;
            else
                break;
        }
    }
    sort(answer,answer+3);
    cout<<answer[0]<<" "<<answer[1]<<" "<<answer[2]<<endl;
}