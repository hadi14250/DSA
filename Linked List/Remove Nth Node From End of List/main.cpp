#include "removeNthFromEnd.cpp"
#include <iostream>
#include <vector>

using namespace std;

ListNode* buildList(vector<int> vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for(size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

vector<int> listToVector(ListNode* head) {
    vector<int> res;
    while(head) {
        res.push_back(head->val);
        head = head->next;
    }
    return res;
}

void runTest(string testName, vector<int> input, int n, vector<int> expected) {
    Solution sol;
    ListNode* head = buildList(input);
    ListNode* result = sol.removeNthFromEnd(head, n);
    if (listToVector(result) == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Standard case",
        {1,2,3,4,5}, 2,
        {1,2,3,5}
    );

    // Test 2: single node
    runTest("Single node",
        {1}, 1,
        {}
    );

    // Test 3: remove last node
    runTest("Remove last node",
        {1,2}, 1,
        {1}
    );

    // Test 4: remove first node
    runTest("Remove first node",
        {1,2,3}, 3,
        {2,3}
    );

    // Test 5: two nodes remove first
    runTest("Two nodes remove first",
        {1,2}, 2,
        {2}
    );

}
