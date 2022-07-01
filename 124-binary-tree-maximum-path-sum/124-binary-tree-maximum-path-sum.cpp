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
    int maxi = INT_MIN;
    
    int maxo(TreeNode* root)
    {
        if(!root) return 0;
        int l = 0;
         int r = 0;
              l =  max(maxo(root->left),0);
            r = max(maxo(root->right),0);
        maxi = max({maxi,r+l+root->val});
        cout<<maxi;
        int ans = max({r+root->val,l+root->val});
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        
        int k = maxo(root);
        return maxi;
        
    }
};