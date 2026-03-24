#include <bits/stdc++.h>
using namespace std;

class LinkedList{   
    struct Node{
        int val;
        Node *next;
        Node *bef;

		Node(): val(-1), next(nullptr), bef(nullptr) {}
    };

    Node *start, *final;

	public:
	LinkedList(): start(nullptr), final(nullptr) {}

    void add(int idx, int vl) {
        Node *val = start;
        for(int i = 0; i < idx; i++) {
            if(val->next == nullptr) break;
            val = val->next;
        }

		if(val == nullptr || val->next == nullptr) {
			add_final(vl);
			return;
		}
		if(val->bef == nullptr) {
			add_start(vl);
			return;
		}

        Node *node = new Node;
		node->val = vl;
		node->bef = val->bef;
		node->next = val;
		val->bef->next = node;
		val->bef = node;
    }

	void add_start(int vl) {
		if(start == nullptr) {
			start = new Node;
			start->val = vl;
			final = start;
			return ;
		}

		Node *val = new Node;
		val->val = vl;
		val->next = start;
		start->bef = val;
		start = val;
		
	}

	void add_final(int vl) {
		if(final == nullptr) {
			start = new Node;
			final = start;
			start->val = vl;
			return ;
		}
		Node *val = new Node;
		val->val = vl;
		val->bef = final;
		final->next = val;
		final = val;
	}

	void print() {
		Node *val = start;
		while(true) {
			cout << val->val << ' ';
			if(val->next == NULL) break;
			val = val->next;
		}
	}

};

int main() {
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;

	LinkedList L;
	L.add(0, 4);
	L.add_start(3);
	L.add_start(6);
	L.add_final(7);
	L.add(1, 4);
	L.print();
}