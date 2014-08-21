class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		if (words.empty()) return{};
		if (L == 0) return{ "" };
		vector<string> output;
		string temp;
		int i = 0;
		while (i < words.size()) {
			int numW1L = 0, lenW1L = 0;
			while (lenW1L + numW1L + 1 - 1 < L && i + numW1L < words.size()) {
				if (L - (lenW1L + numW1L) >= words[i + numW1L].size()) {
					lenW1L += words[i + numW1L].size();
					numW1L++;
				}
				else {
					break;
				}
			}
			if (numW1L > 1 && i + numW1L < words.size()) {
				int totalSpaces = L - lenW1L;
				string aveSpaces(totalSpaces / (numW1L - 1), ' ');
				int extraSpaces = totalSpaces % (numW1L - 1);
				for (int k = 0; k < numW1L - 1; k++) {
					temp.append(words[i + k]);
					temp.append(aveSpaces);
					if (extraSpaces-- > 0) temp.push_back(' ');
				}
				temp.append(words[i + numW1L - 1]);
			}
			else if (numW1L > 1 && i + numW1L == words.size()) {
				for (int k = 0; k < numW1L - 1; k++) {
					temp.append(words[i + k]);
					temp.push_back(' ');
				}
				temp.append(words[i + numW1L - 1]);
				string aveSpaces(L - (lenW1L + numW1L - 1), ' ');
				temp.append(aveSpaces);
			}
			else {
				temp.append(words[i]);
				string aveSpaces(L - lenW1L, ' ');
				temp.append(aveSpaces);
			}
			output.push_back(temp);
			temp.clear();
			i += numW1L;
		}
		return output;
	}
};