#include <bits/stdc++.h>
using namespace std;

//nu am nicio idee cum imi scuipa asta un random, am furat-o dintr-un generator
mt19937 get_rng() {
	seed_seq seq {
		(uint64_t) chrono::duration_cast<chrono::nanoseconds>(
			chrono::high_resolution_clock::now().time_since_epoch()).count(),
		(uint64_t) __builtin_ia32_rdtsc(),
		(uint64_t) (uintptr_t) unique_ptr<char>(new char).get()
	};
	return mt19937(seq);
}
auto rng = get_rng();

int main() {
    freopen("sdo.in", "r", stdin);
    freopen("sdo.out", "w", stdout);
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, K; cin >> N >> K;
    vector<int>A(N + 3);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }    
    int le = 1, ri = 1e9, ans = 1;
    while(true) {
        uniform_int_distribution<>distrib(le, ri);
        int val = distrib(rng);
        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            if(A[i] < val) {
                cnt++;
            }
        }
        if(cnt < K) {
            ans = val;
            le = val + 1;
        }
        else {
            ri = val - 1;
        }
        if(le > ri) break;
    }
    cout << ans;
}