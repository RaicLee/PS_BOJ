#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int s1Len = s1.length();
    int s2Len = s2.length();
    int maxima = 0;
    for (int i=1;i<=s1Len;i++)
    {
        for(int j=1;j<=s2Len;j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[s1Len][s2Len]<<endl;
    return 0;
}