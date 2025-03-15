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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int indicePre = 0;
        return construyeArbol(preorder,inorder,indicePre,0,inorder.size()-1);
        
    }

    TreeNode* construyeArbol(vector<int>& preorder, vector<int>& inorder,int& indicePre, int inicioInorden,int finInorden){
        //Caso base, no hay mas nodos en este rango
        if(inicioInorden > finInorden)
            return nullptr;
        int raiz = preorder[indicePre];
        indicePre++;
        TreeNode* nodoRaiz = new TreeNode(raiz);

        //Buscamos la posicion de la raiz en el inorden
        int indiceInorden = inicioInorden;
        while(indiceInorden <= finInorden && inorder[indiceInorden] != raiz){
            indiceInorden++;
        }

        //Construimos los subarboles
        nodoRaiz->left = construyeArbol(preorder,inorder,indicePre,inicioInorden,indiceInorden-1);
        nodoRaiz->right = construyeArbol(preorder,inorder,indicePre,indiceInorden+1,finInorden);

        return nodoRaiz;
    }
};
