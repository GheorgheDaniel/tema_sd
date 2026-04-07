//cod mai vechi 
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
ifstream f("alee.in");
ofstream g("alee.out");
int a[176][176];
int n, m, x, y;
int l1, c1, l2, c2;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,1,-1 };
int inmat(int i, int j) {
	return i <= n && i >= 1 && j <= n && j >= 1;
}
void lee(int i, int j) {
	queue<pair<int, int>>q;
	a[i][j] = 1;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		for (int d = 0; d < 4; d++) {
			int inou = q.front().first + di[d];
			int jnou = q.front().second + dj[d];
			if (!a[inou][jnou] && inmat(inou, jnou)) {
				a[inou][jnou] = a[q.front().first][q.front().second] + 1;
				q.push(make_pair(inou, jnou));
			}
		}
		q.pop();
	}
}
int main() {
	f >> n >> m;
	for (int i = 1; i <= m; i++) {
		f >> x >> y;
		a[x][y] = 1;
	}
	f >> l1 >> c1 >> l2 >> c2;
	lee(l1, c1);
	g << a[l2][c2];
}