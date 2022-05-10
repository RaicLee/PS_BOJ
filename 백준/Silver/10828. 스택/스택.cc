#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int order = 0;
	stack<int> st;
    cin >> order;
	getchar();   //getline 으로 받을땐 \n제거 하기 위해 미리 제거
	for (int i = 0; i < order; i++)
	{
		string s;
		getline(cin, s);
		//cout << s << endl;

		if (s.find("push") != s.npos)
		{
			int pos = s.find("push");
			st.push(stoi(s.substr(pos + 5, pos + s.length())));
		}
		else if (s.find("pop") != s.npos)
		{
			if (st.empty()) {
				cout << -1 << '\n';
			}
			
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (s.find("empty") != s.npos)
		{
			if (st.empty()) {
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
		else if (s.find("size") != s.npos)
		{
			cout << st.size() << '\n';
		}
		else if (s.find("top") != s.npos)
		{
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else
				cout << st.top() << '\n';
		}
		else
			cout << "NOTHING" << endl;
	}
	return 0;
}