/***********************************************************************************************************************
 * 567. Permutation in String
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * In other words, return true if one of s1's permutations is the substring of s2.
 *
 * Example 1:
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 * Example 2:
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 * Constraints:
 *
 *     1 <= s1.length, s2.length <= 104
 *     s1 and s2 consist of lowercase English letters.
 ******************************************************************************
 * Approach1:
 * 1. sort s1
 * 2. get substring of string s2 of lengthOf(s1) starting from pos 0
 *    3. sort the substring
 *    4. compare sorted s1 string with sorted substring, if same, return true
 * 5. if loop exists then returm false
 *
 * Approach 2:
 * have two maps of length 26 (lowecase letters)
 * 1. parse s1, flag the map based of the char
 * 2. parse s2, use two index
 *    - use index1 to flag the map based of the char
 *    - if index1 > length of s1, use index2 to clear the flag
 *    - if two maps are same return true
 * 3. return false if parse completes
 *
 */

#include <algorithm>
#include <array>
#include <iostream>

namespace leet_algo_prob::prob_567
{
class Solution_1
{
  public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2)
            return false;

        sort(s1.begin(), s1.end());
        ++n2 -= n1;
        for (int i{0}; i < n2; ++i) {
            std::string tmp = s2.substr(i, n1);
            sort(tmp.begin(), tmp.end());
            if (tmp == s1)
                return true;
        }
        return false;
    }
};

class Solution_2
{
  public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        if (s1.length() > s2.length())
            return false;
        std::array<int, 26> hash1{}, hash2{};

        int n1 = s1.size(), n2 = s2.size();
        for (int i{0}; i < n1; i++)
            hash1[s1[i] - int('a')]++; // set flag

        for (int fast{0}, slow{0}; fast < n2; ++fast) {
            hash2[s2[fast] - int('a')]++; // set flag
            if (fast >= n1)
                hash2[s2[slow++] - int('a')]--; // clear flag
            if (hash1 == hash2)
                return true;
        }
        return false;
    }
};
} // namespace leet_algo_prob::prob_567
