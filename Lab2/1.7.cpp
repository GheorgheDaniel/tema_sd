#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string ans;
    vector<int>fr(300), used(300);
    for(int i = 0; i < s.size(); i++) {
        fr[s[i]]++;
    }
    string s1;
    for(int i = 0; i < s.size(); i++) {
        if(fr[s[i]] % 2 == 1) s1 += s[i];
    }

    for(int i = 0; i < s1.size(); i++) {
        fr[s1[i]]--;
        if(used[s1[i]]) continue;
        while(ans.size() > 0 && ans.back() > s1[i] && fr[ans.back()] > 0) {
            used[ans.back()] = 0;
            ans.pop_back();
        }
        if(used[s1[i]] == 0) {
            ans += s1[i];
            used[s1[i]] = 1;
        }
    }
    cout << ans;
}
