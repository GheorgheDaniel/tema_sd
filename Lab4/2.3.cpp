//https://www.infoarena.ro/job_detail/3353954?action=view-source
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(6);

int main() {
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
    
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>>G(N + 3);
    for(int i = 1; i <= M; i++) {
        int x, y, cost; cin >> x >> y >> cost;
        G[x].push_back({y, cost});
    }
    
    priority_queue<pair<int, int>>pq;
    pq.push({0, 1});
    vector<int>d(N + 3, 1e9);
    while(!pq.empty()) {
        auto [cost, poz] = pq.top();
        pq.pop();
        
        if(d[poz] > -cost) {
            
            d[poz] = -cost;
        }
        else continue;
        
        for(auto [nod, cost_m] : G[poz]) {
            if(-cost + cost_m < d[nod]) {
                pq.push({-(-cost + cost_m), nod});
            }
        }
    }

    for(int i = 2; i <= N; i++) {
        if(d[i] != 1e9) cout << d[i] << ' ';
        else cout << 0 << ' ';
    }

}

/*



*/