class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		unordered_set<string> myset;
		int length = 0;
		string temp;
		char *i = needle;
		while (*i != '\0') {
			temp.push_back(*i);
			length++, i++;
		}
		if (*needle == '\0')
			return haystack + length;
		myset.emplace(temp);
		string s;
		i = haystack;
		while (*i != '\0') {
			s.push_back(*i);
			i++;
		}
		for (int j = 0; j < s.size(); j++) {
			temp = s.substr(j, length);
			auto got = myset.find(temp);
			if (got != myset.end()) {
				return haystack + j;
			}
		}
		return NULL;
	}
};