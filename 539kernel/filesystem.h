#ifndef INC_539KERNEL_FILESYSTEM_H
#define INC_539KERNEL_FILESYSTEM_H

#define BASE_BLOCK_ADDRESS 100
#define FILENAME_LENGTH 256

typedef struct {
    int head, tail;
} base_block_t;

typedef struct {
    char filename[FILENAME_LENGTH];
    int next_file_address;
} metadata_t;

void filesystem_init();
void create_file(char *, char *);
char **list_files();
char *read_file(char *);

// Auxiliary functions
metadata_t *load_metadata(int);
int get_address_by_filename(char *);
int get_prev_file_address(int);
int get_files_number();

#endif //INC_539KERNEL_FILESYSTEM_H
