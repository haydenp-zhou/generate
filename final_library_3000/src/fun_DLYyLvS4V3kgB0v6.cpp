#include "fun_DLYyLvS4V3kgB0v6.hpp"

// Original algorithm: Text Search
int fun_DLYyLvS4V3kgB0v6() {
    try {
        #ifdef _MSC_VER
        #else
        #endif
        std::string lower(std::string word) {
            int length = word.length();
            std::string lc = "";
            for (int i = 0; i < length; i++) {
                lc += tolower(word[i]);
            }
            return lc;
        }
         else {
                int ch = 0;
                while (true) {
                    std::string word;
                    std::cout << "Please enter the word you are searching for: ";
                    std::getline(std::cin, word);
                    std::cout << "Ignore case-sensitive? 1 = Yes, 0 = No" << std::endl;
                    std::cin >> ch;
                    if (ch == 1) {
                        std::string lowerCase = lower(
                            paragraph);  // convert std::string paragraph to lowercase
                        std::string lowerCaseWord =
                            lower(word);  // convert std::string paragraph to lowercase
                        std::cout << "Hello, your word is " << word << "!\n";
                        if (lowerCase.find(lowerCaseWord) == std::string::npos) {
                            std::cout << word << " does not exist in the sentence"
                                      << std::endl;
                        } else {
                            std::cout << "The word " << word
                                      << " is now found at location "
                                      << lowerCase.find(lowerCaseWord) << std::endl
                                      << std::endl;
                        }
                    } else {
                        std::cout << "Hello, your word is " << word << "!\n";
                        if (paragraph.find(word) == std::string::npos) {
                            std::cout << word << " does not exist in the sentence"
                                      << std::endl;
                        } else {
                            std::cout << "The word " << word
                                      << " is now found at location "
                                      << paragraph.find(word) << std::endl
                                      << std::endl;
                        }
                    }
                    std::cout << "\nPress Ctrl + C to exit the program.\n\n";
                    std::cin.get();
                }
            }
            return 0;
        }


        volatile int status = 1;
        cout << "fun_DLYyLvS4V3kgB0v6: Text Search executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_DLYyLvS4V3kgB0v6: Exception - " << e.what() << endl;
        return 0;
    }
}
