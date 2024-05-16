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
int count,flag=0;
ListNode* nxt;
    ListNode* reverse_func(ListNode* head, int &k)
    {
        count++;
        if(!head)
        {
            flag=1;
            return NULL;
        }
        if(count==k)
        {
            nxt=head->next;
            return head;
        }
        ListNode* newhead=reverse_func(head->next,k);
        if(flag==0)
        {
            head->next->next=head;
            return newhead;
        }
        else
        return NULL;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* dummy=new ListNode(0); 
        ListNode* pre, *temp;
        pre=dummy;
        while(head)
        {
            count=0;
            temp=reverse_func(head,k);
            if(temp!=NULL)
            {
                pre->next=temp;
                head->next=nxt;
                pre=head;
                head=nxt;
            }
            else
            break;
        }
        return dummy->next;
    }
};
//Or
class Solution {
public:
int count;
ListNode* nxt;
    ListNode* reverse_func(ListNode* head, int &k)
    {
        count++;
        if(count==k)
        {
            nxt=head->next;
            return head;
        }
        ListNode* newhead=reverse_func(head->next,k);
        head->next->next=head;
        return newhead;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* dummy=new ListNode(0); 
        ListNode* pre;
        pre=dummy;
        dummy->next=head;
        int len=0;
        while(head)
        {
            len++;
            head=head->next;
        }
        head=dummy->next;
        while(len-k>=0)
        {
            count=0;
            pre->next=reverse_func(head,k);
            head->next=nxt;
            pre=head;
            head=nxt;
            len-=k;
        }
        return dummy->next;
    }
};
