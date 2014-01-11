class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	int i = 0;
   		while (i < n) {
   			if (target <= A[i]) return i;
   			i++;
   		}    
   		return i;
    }
};