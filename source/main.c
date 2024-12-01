#include <stdio.h>
#include "../include/file_tree.h"


//arg[0] = filepath (not to use here), arg[n...] = real args
int main(int argc, char *argv) {
    printf("This is filesyster!\n");

    File_tree* file_tree = create_tree();
    printf("%s\n", file_tree->root->name);

    Node* my_new_file = (Node*)malloc(sizeof(Node));
    configure_file(my_new_file, "PORN", 0);
    add_file(file_tree->root, my_new_file);
    list_dir(file_tree->root);
    return 0;
}