/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr) return nullptr;
        else if (head->next==nullptr) return head;
        ListNode* h2=head->next;
        ListNode* nxt=h2->next;

        h2->next=head;
        head->next=swapPairs(nxt);
        return h2;
    }
};
// @lc code=end

