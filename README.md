## About

Pipex is a 42 school project aimed to better understand shell redirection, processes and pipes, by handling them in C.

## Build

Clone the repository:
```shell
git clone https://github.com/Daniela-Padilha/42_pipex.git
```
Enter the cloned directory
```shell
cd 42_pipex
```
Run `make` to compile the program without bonus:
```shell
make
```
With bonus:
```shell
make bonus
```

## Usage

Without bonus the input:
```shell
./pipex file1 cmd1 cmd2 file2
```
Behaves like:
```shell
< file1 cmd1 | cmd2 > file2
```
With the bonus the input:
```shell
./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Behaves like:
```shell
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
And the input:
```shell
./pipex here_doc LIMITER cmd cmd1 file
```
Behaves like:
```shell
cmd << LIMITER | cmd1 >> file
```

## Sources

* [Creating and Killing Child Processes in C](https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/)
* [Pipe: an Inter-Process Communication Method](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/)
* [A Comprehensive Guide to Pipex](https://reactive.so/post/42-a-comprehensive-guide-to-pipex/)

## The Norm

This project is written in accordance to the 42 School's "The Norm" (_Version 4_). To review the Norm, [click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).
