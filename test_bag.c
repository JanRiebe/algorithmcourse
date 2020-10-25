#include <stdio.h>
#include "bag.h"

int main()
{
    printf("\n\nTesting bag data structure\n\n");

    Bag root;
    root.next = NULL;
    root.value = NULL;

    printf("Adding an entry at position 15 with value 42.\n");
    BagAdd(&root, 15, 42);    
    
    printf("Adding an entry at position 15 with value 42.\n");
    BagAdd(&root, 15, 42);
    
    printf("Adding an entry at position 15 with value 42.\n");
    BagAdd(&root, 15, 15);

    printf("Adding an entry at position 10 with value 15.\n");
    BagAdd(&root, 10, 15);


    printf("Adding an entry at position -10 with value -10.\n");
    BagAdd(&root, -10, -10);

    printf("Printing number of bags.\n");
    Bag* iter = &root;
    int i = 0;
    while (iter->next)
    {
        printf("%i", i++);
        ChildBag* childIter = iter->next->value;
        while (childIter)
        {
            printf(" - %i", childIter->value);
            childIter = childIter->next;
        }
        
        printf("\n");
        iter = iter->next;
    }


    return 0;
}