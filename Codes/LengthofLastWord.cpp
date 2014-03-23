class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0, back = 0;
        const char *c = s;
        while (*c != '\0') {
        	c++;
            length++;
        }
        if (!length)
            return 0;
        c--;
        while (length != 0 && (*c != ' ' || back == 0)) {
            if (*c == ' ' && back == 0) {
                c--;
                back = 0;
                length--;
                continue;
            }
        	length--;
        	c--;
            back++;
        }
        return back;
    }
};
