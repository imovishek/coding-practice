# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## About This Repository

Personal competitive programming practice repository with solutions organized by online judge/platform.

## Build & Run

Compile a single solution:
```bash
g++ -std=c++17 -O2 -o solution "path/to/problem.cpp"
./solution < input.txt
```

For problems using GNU Policy-Based Data Structures (e.g. `Implementation/Policy Based DS.cpp`):
```bash
g++ -std=c++17 -O2 -o solution solution.cpp
```
No extra flags needed — `<ext/pb_ds/*>` headers are part of GCC's standard library.

## Repository Structure

Solutions are grouped by online judge:
- `USACO/` — USA Computing Olympiad problems
- `Light OJ/` — LightOJ problems (also tracked in `LOJ IDs.txt`)
- `UVa_Online_Judge_Problem_Solutions/` — UVa judge
- `Hackerrank/`, `Codechef/`, `SPOJ/`, `Toph/`, `Timus/`, `TopCoder/`, `csacademy/`, `uvaLive/`, `Project Euler/` — other judges
- `Implementation/` — reusable algorithm templates (segment trees, FFT, suffix arrays, geometry, graph algorithms, etc.)
- `Geo/` — geometry implementations
- `AI/` — AI-generated code

## Templates

- `main.cpp` — primary template with common macros (`pii`, `mkp`, `pb`, `FOR`, `MX`, `mem`, etc.)
- `G++ precode.cpp` — minimal template with geometry/math constants (`EPS`, `pi`)
- `Policy Based DS.cpp` — example of GNU PBDS order-statistics tree (`find_by_order`, `order_of_key`)

## Study Plan

`Plan so far.cpp` lists the algorithms/topics targeted for practice (DP, DSU on tree, HLD, Max flow, KMP, segment trees, geometry, FFT, etc.).
