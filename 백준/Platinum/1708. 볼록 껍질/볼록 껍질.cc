#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stack>
#define MAX 100001
using namespace std;

int N;
typedef long long ll;
typedef struct point {
	ll x;
	ll y;
	ll p,q;
}POINT;
POINT arr[MAX];

bool comp(const POINT &A, const POINT &B)
{
	if (A.y != B.y)
		return (A.y < B.y);
	return (A.x < B.x);
}

bool comp2(const POINT &A, const POINT &B)
{
	if (1LL * A.q *B.p != 1LL * A.p * B.q)
		return (1LL * A.q *B.p) < (1LL * A.p * B.q);
	if (A.y != B.y)
		return A.y < B.y;
	return A.x < B.x;
}

ll ccw(POINT p, POINT q)
{
	return 1LL * (1LL * p.x * q.y - 1LL * p.y * q.x);
}
ll ccw2(POINT r, POINT p, POINT q)//r - p 선분중심 q위치
{
	POINT p_r, q_r;
	p_r.x = p.x - r.x;
	p_r.y = p.y - r.y;
	q_r.x = q.x - r.x;
	q_r.y = q.y - r.y;
	return ccw(p_r, q_r);
}
void solve()
{
	cin >> N;//N <=100,000 --> needs nlogn solution
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].x >> arr[i].y;
		arr[i].p = -1; arr[i].q = -1;
	}
	sort(arr, arr + N, comp);
	for (int i = 1; i < N; i++)
	{
		arr[i].p = arr[i].x - arr[0].x;
		arr[i].q = arr[i].y - arr[0].y;
	}
	sort(arr + 1, arr + N, comp2);
	stack<int> st;
	st.push(0);
	st.push(1);
	int idx = 2;
	while (idx < N)
	{
		while (st.size() >= 2)
		{
			int previous = st.top(); st.pop();
			int pprevious = st.top();
			if (ccw2(arr[pprevious], arr[previous], arr[idx]) > 0)
			{//시계방향일때
				st.push(previous);
				break;
			}
		}
		st.push(idx);
		idx++;
	}
	cout << st.size() << endl;
	
}
int main()
{
	//freopen("sample_input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	

	return 0;
}