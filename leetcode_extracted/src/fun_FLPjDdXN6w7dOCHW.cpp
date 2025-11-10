#include "fun_FLPjDdXN6w7dOCHW.hpp"

int fun_FLPjDdXN6w7dOCHW() {
    // LeetCode Problem: Read N Characters Given Read4

    // Solution class
    class Solution {

        public:
            /**
             * @param buf Destination buffer
             * @param n   Maximum number of characters to read
             * @return    The number of characters read
             */
            int read(char *buf, int n) {
                srand(time(0));
                if (rand()%2){
                    return read1(buf, n);
                }
                return read2(buf, n);
            }

            //read the data in-place. potential out-of-boundary issue
            int read1(char *buf, int n) {
                int len = 0;
                int size = 0;

                // `buf` could be accessed out-of-boundary 
                while(len <=n && (size = read4(buf))>0){
                    size = len + size > n ?  n - len : size;
                    len += size;
                    buf += size;
                }
                return  len;
            }

            //using a temp-buffer to avoid peotential out-of-boundary issue
            int read2(char *buf, int n) {
                char _buf[4];   // the buffer for read4()
                int _n = 0;     // the return for read4()
                int len = 0;    // total buffer read from read4()
                int size = 0;   // how many bytes need be copied from `_buf` to `buf`
                while((_n = read4(_buf)) > 0){
                    //check the space of `buf` whether full or not
                    size = len + _n > n ? n-len : _n;
                    strncpy(buf+len, _buf, size);
                    len += size;
                    //buffer is full
                    if (len>=n){
                        break;
                    }
                }
                return len;
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.read(n);

        // Print result to prevent optimization
        cout << "fun_FLPjDdXN6w7dOCHW: Executed read() from Read N Characters Given Read4" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_FLPjDdXN6w7dOCHW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
