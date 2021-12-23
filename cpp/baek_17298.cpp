#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int N;
stack<int> s;
int ans[1000001];
int arr[1000001];

int main()
{
	cin >> N;

	// 수열 입력받기 
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= arr[i])
			s.pop();

		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(arr[i]);
	}
	
	// 정답 출력
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
}