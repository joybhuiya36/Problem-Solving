//Optimal
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* dummy = pre;
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if (pre->next == cur) pre = pre->next;
            else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
//My Solution
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
