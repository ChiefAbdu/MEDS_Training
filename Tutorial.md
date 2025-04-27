# Bash Scripting Tutorial

Welcome to the **Bash Scripting Tutorial**! This guide will walk you through the basics of bash scripting with some simple examples.

---

## Table of Contents

- [Introduction](#introduction)
- [Setting Up](#setting-up)
- [Hello World](#hello-world)
- [Variables](#variables)
- [Conditionals](#conditionals)
- [Loops](#loops)
- [Functions](#functions)
- [Best Practices](#best-practices)
- [Resources](#resources)

---

## Introduction

**Bash** (Bourne Again SHell) is a command processor that can run in the terminal or any (.sh) file . A bash script is a file containing a series of commands.

**Why learn Bash?**

- Automate tasks(For Example: writing a code which automatically compiles any C File in a given directory)
- Manage system operations
- Efficient text processing

---

## Setting Up

1. Create a file with `.sh` extension:

```bash
nano file_name.sh
```
or

```bash
vim file_name.sh
```
whichever suits your style, vim provides better navigation and text editing than nano. The `file_name` could be any name preferably a name which defines what the file actually does to avoid having to open the file just to check what is going on.


2. Make the script executable:

```bash
chmod +x myscript.sh
```
You can check if your file is executable or not by running `la` in your directory, If it says ` drwxr-xr-x  ` it means your file is executable. The ` -x ` defines if the file is executable.

3. Run the script:

```bash
./myscript.sh
```
if it doesnt work check if your file is executable or not . 


---

## Simple Text

Let's start with the classic first script:

```bash
#!/bin/bash

echo "Hello, World!"
```

> `#!/bin/bash` tells the system to use the bash interpreter to run the code, without this the file system would be unaware for which interpreter to use.

---

## Variables

```bash
#!/bin/bash

name="Abdu"
echo "Hello, $name!"
```

- Variables do not need a `$` when being assigned.
- Use `$` to access the variable assigned.

**Reading user input:**

```bash
#!/bin/bash

echo "Enter your name: "
read user_name
echo "Hello, $user_name!"
```
Takes an input from the user (in this case YOU!) and then displays the text.

---

## Conditionals

### If Statement

Think of the syntax as basic grammar, ` if ` this happens ` then ` this would happen and the ` fi ` at the end is just ` if ` backwards acting like curly brackets where `if` is ` { ` and `fi` is ` } `.

```bash
#!/bin/bash

num=10

if [ $num -gt 5 ]; then
    echo "$num is greater than 5"
fi
```

### If-Else

```bash
#!/bin/bash

read -p "Enter a number: " number

if [ $number -gt 0 ]; then
    echo "Positive number"
else
    echo "Zero or Negative number"
fi
```

**Important Operators:**

- `-eq` Equal
- `-ne` Not Equal
- `-gt` Greater Than
- `-lt` Less Than
- `-ge` Greater or Equal
- `-le` Less or Equal

---

## Loops

### For Loop

To simply put a `for` loop in simple terms you can imagine it as `for` this number just `do` this and then its `done` .
```bash
#!/bin/bash

for i in 1 2 3 4 5
  do
    echo "Looping ... number $i"
  done
```

### While Loop

And the same logic follows for the `while` loop since theyre both essentially a loop with different usages.

```bash
#!/bin/bash

count=1

while [ $count -le 5 ]
do
  echo "Count: $count"
  ((count++))
done
```

---

## Functions

The syntax of the functions is similar to the syntax in C, The first word after `function` is the `name` of the function. The code within the `{ }` are lines that the function uses/runs.

```bash
#!/bin/bash

function greet() {
  echo "Hello, $1!"
}

greet "Abdu"
greet "Umair"
```

- `$1` refers to the first argument passed to the function.

**Return Values:**

```bash
#!/bin/bash

function add() {
  sum=$(( $1 + $2 ))
  echo $sum
}

result=$(add 5 7)
echo "Sum is: $result"
```

---

## Best Practices

- Always start scripts with `#!/bin/bash`
- Use meaningful variable names(Which are easy to understand and make sense)
- Add comments for clarity(To explain your thought process or what a specific line of code does)
- Quote your variables `"$var"`
- Use `set -e` to exit on errors

Example:

```bash
#!/bin/bash
set -e

# This script does important stuff
```

---

## Resources

- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Bash Scripting Cheatsheet](https://devhints.io/bash)
- [ShellCheck](https://www.shellcheck.net/)

---

