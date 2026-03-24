#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("fadema.in", "r", stdin);
    freopen("fadema.out", "w", stdout); 

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

	int N, M;
    cin >> N >> M;
	vector<vector<int>>A1(N + 3, vector<int>(M + 3));
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			cin >> A1[i][j];
		}
	}	
	long long ans = 0;
	vector<int>A(M + 3);
	for(int i = 1; i <= N; i++) {

		vector<int>s;
		s.push_back(0);
		vector<int>le(M + 3), ri(M + 3);
		A[0] = A[M + 1] = -1;

		for(int j = 1; j <= M; j++) {
			if(i == 1 || A1[i][j] != A1[i - 1][j]) A[j]++;	
			else A[j] = 1;
		}
		for(int i = 1; i <= M; i++) {
			while(A[s.back()] >= A[i]) s.pop_back();
			le[i] = s.back();
			s.push_back(i);
		}

		s.clear();
		s.push_back(M + 1);

		for(int i = M; i >= 1; i--) {
			while(A[s.back()] >= A[i]) s.pop_back();
			ri[i] = s.back();
			s.push_back(i);
		}

		int bad = 0;
		for(int j = 1; j <= M; j++) {
			if(A1[i][j] == A1[i][j - 1]) bad = j - 1;
			le[j] = max(le[j], bad);
		}

		bad = M + 1;
		for(int j = M; j >= 1; j--) {
			if(A1[i][j] == A1[i][j + 1]) bad = j + 1;
			ri[j] = min(ri[j], bad);
		}

		for(int i = 1; i <= M; i++) {
			ans = max(ans, 1LL * A[i] * (ri[i] - le[i] - 1));
		}
	}
	cout << ans;
}