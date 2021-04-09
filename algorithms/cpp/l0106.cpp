//根据一棵树的中序遍历与后序遍历构造二叉树。
//
// 注意:
//你可以假设树中没有重复的元素。
//
// 例如，给出
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3]
//
// 返回如下的二叉树：
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
//
// Related Topics 树 深度优先搜索 数组
// 👍 478 👎 0


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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = baseBuild(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }

    TreeNode *
    baseBuild(vector<int> &inorder, vector<int> &postorder, int inLeft, int inRight, int postLeft, int postRight) {
        if (inLeft > inRight) return NULL;

        int inRootIdx = -1;
        for (int i = inLeft; i < inorder.size(); i++) {
            if (inorder[i] == postorder[postRight]) {
                inRootIdx = i;
                break;
            }
        }
        int leftLen = inRootIdx - inLeft;

        TreeNode *root = new TreeNode();
        root->val = postorder[postRight];
        root->left = baseBuild(inorder, postorder, inLeft, inRootIdx - 1, postLeft, postLeft + leftLen - 1);
        root->right = baseBuild(inorder, postorder, inLeft + leftLen + 1, inRight, postLeft + leftLen, postRight - 1);
        return root;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
