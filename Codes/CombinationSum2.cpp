class Solution {
public:
	typedef vector<int>::iterator vit;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    	if (num.empty())
    		return {};
    	sort(num.begin(), num.end());
    	vector<vector<int> > output;
    	vector<int> temp;
   		dfs(output, num, temp, target, 0, num.begin());
   		return output;
    }
    void dfs(vector<vector<int>> &buffer, vector<int> &num, vector<int> temp, int &target, int sum, vit it) {
    	if (sum == target) {
    		buffer.push_back(temp);
    		return;
    	} else if (sum > target)
            return;
        int dup = *it;
        bool dupJ = false;
    	while (it != num.end()) {
            if (dupJ && dup == *it) {
                it++;
                continue;
            }
    		temp.push_back(*it);
    		dfs(buffer, num, temp, target, sum + *it, it+1);
    		temp.pop_back();
            dup = *it, dupJ = true;
            it++;
    	}
    }
};
