/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

//20220603

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
    ListNode* n_head;

    void reverseListRec(ListNode* prev, ListNode* cur) {
        if (cur->next==nullptr) { //last elem
            n_head=cur;
            cur->next=prev;
            return;
        }
        reverseListRec(prev->next,cur->next);
        cur->next=prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        reverseListRec(head, head->next);
        head->next=nullptr;
        return n_head;    
    }
};
// @lc code=end

