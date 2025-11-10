#include "fun_UASIp8z8SPNFE3Cz.hpp"

int fun_UASIp8z8SPNFE3Cz() {
    // LeetCode Problem: Encode And Decode Tinyurl

    // Solution class
    class Solution {

    public:
        Solution() : gen_((random_device())()) {
        }

        // Encodes a URL to a shortened URL.
        string encode(string longUrl) {
            string key = getRand();
            while (lookup_.count(key)) {
                key = getRand();
            }
            lookup_[key] = longUrl;
            return "http://tinyurl.com/" + key;
        }

        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl) {
            return lookup_[shortUrl.substr(tiny_url.length())];
        }

    private:
        string getRand() {
            string random;
            for (int i = 0; i < random_length; ++i) {
                random += alphabet_[uniform_int_distribution<int>{0, alphabet_.length() - 1}(gen_)];
            }
            return random;
        }

        const int random_length = 6;
        const string tiny_url = "http://tinyurl.com/";
        const string alphabet_ = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        default_random_engine gen_;
        unordered_map<string, string> lookup_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.Solution(s);

        // Print result to prevent optimization
        cout << "fun_UASIp8z8SPNFE3Cz: Executed Solution() from Encode And Decode Tinyurl" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_UASIp8z8SPNFE3Cz: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
