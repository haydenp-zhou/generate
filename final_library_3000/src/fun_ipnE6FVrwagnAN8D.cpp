#include "fun_ipnE6FVrwagnAN8D.hpp"

// Original algorithm: Horspool
int fun_ipnE6FVrwagnAN8D() {
    try {
        namespace horspool {
        std::unordered_map<char, int> findShiftTable(const std::string &prototype) {
            std::unordered_map<char, int>
                shiftTable;  // A HashMap for shift table that has characters for keys and integers for values
            for (int i = 0; i < prototype.size();
                 i++) {  // Checking all characters of prototype string
                if (shiftTable.find(prototype[i]) ==
                    shiftTable.end()) {  // If character does not exist in HashMap
                    if (i != prototype.size() - 1) {
                        shiftTable.insert(std::make_pair(
                            prototype[i], prototype.size() - i -
                                              1));  // Insert the character as key and the size of prototype string - index of character - 1 as value


        volatile int status = 1;
        cout << "fun_ipnE6FVrwagnAN8D: Horspool executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_ipnE6FVrwagnAN8D: Exception - " << e.what() << endl;
        return 0;
    }
}
