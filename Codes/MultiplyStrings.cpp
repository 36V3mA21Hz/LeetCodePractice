class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return "";
        if (num1 == "0" || num2 == "0")
            return "0";
        string ans;
        int n1 = num1.size(), n2 = num2.size();
        int p1 = 0, p2 = 0, carry = 0;
        int posMax = n1 + n2 - 1, pos = 0;
        while (pos < posMax) {
            int temp = 0;
            int i = n1 - 1 - pos, j = n2 - 1;
            if (i < 0) { i = 0, j = n2 - (pos - n1) - 2 ; }
            while (i >= 0 && i < num1.size() && j >= 0 && j < num2.size()) {
                temp += (num1[i++] - '0') * (num2[j--] - '0');
            }
            temp += carry;
            carry = temp / 10;
            ans.push_back(temp % 10 + '0');
            if (p1 < n1) p1++;
            if (p2 < n2) p2++;
            pos++;
        }
        if (carry) ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};