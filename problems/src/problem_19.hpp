/***********************************************************************************************************************
 * 19. Remove Nth Node From End of List
 *
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 * Constraints:
 *  The number of nodes in the list is sz.
 *  1 <= sz <= 30
 *  0 <= Node.val <= 100
 *  1 <= n <= sz
 *
 ***************************************
 * we need the size of the list to make calculations
 *
 */
namespace leet_algo_prob::prob_19
{

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;

    ListNode()
        : val(0)
        , next(nullptr)
    {
    }

    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }

    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution
{
    int getListLen(ListNode* head)
    {
        ListNode* tmp{head};
        int size{0};
        while (tmp) {
            size++;
            tmp = tmp->next;
        }
        return size;
    }

  public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head == nullptr)
            return nullptr;

        int len{getListLen(head)};
        if (len <= 1)
            return nullptr;

        ListNode* prev{nullptr};
        if (len == n) {
            prev = head;
            head = head->next;
            prev->next = nullptr;
            delete (prev);
            return head;
        }
        ListNode* curr{head};
        int pos{len - n - 1};
        // std::cout << " pos:" << pos;
        while (curr && pos >= 0) {
            prev = curr;
            curr = curr->next;
            --pos;
        }
        if (curr) {
            // std::cout << " curr:"<< curr->val;
            prev->next = curr->next;
            curr->next = nullptr;
            delete (curr);
        }
        // else{
        //     std::cout << " curr: invalid";
        // }
        return head;
    }
};
} // namespace leet_algo_prob::prob_876
