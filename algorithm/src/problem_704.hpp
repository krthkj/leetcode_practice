/***********************************************************************************************************************
 * 704. Binary Search
 *
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search
 * target in nums. If target exists, then return its index. Otherwise, return -1.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 *
 * Example 2:
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * -104 < nums[i], target < 104
 * All the integers in nums are unique.
 * nums is sorted in ascending order.
 *
 ***********************************************************************************************************************
 * Binary Search Algo
 * ------------------
 * binary_search(array, target)
 *     if mid_of_array == target then
 *         return mid
 *     else if target < mid_of_array then
 *         binary_search( array(begin , mid-1), target )
 *     else if target > mid_of_array then
 *         binary_search( array(mid+1, end), target)
 *
 */

#include <algorithm>
#include <vector>

namespace leet_algo_prob::prob_704
{
enum Result : int { NOT_FOUND = -1 };

class Solution_1 // Recursive
{
    int bin_search(std::vector<int>& data, int low, int high, int target)
    {
        if (low <= high) {
            int mid{(low + high) / 2};
            if (target == data.at(mid))
                return mid;
            else if (target < data.at(mid))
                return bin_search(data, low, mid - 1, target);
            else
                return bin_search(data, mid + 1, high, target);
        } else
            return Result::NOT_FOUND;
    }

  public:
    int search(std::vector<int>& nums, int target)
    {
        if (nums.empty())
            return Result::NOT_FOUND;
        return bin_search(nums, 0, nums.size() - 1, target);
    }
};

class Solution_2 // using built-in function
{
  public:
    int search(std::vector<int>& nums, int target)
    {
        int idx = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (idx > 0 && nums[idx - 1] == target) {
            return idx - 1;
        } else {
            return Result::NOT_FOUND;
        }
    }
};

class Solution_3 // using non-recursive
{
  public:
    int search(std::vector<int>& nums, int target)
    {
        int low{0}, high{int(nums.size()) - 1}, mid{0};
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return Result::NOT_FOUND;
    }
};
} // namespace leet_algo_prob::prob_704
