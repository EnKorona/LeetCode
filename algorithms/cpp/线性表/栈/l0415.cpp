//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。 
//
// 
//
// 提示： 
//
// 
// num1 和num2 的长度都小于 5100 
// num1 和num2 都只包含数字 0-9 
// num1 和num2 都不包含任何前导零 
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式 
// 
// Related Topics 数学 字符串 模拟 
// 👍 416 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size() - 1;
        int len2 = num2.size() - 1;
        int add = 0;
        string ans = "";
        while (len1 >= 0|| len2 >=0 || add != 0) {
            int a = len1 >= 0 ? num1[len1] - '0' : 0;
            int b = len2 >= 0 ? num2[len2] - '0' : 0;
            int result = a + b + add;
            ans.push_back('0' + result%10);
            add = result/10;
            len1--;
            len2--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
