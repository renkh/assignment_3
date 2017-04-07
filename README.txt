Assignment 3
----------------
All parts of the assignment are complete. Rehash factor R is 43. 
----------------
Bugs:
Part 3: 
The program prints out trailing “,“ at the end for every correction even if it’s the last one in the list. Some words are not in the dictionary, “napster”, the program prints them out without corrections. Some words are abbreviations, “PT”, the program does not recognize abbreviations but provides possible corrections like apt, opt. Words with numbers, “9th”, will have the number removed then spell check “th”. Words with “‘“ like Patel’s, have “’s” removed but then words like “doesn’t” become “doesn”. The only punctuation marks that are removed are: , . : ; [ ] ‘ " - 
----------------
Compilation Instructions
----------------
Open a terminal.
Go to the directory containing the source code.
To compile type:
  make all
----------------
It is assumed that you are using a Linux machine and a g++ compiler.
----------------
To execute:
For Part 1 and 2:
In source code directory type:

./CreateAndTestHash <words file name> <query words file name> <flag> 

<words file name> should be a file containing dictionary words
<flag> should be “quadratic” for quadratic probing, “linear” for linear probing, and “double” for double hashing.

Example: 

./CreateAndTestHash words.txt query_words.txt quadratic


For Part 3:
In source code directory type:

./SpellCheck <document file> <dictionary file> 

<document file> should be the text file you want to spell check
<dictionary file> should be the file containing dictionary words

Example:

./SpellCheck document1.txt wordsEn.txt
---------------
