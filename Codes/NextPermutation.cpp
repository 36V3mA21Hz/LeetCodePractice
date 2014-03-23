class Solution {
public:
	typedef vector<int>::iterator vit;
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1)
        	return;
        auto it = num.end() - 1;
        vit vpivot = num.begin() + 1;
        while (it != num.begin()) {
        	if (*it > *(it - 1)) {
        		vpivot = it;
        		break;
        	}
        	it--;
        }
        it = num.end() - 1;
        vit vrep = it;
        int min = INT_MAX;
        while (it != vpivot - 1) {
        	if (*it > *(vpivot - 1) && *it < min) {
        		vrep = it;
                min = *vrep;
        	}
        	it--;
        }
        int temp = *vrep;
        *vrep = *(vpivot - 1);
        *(vpivot - 1) = temp;
        
        sort(vpivot, num.end());
    }
};
