/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return util(inorder, postorder, 0, postorder.size() - 1, postorder.size() - 1);
    }

    TreeNode * util(vector<int>& inorder, vector<int>& postorder, int start, int end , int index) {
        if (start > end) return nullptr;
        TreeNode * root = new TreeNode(postorder[index]);
        int mid = -1;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == postorder[index])
                mid = i;
        }
        root->right = util(inorder, postorder, mid + 1, end, index - 1 );
        root->left = util(inorder, postorder, start, mid - 1, index - 1 - (end - mid)); // important
        return root;

    }
};