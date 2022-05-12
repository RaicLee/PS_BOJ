#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[101][101][101];
int main()
{
    string s1,s2,s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    int s1Len = s1.length();
    int s2Len = s2.length();
    int s3Len = s3.length();
    
    for (int i=1;i<=s1Len;i++)
    {
        for(int j=1;j<=s2Len;j++)
        {
            for (int k=1;k<=s3Len;k++)
            {
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                else
                {
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k]);
                    dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);    
                }
            }
        }
    }
    cout<<dp[s1Len][s2Len][s3Len]<<endl;
    /*
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
    */
    return 0;
}