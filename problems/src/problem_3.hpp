/***********************************************************************************************************************
 * 3. Longest Substring Without Repeating Characters
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 *
 * Example 1:
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * Constraints:
 *
 *     0 <= s.length <= 5 * 104
 *     s consists of English letters, digits, symbols and spaces.
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>

namespace leet_algo_prob::prob_3
{
class Solution_1
{
  public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::map<char, int> ss_map;
        int max_len{0};
        int i{0}, n{int(s.length())}, cur_size{0};
        while (i < n) {
            if (ss_map.find(s[i]) != ss_map.end()) {
                i = ss_map[s[i]] + 1;
                ss_map.clear();
            }
            ss_map.insert(std::make_pair(s[i], i));
            ++i;
            cur_size = int(ss_map.size());
            max_len = max_len > cur_size ? max_len : cur_size;
        }
        return max_len;
    }
};

class Solution_2
{
  public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> ss_map;
        int max_len{0};
        int i{0}, j{0}, n{int(s.length())};
        while (j < n) {
            if (ss_map[s[j]] > 0) {
                i = std::max(ss_map[s[j]], i);
            }
            ss_map[s[j]] = j + 1;
            ++j;
            max_len = std::max(max_len, j - i);
        }
        return max_len;
    }
};
} // namespace leet_algo_prob::prob_3
