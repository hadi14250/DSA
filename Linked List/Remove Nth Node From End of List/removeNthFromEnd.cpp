#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_size = 0;
        ListNode* node = head;

        while(node) {
            list_size++;
            node = node->next;
        }

        int target = list_size - n;

        if(target == 0) {
            return head->next;
        }

        node = head;
        for(int i = 1; i < target; i++) {
            node = node->next;
        }

        node->next = node->next->next;

        return head;
    }
};
