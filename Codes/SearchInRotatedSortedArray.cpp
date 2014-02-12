class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0)
        	return -1;
    	return searchAux(A, 0, n-1, target);
        
    }
    int searchAux(int A[], int l, int r, int &target) {
    	if (l > r)
    		return -1;
    	int mid = (l + r) / 2;
    	if (A[mid] == target)
    		return mid;
    	int q1 = searchAux(A, l, mid - 1, target);
    	int q2 = searchAux(A, mid + 1, r, target);
    	int q = q1 > q2 ? q1 : q2;
    	return q;
    }
};