class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (n == 0)
        	return {-1, -1};
        vector<int> output;
        output.push_back(INT_MAX);
        output.push_back(INT_MIN);
        bool found = false;
        searchAux(A, 0, n - 1, target, output, found);
        if (!found)
            return {-1, -1};
        return output;
    }
   	void searchAux(int A[], int l, int r, int &target, vector<int> &buffer, bool &found) {
    	if (l > r)
    		return;
    	int mid = (l + r) / 2;
    	searchAux(A, l, mid - 1, target, buffer, found);
    	searchAux(A, mid + 1, r, target, buffer, found);
        if (A[mid] == target) {
            found = true;
    		if (mid < buffer[0])
    			buffer[0] = mid;
    		if (mid > buffer[1])
    			buffer[1] = mid;
    	}
    }
};
