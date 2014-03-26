class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        if (strs.empty())
        	return {};
        vector<string> output;
        vector<int> dup(26, 0);
        vector<vector<int>> dups(strs.size(), dup);
        for (auto it = strs.begin(); it != strs.end(); it++) {	
        	for (auto si = (*it).begin(); si != (*it).end(); si++) {
    			dups[it - strs.begin()][*si - 'a']++;
        	}
        }
        unordered_map<int, unordered_set<int>> dupCounter;
        int n = (int)strs.size();
        for (int j = 0; j < 26; j++) {
        	for (int i = 0; i < n; i++) {
    			if (dups[i][j]) {
    				if (dupCounter.empty()) {
    					unordered_set<int> indices;
    					indices.insert(i);
    					dupCounter.insert(dups[i][j], indices);
    				} else {
    					auto it = dupCounter.find(dups[i][j]);
    					if (it == dupCounter.end()){
    						unordered_set<int> indices;
    						indices.insert(i);
    						dupCounter.insert(dups[i][j], indices);
    				 	} else {
    				 		(it->second).insert(i);
    					}
    				}
    			}  		
        	}
        } 
        for ()

    	for (auto it = indices.begin(); it != indices.end(); it++) {
    		output.push_back(strs[*it]);
    	}
        return output;
    }
};