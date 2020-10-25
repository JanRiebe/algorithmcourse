/*
This is a simple bag that currently only supports adding.
*/
#include <stdlib.h>

typedef struct ChildBag
{
    struct ChildBag* next;
    int value;
} ChildBag;


typedef struct Bag
{
    struct Bag* next;
    ChildBag* value;
} Bag;


Bag* BagConstructor()
{
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->next = NULL;
    newBag->value = NULL;
}


int BagAdd(Bag* bagStart, int index, int value)
{
    if(!bagStart)
        return 0;

    Bag* iter = bagStart;
    for(int i=0;i<index;i++)
    {
        if(!iter->next)
        {
            iter->next = (Bag*)malloc(sizeof(Bag));
            iter->next->next = NULL;
        }
        iter=iter->next;
    }
    ChildBag* oldValue = iter->value;
    iter->value = (ChildBag*)malloc(sizeof(ChildBag));
    iter->value->next = oldValue;
    iter->value->value = value;    

    return 1;
}

ChildBag* BagGetChildren(Bag* bagRoot, int index)
{
    //TODO implement
}

ChildBag* BagGetChild(Bag* bagRoot, int index, int childIntex)
{
    //TODO implement
}