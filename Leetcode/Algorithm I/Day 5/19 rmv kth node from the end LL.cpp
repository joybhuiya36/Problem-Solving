//Two Pointer where slow is started from kth delay
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for(int i = 1; i<=n;i++){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
//Counting numbers through slow-fast pointer, then deleting process
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        int count=0;
        while(fast && fast->next)
        {
            count+=2;
            fast=fast->next->next;
        }
        if(fast!=NULL) count++;
        if(count==n) return head->next;
        n=count-n-1;
        fast=head;
        while(n--)
        {
            fast=fast->next;
        }
        fast->next=fast->next->next;
        return head;
    }
};
