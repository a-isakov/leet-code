// https://leetcode.com/problems/rectangle-area/
// Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
//
//The first rectangle is defined by its bottom - left corner(ax1, ay1) and its top - right corner(ax2, ay2).
//
//The second rectangle is defined by its bottom - left corner(bx1, by1) and its top - right corner(bx2, by2).
//
//
//
//Example 1:
//
//Rectangle Area
//Input : ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
//Output : 45
//Example 2 :
//
//    Input : ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
//    Output : 16
//
//
//    Constraints :
//
//    -104 <= ax1 <= ax2 <= 104
//    - 104 <= ay1 <= ay2 <= 104
//    - 104 <= bx1 <= bx2 <= 104
//    - 104 <= by1 <= by2 <= 104
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        const int s1 = (ax2 - ax1) * (ay2 - ay1);
        const int s2 = (bx2 - bx1) * (by2 - by1);
        int dx = 0;
        int dy = 0;
        XRESULT xRes = getXResult(ax1, ax2, bx1, bx2);
        if (xRes != XRESULT::NO_INTERSECTION)
        {
            XRESULT yRes = getXResult(ay1, ay2, by1, by2);
            if (yRes != XRESULT::NO_INTERSECTION)
            {
                if (xRes == XRESULT::INSIDE12)
                {
                    if (yRes == XRESULT::INSIDE12)
                        return s1;
                    dx = bx2 - bx1;
                }
                else if (xRes == XRESULT::INSIDE21)
                {
                    if (yRes == XRESULT::INSIDE21)
                        return s2;
                    dx = ax2 - ax1;
                }
                else if (xRes == XRESULT::INTERSECTION12)
                    dx = ax2 - bx1;
                else // xRes == XRESULT::INTERSECTION21
                    dx = bx2 - ax1;

                if (yRes == XRESULT::INSIDE12)
                    dy = by2 - by1;
                else if (yRes == XRESULT::INSIDE21)
                    dy = ay2 - ay1;
                else if (yRes == XRESULT::INTERSECTION12)
                    dy = ay2 - by1;
                else // yRes == XRESULT::INTERSECTION21
                    dy = by2 - ay1;
            }
        }
        return s1 + s2 - (dx * dy);
    }

    void test()
    {
        std::cout << "Test 1 " << std::string(computeArea(-3, 0, 3, 4, 0, -1, 9, 2) == 45 ? "passed" : "FAILED") << "\n";
        std::cout << "Test 2 " << std::string(computeArea(-2, -2, 2, 2, -2, -2, 2, 2) == 16 ? "passed" : "FAILED") << "\n";
    }

private:
    enum XRESULT {
        NO_INTERSECTION,
        INTERSECTION12,
        INTERSECTION21,
        INSIDE12,
        INSIDE21
    };

    inline XRESULT getXResult(int& ax1, int& ax2, int& bx1, int& bx2)
    {
        if (ax1 < bx1)
        {
            // first is on the left
            if (bx1 >= ax2)
            {
                // no intersection
                return XRESULT::NO_INTERSECTION;
            }
            else if (bx1 < ax2 && bx2 > ax2)
            {
                // intersection
                return XRESULT::INTERSECTION12;
            }
            else
            {
                // second inside first one
                return XRESULT::INSIDE12;
            }
        }
        else
        {
            // second is on the left
            if (bx2 <= ax1)
            {
                // no intersection
                return XRESULT::NO_INTERSECTION;
            }
            else if (bx2 > ax1 && bx2 < ax2)
            {
                // intersection
                return XRESULT::INTERSECTION21;
            }
            else
            {
                // first inside second one
                return XRESULT::INSIDE21;
            }
        }
        return XRESULT::NO_INTERSECTION; // should never get here
    }
};