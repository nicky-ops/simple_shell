# C - Simple Shell
##### In this project we wrote a simple UNIX command interpreter
* A shell is a computer program that exposes the operating system's services to a user or to other programs.
* It is referred to as a shell since it is the outermost layer around the operating system.
* To use a Command line shell, you need to be familiar with commands and their calling sysntax, and know the specific shell scripting language i.e *bash*.
* A CLI uses alphanumeric characters typed on the keyboard to provide instructions and data to the OS interactively.
* A *read-eval-print loop (REPL)* is a simple interactive environment in computer programming that takes user inputs, executes them and then presents the result to the user.
## PID & PPID
A process has a unique ID referred to as a *process ID* that is used to interact with and manipulate process. The current Process ID can be retrived using the system call <getpid>.
* Every time a program is run, a new process is created hence a new PID for each instance of a program.
* Every process has a parent that is a process that created it. YOu can get the PID of the parent by using the getppid system call from the child process.
* The PID of the parent process is the same for every instance of the same program run within the same shell.

## Executing a Program
*execve* is a system call that allows a process to execute another program. It loads the new program into the current process' memory in place of the previous program.
### The simple shell should
1. Read input from the user i.e using fgets(). If the command line arguments have been specified, then the shell treats the first argument as the name of a file from which to read commands.
2. Parse input to seperate the command/script and its arguments using strtok().
3. Fork child process to execute a command using fork() to create a child process.
4. Execute the command in the child process using execvp(). This function takes the command and its arguments as its arguments.
5. Wait for the child process to complete using the wait() or waitpid() function.
