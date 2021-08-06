//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
// 有效字符串需满足：
//
//
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
//
//
//
//
// 示例 1：
//
//
//输入：s = "()"
//输出：true
//
//
// 示例 2：
//
//
//输入：s = "()[]{}"
//输出：true
//
//
// 示例 3：
//
//
//输入：s = "(]"
//输出：false
//
//
// 示例 4：
//
//
//输入：s = "([)]"
//输出：false
//
//
// 示例 5：
//
//
//输入：s = "{[]}"
//输出：true
//
//
//
// 提示：
//
//
// 1 <= s.length <= 104
// s 仅由括号 '()[]{}' 组成
//
// Related Topics 栈 字符串
// 👍 2532 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        // 建立映射，key是右括号，value是左括号
        unordered_map<char,char> mp = {
                {')','('},
                {']','['},
                {'}','{'}
        };
        stack<char> stk;
        // 依次遍历每个字符
        for (char c :s) {
            // unordered_map::count()的本质在检查map中是否存在对应的key
            if (mp.count(c)) {
                // 如果当前遍历到右括号，就要检查栈是不是空的，如果不是空的，就看栈顶元素是否是当前字符对应的左括号
                if (stk.empty() || stk.top() != mp[c]) {
                    return false;
                }
                // 如果当前元素对应上了，则将栈顶的左括号出栈
                stk.pop();
            } else {
                // 如果当前遍历到左括号，则将其入栈
                stk.push(c);
            }
        }
        // 全部遍历完后，如果栈非空，则匹配失败
        return stk.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
