#include<iostream>
#include<vector>
int memoized_cut_rod_aux(vector<int> &p, int n, vector<int> &r);

int memoized_cut_rod(vector<int> &p, int n) {
	vector<int> r(n+1, INT_MIN);
	return memoized_cut_rod_aux(p, n, r);
}
int memoized_cut_rod_aux(vector<int> &p, int n, vector<int> &r) {
	if (r[n] >= 0) 
		return r[n];
	int q;
	if (n == 0)
		q = 0;
	else {
		q = INT_MIN;
		for (int i = 1; i <= n; i++) {
			int m = p[i-1] + memoized_cut_rod_aux(p, n - i, r);
			if (q < m)
				q = m;
		}
	}
	r[n] = q;
	return q;
}

int main() {
	vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int result = memoized_cut_rod(p, p.size());
}