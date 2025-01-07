# Pipex Project

This project aims to mimic the functionality of shell pipes in C. It handles command execution and pipes similar to the shell command `< file1 cmd1 | cmd2 > file2`.

## Description

The program `pipex` takes 4 arguments:
- file1: Input file
- cmd1: First command to execute
- cmd2: Second command to execute
- file2: Output file

It behaves exactly the same as the shell command: `< file1 cmd1 | cmd2 > file2`

## Implementation

The project uses the following system calls and functions:
- `pipe`: Creates a pipe for communication between processes
- `fork`: Creates child processes
- `execve`: Executes commands
- `dup2`: Redirects file descriptors
- `access`: Checks file permissions
- `open`: Opens files
- `unlink`: Removes files
- `exit`: Exits processes
- `malloc/free`: Memory management
- `wait`: Waits for child processes

## Usage

1. Clone the repository
2. Compile with `make`
3. Run the program:
```bash
./pipex infile "cmd1" "cmd2" outfile
```

### Examples:
```bash
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile

./pipex infile "grep hello" "wc -w" outfile
# Equivalent to: < infile grep hello | wc -w > outfile
```

## Project Structure

```
.
├── Makefile
├── includes/
│   └── pipex.h
├── src/
│   ├── pipex.c
│   └── pipex_utils.c
└── README.md
```

## Error Handling

The program handles various error cases:
- Invalid number of arguments
- File permissions
- Command not found
- Pipe creation failure
- Fork failure
- Memory allocation failure

## Memory Management

All allocated memory is properly freed to prevent memory leaks:
- Command arguments
- Path strings
- Process cleanup

## Additional Notes

- Handles both relative and absolute paths for commands
- Supports command arguments with spaces
- Proper error messages for debugging
- Clean exit with appropriate status codes
