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
    TreeNode* invertTree(TreeNode* root) {
        if(root != nullptr){
            if(root->left != nullptr){
                if(root->right != nullptr){
                    //Ambos
                    TreeNode* aux = root->left;
                    root->left = invertTree(root->right);
                    root->right = invertTree(aux);

                }else{
                    //Solo izquierda
                    root->right = invertTree(root->left);
                    root->left = nullptr;
                }
            }else{
                if(root->right != nullptr){
                    //Solo derecha
                    root->left = invertTree(root->right);
                    root->right = nullptr;
                }
            }
        }
        return root;
    }
};
