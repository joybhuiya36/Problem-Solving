class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* pre=NULL;
        ListNode* cur;
        ListNode* temp;
        cur=slow;
        while(cur!=NULL)
        {
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        ListNode* n1=head;
        ListNode* n2=pre;
        while(n2->next)
        {
           temp=n1->next;
           cout<<temp->val<<endl;
           n1->next=n2;
           n1=temp;
           
           temp=n2->next;
           n2->next=n1;
           n2=temp;
        }
        // while(pre)
        // {
        //     cout<<pre->val<<" ";
        //     pre=pre->next;
        // }
    }
};
