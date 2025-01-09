# brainfuck interpreter 🧠

a blazingly fast brainfuck interpreter written in c, built in 30 minutes because why not? perfect for those moments when you absolutely need to run esoteric code at 3 am.

## about

this is a minimal, efficient brainfuck interpreter that supports all standard brainfuck operations with proper memory management and error handling. built it during a coffee break because regular programming languages were feeling too mainstream.

features:
- full brainfuck instruction set support
- 30,000 memory cells (classic specification)
- robust error handling for unmatched brackets
- zero external dependencies

## quick start

### build & run

1. clone the repository:
```bash
git clone https://github.com/aadithyanr/bf-interpreter.git
cd bf-interpreter
```

2. compile:
```bash
make
```

3. run your brainfuck program:
```bash
./brainfuck yourprogram.bf
```

### example program

included `maga.bf` outputs "MAKE AMERICA GREAT AGAIN" bc why not start with something controversial? xD

```bash
./brainfuck maga.bf
```

## how it works

the interpreter processes eight brainfuck commands:
- `>` move pointer right
- `<` move pointer left
- `+` increment current cell
- `-` decrement current cell
- `.` output current cell
- `,` input to current cell
- `[` start loop
- `]` end loop

## clean up

```bash
make clean
```

## why?

bc sometimes you just need to write a brainfuck interpreter to assert dominance in the coding world. also, it was a fun way to practice memory management in c.

## license

feel free to use this however you want. i wrote it in 30 minutes, it's not exactly the next linux kernel.
