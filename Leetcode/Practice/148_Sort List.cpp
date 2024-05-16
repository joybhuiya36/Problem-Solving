class Solution {
public:
ListNode *slow, *fast;
    ListNode* mergeSort(ListNode* a, ListNode* b)
    {
        ListNode* dummy= new ListNode(-999999);
        ListNode* ptr=dummy;
        while(a && b)
        {
            if(a->val<b->val)
            {
                ptr->next=a;
                a=a->next;
            }
            else
            {
                ptr->next=b;
                b=b->next;
            }
            ptr=ptr->next;
        }
        if(a)
        ptr->next=a;
        if(b)
        ptr->next=b;
        return dummy->next;
    }
    ListNode* findMid(ListNode* head, ListNode* tail)
    {
        slow=fast=head;
        while(fast!=tail && fast->next!=tail)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* divide(ListNode* head, ListNode* tail)
    {
        if(head==tail)
        return new ListNode(head->val);
        ListNode* mid=findMid(head,tail);
        ListNode* left= divide(head,mid);
        ListNode* right= divide(mid->next,tail);
        return mergeSort(left,right);
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        ListNode* tail=head;
        while(tail->next!=NULL)
        tail=tail->next;
        return divide(head,tail);
    }
};
