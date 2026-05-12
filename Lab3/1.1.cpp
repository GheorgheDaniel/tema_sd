#include <bits/stdc++.h>
using namespace std;

class Hash{
    private:
    vector<list<int>>h;
    int actual_modulo = 1;
    void resize(int val) {
        vector<list<int>>h1;
        h1.resize(val);
        for(int i = 0; i < h.size(); i++) {
            for(auto v1 : h[i]) h1[v1 % val].emplace_back(v1);
        }
        h = h1;

        actual_modulo = val;
        
    }
    public:
    Hash(int val = 97) {
        resize(val);
    };
    bool exists(int X) {
        for(auto i : h[X % actual_modulo]) if(X == i) return true;
        return false;
    }
    void insert(int X) {
        h[X % actual_modulo].emplace_back(X);
    }

    void erase(int X) {
        auto it = h[X % actual_modulo].begin();
        while(*it != X && it != h[X % actual_modulo].end()) it++;
        h[X % actual_modulo].erase(it);
    }

};

int main() {

    Hash h1;
    h1.insert(34);
    cout << h1.exists(34) << '\n';
    cout << h1.exists(75) << '\n';
    h1.erase(34);   
    cout << h1.exists(34) << '\n';
}