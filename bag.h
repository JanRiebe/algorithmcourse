/*
This is a simple bag that currently only supports adding.
*/
#include <stdlib.h>
#include <stdio.h>//TODO remove
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

int BagGetChildren(Bag* bagRoot, int index)
{
    //TODO implement
}

int BagGetChild(Bag* bagRoot, int index, int childIntex)
{
    //TODO implement
}