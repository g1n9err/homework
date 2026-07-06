# C Homework

A collection of C programming exercises, organized by topic.

## Structure

| Folder       | Topic              |
|--------------|--------------------|
| `conditions` | if / else, switch  |
| `loops`      | for, while, do/while |
| `arrays`     | arrays and strings |
| `dyn_mem`    | malloc, free, pointers |
| `matrix`     | 2D arrays and matrix ops |
| `signals`    | signal handlers (SIGINT, etc.) |

Each exercise is a standalone `.c` file (or a small folder for multi-file tasks).

## Build & Run

Most exercises compile with GCC:

```bash
gcc ex1.c -o ex1 && ./ex1
```

### Multi-file exercises

**`dyn_mem/ex1-4/`**

```bash
cd dyn_mem/ex1-4
gcc main.c implement.c -o ex && ./ex
```

**`dyn_mem/ex_9/`**

```bash
cd dyn_mem/ex_9
gcc main.c stud_implement.c -o ex && ./ex
```

**`matrix/ex9/`** (shared library + `dlopen`)

```bash
cd matrix/ex9
gcc -fPIC -shared matrix.c -o libmatrix.so
gcc main.c -ldl -o ex && ./ex
```

## Requirements

- GCC
- Linux (for `signals/` and `matrix/ex9` dynamic loading)
