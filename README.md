# push_swap

Sort a stack of integers using only a second stack and a **restricted instruction
set** — the goal is the smallest possible number of operations.

**Language:** C (`-Wall -Wextra -Werror`) · **Context:** 42 School — solo

## Operations

`sa` `sb` `ss` · `pa` `pb` · `ra` `rb` `rr` · `rra` `rrb` `rrr`

## Run

```bash
make
./push_swap "4 67 3 87 23"
ARG="5 2 8 1 9 3"; ./push_swap $ARG | wc -l          # count moves
ARG="…"; ./push_swap $ARG | ./checker_linux $ARG      # verify (OK / KO)
```

## Algorithm

- **Small inputs (≤ 5)** are handled by hand-written optimal sequences.
- **Larger inputs** use a **cost-driven greedy** approach:
  1. numbers are replaced by their rank (index), so the values themselves stop mattering;
  2. everything is pushed to stack B;
  3. for each element of B, the code computes the *cost* of bringing it to the
     right place in A — counted as rotations on each side, using the combined
     `rr` / `rrr` moves whenever both stacks rotate the same way;
  4. the cheapest element is moved, and the step repeats until B is empty;
  5. a final rotation puts the smallest element of A on top.

## Target

The project's top grading band: **< 700 moves for 100 numbers**, **< 5500 for 500**.

## Notes

- Input parsing rejects non-integers, overflow, and duplicates before any work starts.
- All allocations are freed on every error path.
