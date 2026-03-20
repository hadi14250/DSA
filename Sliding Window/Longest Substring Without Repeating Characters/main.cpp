#include "lengthOfLongestSubstring.cpp"
#include <iostream>
#include <string>

using namespace std;

void runTest(string testName, string s, int expected) {
    Solution sol;
    auto result = sol.lengthOfLongestSubstring(s);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Standard case",
        "abcabcbb", 3
    );

    // Test 2: all same characters
    runTest("All same characters",
        "bbbbb", 1
    );

    // Test 3: mixed repeats
    runTest("Mixed repeats",
        "pwwkew", 3
    );

    // Test 4: empty string
    runTest("Empty string",
        "", 0
    );

    // Test 5: no repeating characters
    runTest("No repeating characters",
        "abcdef", 6
    );

}
