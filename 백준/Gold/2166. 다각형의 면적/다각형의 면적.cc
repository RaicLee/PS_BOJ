#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
vector<pii> vec;
typedef long long ll;
ll ccw(pii a, pii b, pii c)
{
    ll result = (1LL * a.first * b.second + 1LL * b.first * c.second + 1LL * c.first * a.second);
    result -= (1LL * b.first * a.second + 1LL * c.first * b.second + 1LL * a.first * c.second);
    return 1LL * result;
}

int main()
{
    int N;
    cin>>N;
    for (int i=0;i<N;i++)
    {
        pii now;
        cin>>now.first>>now.second;
        vec.emplace_back(now);
    }
    ll result = 0;
    for (int i=1;i<N-1;i++)
    {
        result += ccw(vec[0],vec[i],vec[i+1]);
    }
    result = abs(result);
    cout<<result/2;
    if (result&1)cout<<".5"<<endl;
    else cout<<".0"<<endl;
    return 0;
}