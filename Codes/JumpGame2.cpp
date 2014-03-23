class Solution {
public:
    int jump(int A[], int n) {
    	if (n <= 1)
    		return 0;
    	int maxCover = A[0], jumps = 0, curCover = -1;
    	for (int i = 0; i < n; i++) {
            if (maxCover >= n - 1) {
                jumps++;
                break;
            }
            if (A[i] + i > curCover) {
    			curCover = i + A[i];
    		}
            if (curCover > maxCover && i == maxCover) {
                jumps++;
                maxCover = curCover;
            }
    	}
    	return jumps;
    }
};
