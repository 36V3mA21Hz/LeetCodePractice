#include <iostream>
class Solution {
public:
    int singleNumber(int A[], int n) {
        int x = 0;
        for (int i = 0; i < n; i++) {
        x = x ^ A[i];
        }
        return x;
    }
};

int main() {
    int A[] = {1,2,1};
    Solution s;
    std::cout << s.singleNumber(A, 3) << '\n';
    return 0;
}
