class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.empty() && s1.empty() && s2.empty()) return true;
		if (!s3.empty() && s1.empty() && s2.empty()) return false;
		vector<int> m1(s1.size()), m2(s2.size());
		int j1 = 0, j2 = 0, k1 = 0, k2 = 0;
		for (int i = 0; i < s3.size(); i++) {
			if (j1 < s1.size() && s3[i] == s1[j1])
				m1[j1++] = i;
			if (j2 < s2.size() && s3[i] == s2[j2])
				m2[j2++] = i;
		}
		if (j1 != s1.size() || j2 != s2.size())
			return false;
		j1 = 0, j2 = 0;
		for (int i = 0; i < s3.size(); i++) {
			if (k1 < m1.size() && i == m1[k1]) {
				k1++;
			}
			else if (s3[i] == s2[j2])
				j2++;
		}
		if (j2 != s2.size())
			return false;
		for (int i = 0; i < s3.size(); i++) {
			if (k2 < m2.size() && i == m2[k2]) {
				k2++;
			}
			else if (s3[i] == s1[j1])
				j1++;
		}
		if (j1 != s1.size())
			return false;
		return true;
	}
};