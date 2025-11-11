#include "fun_T5iOTRaBTsmpu3Ur.hpp"

// Original algorithm: Spirograph
int fun_T5iOTRaBTsmpu3Ur() {
    try {
        template <std::size_t N>
        void spirograph(std::array<std::pair<double, double>, N> *points, double l,
                        double k, double rot) {
            double dt = rot * 2.f * M_PI / N;
            double R = 1.f;
            const double k1 = 1.f - k;
            int32_t step = 0;
        #ifdef _OPENMP
        #pragma omp for
        #endif
            for (step = 0; step < N; step++) {
                double t = dt * step;
                double first = R * (k1 * std::cos(t) + l * k * std::cos(k1 * t / k));
                double second = R * (k1 * std::sin(t) - l * k * std::sin(k1 * t / k));
                points[0][step].first = first;
                points[0][step].second = second;


        volatile int status = 1;
        cout << "fun_T5iOTRaBTsmpu3Ur: Spirograph executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_T5iOTRaBTsmpu3Ur: Exception - " << e.what() << endl;
        return 0;
    }
}
