//根据一棵树的前序遍历与中序遍历构造二叉树。
//
// 注意:
//你可以假设树中没有重复的元素。
//
// 例如，给出
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]
//
// 返回如下的二叉树：
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// Related Topics 树 深度优先搜索 数组
// 👍 976 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = baseBuild(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return root;
    }

    TreeNode *
    baseBuild(vector<int> &preorder, vector<int> &inorder, int preleft, int preright, int inleft, int inright) {
        if (preleft > preright) return NULL;

        int inRootIdx = -1;
        for (int i = inleft; i < inorder.size(); i++) {
            if (inorder[i] == preorder[preleft]) {
                inRootIdx = i;
                break;
            }
        }
        int leftLen = inRootIdx - inleft;

        TreeNode *root = new TreeNode();
        root->val = preorder[preleft];
        root->left = baseBuild(preorder, inorder, preleft + 1, preleft + leftLen, inleft, inRootIdx - 1);
        root->right = baseBuild(preorder, inorder, preleft + leftLen + 1, preright, inRootIdx + 1, inright);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
