#include <iostream>
#include <memory.h>
#define endl "\n"
#define MOD 1000000007
#define MAX_N 101
#define fastio() ios::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;
ll dp[MAX_N][MAX_N][MAX_N];
void solve()
{
    int L,R,N;//<=20
    memset(dp,0,sizeof(dp));
    cin>>N>>L>>R;
    dp[1][1][1] = 1;//첫번째 건물 높으면 왼쪽 오른쪽 모두 1개씩만 보임
    for (int idx=2;idx<=N;idx++)
    {
        for (int left=1;left<=L;left++)//왼쪽 고정
        {
            for(int right = 1;right<=R;right++)
            {
          
                ll leftPlace = dp[idx - 1][left-1][right];
                ll rightPlace = dp[idx-1][left][right-1];
                ll middlePlace = (idx - 2) * dp[idx-1][left][right];
                dp[idx][left][right] = (leftPlace+ rightPlace + middlePlace)%MOD;
            }
        }
    }
    cout<<dp[N][L][R]<<endl;
}

int main()
{
    fastio();
    int tc;
    //cin>>tc;
    tc=1;
    for (int t=1;t<=tc;t++)
    {
        //cout<<"#"<<t<<" ";
        solve();
    }
}