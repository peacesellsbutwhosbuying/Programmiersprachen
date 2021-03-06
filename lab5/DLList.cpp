#include<iostream>
#include"DLList.h"

using std::cout;
using std::endl;

bool DLList::moveNext()
{
    if(first ==  NULL)       return false;
    if(current == NULL)
    {
      current=first;
      return true;
    }
    if(current->next == NULL) return false;
    current = current->next;
    return true;
}

bool DLList::movePrev()
{
    if(first == NULL)       return false;
    if(current == NULL) 
    {
      current=first; 
      return true;
    }
    if(current->prev == NULL) return false;
    current = current->prev;
    return true;
}
bool DLList::moveFirst()
{
    if(first == NULL) return false;
    current = first;
    return true;
}

bool DLList::moveLast()
{
    if(last == NULL) return false;
    current = last;
    return true;
}

bool DLList::init(Bunny data)
{
   if(first == NULL)
   {
        first = new Node;
        last = first;
        current = first;
        first->prev = NULL;
        first->next = NULL;
        first->data = data;
        count = 1;
        return true;
   }
   else
        return false;
}

bool DLList::addNext(Bunny data)
{
	if(first == NULL) return init(data);

	Node* temp = current->next;
	current->next = new Node;
	current->next->next = temp;
	current->next->prev = current;

	if(temp == NULL)
        last = current->next;
	else
        temp->prev = current->next;

    current = current->next;
    current->data = data;
    count++;
    return true;

}

bool DLList::addPrev(Bunny data)
{
	if(first == NULL) return init(data);

	Node* temp = current->prev;
	current->prev = new Node;
	current->prev->next = current;
	current->prev->prev = temp;

	if(temp == NULL)
        first = current->prev;
	else
        temp->next = current->prev;

    current = current->prev;
    current->data = data;
    count++;
    return true;
}

bool DLList::addFirst(Bunny data)
{
    if (moveFirst()) return addPrev(data);
    else return false;
}

bool DLList::addLast(Bunny data)
{
    if (moveLast()) return addNext(data);
    else return false;
}

void DLList::out()
{
  system("clear");
    if(first == NULL)  
    {
      cout<<"List is empty"<<endl;
      return;
    }

    Node* temp = first;
    cout << "List: " << endl;
    do
    {
       cout << temp->data.name <<" ";
       cout << temp->data.age <<" ";
       cout << temp->data.weight <<" ";
       cout << temp->data.isHungry <<" ";
       temp = temp->next;
       cout << endl;
    }
    while(temp);
    cout << endl;
}

void DLList::info()
{

    if(count)
        cout << "List node count: " << count << endl;
    else
        cout << "List is empty" << endl;
    //if(current == NULL)
        if(moveFirst())
        {
            cout << "Current name: " << current->data.name << endl;
            cout << "Current age: " << current->data.age << endl;
            cout << "Current weight: " << current->data.weight << endl;
            cout << "Current hunger: " << current->data.isHungry << endl;
        }
}

bool DLList::delFirst(Bunny &data)
{
    if(first == NULL)      return false;
    if(current != first)    moveFirst();

    Node* temp = current->next;
    data = current->data;

    if(temp) temp->prev = NULL;
    delete current;

    current = temp;
    first = temp;
    count--;
    if(temp == NULL) 
    {
      last=NULL; 
      return false;
    }
    return true;
}

bool DLList::delLast(Bunny &data)
{
    if(first == NULL)      return false;
    if(current!=last)    moveLast();

    Node* temp = current->prev;
    data = current->data;

    if(temp) temp->next = NULL;
    delete current;

    current = temp;
    last = temp;
    count--;

    if(temp == NULL) 
    {
      first=NULL; 
      return false;
    }
    return true;
}

bool DLList::del(Bunny &data)
{
    if(first == NULL) return false;
	if(current == NULL) return false;

	if(current==first) return delFirst(data);
    if(current==last) return delLast(data);

    Node* temp = current->next;
	data = current->data;

	current->prev->next = current->next;
	current->next->prev = current->prev;

	delete current;
	current = temp;
	count--;
	return true;
}

bool DLList::delNext(Bunny &data)
{
  if(first == NULL) return false;
	if(current == NULL) return false;
	if (moveNext()) return del(data);
  return false;
}
bool DLList::delPrev(Bunny &data)
{
  if(first == NULL) return false;
	if(current == NULL) return false;
	if (movePrev()) return del(data);
  return false;
}

void DLList::clear()
{
   if(!moveFirst())
   {
       cout << "List is empty" << endl;
       return;
   }
   Bunny k;
   while(del(k));
}
