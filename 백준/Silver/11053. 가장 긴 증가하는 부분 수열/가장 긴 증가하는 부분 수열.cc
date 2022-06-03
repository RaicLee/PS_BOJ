/**
 * @Author: Yshinobu
 * @Date:   2022-06-03 13:29:27
 * @Last Modified by:   Yshinobu
 * @Last Modified time: 2022-06-03 14:36:59
 */
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    int N;
    cin>>N;
    vector<int> vec;
    vec.push_back(0);
    for (int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        vec.push_back(num);
    }
    int dp[1001];
    fill(dp,dp+1001,1);
    int answer = 0;
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=i;j++)
        {
            if (vec[i] > vec[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        answer = max(answer,dp[i]);
    }
    cout<<answer<<endl;
    return 0;
}
