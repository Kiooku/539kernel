#ifndef INC_539KERNEL_PAGIN_H
#define INC_539KERNEL_PAGIN_H

#define PDE_NUM 3
#define PTE_NUM 1024

extern void load_page_directory();
extern void enable_paging();

void paging_init();
int create_page_entry(int, char, char, char, char, char, char, char, char);

#endif //INC_539KERNEL_PAGIN_H