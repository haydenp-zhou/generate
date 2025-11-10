#include "fun_Z8gUsccmdCN8GOxY.hpp"

int fun_Z8gUsccmdCN8GOxY() {
    // LeetCode Problem: Find Duplicate File In System

    // Solution class
    class Solution {

    public:
        vector<vector<string>> findDuplicate(vector<string>& paths) {
            unordered_map<string, vector<string>> files;
            for (const auto& path : paths) {
        	    stringstream ss(path);
        	    string root;
        	    string s;
        	    getline(ss, root, ' ');
        	    while (getline(ss, s, ' ')) {
        		    auto fileName = root + '/' + s.substr(0, s.find('('));
        		    auto fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
        		    files[fileContent].emplace_back(fileName);
        	    }
            }

            vector<vector<string>> result;
            for (const auto& file : files) {
        	    if (file.second.size() > 1) {
        		    result.emplace_back(file.second);
        	    }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.findDuplicate(strs);

        // Print result to prevent optimization
        cout << "fun_Z8gUsccmdCN8GOxY: Executed findDuplicate() from Find Duplicate File In System" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Z8gUsccmdCN8GOxY: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
