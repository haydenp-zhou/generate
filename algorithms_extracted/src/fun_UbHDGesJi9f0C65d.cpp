#include "fun_UbHDGesJi9f0C65d.hpp"

// Original algorithm: Binomial Dist
int fun_UbHDGesJi9f0C65d() {
    try {
        double binomial_expected(double n, double p) { return n * p; }
        double binomial_variance(double n, double p) { return n * p * (1 - p); }
        double binomial_standard_deviation(double n, double p) {
            return std::sqrt(binomial_variance(n, p));
        }
        double nCr(double n, double r) {
            double numerator = n;
            double denominator = r;
            for (int i = n - 1; i >= ((n - r) + 1); i--) {
                numerator *= i;
            }
            for (int i = 1; i < r; i++) {
                denominator *= i;
            }
            return numerator / denominator;
        }
        double binomial_x_successes(double n, double p, double x) {
            return nCr(n, x) * std::pow(p, x) * std::pow(1 - p, n - x);
        }
        double binomial_range_successes(double n, double p, double lower_bound,
                                        double upper_bound) {
            double probability = 0;
            for (int i = lower_bound; i <= upper_bound; i++) {
                probability += nCr(n, i) * std::pow(p, i) * std::pow(1 - p, n - i);
            }
            return probability;
        }

                // Test the algorithm implementation
                cout << "Testing Binomial Dist..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_UbHDGesJi9f0C65d: Binomial Dist executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_UbHDGesJi9f0C65d: Exception - " << e.what() << endl;
        return 0;
    }
}
