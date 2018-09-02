struct Agenda{
    int cphone;
    char name[10];
};

void menu();
void refreshVar(void *pBuffer, void **op, void **count, void **lp);
void *AddTo(void *pBuffer, int *count);
void PrintAll(void *pBuffer,int *count, int *lp);
