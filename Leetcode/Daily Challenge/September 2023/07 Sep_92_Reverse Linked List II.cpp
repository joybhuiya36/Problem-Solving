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
    pair<ListNode*,ListNode*> rvrs(ListNode* root, int count)
    {
        if(count==0) return {root,root->next};
        auto cur=rvrs(root->next,count-1);
        root->next->next=root;
        root->next=NULL;
        return cur;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l=head;
        ListNode* tmp=NULL;
        int n=left-1;
        while(n--)
        {
            tmp=l;
            l=l->next;
        }
        auto rslt=rvrs(l,right-left);
        if(tmp!=NULL)
        {
            tmp->next=rslt.first;
            l->next=rslt.second;
        }
        else
        {
            l->next=rslt.second;
            head=rslt.first;
        }
        return head;
    }
};
