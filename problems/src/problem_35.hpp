/***********************************************************************************************************************
 * 35. Search Insert Position
 *
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return
 * the index where it would be if it were inserted in order.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 *
 * Example 2:
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 *
 * Example 3:
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 *
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 *
 */

#include <vector>

namespace leet_algo_prob::prob_35
{
class Solution
{
  public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        int l{0}, r{int(nums.size()) - 1}, mid{r / 2};
        while (l <= r) {
            if (target == nums.at(mid))
                return mid;
            else if (target < nums.at(mid))
                r = mid - 1;
            else
                l = mid + 1;
            mid = l + (r - l) / 2;
        }
        return l;
    }
};
} // namespace leet_algo_prob::prob_35
