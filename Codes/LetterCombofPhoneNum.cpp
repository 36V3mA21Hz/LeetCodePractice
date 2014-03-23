class Solution {
public:
	typedef string::iterator sit;
    vector<string> letterCombinations(string digits) {
    	if (digits.empty())
    		return {""};
    	vector<string> output;
    	string comb;
    	lCAux(digits, output, comb, digits.begin(), digits.end());
    	return output;
    }
    void lCAux(string &digits, vector<string> &output, string comb, sit sstart, sit send) {
    	if (sstart == send) {
    		output.push_back(comb);
    		return;
    	}
        if (*sstart <= '6') {
            for (int i = 0; i < 3; i++) {
                char cTemp = 'a' + (*sstart - '2') * 3 + i;
                comb.push_back(cTemp);
                lCAux(digits, output, comb, sstart+1, send);
                comb.pop_back();
            }
        } else if (*sstart == '7'){
            for (int i = 0; i < 4; i++) {
                char cTemp = 'p' + i;
                comb.push_back(cTemp);
                lCAux(digits, output, comb, sstart+1, send);
                comb.pop_back();
            }
        } else if (*sstart == '8'){
            for (int i = 0; i < 3; i++) {
                char cTemp = 't' + i;
                comb.push_back(cTemp);
                lCAux(digits, output, comb, sstart+1, send);
                comb.pop_back();
            }
        } else if (*sstart == '9'){
            for (int i = 0; i < 4; i++) {
                char cTemp = 'w' + i;
                comb.push_back(cTemp);
                lCAux(digits, output, comb, sstart+1, send);
                comb.pop_back();
            }
        }
    }
};
