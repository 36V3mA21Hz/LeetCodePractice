class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.empty())
			return{};
		vector<string> output;
		string t;
		restoreIPs(output, s, 0, t, 1);
		return output;
	}
	void restoreIPs(vector<string> &output, string &s, int cur, string t, int steps) {
		if (cur == s.size() && steps == 5) {
			t.pop_back();
			output.push_back(t);
			return;
		}
		else if (cur < s.size() && steps == 5 || cur >= s.size() && steps < 5) {
			return;
		}
		for (int i = 3; i >= 1; i--) {
			if (cur + i <= s.size() && stoi(s.substr(cur, i)) < 256 && !(s[cur] == '0' && i > 1)) {
				t.append(s, cur, i);
				t.push_back('.');
				restoreIPs(output, s, cur + i, t, steps + 1);
				t.pop_back();
				t.erase(t.size() - i, i);
			}
		}
	}
};