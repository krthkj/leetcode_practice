/***********************************************************************************************************************
 * 876. Middle of the Linked List
 *
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node.
 *
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [3,4,5]
 * Explanation: The middle node of the list is node 3.
 *
 * Example 2:
 * Input: head = [1,2,3,4,5,6]
 * Output: [4,5,6]
 * Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 *
 *
 * Constraints:
 * The number of nodes in the list is in the range [1, 100].
 * 1 <= Node.val <= 100
 *
 *************************************************
 * mid is nothing but half.
 * have twopointers, one moves at 1x speed, second one moves at 2x speed. when second pointer reached the end,
 * the first pointer is pointing to the middle.
 *
 */

namespace leet_algo_prob::prob_876
{

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution_1
{
  public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* cur{head};
        ListNode* mid{head};
        int count{1};
        while (cur->next) {
            if (count++ % 2 == 0)
                mid = mid->next;
            cur = cur->next;
        }
        if (count % 2 == 0)
            return mid->next;
        else
            return mid;
    }
};

class Solution_2
{
  public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* cur{head};
        ListNode* mid{head};
        while (cur->next) {
            mid = mid->next;
            if (nullptr == cur->next->next)
                break;
            cur = cur->next->next;
        }
        return mid;
    }
};
} // namespace leet_algo_prob::prob_876
