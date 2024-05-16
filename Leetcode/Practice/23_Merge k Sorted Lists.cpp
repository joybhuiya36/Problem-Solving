class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        if(!a) return b;
        if(!b) return a;
        if(a->val<b->val)
        {
            a->next= merge(a->next,b);
            return a;
        }
        else
        {
            b->next= merge(a,b->next);
            return b;
        }
        return NULL;
    }
    ListNode* divide(int l, int r, vector<ListNode*> &lists)
    {
        if(l>r) return NULL;
        if(l==r) return lists[l];
        int mid=l+((r-l)/2);
        ListNode* ll= divide(l,mid,lists);
        ListNode* rr= divide(mid+1,r,lists);
        return merge(ll,rr);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        return divide(0,n-1,lists);
    }
};
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

