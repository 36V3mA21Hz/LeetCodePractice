class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        int pos = 0;
        string commonPrefix;
        string::iterator it, it2;
        while (strs.size() > 1) {
            it2 = strs[0].begin() + pos;
	        for (int i = 1; i < strs.size(); i++) {
	        	it = strs[i].begin() + pos;
	        	if (it == strs[i].end() || *it != *it2)
	        		return commonPrefix;
                it2 = it;
	        }
	        commonPrefix.push_back(*it2);
	        pos++;
	    }
	    return strs[0];
    }
};
