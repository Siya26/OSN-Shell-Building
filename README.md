<!-- file is written in markdown format -->
```
OS: Linux
```

* It is assumed that valid inputs are given. 
* Pressing only ENTER leads to an infinite loop.
* exit command exits the terminal.

Compile the code as follows:
```
make 
./main
```
* The driver code for the shell is written in main.c
* global.h contains all the function declarations and global arrays.
* header.h contains all the headers.

* If the directory doesn't exist then it is prints an error.

* input/output redurection is handled in io.c
* piping of commands is handles in pip.c

## Specification 1
* Handled in io.c
* The commands for specification 1 can be executed as follows:

```
cat < <file_name>
echo "text" > <file_name>
```
* All the cases of '<', '>', '>>' are handled.

## Specification 2
* Handled in pip.c
* The commands for specification 2 can be executed as follows:

```
cat <file_name> | wc
cat <file_name> | head -7 | tail -5
```

* The commands for specification 3 can be executed as follows:

```
cat < <file_name> | wc -l > lines.txt
```
## Specification 4
* Handled in job.c
* The commands for specification 4 can be executed as follows:

```
jobs
jobs -r
jobs -s
sig <job_number> <signal_number>
fg <job_number>
bg <job_number>
```
* jobs : prints a list of all currently running background processes in alphabetical order. jobs -r prints running process and jobs -s prints stopped processes.

* sig : takes the job number of a running job and sends the signal corresponding to the signal number to that process. 

* fg : brings the running or stopped background job corresponding to job number to the foreground and changes its state to running.

* bg : changes the state of a stopped background job to running.

## Specification 5
* Handled in main.c
* It handles ctrl + d, ctrl + c and ctrl + z.
* CTRL-Z : it pushes any currently running foreground job into the background, and changes its state from ‘running’ to ‘stopped.’ This doesn't have any effect on the shell if there is no foreground process running.

* CTRL-C : it interrupts any currently running foreground job, by sending it the SIGINT signal. This doesn't have any effect on the shell if there is no foreground process running.

* CTRL-D : it should logs out of ths shell, without having any effect on the actual terminal.

#### Output is printed on console and to the respective files.

*Thanks!*