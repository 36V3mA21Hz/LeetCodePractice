class Solution {
public:
	int atoi(const char *str) {
		const char *ip = str, *start = NULL, *end = NULL;
		int num = 0;
		bool neg = false;
		while (*ip != '\0') {
			if ((*ip == '-' || *ip == '+') && start == NULL) {
				if (*ip == '-') neg = true;
				start = ip;
			} else if (*ip - '0' >= 0 && *ip - '9' <= 0 && end == NULL) {
				if (start == NULL) start = ip;
				if (!neg && num > INT_MAX/10) {return INT_MAX;}
				if (!neg && num == INT_MAX/10 && *ip - '0' >= 7) {return INT_MAX;}
				if (neg && -num < INT_MIN/10) {return INT_MIN;}
				if (neg && -num == INT_MIN/10 && *ip - '0' >= 8) {return INT_MIN;}
				num = *ip - '0' + num * 10;
			} else if ((*ip - '0' < 0 || *ip - '9' > 0) && !(*ip == ' ' && start == NULL)) {
				break;
			}
			ip++;
		}
		return (neg ? -num : num);
	}
};