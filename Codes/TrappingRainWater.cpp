class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3)
        	return 0;
        int leftWall[2] = {0, A[0]};
        int rightWall[2] = {0. A[0]};
        int volume = 0;
        for (int i = 1; i < n; i++) {
        	rightWall[0] = i;
        	rightWall[1] = A[i];
        	if (rightWall[1] != 0 && leftWall[1] != 0) {
        		volume += getVolume(leftWall, rightWall);
        		
        	}
        }
        return volume;
    }
    int getVolume(int l[], int r[]) {
    	int volume = (l[1] < r[1] ? l[1] : r[1]) * (r[0] - l[0] -1);
    	return volume;
    }
};