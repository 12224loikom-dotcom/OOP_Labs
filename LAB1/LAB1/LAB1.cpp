#include<iostream>
#include<math.h>

using namespace std;

double calculation_a(double x, double y, double z, double b) {
	double b1 = 3 + exp(y - x) + sqrt(pow(fabs(y * y + b), 0.3));
	double b2 = 1 + pow(x, 2) * (fabs(y - pow(tan(pow(z, 2)), 2)));
	return  pow(fabs(z), 0.2) * (b1 / b2);
}
double calculation_b(double x, double y, double z) {
	return  y * pow(fabs(pow(fabs(x), 0.3) / (z + y) + pow(tan(x + pow(z, 2)) / (2 * x - 1.4), 2)), 1.0 / 3.0) - z * exp(pow(x, 2) - y);

}
int main() {

	int n;
	cout << "Enter variante number:";
	cin >> n;

	double x = 0.48 * n;
	double y = 0.47 * n;
	double z = -1.32 * n;

	double b = calculation_b(x, y, z);
	cout << "Function value b = " << b << endl;

	double a = calculation_a(x, y, z, b);
	cout << "Function value à = " << a << endl;

	cout << "   x\t\tb(x)\t\t\ta(x)" << endl;
	cout << "----------------------------------------------------" << endl;

	double start = -1;
	double end = 1;
	double step = 0.2;



	for (double x = start; x <= end; x += step) {
		b = calculation_b(x, y, z);
		a = calculation_a(x, y, z, b);

		cout << x << "   \t   " << b << "   \t   " << a << endl;
	}
	return 0;
}
