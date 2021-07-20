//统计一个数字在排序数组中出现的次数。
//
//
//
// 示例 1:
//
//
//输入: nums = [5,7,7,8,8,10], target = 8
//输出: 2
//
// 示例 2:
//
//
//输入: nums = [5,7,7,8,8,10], target = 6
//输出: 0
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums 是一个非递减数组
// -109 <= target <= 109
//
//
//
//
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-
//position-of-element-in-sorted-array/
// Related Topics 数组 二分查找
// 👍 190 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int> &nums, int target) {
        return findRightBoundary(nums, target) - findRightBoundary(nums, target - 1);
    }

    int findRightBoundary(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] <= target) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
