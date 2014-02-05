class Solution {
public:
    void sortColors(int A[], int n) {
        if (n == 1) return;
    	int red = 0, white = 0, blue = 0;
    	if (n % 2 == 0) {
	   		for (int i = 0; i < n; i++) {
	   			if (i < n / 2) {
		   			decide(A[i], red, white, blue);
	   				decide(A[i + n / 2], red, white, blue);
	   			} else {
	   				if (red-- > 0)
	 					A[i - n / 2] = 0;
	 				else if (white-- > 0)
	 					A[i - n / 2] = 1;
	 				else if (blue-- > 0)
	 					A[i - n / 2] = 2;
	 				if (blue-- > 0)
	 					A[3 * n / 2 - i - 1] = 2;
	 				else if (white-- >0)
	 					A[3 * n / 2 - i - 1] = 1;
	 				else if (red-- > 0)
	 					A[3 * n / 2 - i - 1] = 0;
	  		 	}
	   		}
	   	} else {
	   		for (int i = 0; i < n; i++) {
	   			if (i < n / 2) {
		   			decide(A[i], red, white, blue);
	   				decide(A[i + n / 2 + 1], red, white, blue);
	   			} else if (i == n / 2) {
	   				decide(A[i], red, white, blue);
	   				if (red > i) {
	   					A[0] = 0;
	   					red--;
	   				} else if (blue > i) {
	   					A[n-1] = 2;
	   					blue--;
	   				} else {
		   				A[i] = 1;
		   				white--;
	   				}
	   			} else {
	   				if (red-- > 0)
	 					A[i - n / 2 - 1] = 0;
	 				else if (white-- > 0)
	 					A[i - n / 2 - 1] = 1;
	 				else if (blue-- > 0)
	 					A[i - n / 2 - 1] = 2;
	 				if (blue-- > 0)
	 					A[3 * n / 2 - i] = 2;
	 				else if (white-- >0)
	 					A[3 * n / 2 - i] = 1;
	 				else if (red-- > 0)
	 					A[3 * n / 2 - i] = 0;
	  		 	}
	   		};
	   	}
    }
    void decide(int x, int &red, int &white, int &blue) {
    	switch (x) {
			case 0 :
				red++;
				break;
			case 1 :
				white++;
				break;
			case 2 :
				blue++;
				break;
		}
    }
};