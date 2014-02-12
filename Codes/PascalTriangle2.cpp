class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> curLevel;
    	vector<int> nextLevel;

    	curLevel.push_back(1);
    	for (int i = 0; i < rowIndex; i++) {
    		nextLevel.push_back(1);
    		for (int j = 1; j < i + 1; j++) {
    			nextLevel.push_back(curLevel[j-1] + curLevel[j]);
    		}
    		nextLevel.push_back(1);
    		curLevel = nextLevel;
    		nextLevel.clear();
    	}
    	return curLevel;
    }
};