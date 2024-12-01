#include <stdio.h>
#include "../include/file_tree.h"
#include <string.h>

#define MAX_CHILDREN 10
#define ROOT_NAME "/"

// typedef struct Node {
//     char* name;
//     Node** children;

// } Node;

// typedef struct File_tree {
//     Node* root;
// } File_tree;

//set up name for a file node then allocate space for its children
void configure_file(Node* file_node, const char* file_name, int is_dir) {
    file_node->name = strdup(file_name);
    file_node->is_directory = is_dir;
    file_node->child_count = 0;
    file_node->children = (Node**)malloc(sizeof(Node*)*MAX_CHILDREN);
}

//add file to the current directory passed
void add_file(Node* dir_node, Node* new_file) {

    //file has no children!
    if(dir_node->is_directory == 0) {
        printf("provided directory is a file! cannot add to it");
        return;
    }

    //check if the node has the max number of children
    if(dir_node->child_count >= MAX_CHILDREN) {
        printf("Maximum amount of files in this directory (10) reached!");
        return;
    }

    //add the file to the next free spot
    if(dir_node->children[dir_node->child_count] == NULL) {
        dir_node->children[dir_node->child_count] = new_file;
    }

    else {
        printf("Error adding the file");
        return;
    }

    dir_node->child_count++;
}

void list_dir(Node* dir_node) {
    for(int i = 0; dir_node->children[i] != NULL; i++) {
        printf("%s ", dir_node->children[i]->name);
    }
}

//creates the initial tree with the root node
File_tree* create_tree() {
    File_tree* my_fileTree = (File_tree*)malloc(sizeof(File_tree));
    
    if(my_fileTree == NULL) {
        perror("Failed to malloc file tree");
        exit(1);
    }

    my_fileTree->root = (Node*)malloc(sizeof(Node));

    if(my_fileTree->root == NULL) {
        perror("Failed to malloc root node");
        exit(1);
    }

    configure_file(my_fileTree->root, ROOT_NAME, 1);
    return my_fileTree;
}