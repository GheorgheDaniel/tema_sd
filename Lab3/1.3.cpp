#include <bits/stdc++.h>
using namespace std;

class StringHashing{
    const int MOD = 1e9 + 7;
    public:
    unsigned long long gethash(string &a) {
        unsigned long long val = 0;
        unsigned long long pw = 1;
        for(int i = 0; i < a.size(); i++) {
            val += ((a[i] - 'a' + 1) * pw);
            pw *= 27;
        }
        return val;
    }
    
};

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    StringHashing SH;
    unordered_map<unsigned long long, int>m;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        unsigned long long hsh = SH.gethash(s);
        if(m.count(hsh)) cout << 1 << '\n';
        else cout << 0 << '\n';
        m[hsh]++;
    }

}