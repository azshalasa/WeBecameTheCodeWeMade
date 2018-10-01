struct Agenda{
    int cphone;
    char name[10];
};

void menu();
void refreshVar(void *pBuffer, void **op, void **count, void **lp);
void *AddTo(void *pBuffer, void *count);
void *RemoveTo(void *pBuffer, void *count, void *lp, void *op);
void SearchTo(void *pBuffer, void *count, void *lp, void *op);
void PrintAll(void *pBuffer, void *count, void *lp);
// Sorts of Sorts
void Bubble(void *pBuffer, void *count, void *lp, void *op);
void Insertion(void *pBuffer, void *count, void *lp, void *op);
void Selection(void *pBuffer, void *count, void *lp, void *op);
void Random(void *pBuffer, void *count, void *lp, void *op);
