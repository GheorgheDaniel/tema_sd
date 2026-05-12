//https://www.infoarena.ro/problema/ratina
#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 10000;
const int MAX = 200000;
const int ALPHA = 26;
int label = 1;
int step;
int lbl[N_MAX + 3];
int fst[MAX + 3];

int coresp[MAX + 3];
vector<int>euler;
int p;
int level[MAX + 3];

struct Trie{

    struct Node{
        int cnt;
        Node *next[ALPHA];

        Node() {
            cnt = 0;
            for(int i = 0; i < ALPHA; i++) {
                next[i] = NULL;
            }
        }
    };

    Node *root;

    Trie() {
        root = new Node;
        root->cnt = label;
        label++;
    }

    void insert(string &s) {
        Node *curr = root;

        for(auto it : s) {
            if(curr->next[it - 'a'] == NULL) {
                curr->next[it - 'a'] = new Node;
                curr->next[it - 'a']->cnt = label;
                label++;
            }

            curr = curr->next[it - 'a'];
        }
        lbl[step] = curr->cnt;
    }

    
    void dfs(Node *nod, int parent = 0) {
        p++;
        int p1 = p;
        fst[nod->cnt] = euler.size();
        euler.push_back(p);
        level[p1] = level[parent] + 1;
        for(int i = 0; i < 26; i++) {
            if(nod->next[i] != NULL) {
                dfs(nod->next[i], p1);
                euler.push_back(p1);
            }
        }
        
        
    }
}T; 

int N, M;
int t, x;
int rmq[MAX + 3][19];
int E[MAX + 3];

int query(int l, int r) {
    int len = r - l + 1;
    int loglen = E[len];
    return min(rmq[l][E[len]], rmq[r - (1 << E[len]) + 1][E[len]]);
}


int main() {
    freopen("ratina.in", "r", stdin);
    freopen("ratina.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s;

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> s;
        step = i;
        T.insert(s);
        //cout << lbl[i] << ' ';
    }   

    T.dfs(T.root);

    for(int i = 0; i < euler.size(); i++) {
        rmq[i][0] = euler[i];
    }   
    
    for(int b = 1; b <= 18; b++) {
        for(int i = 0; i < euler.size(); i++) {
            rmq[i][b] = rmq[i][b - 1];

            int j = i + (1 << (b - 1));
            if(j < euler.size()) {
                rmq[i][b] = min(rmq[i][b], rmq[j][b - 1]);
            }
            //cout << rmq[i][b] << ' ';
        }
        //cout << '\n';
    }

    // for(auto i : euler) {
    //     cout << i << ' ';
    // }

    // cout << '\n';

    for(int i = 2; i <= euler.size(); i++) {
        E[i] = 1 + E[i / 2];
    }


    // for(int i = 1; i <= N; i++) {
    //     cout << fst[lbl[i]] << ' ';
    // }
    // cout << '\n';

    for(int i = 1; i <= M; i++) {
        cin >> t;

        int minn = INT_MAX, maxx = 0;
        for(int j = 1; j <= t; j++) {
            cin >> x;
            minn = min(minn, fst[lbl[x]]);
            maxx = max(maxx, fst[lbl[x]]);
        }
        //cout << minn << ' ' << maxx << '\n';
        cout << level[query(minn, maxx)] - 1 << '\n';
    }
}

/*

    Imi marchez cu o eticheta distincta in cnt ()
    Pentru fiecare cuvant imi tin un vector cu eticheta ultimei litere 
    Imi tin un vector cu prima aparitie in dfs a etichetei 
    Imi tin un vector cu parcurgerea Euler caruia ii voi calcula un RMQ(euler)


*/