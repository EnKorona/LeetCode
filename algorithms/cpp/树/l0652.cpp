//给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
//
// 两棵树重复是指它们具有相同的结构以及相同的结点值。
//
// 示例 1：
//
//         1
//       / \
//      2   3
//     /   / \
//    4   2   4
//       /
//      4
//
//
// 下面是两个重复的子树：
//
//       2
//     /
//    4
//
//
// 和
//
//     4
//
//
// 因此，你需要以列表的形式返回上述重复子树的根结点。
// Related Topics 树
// 👍 263 👎 0


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
    vector<TreeNode*> ans;
    map<string,int> record;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serializeAndRecord(root);
        return ans;
    }
    // 序列化的目的是唯一标识一棵树，比当场判断这棵树要更有效率。在序列化的过程中直接把遇到的每棵树进行处理，如果出现过就加入队列
    string serializeAndRecord(TreeNode* root) {
        if (root == NULL) {
            return "#";
        }
        string left = serializeAndRecord(root -> left);
        string right= serializeAndRecord(root -> right);

        string subTree = left + "," + right + "," + to_string(root -> val);
        if (record[subTree] == 1) {
            ans.push_back(root);
        }
        record[subTree]++;
        return subTree;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
