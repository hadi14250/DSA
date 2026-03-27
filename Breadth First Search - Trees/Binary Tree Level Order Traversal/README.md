# Binary Tree Level Order Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow) ![Topic](https://img.shields.io/badge/Topic-BFS-blue) ![Topic](https://img.shields.io/badge/Topic-Trees-blue)

---

## Problem

Given a binary tree `root`, return the level order traversal of it as a nested list, where each sublist contains the values of nodes at a particular level in the tree, from left to right.

---

## Examples

**Example 1:**

![Example 1](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/a4639809-0754-4eda-221f-a4cd58bd9c00/public)

```
Input:  root = [1,2,3,4,5,6,7]
Output: [[1],[2,3],[4,5,6,7]]
```

**Example 2:**
```
Input:  root = [1]
Output: [[1]]
```

**Example 3:**
```
Input:  root = []
Output: []
```

---

## Constraints

- `0 <= The number of nodes in the tree <= 1000`
- `-1000 <= Node.val <= 1000`
