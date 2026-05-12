//https://kilonova.ro/submissions/163664
//e un cod mai vechi
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int MAX = 50000;
int N;
char c[MAX + 3];
bool a[6][MAX + 3];
int dim[6];

bool F(int dim1) {
    //cout << dim1 << ' ';
    map<long long, int>m1;
    for(int i = 1; i <= N; i++) {
        long long hash = 0;
        for(int j = 1; j <= dim[i]; j++) {
            if(j > dim1) {
                hash -= 2 * a[i][j - dim1];
                hash = 1LL * hash >> 1;
                hash += (1LL * 1 << dim1) * a[i][j];
            }
            else {
                hash += (1LL * 1 << j) * a[i][j];
            }
            //if(dim1 == 1) cout << hash << ' ';
            if(j >= dim1) { 
            m1[hash] += (1 << (i - 1));
            if(m1[hash] == (1 << N) - 1) return true;
            }
        }
       // cout << '\n';
       //if(dim1 == 1) cout << m1[2] << ' ';
    }
    return false;
}


int main() {
    freopen("subsecvente.in", "r", stdin);
    freopen("subsecvente.out", "w", stdout);
    cin >> N;
    cin.get();
    for(int i = 1; i <= N; i++) {
        cin.getline(c, MAX);
        int M = strlen(c);
        for(int j = 0; j < M; j++) {
            if(c[j] == 'a') a[i][j + 1] = 0;
            else a[i][j + 1] = 1;
        }
        dim[i] = M + 1;
    }
    int st = 1, dr = 60, best = 0;
    while(st <= dr) {
        int mid = (st + dr) / 2;
        if(F(mid)) {
            best = mid;
            st = mid + 1;
        }
        else dr = mid - 1;
    }
    cout << best;
}