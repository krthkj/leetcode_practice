/***********************************************************************************************************************
 * 283. Move Zeroes
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * Note that you must do this in-place without making a copy of the array.
 *
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * -231 <= nums[i] <= 231 - 1
 *
 * Follow up: Could you minimize the total number of operations done?
 *
 ***********************************************************************************************************************
 * have two pointers, slow and fast.
 * index: fast=0, slow=0
 * if fast == 0 then fast++
 * if fast != 0 then swap (fast, slow); slow++; fast++;
 */
 
 #include <vector>
 
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n{int(nums.size())};
        for(int slowPtr{0},fastPtr{0}; slowPtr<n && fastPtr <n;fastPtr++){
            if (nums[fastPtr]!=0 ){
                    int tmp{nums[fastPtr]};
                    nums[fastPtr]= nums[slowPtr];
                    nums[slowPtr++]= tmp;
                }
        }
    }
};
