/*
 * 189. Rotate Array
 * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 * Example 2:
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 *
 * Constraints:
 *   1 <= nums.length <= 105
 *   -231 <= nums[i] <= 231 - 1
 *   0 <= k <= 105
 *
 * Follow up:
 * - Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
 * - Could you do it in-place with O(1) extra space?
 ***********************************************************************************************************************
 * nums = [1,2,3,4, 5,6,7]; k = 3
 *        [1,2,3,4][5,6,7]
 *        [5,6,7][1,2,3,4]
 *
 * nums = [1,2,3,4,5,6,7]; k = 3, n =6
 * reverse all   [7,6,5,4,3,2,1]
 * reverse (0,3) [5,6,7,4,3,2,1]
 * reverse (4,6) [5,6,7,1,2,3,4]
 *
 */

#include <algorithm>
#include <vector>

namespace leet_algo_prob::prob_189
{
class Solution
{
  public:
    void rotate(std::vector<int>& nums, int k)
    {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
} // namespace leet_algo_prob::prob_189
