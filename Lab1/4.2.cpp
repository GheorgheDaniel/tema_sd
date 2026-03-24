#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    auto sqrt = [&] (int X) {
        int st = 1, dr = X, best = 0;
        while(st <= dr) {
            int mid = (st + dr) / 2;
            if(1LL * mid * mid <= X) {
                best = mid;
                st = mid + 1;
            }
            else {
                dr = mid - 1;
            }
        }

        return best;
    };

    cout << sqrt(N);

}

/*

    -> Pot cauta in log() cu cautare binara
    -> Pot sa imi precalculez radicalul fiecarui numar atata timp cat imi ajunge memoria

*/