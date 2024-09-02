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
    TreeNode* build(vector<int> &inorder, int inlo, int inhi, vector<int> &postorder, int postlo, int posthi){
        if(postlo > posthi)  return NULL;
        TreeNode* root = new TreeNode(postorder[posthi]);
        if(postlo == posthi) return root;
        int i = inlo;
        while(i <= inhi){
            if(inorder[i] == postorder[posthi])
                break;
            i++;
        }
        int leftcount = i - inlo;
        int rightcount = inhi - i;
        root->left = build(inorder,inlo,i-1,postorder,postlo,postlo+leftcount-1);
        root->right = build(inorder,i+1,inhi,postorder,postlo+leftcount,posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int hi = postorder.size()-1;
       return build(inorder,0,hi,postorder,0,hi);
    }
};