Sophia Fondell
CS 410: Assignment 0 - README

Programs to copy object files and access their symbols and sections using statically and dynamically linked libraries

FOR ALL TASKS, I USED THE EXECUTABLE FILE objsym AS MY FILENAME ARG FOR
TESTING ALL PROGRAMS (which is why it's not included in make clean, but it
certainly could be if one had another executable or object file, I just
chose to use this one for whatever reason ¯\_(ツ)_/¯ )

Task A:

-Compilation:
To compile getsyms.c and getsections.c to executable files along with all
required object files and libraries type: make taska

To clean the directory and recompile, type: make clean

-Running Task A:
Once all required files and libraries have been compiled, run getsyms.c and
getsections.c in the following manner:

./getsyms filename
./getsections filename 

Each takes one command line argument which is the name of the file to print
out symbols for or sections for respectively.

Task B:

-Compilation:
To compile getsyms_dl.c and getsections_dl.c to executable files along with
all required object files and libraries type: make taskb

To clean the directory and recompile, type: make clean

-Running Task B:
Once all required files and libraries have been compiled, run getsyms_dl.c
and getsections_dl.c in the following manner:

./getsyms_dl filename RTLD_LAZY|RTLD_NOW
./getsections_dl filename RTLD_LAZY|RTLD_NOW

Each takes two command line arguments: the first which are the name of the file to
print out symbols for or sections for respectively and the second of which
is either the flag RTLD_LAZY (load symbols as they're needed) or RTLD_NOW
(load symbols at the time of dynamic library linking).

*Additionally: On line 136 of both programs, there's a call to a function
 calc_stats() to print out how long it takes to link the library 50 times,
 uncomment to see the results of the micro benchmark and comment to not
 call the function. 

The stats file was created on ssh sfondell@csa2.bu.edu using the executable
file objsym (which is not included in make clean as I used it for testing
all tasks)

**The following line should be pasted and ran in the terminal so that the
  program is able to locate the shared library during compilation:

export LD_LIBRARY_PATH=/home/ugrad/sfondell/cs410/a0:$LD_LIBRARY_PATH

Task C:

I decided to include objcopy.o in libobjdata.a as I thought it would be
easier and thus, the makefile and the executable where the library function
is tested, copysection.c -> copysection, use the static library as such.

-Compilation:
To compile copysection.c to an executable file along with all required
object files and libraries type: make taskc

-Running Task C:
I decided to test the library function implemented in objcopy.c in a simple
file copysection.c. Once all required files and libraries have been
compiled, copysection.c can be ran in the following manner:

./copysection filename

The executable takes one commandline argument, which is a filename that it
then passes into the library function being tested. The executable itself
finds the .text section of the filename argument and outputs it into a file
text-output which should appear in the current working directory after
execution. One can see the contents of the file as an octal dump by typing:

cat text-output | od
