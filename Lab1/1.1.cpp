#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    vector<int>A(N + 3);
    vector<long long>sp(N + 3);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        sp[i] = sp[i - 1] + A[i];
    }
    long long ans = -1e18;
    int Q; cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int l, r; cin >> l >> r;
        if(l > r) swap(l, r);
        ans = max(ans, sp[r] - sp[l - 1]);
    }
    cout << ans << '\n';
    
}