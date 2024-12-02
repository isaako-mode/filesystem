#include <stdio.h>
#include <string.h>
#include "../include/file_tree.h"


//arg[0] = filepath (not to use here), arg[n...] = real args
int main(int argc, char *argv[]) {
    printf("This is filesyster!\n");
    fflush(stdout);

    File_tree* file_tree = create_tree();
    printf("%s\n", file_tree->root->name);

    while(1) {
        char input_buffer[120];

        //get user input
        fgets(input_buffer, sizeof(input_buffer), stdin);
        // if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
        //     perror("fgets failed or stdin closed");
        //     break;  // Exit the loop if stdin is closed
        // }

        //set ending newline to null terminator
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        printf("\nfile syster recieved input!: %s\n", input_buffer);
        fflush(stdout);
    }

    // Node* my_new_file = (Node*)malloc(sizeof(Node));
    // configure_file(my_new_file, "PORN", 0);
    // add_file(file_tree->root, my_new_file);
    // list_dir(file_tree->root);
    return 0;
}