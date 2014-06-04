class Solution {
public:
	void reverseWords(string &s) {
		int n = s.size(), mark = n - 1;
		string output;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == ' ') {
				if (s[mark] != ' ' && !output.empty())
					output.push_back(' ');
				output.append(s, i + 1, mark - i);
				mark = i - 1;
			}
			else if (i == 0) {
				if (s[mark] != ' ' && !output.empty())
					output.push_back(' ');
				output.append(s, i, mark - i + 1);
			}
		}
		s = output;
	}
};