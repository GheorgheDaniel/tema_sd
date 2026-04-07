#include <bits/stdc++.h>
using namespace std;


int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);

    int N; cin >> N;
    int cel = 0;
    for(int i = 1; i < N; i++) {
        if(knows(cel, i)) cel = i;
    }

    for(int i = 0; i < N; i++) {
        if(cel == i) continue ;
        if(knows(cel, i) == 1 || knows(i, cel) == 0) {
            cout << "nu am celebritate";
            return 0 ;
        }

    }

    cout << cel;
}