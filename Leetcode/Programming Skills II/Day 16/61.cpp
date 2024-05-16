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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        return head;
        ListNode* last;
        ListNode* cur=head;
        int count=0;
        while(cur)
        {
            count++;
            if(cur->next==NULL)
            last=cur;
            cur=cur->next;
        }
        k%=count;
        if(k==0)
        return head;
        count-=k;
        cur=head;
        for(int i=0;i<count-1;i++)
        cur=cur->next;
        last->next=head;
        head=cur->next;
        cur->next=NULL;
        return head;
    }
};
