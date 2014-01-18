class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> result;
    	int gary;
    	for (int i = 0; i < 1 << n; i++) {
    		gary = (i >> 1) ^ i;
    		result.push_back(gary);
    	}  
    	return result;
    }
};