#include "appendCharacters.cpp"
#include <iostream>
#include <string>

using namespace std;

void runTest(string testName, string s, string t, int expected) {
    Solution sol;
    auto result = sol.appendCharacters(s, t);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case - need to append 4 chars
    runTest("Standard case",
        "coaching", "coding",
        4
    );

    // Test 2: t already a subsequence
    runTest("T already a subsequence",
        "abcde", "a",
        0
    );

    // Test 3: no common characters
    runTest("No common characters",
        "z", "abcde",
        5
    );

    // Test 4: t is full subsequence of s
    runTest("T is full subsequence of s",
        "abcde", "ace",
        0
    );

    // Test 5: partial match
    runTest("Partial match",
        "abc", "abcd",
        1
    );

}
