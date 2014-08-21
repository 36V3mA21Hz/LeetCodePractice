class Solution {
public:
	bool isNumber(const char *s) {
		const char *ip = s;
		bool decimal = false, sci = false;
		while (*ip == ' ') ip++;
		if (*ip == '\0') return false;
		if (*ip == '+' || *ip == '-') {
			if (*(ip + 1) == '\0') return false;
			ip++;
		}
		while (*ip != ' ' && *ip != '\0') {
			if (*ip == '.') {
				if (decimal) return false;
				decimal = true;
				if (sci) return false;
				if (!(ip > s && *(ip - 1) >= '0' && *(ip - 1) <= '9') && 
					!(*(ip + 1) >= '0' && *(ip + 1) <= '9')) return false;
			} else if (*ip == 'e') {
				if (sci) return false;
				sci = true;
				if (!(*(ip + 1) >= '0' && *(ip + 1) <= '9') && !(*(ip + 1) == '+' || *(ip + 1) == '-')) return false;
				if (!(ip > s && *(ip - 1) >= '0' && *(ip - 1) <= '9' || *(ip - 1) == '.')) return false;
			} else if (*ip == '+' || *ip == '-') {
				if (!(ip > s && *(ip - 1) == 'e')) return false;
				if (!(*(ip + 1) >= '0' && *(ip + 1) <= '9')) return false;
			} else if (*ip < '0' || *ip > '9') {
				return false;
			}
			ip++;
		}
		while (*ip != '\0') {
			if (*ip != ' ') return false;
			ip++;
		}
		return true;
	}
};