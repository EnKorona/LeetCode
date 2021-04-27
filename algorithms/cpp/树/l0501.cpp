//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
//
// 假定 BST 有如下定义：
//
//
// 结点左子树中所含结点的值小于等于当前结点的值
// 结点右子树中所含结点的值大于等于当前结点的值
// 左子树和右子树都是二叉搜索树
//
//
// 例如：
//给定 BST [1,null,2,2],
//
//    1
//    \
//     2
//    /
//   2
//
//
// 返回[2].
//
// 提示：如果众数超过1个，不需考虑输出顺序
//
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
// Related Topics 树
// 👍 296 👎 0


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
    map<int,int> m;
    vector<int> findMode(TreeNode* root) {
        preFindMode(root);
        int max = 0;
        vector<int> ans;
        for(auto it = m.begin();it != m.end();it++) {
            if (it -> second > max) max = it -> second;
        }
        for(auto it = m.begin();it != m.end();it++) {
            if (it -> second == max) ans.push_back(it -> first);
        }
        return ans;
    }
    void preFindMode(TreeNode* root) {
        if (root == NULL) return;
        m[root -> val]++;
        preFindMode(root -> left);
        preFindMode(root -> right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
