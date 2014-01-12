class Solution {
public:
	int romanToInt(string s) {
	    vector<int> tmp;
	    for (int i = 0; i < s.length(); i++) {
	        switch (s[i]) {
	            case 'M': tmp.push_back(1000);  break;
	            case 'D': tmp.push_back(500);   break;
	            case 'C': tmp.push_back(100);   break;
	            case 'L': tmp.push_back(50);    break;
	            case 'X': tmp.push_back(10);    break;
	            case 'V': tmp.push_back(5); break;
	            case 'I': tmp.push_back(1); break;
	        }
	    }
	    int num = tmp[0];
	    for (int i = 1; i < tmp.size(); i++) {
	        if (tmp[i-1] < tmp[i]) {
	            num += tmp[i] - 2 * tmp[i-1];
	        } else {
	            num += tmp[i];
	        }
	    }
	    return num;    
	}
};