#include <iostream>
#include <string>
#include <algorithm>
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
    
    string result="";
    {
        int i=s1Len;
        int j=s2Len;
        while (i>0 && j>0)
        {
            if (dp[i][j] == dp[i][j-1])
                j--;
            else if (dp[i][j] == dp[i-1][j])
                i--;
            else
            {   i--;
                j--;
                result+=s1[i];
            }
        }
    }
    reverse(result.begin(),result.end());
    cout<<result<<endl;
    return 0;
}