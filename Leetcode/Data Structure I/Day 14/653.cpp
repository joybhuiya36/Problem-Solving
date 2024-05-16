/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        vector<int> v;
        int target=k-root->val;
        while(root || !stk.empty())
        {
            while(root!=NULL)
            {
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            v.push_back(root->val);
            if(k!=target*2 && root->val==target)
            return true;
            root=root->right;
        }

        int l, r;								//	Or, sum of two pointer matching to target
        for(int i=0;i<v.size()-1;i++)			//	while (i < j)
        {										//	{
            target=k-v[i];						//		int sum = inorder[i] + inorder[j];
            l=i+1; r=v.size()-1;				//		if(sum == k) return true;
            while(l<=r)							//		else if(sum > k) j--;
            {									//		else i++;
                int mid=(l+r)/2;				//	}
                if(v[mid]==target)
                return true;
                else if(v[mid]>target)
                r=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};
