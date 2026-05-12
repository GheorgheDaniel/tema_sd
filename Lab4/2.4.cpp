//https://www.pbinfo.ro/detalii-evaluare/41545563
//cod mai vechi
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
struct IntCmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};
priority_queue<int, deque<int>, IntCmp> q;
int n;
int smin;
int main(){
    cin >> n;
    for(int i = 1, nr; i <= n; i++){
        cin >> nr;
        q.push(nr);
    }
    while(!q.empty()){
        int primul, doiul;
        primul = q.top();
        q.pop();
        if(!q.empty()) 
        {
        doiul = q.top(), q.pop();
        int suma = primul + doiul;
        smin = smin + suma;
        q.push(suma);
        }
    }
    cout << smin;
}