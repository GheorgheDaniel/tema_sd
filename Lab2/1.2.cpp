#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("strabunica.in", "r", stdin);
    freopen("strabunica.out", "w", stdout); 

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
	vector<int>le(N + 3), ri(N + 3);
	for(int i = 1; i <= N; i++) {
		while(A[s.back()] >= A[i]) s.pop_back();
		le[i] = s.back();
		s.push_back(i);
	}

	s.clear();
	s.push_back(N + 1);

	for(int i = N; i >= 1; i--) {
		while(A[s.back()] >= A[i]) s.pop_back();
		ri[i] = s.back();
		s.push_back(i);
	}
	
	long long ans = 0;
	for(int i = 1; i <= N; i++) {
		ans = max(ans, 1LL * A[i] * (ri[i] - le[i] - 1));
	}
	cout << ans;
}