#ifndef DDLIST_H
#define DDLIST_H
#include <stddef.h>

struct DLList
{
    struct Node
    {
        int data;     
        Node* next;   
        Node* prev;   
    };

    Node* first = NULL;    
    Node* last = NULL;     
    Node* current = NULL;     
    int count;        

    void out();
    void info();
    void clear();

    bool moveNext();
    bool movePrev();
    bool moveFirst();
    bool moveLast();

    bool init(int);
    bool addNext(int);
    bool addPrev(int);
    bool addFirst(int);
    bool addLast(int);

    bool del(int &);
    bool delNext(int &);
    bool delPrev(int &);
    bool delFirst(int &);
    bool delLast(int &);
};
#endif