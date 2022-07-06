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
     bool twos(TreeNode *root, TreeNode *cur, int target)
     {    if(root) {
         
         
         if(cur!=root and root->val==target)
         {
               return true;
         }
          else if((root->val)>target)
          {
              return twos(root->left,cur,target);
          }
        else if((root->val)<target)
          {
              return twos(root->right,cur,target);
          }
     }
       return false;
     }
    
    bool check( TreeNode *root, TreeNode *cur, int target) 
    {
        
         if(!cur or !root) return 0;
        return twos(root,cur,target - cur->val)||check(root,cur->left,target)||check(root,cur->right,target);
    }
    
    
    
    bool findTarget(TreeNode* root, int k) {
        return  check(root,root,k);
    }
};