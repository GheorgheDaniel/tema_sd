#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout); 

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

	int N;
    cin >> N;
	vector<int>A(N + 3);
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	vector<int>s;
	s.push_back(0);

	for(int i = 1; i <= N; i++) {
		while(A[s.back()] >= A[i]) s.pop_back();
		cout << s.back() << ' '; s.push_back(i);
	}
}