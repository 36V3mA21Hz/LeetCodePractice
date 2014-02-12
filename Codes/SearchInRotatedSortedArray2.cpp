class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0)
        	return false;
    	return searchAux(A, 0, n-1, target);
        
    }
    bool searchAux(int A[], int l, int r, int &target) {
    	if (l > r)
    		return false;
    	int mid = (l + r) / 2;
    	if (A[mid] == target)
    		return true;
    	bool q1 = searchAux(A, l, mid - 1, target);
    	bool q2 = searchAux(A, mid + 1, r, target);
    	return q1||q2;
    }
};