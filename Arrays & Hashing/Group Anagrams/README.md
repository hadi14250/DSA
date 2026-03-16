# Group Anagrams

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow) ![Topic](https://img.shields.io/badge/Topic-Hash%20Map-blue) ![Topic](https://img.shields.io/badge/Topic-String-blue) ![Topic](https://img.shields.io/badge/Topic-Sorting-blue)

---

## Problem

Given an array of strings `strs`, group the anagrams together. You can return the answer in **any order**.

---

## Examples

**Example 1:**
```
Input:  strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```
- `"bat"` has no anagram partner in the array.
- `"nat"` and `"tan"` are anagrams of each other.
- `"ate"`, `"eat"`, and `"tea"` are all anagrams of each other.

**Example 2:**
```
Input:  strs = [""]
Output: [[""]]
```

**Example 3:**
```
Input:  strs = ["a"]
Output: [["a"]]
```

---

## Constraints

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters only.