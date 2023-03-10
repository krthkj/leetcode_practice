/***********************************************************************************************************************
 * 344. Reverse String
 *
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 *
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 * Constraints:
 * 1 <= s.length <= 105
 * s[i] is a printable ascii character.
 *
 */

#include <vector>

namespace leet_algo_prob::prob_344
{
class Solution
{
  public:
    void reverseString(std::vector<char>& s)
    {
        int r = s.size() - 1;
        int f{0};
        while (f < r) {
            swap(s[f++], s[r--]);
        }
    }
};
} // namespace leet_algo_prob::prob_344
