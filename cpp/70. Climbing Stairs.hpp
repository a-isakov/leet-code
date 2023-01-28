//You are climbing a staircase.It takes n steps to reach the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Example 1 :
//
//Input : n = 2
//Output : 2
//Explanation : There are two ways to climb to the top.
//1. 1 step + 1 step
//2. 2 steps
//Example 2 :
//
//Input : n = 3
//Output : 3
//Explanation : There are three ways to climb to the top.
//1. 1 step + 1 step + 1 step
//2. 1 step + 2 steps
//3. 2 steps + 1 step
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        int result = 3;
        int prev = 3;
        int prev_prev = 2;
        for (int i = 4; i <= n; i++)
        {
            result = prev + prev_prev;
            prev_prev = prev;
            prev = result;
        }
        return result;
    }

    void test()
    {
        std::cout << "Test 1 " << (climbStairs(1) == 1 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 2 " << (climbStairs(2) == 2 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 3 " << (climbStairs(3) == 3 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 4 " << (climbStairs(4) == 5 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 5 " << (climbStairs(5) == 8 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 6 " << (climbStairs(6) == 13 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 7 " << (climbStairs(7) == 21 ? "passed" : "FAILED") << "\n";
    }
};