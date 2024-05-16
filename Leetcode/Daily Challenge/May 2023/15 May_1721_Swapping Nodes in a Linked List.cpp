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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;
        while(k--)
        {
            head=head->next;
        }
        ListNode* ptr=head;
        ListNode* cur=dummy;
        while(head)
        {
            head=head->next;
            cur=cur->next;
        }
        swap(cur->val,ptr->val);
        return dummy->next;
    }
};
