/***********************************************************************************************************************
 * 977. Squares of a Sorted Array
 *
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in
 * non-decreasing order.
 *
 * Example 1:
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 *
 * Example 2:
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums is sorted in non-decreasing order.
 *
 * Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a
 * different approach?
 *
 ***********************************************************************************************************************
 * easy way: First step is to square and there sort.
 *
 * Squaring removed negative, and hence the list is sorted on either side of the zero.
 * 
 * a=[-4,-3,0,1,2,6,10]; b[0,0,0,0,0,0,0]
 * l=0, r=6, p=6; abs(a.l)<=abs(a.r); b.p=a.r; p--, r--; b[0,0,0,0,0,0,100]
 * l=0, r=5, p=5; abs(a.l)<=abs(a.r); b.p=a.r; p--, r--; b[0,0,0,0,0,36,100]
 * l=0, r=4, p=4; abs(a.l)>abs(a.r); b.p=a.r; p--, l++;  b[0,0,0,0,16,36,100]
 * l=1, r=4, p=3; abs(a.l)>abs(a.r); b.p=a.r; p--, l++;  b[0,0,0,9,16,36,100]
 * l=2, r=4, p=2; abs(a.l)<=abs(a.r); b.p=a.r; p--, r--; b[0,0,2,9,16,36,100]
 * l=2, r=3, p=1; abs(a.l)<=abs(a.r); b.p=a.r; p--, r--; b[0,1,2,9,16,36,100]
 * l=2, r=2, p=0; abs(a.l)<=abs(a.r); b.p=a.r; p--, r--; b[0,1,2,9,16,36,100]
 */

#include <cmath>
#include <vector>

namespace leet_algo_prob::prob_977
{
class Solution
{
  public:
    std::vector<int> sortedSquares(std::vector<int>& nums)
    {
        std::vector<int> res(nums.size());
        int l{0}, r{int(nums.size()) - 1}, p{r};
        while (l <= r) {
            if (std::abs(nums[l]) > std::abs(nums[r]))
                res[p--] = std::pow(nums[l++], 2);
            else
                res[p--] = std::pow(nums[r--], 2);
        }
        return res;
    }
};
} // namespace leet_algo_prob::prob_977
