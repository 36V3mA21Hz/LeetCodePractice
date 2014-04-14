class Solution {
public:
	typedef string::iterator sit;
    string multiply(string num1, string num2) {
    	const int tennine = 1000000000; // 1 000 000 000
    	unsigned x1 = 0, x2 = 0, m1 = 1, m2 = 1;
    	int l1 = 0, l2 = 0;
    	vector<int> v1, v2;
        sit i1 = num1.end() - 1, i2 = num2.end() - 1;
        while (i1 >= num1.begin() || i2 >= num2.begin()) {
        	if (i1 >= num1.begin() && i2 >= num2.begin()) {
        		x1 += (*i1 - '0') * m1;
        		x2 += (*i2 - '0') * m2;
                m1 *= 10, m2 *= 10;
        		l1++, l2++, i1--, i2--;
        	} else if (i1 >= num1.begin()) {
        		x1 += (*i1 - '0') * m1;
                m1 *= 10;
        		l1++, i1--;
        	} else if (i2 >= num2.begin()) {
        		x2 += (*i2 - '0') * m2;
                m2 *= 10;
        		l2++, i2--;
        	}
        	if (l1 == 9 || i1 == num1.begin() - 1) {
        		v1.push_back(x1);
        		x1 = 0, l1 = 0, m1 = 1;
                if (i1 < num1.begin())
                    i1--;
        	}
        	if (l2 == 9 || i2 == num2.begin() - 1) {
        		v2.push_back(x2);
        		x2 = 0, l2 = 0, m2 = 1;
                if (i2 < num2.begin())
                    i2--;
        	}
        }
        string buffer;
        int vn1 = (int)v1.size(), vn2 = (int)v2.size();
        unsigned long carry = 0;
        for (int basis = 0; basis <= vn1 + vn2; basis++) {
        	unsigned long temp = carry;
        	for (int i = 0; i <= basis; i++) {
        		int j = basis - i;
        		if (j < vn2 && i < vn1) {
        			temp += (unsigned long)v1[i] * (unsigned long)v2[j];
        		}
        	}
            carry = temp / tennine;
            temp = temp % tennine;
        	while (temp) {
        		buffer.push_back(temp % 10 + '0');
        		temp /= 10;
        	}
        }
        i1 = buffer.begin(), i2 = buffer.end() - 1;
        while (i1 < i2) {
            swap(*i1, *i2);
            i1++, i2--;
        }
        if (buffer.empty())
            buffer.push_back('0');
        return buffer;
    }
};
