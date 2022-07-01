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
     vector<TreeNode*> vec;
     void prorder(TreeNode* root)
     {   
         if(!root)
         {
             return;
         }
          vec.push_back(root);
         prorder(root->left);
         prorder(root->right);
     }
    void flatten(TreeNode* root) {
        
          vec.clear();
          prorder(root);
          for(int i =1; i<vec.size();i++)
          {
              root->right = vec[i];
              root->left = NULL;
              root= root->right;
          }
        
    }
};