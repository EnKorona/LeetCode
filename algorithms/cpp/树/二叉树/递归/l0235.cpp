//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。”
//
// 例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5]
//
//
//
//
//
// 示例 1:
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//输出: 6
//解释: 节点 2 和节点 8 的最近公共祖先是 6。
//
//
// 示例 2:
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//输出: 2
//解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
//
//
//
// 说明:
//
//
// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉搜索树中。
//
// Related Topics 树
// 👍 571 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ancestor = new TreeNode();
    // 增加标记位，第一次找到的公共祖先是最近公共祖先，如果不是第一次找到的，就不进行记录
    int flag = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        judgeCommonAncestor(root,p,q);
        return ancestor;
    }
    // 按照后序遍历的方式从下往上查找第一个既是p的祖先节点又是q的祖先节点的节点，即是最近公共祖先
    void judgeCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return;
        judgeCommonAncestor(root -> left,p,q);
        judgeCommonAncestor(root -> right,p,q);
        if (findAncestor(root,p) && findAncestor(root,q) && flag == 0) {
            ancestor = root;
            flag = 1;
            return;
        }
    }
    // 判断root是不是node的祖先
    bool findAncestor(TreeNode* root,TreeNode* node) {
        if (root == NULL) return false;
        if (root == node) return true;
        return findAncestor(root -> left,node) || findAncestor(root -> right,node);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
