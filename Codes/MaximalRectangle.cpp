class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        vector<int> height(matrix[0].size(), 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++) {
        	for (int j = 0; j < matrix[0].size(); j++) {
        		if (matrix[i][j])
        			height[j] += 1;
        		else
        			height[j] = 0;
        	}
        	maxArea = max(maxArea, LarRecInHisto(height));
        }
        return maxArea;
    }
    int LarRecInHisto(vector<int> &height) {
    	stack<int> incH;
    	int sum = 0;
    	height.push_back(0);
    	for (int i = 0; i < height.size(); i++) {
    		if (incH.empty() || height[i] > height[incH.top()])
    			incH.push(i);
    		else {
    			int tmp = incH.top();
    			incH.pop();
    			sum = max(sum, height[tmp] * (incH.empty() ? i : i - incH.top() - 1));
    			i--;
    		}
    	}
    	return sum;
    }
};