// https://leetcode.com/problems/add-binary/
//Given two binary strings a and b, return their sum as a binary string.
//
//Example 1:
//
//Input: a = "11", b = "1"
//Output : "100"
//
//Example 2 :
//
//Input : a = "1010", b = "1011"
//Output : "10101"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int sizeA = (int)a.length();
        int sizeB = (int)b.length();
        int sizeMax = max(sizeA, sizeB);
        string res((size_t)sizeMax, '0');
        bool lastBit = false;
        for (int i = sizeMax; i != 0; i--)
        {
            sizeA--;
            sizeB--;
            bool a1 = is1(a, sizeA);
            bool b1 = is1(b, sizeB);
            if (a1 && b1)
            {
                if (lastBit)
                    res[i - 1] = '1';
                else
                    lastBit = true;
            }
            else if (a1 || b1)
            {
                if (!lastBit)
                    res[i - 1] = '1';
            }
            else
            {
                if (lastBit)
                {
                    res[i - 1] = '1';
                    lastBit = false;
                }
            }
            //std::cout << res << "\n";
        }
        if (lastBit)
        {
            res = "1" + res;
        }
        return res;
    }

    inline bool is1(string &s, int pos)
    {
        if (pos < 0)
            return false;
        return s[pos] == '1' ? true : false;
    }

    void test()
    {
        std::cout << "Test 1 " << std::string(addBinary("11", "1") == "100" ? "passed" : "FAILED") << "\n";
        std::cout << "Test 2 " << std::string(addBinary("1010", "1011") == "10101" ? "passed" : "FAILED") << "\n";
    }
};