#ifndef UTILITIES_H
#define UTILITIES_H

int gcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return ((a * b) / gcd(a, b));
}

// Simplifies the receiver
vector<int> simplify(int numerator, int denominator) {
	vector<int> result;
	int factor = gcd(numerator, denominator);
	result.push_back(numerator / factor);
	result.push_back(denominator / factor);
	return result;
}

#endif