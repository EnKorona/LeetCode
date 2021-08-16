//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
// 说明：本题中，我们将空字符串定义为有效的回文串。
//
//
//
// 示例 1:
//
//
//输入: "A man, a plan, a canal: Panama"
//输出: true
//解释："amanaplanacanalpanama" 是回文串
//
//
// 示例 2:
//
//
//输入: "race a car"
//输出: false
//解释："raceacar" 不是回文串
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 2 * 105
// 字符串 s 由 ASCII 字符组成
//
// Related Topics 双指针 字符串
// 👍 404 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0,j = s.size()-1;
        while (i < j) {
            while (!isLetter(s[i]) && i< s.size()) i++;
            while (!isLetter(s[j]) && j > 0) j--;
            if (i >= j) return true;
            if (toLowerCase(s[i]) != toLowerCase(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
    char toLowerCase(char c) {
        if (c >= 'a' && c <= 'z') return c;
        else return c - ('A' - 'a');
    }
    bool isLetter(char c) {
        if (c >= 'a' && c <='z') return true;
        if (c >= 'A' && c <='Z') return true;
        if (c >= '0' && c <='9') return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
