/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>

using namespace std;

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> node_map;
        Node *n = head;
        while (n != nullptr)
        {
            Node *map_node = new Node(n->val);
            node_map[n] = map_node;
            n = n->next;
        }
        n = head;
        while (n != nullptr)
        {
            node_map[n]->next = node_map[n->next];
            node_map[n]->random = node_map[n->random];
            n = n->next;
        }
        return node_map[head];
    }
};
// @lc code=end
