#include <iostream>
#include <string>
int removeDuplicates(int A[], int n) {
	if (n < 2) return n;
	int end = 1;
	for (int i = 1; i < n; i++) {
		int start = 0;
		for (start; start < end; start++) {
			if (A[i] == A[start]) {
				break;
			}
		}
		if (start == end) {
			A[end] = A[i];
			end++;
		}
	}
	return end;
}

int main() {
	int A[] = { 1, 2, 2, 1, 3, 1, 2 };
	int x = removeDuplicates(A, 7);
	std::cout << x;
}