class Solution {
public:
	string minWindow(string S, string T) {
		if (S.empty() || T.empty())
			return "";
		int n = S.size(), metCharNum = 0;
		int winStart = -1, minWindowSize = INT_MAX;
		int needToFind[256] = { 0 }, hasFound[256] = { 0 };
		for (int i = 0; i < T.size(); i++)
			needToFind[T[i]]++;
		for (int start = 0, end = 0; end < S.size(); end++) {
			if (needToFind[S[end]] == 0) continue;
			hasFound[S[end]]++;
			// <= because metCharNum is 0 initially
			bool t1 = hasFound[S[end]] <= needToFind[S[end]];
			if (hasFound[S[end]] <= needToFind[S[end]])
				metCharNum++;
			if (metCharNum == T.size()) {
				while (needToFind[S[start]] == 0 || hasFound[S[start]] > needToFind[S[start]]) {
					if (hasFound[S[start]] > needToFind[S[start]])
						hasFound[S[start]]--;
					start++;
				}
				if (end - start + 1 < minWindowSize) {
					winStart = start;
					minWindowSize = end - start + 1;
				}
			}
		}
		if (metCharNum == T.size())
			return S.substr(winStart, minWindowSize);
		return "";
	}
};