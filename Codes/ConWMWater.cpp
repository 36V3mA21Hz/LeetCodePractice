class Solution {
public:
    int maxArea(vector<int> &height) {
   		if (height.empty())
   			return 0;
   		int n = height.size();
   		if (n == 1)
   			return height[0];
   		int max = 0;
   		for (int i = 0; i < n - 1; i++) {
   			for (int j = i + 1; j < n; j++) {
   				int q = findArea(i, j, height);
   				if (max < q))
   					max = q;
   			}
   		}
   		return max;
    }
    int findArea(int i, int j, vector<int> &height) {
    	if (height[i] <= height[j])
    		return height[i] * (j - i);
    	else
    		return height[j] * (j - i);
    }
};