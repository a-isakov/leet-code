//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
//
//Example 1:
//Input: head = [1,1,2]
//Output: [1,2]
//
//Example 2:
//Input: head = [1,1,2,3,3]
//Output: [1,2,3]
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head != nullptr) {
            ListNode* node = head;
            while (node) {
                while (node->next != nullptr && node->val == node->next->val) {
                    ListNode* del = node->next;
                    node->next = node->next->next;
                    delete del;
                }
                node = node->next;
            }
        }
        return head;
    }

    ListNode* getListFromVector(vector<int> v) {
        if (v.empty())
            return nullptr;
        ListNode *last = nullptr;
        for (size_t i = v.size(); i != 0; i--) {
            ListNode *node = new ListNode(v[i - 1], last);
            last = node;
        }
        return last;
    }

    vector<int> getVectorFromList(ListNode *head) {
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        return v;
    }

    void test()
    {
        std::cout << "Test 1 " << (getVectorFromList(deleteDuplicates(getListFromVector({1, 1, 2}))) == vector<int>({1, 2}) ? "passed" : "FAILED") << "\n";
        std::cout << "Test 2 " << (getVectorFromList(deleteDuplicates(getListFromVector({1, 1, 2, 3, 3}))) == vector<int>({1, 2, 3}) ? "passed" : "FAILED") << "\n";
        std::cout << "Test 3 " << (getVectorFromList(deleteDuplicates(getListFromVector({}))) == vector<int>({}) ? "passed" : "FAILED") << "\n";
        std::cout << "Test 4 " << (getVectorFromList(deleteDuplicates(getListFromVector({1, 1, 1}))) == vector<int>({1}) ? "passed" : "FAILED") << "\n";
    }
};