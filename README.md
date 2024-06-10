# Pipex

## Overview

The `pipex` project simulates the behavior of a shell pipeline. It introduces UNIX I/O mechanisms like pipes and file redirections in C programming. The project aims to replicate the behavior of chaining commands with pipes using the command `./pipex file1 cmd1 cmd2 file2`.

## Objectives

- To learn about UNIX processes and interprocess communication.
- To implement an understanding of pipe, fork, dup, and execve system calls.
- To handle errors and manage input/output effectively.

## Build Instructions

Use the provided Makefile to compile the project:
```bash
make all
```

## Usage
pipex should be executed as follows:

```bash
./pipex file1 cmd1 cmd2 file2
```

This behaves similarly to the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

### Example
To mimic the command :
```bash
line ls -l | wc -l > outfile
```
prompt :
```bash
./pipex infile "ls -l" "wc -l" outfile
```

## Requirements

- Error Handling: The program must handle errors thoroughly, similar to how shell commands are handled.
- Memory Leaks: Ensure there are no memory leaks in the program.
- Commands Execution: The program must be able to execute the commands properly using the arguments.

## Features

Execute two commands with their arguments, redirecting input and output correctly.
Implement the functionality using UNIX system calls like pipe, fork, dup, dup2, and execve.

## Contributors

- @iamgrg

## License

![MIT License](https://img.shields.io/badge/license-MIT-green)
Distributed under the MIT License.
