/*
This is a simple bag that currently only supports adding.
*/
#include <stdlib.h>

typedef struct ChildBag //TODO rename edge
{
    struct ChildBag* next;
    int value;
} ChildBag;


typedef struct Bag       //TODO rename vertex
{
    struct Bag* next;
    ChildBag* value;
} Bag;


Bag* BagConstructor()       //TODO rename graph constructor
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

//TODO test
int BagIterate(Bag** index, Bag* root)
{
    static Bag* pointer;

    if(root)
        pointer = root;    
    else
        pointer = pointer->next;

    if(!pointer)
        return 0;

    *index = pointer;

    return 1;
}