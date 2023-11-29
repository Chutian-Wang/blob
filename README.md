# blob

> CS32 fall project #2
> <https://github.com/ucsb-cs32/f23>

## GitHub Rules

- Do not push to the master branch directly. Always create a PR.
- Code review comments must be meaningful.
- Commit messages must be meaningful.
- Always format your code before submitting for review.
- C++ files with main() functions should go directly inside src.
- All other C++ files (including headers) should go inside src/lib.
- Make an announcement to all group members before you edit the Makefile
- Always update README.md (including the file/class trees) for documentation.

## Build and Run Instructions

> You will need all the packages installed first if you are on MacOS, refer to [Libraries](#libraries) section.

For MacOS

- run `make -SYS=mac` to build
- run `make mac-run` to run

For CSIL computers

- run `make -SYS=csil` to build
- run `make csil-run` to run

## Debugging

- GDB/LLDB
- If you are on MacOS, there is a subsitute for Valgrind:
use `leaks --atExit -- <command and args>`. For example,
`leaks --atExit -- ./build/parse < test.txt` will print any
memory leaks that have occured along with other information.
Unfortunately, it sometimes does not provide you with any
information regarding the source of the leaks, e.g. when your
code segfaults. `leaks` comes with OSX after 2020.

## File Structure

```
TBD
```

## Class Structure and Special Macros

```
TBD
```

## Code Format

We will use the google format conventions for our projects.
To automate the formatting process, you can use clang-format.
clang-format can be installed with most package managing
programs such as apt-get or brew if you are on MacOS.
> <https://clang.llvm.org/docs/ClangFormat.html>
> Example Usage: `clang-format -i -style=google ./src/*.cpp ./src/lib/*.cpp ./src/lib/*.h`

We will use the following variable naming conventions.

- Functions: camel_case_func()
- Class/Struct/Types: ExampleClass
- Macros: EXAMPLE_MACRO
- ScryptError class naming please refer to error handling section.

## Libraries

We will be using the GLUT tool chain which is installed on csil. To make it easier to debug locally and create an environment as close as that of the csil computers, we will be using the `freeglut` and `xquartz` packeges on MacOS local dev environment. If you have homebrew, run `brew install freeglut xquartz` to install freeglut and xquartz.

If you do not have homebrew, you can go to <https://brew.sh> and download this package management tool. You will need to modify the Makefile if you choose to use another package management tool that puts libraries in different places.

## Error Handling

TBD

## General Workflow

We work in two threads usually. Both threads fetch from the
master branch for the last checkpoint. Thread A works on the
files and make some commits. When thread A is satisfied with
their work, they submit a PR to be reviewed by thread B. Thread
B will pull from thread A's branch and review the code to make
constructive comments. Thread A will then review thread B's
comments and make changes accordingly and make new commits.
**When both threads are satisfied, thread B will merge the PR.**

## Team Information

|   Name        |   Email                   |
|---------------|---------------------------|
|Barry Wang     |<chutian_wang@ucsb.edu>      |
|Chloe Ta       |<cqta@ucsb.edu>              |
|Evania Cheng   |<evania@umail.ucsb.edu>      |
|Jennie Wu      |<Jingyi_wu@umail.ucsb.edu>   |

## Class Links

- GitHub for the syllabus, the schedule, and the assignments:
    <https://github.com/ucsb-cs32/f23>
- Piazza for class announcements and Q&A:
    <https://piazza.com/ucsb/fall2023/cs32>
- Gradescope for turning in your assignments:
    <https://www.gradescope.com/courses/640286>

## References

- OpenGL official documentation:
    <https://www.khronos.org/opengl>
- C++ Reference The simple, user-friendly version:
    <https://cplusplus.com/reference/>
- C++ Reference The more detailed but less friendly version:
    <https://en.cppreference.com/w/>
- Bash Cheatsheet For finding your way around the console:
    <https://xavierholt.github.io/cheatsheets/bash.html>
- Git Cheatsheet For most common Git commands:
    <https://xavierholt.github.io/cheatsheets/git.html>
- GDB Cheatsheet For when you’re debugging:
    <https://xavierholt.github.io/cheatsheets/gdb.html>
- Makefile Tutorial To save you a lot of typing:
    <https://makefiletutorial.com/>
