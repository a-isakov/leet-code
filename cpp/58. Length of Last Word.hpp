// https://leetcode.com/problems/length-of-last-word/
// Given a string s consisting of words and spaces, return the length of the last word in the string.
//
//A word is a maximal
//substring
//consisting of non - space characters only.
//
//Example 1:
//
//Input: s = "Hello World"
//Output : 5
//Explanation : The last word is "World" with length 5.
//Example 2 :
//
//	Input : s = "   fly me   to   the moon  "
//	Output : 4
//	Explanation : The last word is "moon" with length 4.
//	Example 3 :
//
//	Input : s = "luffy is still joyboy"
//	Output : 6
//	Explanation : The last word is "joyboy" with length 6.
//
//
//	Constraints :
//
//	1 <= s.length <= 104
//	s consists of only English letters and spaces ' '.
//	There will be at least one word in s.
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        const char *c = s.c_str();
        int counter = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (c[i] == ' ') {
                if (counter)
                    break;
            }
            else
                counter++;
        }
        return counter;
    }

    void test()
    {
        std::cout << "Test 1 " << std::string(lengthOfLastWord("Hello World") == 5 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 2 " << std::string(lengthOfLastWord("   fly me   to   the moon  ") == 4 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 3 " << std::string(lengthOfLastWord("luffy is still joyboy") == 6 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 4 " << std::string(lengthOfLastWord("a") == 1 ? "passed" : "FAILED") << "\n";
    }
};