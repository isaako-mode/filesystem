#ifndef FILE_TREE_H
#define FILE_TREE_H

#include <stdlib.h>

// Node structure represents files and directories in the file system
typedef struct Node {
    char* name;           // Name of the file or directory
    struct Node** children; // Array of pointers to child nodes
    int is_directory;     // 1 if directory, 0 if file
    int child_count;      // Number of children
    // int capacity;         // Capacity of the children array
} Node;

// File tree structure represents the entire file system
typedef struct File_tree {
    Node* root;           // Root node of the file tree
} File_tree;

/**
 * Configure a file or directory node with a name and type.
 * 
 * @param file_node Pointer to the node to configure
 * @param file_name Name of the file or directory
 * @param is_directory 1 if the node is a directory, 0 if it is a file
 */
void configure_file(Node* file_node, const char* file_name, int is_dir);

/**
 * Create a new file tree with a root node.
 * 
 * @return Pointer to the newly created file tree
 */
File_tree* create_tree();

void add_file(Node* dir_node, Node* new_file);
void list_dir(Node* dir_node);




#endif // FILE_TREE_H
