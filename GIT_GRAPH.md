# Git History Graph - Latcoding Repository

This document visualizes the complete git commit history and branching/merging structure of the `latcoding` repository, covering everything from C programming practice milestones to mini-projects like Tetris and git blob/stash experiments.

## Mermaid Graph

```mermaid
flowchart TD
    %% Styling definitions
    classDef learning fill:#e1f5fe,stroke:#01579b,stroke-width:2px;
    classDef project fill:#fff9c4,stroke:#fbc02d,stroke-width:2px;
    classDef advanced fill:#e8f5e9,stroke:#2e7d32,stroke-width:2px;
    classDef merge fill:#f3e5f5,stroke:#7b1fa2,stroke-width:2px;

    subgraph C_Learning [C Programming Fundamentals & Practice]
        C1["8d673a1: Add rynnn.c & boolean practice"] --> C2["60b2dbb / c28a529: rynnn.c incremental updates"]
        C2 --> C3["f7a06b3: else if & nested if (3-day mastery)"]
        C3 --> C4["dd5a029 / 38ddea8: Bro Code user input & switch statements"]
        C4 --> C5["6ff31c7 - 17f7fba: Math functions & debugging user input"]
        C5 --> C6["3b4d8e2 - f4cba33: String handling & if-else exercises"]
        C6 --> C7["532b507 - 0189116: Weight converter & switch statement mastery"]
        C7 --> C8["6d8b093 - ddd2902: Nested if correction & progress commits"]
        C8 --> C9["b7322da - af844a8: strlen & sub-conscious brain exercises"]
        C9 --> C10["8d1a7fd - 3aedb60: Rebuilds & shopping cart trials"]
        C10 --> C11["d3870e6 - b55eb92: Shopping cart & boolean loop fixes"]
        C11 --> C12["1af1dbf - 59f85d4: Boolean data types & weight conversion program"]
        C12 --> C13["a874c59 - 206108f: Degree converter & re-learning nested if"]
        C13 --> C14["f79b505 - dcf78fb: Simple calculator & Function basics"]
        C14 --> C15["72ce730 - f497e6c: Function scope & function prototypes"]
        C15 --> C16["c046de8 - b5fdf32: While loops & for loops mastery"]
        C16 --> C17["804fc16 - 79621f3: Break/continue statements & random number generator"]
    end

    subgraph Side_Projects [Side Projects & Tetris]
        C17 --> P1["13fc5bd & 0ebb980: Gabut bikin Tetris"]
        P1 --> P2["1de408c: Add project files (README, index.html, .gitignore)"]
        P2 --> P3["a846009 & 6abafec: Tetris project (vibe coded)"]
    end

    subgraph Blobs_Stashes [Blob Practice, Stashing & Detached Head]
        P3 --> B1["f94ef05: Disini sy praktek tentang blob ya"]
        B1 --> B2["4858cbd: Index on detached HEAD"]
        B1 --> B3["d2b23c6: WIP on blob practice"]
        B2 --> M1
        B3 --> M1
        B1 --> F1["fd92085: Push retry attempts after failures"]
        F1 --> M1["1c50def: Merge commit 'refs/stash' into list"]
    end

    subgraph Repo_Cleanup [Recent Cleanup]
        M1 --> CL1["ca22723: 'yo'"]
        CL1 --> CL2["818ff50: chore: delete learn_c and rynnn"]
    end

    %% Class assignments
    class C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13,C14,C15,C16,C17 learning;
    class P1,P2,P3 project;
    class B1,B2,B3,F1 advanced;
    class M1,CL1,CL2 merge;
end
```

## Summary of Phases
1. **C Programming Foundation:** Consistent daily practice building C programs (`rynnn.c`, calculators, weight/degree converters, shopping carts, loops, functions, pointers/strlen, math functions, nested conditionals).
2. **Side Projects:** Fun exploratory coding projects like Tetris ("vibe coded by gabut").
3. **Git Advanced Practice:** Exploring git internals (`blob` objects), detached HEAD states, work-in-progress (WIP) stashes, and merge commits.
4. **Cleanup:** Tidying up unused files and directories.
