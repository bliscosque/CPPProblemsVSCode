/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* ansHead=nullptr;
    ListNode* ansLast=nullptr;

    void mergeTL(ListNode* list1, ListNode* list2) {
        if (list1==nullptr && list2==nullptr) return;
        else if (list1==nullptr) {
            if (ansHead==nullptr) {
                ansHead=list2;
                ansLast=list2;
            }
            else {
                ansLast->next=list2;
                ansLast=ansLast->next;
            }
            mergeTL(list1, list2->next);
        }
        else if (list2==nullptr) {
            if (ansHead==nullptr) {
                ansHead=list1;
                ansLast=list1;
            }
            else {
                ansLast->next=list1;
                ansLast=ansLast->next;
            }
            mergeTL(list1->next,list2);
        }
        else {
            if (list1->val > list2->val) {
                if (ansHead==nullptr) {
                    ansHead=list2;
                    ansLast=list2;
                }
                else {
                    ansLast->next=list2;
                    ansLast=ansLast->next;                    
                }
                mergeTL(list1, list2->next);

            }
            else {
                if (ansHead==nullptr) {
                    ansHead=list1;
                    ansLast=list1;
                }
                else {
                    ansLast->next=list1;
                    ansLast=ansLast->next;
                }
                mergeTL(list1->next,list2);
            }
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ansHead=nullptr; ansLast=nullptr;
        mergeTL(list1,list2);
        return ansHead;
    }
};
// @lc code=end

