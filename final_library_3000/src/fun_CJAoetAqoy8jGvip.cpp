#include "fun_CJAoetAqoy8jGvip.hpp"

// Original algorithm: Ode Semi Implicit Euler
int fun_CJAoetAqoy8jGvip() {
    try {
        void problem(const double &x, std::valarray<double> *y,
                     std::valarray<double> *dy) {
            const double omega = 1.F;             // some const for the problem
            dy[0][0] = y[0][1];                   // x dot
            dy[0][1] = -omega * omega * y[0][0];  // y dot
        }
        void exact_solution(const double &x, std::valarray<double> *y) {
            y[0][0] = std::cos(x);
            y[0][1] = -std::sin(x);
        }
        void semi_implicit_euler_step(const double dx, const double &x,
                                      std::valarray<double> *y,
                                      std::valarray<double> *dy) {
            problem(x, y, dy);         // update dy once
            y[0][0] += dx * dy[0][0];  // update y0
            problem(x, y, dy);         // update dy once more
            dy[0][0] = 0.f;      // ignore y0
            y[0] += dy[0] * dx;  // update remaining using new dy
        }
        double semi_implicit_euler(double dx, double x0, double x_max,
                                   std::valarray<double> *y,
                                   bool save_to_file = false) {
            std::valarray<double> dy = y[0];
            std::ofstream fp;
            if (save_to_file) {
                fp.open("semi_implicit_euler.csv", std::ofstream::out);
                if (!fp.is_open()) {
                    std::perror("Error! ");
                }
            }
            std::size_t L = y->size();
            /* start integration */
            std::clock_t t1 = std::clock();
            double x = x0;
            do {  // iterate for each step of independent variable
                if (save_to_file && fp.is_open()) {
                    fp << x << ",";
                    for (int i = 0; i < L - 1; i++) {
                        fp << y[0][i] << ",";
                    }
                    fp << y[0][L - 1] << "\n";
                }
                semi_implicit_euler_step(dx, x, y, &dy);  // perform integration
                x += dx;                                  // update step
            } while (x <= x_max);  // till upper limit of independent variable
            /* end of integration */
            std::clock_t t2 = std::clock();
            if (fp.is_open())
                fp.close();
            return static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
        }
        void save_exact_solution(const double &X0, const double &X_MAX,
                                 const double &step_size,
                                 const std::valarray<double> &Y0) {
            double x = X0;
            std::valarray<double> y = Y0;
            std::ofstream fp("exact.csv", std::ostream::out);
            if (!fp.is_open()) {
                std::perror("Error! ");
                return;
            }
            std::cout << "Finding exact solution\n";
            std::clock_t t1 = std::clock();
            do {
                fp << x << ",";
                for (int i = 0; i < y.size() - 1; i++) {
                    fp << y[i] << ",";
                }
                fp << y[y.size() - 1] << "\n";
                exact_solution(x, &y);
                x += step_size;
            } while (x <= X_MAX);
            std::clock_t t2 = std::clock();
            double total_time = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;
            std::cout << "\tTime = " << total_time << " ms\n";
            fp.close();
        }
        ; /* initial value Y = y(x = x_0) */
            double step_size;
            if (argc == 1) {
                std::cout << "\nEnter the step size: ";
                std::cin >> step_size;
            } else {
                step_size = std::atof(argv[1]);
            }
            double total_time = semi_implicit_euler(step_size, X0, X_MAX, &Y0, true);
            std::cout << "\tTime = " << total_time << " ms\n";
            /* compute exact solution for comparion */
            save_exact_solution(X0, X_MAX, step_size, Y0);
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Ode Semi Implicit Euler..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_CJAoetAqoy8jGvip: Ode Semi Implicit Euler executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_CJAoetAqoy8jGvip: Exception - " << e.what() << endl;
        return 0;
    }
}
