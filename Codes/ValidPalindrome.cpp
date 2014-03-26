class Solution {
public:
    bool isPalindrome(string s) {
    	if (s.empty())
    		return true;
        string::iterator si1 = s.begin(), si2 = s.end() - 1;
        while (si1 != si2) {
        	if (*si1 == *si2 || abs(*si1 - *si2) == 32) {
        		si1++;
        		si2--;
        	} else {
        		if (!isAlphanumeric(si1) && !isAlphanumeric(si2)) {
        			si1++;
        			si2--;
        		} else if (!isAlphanumeric(si1)) {
        			si1++;
        		} else if (!isAlphanumeric(si2)) {
        			si2--;
        		} else {
        			return false;
        		}
        	}
        }
        return true;
    }
    bool isAlphanumeric(string::iterator si) {
    	if ((*si - '0' >= 0 && *si - '9' <= 0) || (*si - 'A' >= 0 && *si - 'Z' <= 0) || (*si - 'a' >= 0 && *si - 'z' <= 0))
    		return true;
    	else
    		return false;
    }
};
