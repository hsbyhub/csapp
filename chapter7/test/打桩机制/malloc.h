#define malloc(size) mymalloc(size)
#define free(size) myfree(size)

void *mymalloc(unsigned size);
void myfree(void *ptr);

