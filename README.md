# Huffman Coding Project

### Introductory note
This project was the final exam of the Data Structure discipline, taught by Professor Márcio Ribeiro, of the Computer Engineering course at the Federal University of Alagoas (Brazil) in 2018.

The aim was to make good use of learned data structures. Our group used the **C language** for the program, Huffman **tree depth test**, unit test cases for all data structs with **CUnit**, **plot in R** and a **seminar** about Btree.

### The Huffman Algorithm to compress files
The algorithm consists of compressing a file by mapping the repetition of bytes. For easy understanding, think that if "11111111" is the group of bytes with the highest file repetition, "renaming it" would compress the file.

`AAAAAAAAAAAAABBBBBBCCCDD`

> *The size of this sequencial txt file is 24 bytes and 14 bytes after compression.*

For this, the algorithm uses **heap** to sort, **hashtable** to calculate repetitions and a **binary tree** for map them.
