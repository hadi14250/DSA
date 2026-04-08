#include "isAnagram.cpp"
#include <iostream>
#include <string>

using namespace std;

void runTest(string testName, string s, string t, bool expected) {
    Solution sol;
    auto result = sol.isAnagram(s, t);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: valid anagram
    runTest("Valid anagram",
        "racecar", "carrace",
        true
    );

    // Test 2: not an anagram
    runTest("Not an anagram",
        "jar", "jam",
        false
    );

    // Test 3: different lengths
    runTest("Different lengths",
        "abc", "ab",
        false
    );

    // Test 4: single character match
    runTest("Single character match",
        "a", "a",
        true
    );

    // Test 5: same characters different counts
    runTest("Same characters different counts",
        "aab", "abb",
        false
    );

}
