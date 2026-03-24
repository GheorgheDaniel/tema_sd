#include <bits/stdc++.h>
using namespace std;

mt19937 get_rng() {
	seed_seq seq {
		(uint64_t) chrono::duration_cast<chrono::nanoseconds>(
			chrono::high_resolution_clock::now().time_since_epoch()).count(),
		(uint64_t) __builtin_ia32_rdtsc(),
		(uint64_t) (uintptr_t) unique_ptr<char>(new char).get()
	};
	return mt19937(seq);
}

auto rng = get_rng();

class structure{
    vector<int>v;
    public:
    void insert(int x) {
        v.push_back(x);
    }
    int pop() {
        uniform_int_distribution<>idx(0, v.size() - 1);
        int index = idx(rng);
        int val = v[index];
        swap(v.back(), v[index]);
        v.pop_back();
        return val;
    }
};

int main() {
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    structure data;
    data.insert(5);
    data.insert(18);
    cout << data.pop();
}