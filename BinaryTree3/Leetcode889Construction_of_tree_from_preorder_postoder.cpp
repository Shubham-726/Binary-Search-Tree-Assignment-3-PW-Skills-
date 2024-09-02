// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* build(vector<int>& preorder,vector<int> &postorder,int postlo,int posthi,int &index){
//         if(postlo > posthi) return NULL;
//         TreeNode* root = new TreeNode(preorder[index]);
//         index++;
//         if(postlo == posthi) return root;
//         int i = postlo;
//         while(i <= posthi){
//             if(postorder[i] == preorder[index])
//                 break;
//                 i++;
//         }
//         int leftcount = i - postlo;
//         int rightcount = posthi - i;
//         root->left = build(preorder,postorder,postlo,i,index);
//         root->right = build(preorder,postorder,i+1,posthi-1,index);
//         return root;
//     }
//     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//         int n =  preorder.size();
//         int index = 0;
//         return build(preorder,postorder,0,n-1,index);
//     }
// };
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
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int prelo, int prehi, int postlo, int posthi) {
        if (postlo > posthi) return NULL;
        
        // The first element in the current preorder segment is the root
        TreeNode* root = new TreeNode(preorder[prelo]);
        
        if (prelo == prehi) return root; // If there's only one element, return it
        
        // Find the root of the left subtree in postorder array
        int leftRootVal = preorder[prelo + 1];
        int i = postlo;
        while (i <= posthi) {
            if (postorder[i] == leftRootVal)
                break;
            i++;
        }
        
        int leftCount = i - postlo +1;
        
        // Recursively build the left and right subtrees
        root->left = build(preorder, postorder, prelo + 1, prelo + leftCount, postlo, i);
        root->right = build(preorder, postorder, prelo + leftCount + 1, prehi, i + 1, posthi - 1);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, postorder, 0, n - 1, 0, n - 1);
    }
};
