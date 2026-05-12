//https://www.infoarena.ro/job_detail/3353949?action=view-source
#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("secv5.in", "r", stdin);
    freopen("secv5.out", "w", stdout);
    int N, L, U;
    cin >> N >> L >> U;

    vector<long long>A(N + 3);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int left = 1, right = 1;
    unordered_map<long long, int>multe, putine;
    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        putine[A[i]]++;
        multe[A[i]]++;

        bool ok = 0;
        while(putine.size() >= L) {
            putine[A[right]]--;
            if(putine[A[right]] == 0) putine.erase(A[right]);
            right++;
            ok = 1;
        }
        if(ok) {
            right--;
            putine[A[right]]++;
        }

        while(multe.size() > U) {
            multe[A[left]]--;
            if(multe[A[left]] == 0) multe.erase(A[left]);
            left++;
        }
        if(putine.size() == L) {
            // cout << left << ' ' << right << ' ' << i << ' ' << '\n';
            ans += right - left + 1;
        }
    }

    cout << ans;
}