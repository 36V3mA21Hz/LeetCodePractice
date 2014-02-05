class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
        	return 0;
        int dupCounter = 0, dupContent = A[0];
        int noDup = 0;
        for (int i = 1; i < n; i++) {
        	if (dupContent == A[i]) {
        		if (dupCounter < 2) {
        			dupCounter++;
        			noDup++;
        		} else if (dupCounter >= 2) {
        			dupCounter++;
        		}
        	} else {
        		dupCounter = 0;
        		dupContent = A[i];
        		A[noDup] = dupContent;
        		noDup++;
        	}
        }
        return noDup;
    }
};