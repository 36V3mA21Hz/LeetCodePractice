class Solution {
public:
	typedef string::iterator sit;
    vector<vector<string>> partition(string s) {
        if (s.empty())
        	return {};
		vector<vector<string> > output;
		vector<string> buffer;
		BFS(s, s.begin(), s.end()-1, buffer, output);
		return output;
    }
    void BFS(string &s, sit sstart, sit send, vector<string> buffer, vector<vector<string> > &output) {
    	if (sstart == s.end()) {
    		output.push_back(buffer);
    		return;
    	}
        vector<string> savor = buffer;
        for (auto it = sstart;it <= send; it++) {
        	string stmp;
        	buffer = savor;
        	if (!palindrome(s, sstart, it))
        		continue;
        	stmp.append(sstart, it+1);
        	buffer.push_back(stmp);
        	partitionAux(s, it+1, send, buffer, output);
        }
    }
    bool palindrome(string &s, sit sstart, sit send) {
    	if (send == sstart)
    		return true;
    	while (sstart <= send) {
    		if (*sstart != *send)
    			return false;
    		sstart++;
    		send--;
    	}
    	return true;
    }
};
