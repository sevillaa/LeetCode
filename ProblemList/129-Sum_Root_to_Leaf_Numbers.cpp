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
    
    int sumNumbers(TreeNode* root) {
        if(root->left != nullptr || root->right != nullptr){
           return complementario(root->left,root->val) + complementario(root->right,root->val);          
        }
        return root->val;
    }
    int complementario(TreeNode* root,int act){
        if(root != nullptr){
            int num = act * 10 + root->val;
            if(root->left == nullptr && root->right == nullptr){
            //si es hoja sumamos el numero a suma
                return num;
            }else{
                if(root->left != nullptr){                
                    if(root->right != nullptr){
                        return complementario(root->left ,num) + complementario(root->right ,num);
                    }else{
                        return  complementario(root->left,num);
                    }             
                }else{
                    return  complementario(root->right,num);
                }
            }
        }else
            return 0;
        
    }
};
