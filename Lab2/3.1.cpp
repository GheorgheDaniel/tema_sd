#include <iostream>
#include <deque>
using namespace std;
const int MAX = 5000000;
int N, K;
int A[MAX + 3];
deque<int>dq;
long long sum;
int main() {
    freopen("deque.in", "r", stdin);
    freopen("deque.out", "w", stdout);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++) {
        while(!dq.empty() && A[i] <= A[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(dq.front() < i - K + 1) dq.pop_front(); 
        if(i >= K) sum += A[dq.front()];
        //cout << dq.front() << ' ';
    }
    cout << sum;
}