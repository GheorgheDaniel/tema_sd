//https://www.infoarena.ro/job_detail/3354725?action=view-source
#include <bits/stdc++.h>
using namespace std;

const int ALPHA = 27;
const int MAX = 1e5;
int N;
long long A[MAX + 3];
int step;
int l, r;
int leftaux;

string matching;

struct Trie{

    struct Node{
        int cnt, pfx;
        Node *next[ALPHA];

        Node() {
            cnt = 0;
            pfx = 0;
            for(int i = 0; i < ALPHA; i++) {
                next[i] = NULL;
            }
        }
    };

    Node *root;

    Trie() {
        root = new Node;
    }

    void insert(string &s) {

        Node *curr = root;
        for(auto it : s) {
            if(curr->next[it - 'a'] == NULL) {
                curr->next[it - 'a'] = new Node;
            }
            curr = curr->next[it - 'a'];
            curr->pfx++;
        }
        curr->cnt++;
    }

    void erase(string &s) {
        Node *curr = root;
        for(int it = 0; it < s.size(); it++) {
            if(curr->next[(s[it] - 'a')] != NULL) {
                curr = curr->next[(s[it] - 'a')];
                curr->pfx--;
            }
            else {
                return ;
            }
        }
        curr->cnt--;
    }

    int occ(string &s) {
        Node *curr = root;
        for(int it = 0; it < s.size(); it++) {
            if(curr->next[(s[it] - 'a')] != NULL) {
                curr = curr->next[(s[it] - 'a')];
            }
            else {
                return 0;
            }
        }
        return curr->cnt;
    }

    int longest(string &s) {
        int val = 0;
        Node *curr = root;
        for(int it = 0; it < s.size(); it++) {
            if(curr->next[(s[it] - 'a')] != NULL) {
                curr = curr->next[(s[it] - 'a')];
                if(curr->pfx != 0) val = it + 1;
            }
            else {
                return val;
            }
        }
        return val;
    }
}T;
string s;
int main() {
    freopen("trie.in", "r", stdin);
    freopen("trie.out", "w", stdout);
    int op; string word;
    while(cin >> op >> word) {
        if(op == 0) {
            T.insert(word);
        }
        if(op == 1) {
            T.erase(word);
        }
        if(op == 2) {
            cout << T.occ(word) << '\n';
        }
        if(op == 3) {
            cout << T.longest(word) << '\n';
        }
    }

}