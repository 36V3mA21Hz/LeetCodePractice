class Solution {
public:
	double pow(double x, int n) {
		if (n < 0)
			return 1.0 / powAux(x, -n);
		else
			return powAux(x, n);
	}
	double powAux(double x, int n) {
		if (n == 0)
			return 1;
		double q = powAux(x, n / 2);
		if (n % 2 == 1)
			return q * q * x;
		else
			return q * q; 
	}
};