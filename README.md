<p align="center">
  <img alt="TABLER's tree icon" src="https://raw.githubusercontent.com/tabler/tabler-icons/6cd6f4df5501db67b221ba1595f7f31545041bc4/icons/filled/binary-tree.svg" height="120">
  <h3 align="center">AVL Tree</h3>
  <p align="center">Implementation of AVL tree in C language</p>
</p>

## About
The project consists of a simple demonstration of the use of an AVL tree that accepts (by the user) two operations: ADD and REMOVE

In addition to the demonstration part of the program, the project code has an entire TAD implemented for future uses of this same AVL tree as a functional library, in addition to adding and removing.

## Usage (./myavl)

### Compiling

```bash
make;
./myavl;

# Usage example (input and output)
./myavl < input.in > output.ou;

# Clean archives
make clean;
```

### UUsing the program
* The program accepts two types of input
* The program consists of input lines (insert or remove) for its AVL, which at the end of the program prints an AVL tree in pre-order with the levels

* Insert number: `i 10`
* Remove number: `r 10`
  * If the number does not exist, just ignore the request

* To stop the program and print the tree, just reach an EOF or set an incompatible "mode" (different from I or R)

* Example:
    ```plaintext
    i 3
    i 4
    r 2
    ```

### Output

* At the end, it prints an AVL tree in the form `number, level`
* Root being the number 0

    ```plaintext
    10, 1
    15, 0
    20, 1 
    ```

## Arquivos

* `avl.h`: signatures of the AVL ADT functions, in addition to the node struct used throughout the tree.
* `avl.c`: implementation of the AVL manipulation functions, in addition to indirect functions that assist this process.
* `main.c`: the program itself, in addition to having main( )

## Funcionalidades

## Features

### Indirect functions (cannot be called)

* `Node* __create_node(int v, Node* father)` - a function that creates a new node (dynamically allocated) with a certain defined parent
* `int __balance_value(Node* n)` - finds the balance value of a node, being 2 for unbalanced on the right and -2 for unbalanced on the left.
* `Node* __adjustment_avl(Node *n)` - just checks if it needs balancing and adjusts the tree according to the AVL (used when inserting and deleting)
  
### TAD AVL functions

* `Node* create_avl(int v)` - creates the avl tree and returns its pointer dynamically - useful for the first element
* `Node* insert_avl(int v, Node **root)` - inserts an element into a previously created avl tree and balances the AVL
* `Node* rotate_tree_avl_left(Node *n)` - rotates the tree to the left
* `Node* rotate_tree_avl_right(Node *n)` - rotates the tree to the right
* `void view_avl(Node *n)` - prints the avl in the form "number, level" in a pre-order (ordered)
* `Node* search_avl(int v, Node *root)` - searches for an element and returns its node if found (returns the first number found)
* `size_t height_avl(Node *n)` - returns the size of the current tree
* `Node* delete_avl(int v, Node *root)` - deletes a defined number, if it doesn't have the number, it just does nothing. If found, delete the number and balance the tree
* `void destroy_avl(Node *root)` - destroys the avl at the end, deallocating all allocated memory.

<br />

<p align="center">Created with 💙 by <a href="https://github.com/tuildes">tuildes</a></p>
