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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* l=head;
        ListNode* r=head->next;
        
        while(r)
        {
            if(l->val==r->val)
            {
                while(r && l->val==r->val)
                {
                    r=r->next;
                }
                pre->next=r;
                l=r;
                if(r)
                r=r->next;
            }
            else
            {
                pre=pre->next;
                l=l->next;
                r=r->next;
            }
        }
        return dummy->next;
    }
};
