#include <bits/stdc++.h>
using namespace std;

mt19937 rng(6);

int main() {
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int>A(N + 3);

    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<long long>pfx(N + 3);
    vector<long long>pfxA(N + 3);
    unordered_map<int, int>m;
    for(int i = 0; i < N; i++) {
        m[i] = (rng()) % (1 << 30);
        pfx[i] += m[i];
        pfx[i + 1] += pfx[i];
    }

    for(int i = 1; i <= N; i++) {
        if(A[i] >= N) A[i] = 0;
        else A[i] = m[A[i]];
        pfxA[i] = pfxA[i - 1] + A[i];
    }
    
    int Q; cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int l, r; cin >> l >> r;
        if(pfx[r - l] == pfxA[r] - pfxA[l - 1]) {
            cout << 1 << '\n';
        }
        else cout << 0 << '\n';
    }
}

/*

4
0 1 2 0
3
1 3
4 4
1 4

1
1
0

*/