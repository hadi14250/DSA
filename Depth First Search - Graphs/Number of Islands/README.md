# Number of Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow) ![Topic](https://img.shields.io/badge/Topic-DFS-blue) ![Topic](https://img.shields.io/badge/Topic-Graphs-blue)

---

## Problem

Given a 2D grid `grid` where `'1'` represents land and `'0'` represents water, count and return the number of islands.

An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid (i.e., all the edges are water).

---

## Examples

**Example 1:**
```
Input: grid = [
  ["0","1","1","1","0"],
  ["0","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**
```
Input: grid = [
  ["1","1","0","0","1"],
  ["1","1","0","0","1"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 4
```

---

## Constraints

- `1 <= grid.length, grid[i].length <= 100`
- `grid[i][j]` is `'0'` or `'1'`.
