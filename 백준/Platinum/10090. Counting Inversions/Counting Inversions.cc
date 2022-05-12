#include <iostream>
using namespace std;

long long sum;
int arr[1000001];
int temp[1000001];
void merge(int left,int mid,int right)
{
    int i = left;
    int j = mid+1;
    int tCount = left;
    
    while (i<=mid && j<=right)
    {
        if (arr[i]<=arr[j])
            temp[tCount++] = arr[i++];
        else
        {
            temp[tCount++] = arr[j++];
            sum += (mid - i + 1);
        }
    }
    while (i <= mid)
        temp[tCount++] = arr[i++];
    while (j <= right)
        temp[tCount++] = arr[j++];
    for (int i=left; i<=right;i++)
        arr[i] = temp[i];
}
void mergeSort(int left,int right)
{
    if (left == right)
        return ;
    int mid = (left+right)>>1;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    mergeSort(1,n);
    cout<<sum<<"\n";
    return 0;
}