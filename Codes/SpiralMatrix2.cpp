class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	if (n == 0)
    		return {};
        vector<int> row(n, 0);
    	vector<vector<int> > buffer(n, row);
    	int num = 0, sphere = 0, final = num;
    	for (int len = n - 1; len > 0; len -= 2) {
            num = final;
    		for (int index = 0; index < len; index++) {
                num++;
    			buffer[sphere][index + sphere] = num;
    			buffer[index + sphere][n-1 - sphere] = num+len;
    			buffer[n-1 - sphere][n-1 - sphere - index] = num+2 *len;
    			buffer[n-1 - sphere - index][sphere] = num+3 *len;
                final = num + 3 * len;
    		}
    		sphere++;
    	}
    	if (n % 2)
    		buffer[n/2][n/2] = ++final;
    	return buffer;
    }
};
