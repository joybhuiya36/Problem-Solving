/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0, n=0;
        ListNode* mt=headA;
        ListNode* nt=headB;
        while(mt || nt)
        {
            if(mt)
            {
                m++;
                mt=mt->next;
            }
            if(nt)
            {
                n++;
                nt=nt->next;
            }
        }
        mt=headA; nt=headB;
        int t=abs(m-n);
        if(m>n)
        while(t--)
        mt=mt->next;
        else if(n>m)
        while(t--)
        nt=nt->next;
        while(mt && nt)
        {
            if(mt==nt)
            return mt;
            mt=mt->next;
            nt=nt->next;
        }
        return NULL;
    }
};
