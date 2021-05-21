#ifndef DDLIST_H
#define DDLIST_H
#include <stddef.h>
#include <string>

struct Bunny
{
  std::string name;
  int age;
  double weight;
  bool isHungry;
};

struct DLList
{
    struct Node
    {
        Bunny data;     
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

    bool init(Bunny);
    bool addNext(Bunny);
    bool addPrev(Bunny);
    bool addFirst(Bunny);
    bool addLast(Bunny);

    bool del(Bunny &);
    bool delNext(Bunny &);
    bool delPrev(Bunny &);
    bool delFirst(Bunny &);
    bool delLast(Bunny &);
};
#endif