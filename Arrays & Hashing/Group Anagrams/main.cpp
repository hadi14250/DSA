#include "groupAnagrams.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortResult(vector<vector<string>>& result) {
    for (auto& group : result) sort(group.begin(), group.end());
    sort(result.begin(), result.end());
}

void runTest(string testName, vector<string> input, vector<vector<string>> expected) {
    Solution sol;
    auto result = sol.groupAnagrams(input);
    sortResult(result);
    sortResult(expected);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Mixed anagrams",
        {"eat","tea","tan","ate","nat","bat"},
        {{"bat"}, {"nat","tan"}, {"ate","eat","tea"}}
    );

    // Test 2: empty string
    runTest("Single empty string",
        {""},
        {{""}}
    );

    // Test 3: single character
    runTest("Single character",
        {"a"},
        {{"a"}}
    );

    // Test 4: all same anagram
    runTest("All same anagram",
        {"abc","bca","cab"},
        {{"abc","bca","cab"}}
    );

    // Test 5: no anagrams
    runTest("No anagrams",
        {"abc","def","ghi"},
        {{"abc"},{"def"},{"ghi"}}
    );

}