#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

int N, M;
long long tree[MAX] = {0};
long long result = 0;

long long bsearch(int low, int high) {
  long long sum = 0;
  long long mid = (low  + high) / 2;

  if(low > high)
    return result;

  for(int i = 0; i < N; i++) {
    if(tree[i] < mid)
      break;
    sum += tree[i] - mid;
  }

  if(sum >= M)
    result = result < mid ? mid : result;

  if(sum > M)
    return bsearch(mid + 1, high);
  else
    return bsearch(low, mid - 1);
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    cin >> tree[i];
  sort(tree, tree + N, greater<int>());
  cout << bsearch(0, tree[0]);
}