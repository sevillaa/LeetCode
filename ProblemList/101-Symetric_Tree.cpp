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
 */class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true; // Un árbol vacío es simétrico
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* izq, TreeNode* der) {
        if (izq == nullptr && der == nullptr) return true;  // Ambos son nullptr → simétrico
        if (izq == nullptr || der == nullptr) return false; 
        
        if (izq->val != der->val) return false; // Valores distintos → no simétrico

        // Verificamos la simetría intercambiando subárboles
        return isMirror(izq->left, der->right) && isMirror(izq->right, der->left);
    }
};
