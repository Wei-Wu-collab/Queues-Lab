/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
  node* newNode = new node();
  node* temp = new node();
  newNode->data = item;
  newNode->priority = priority;
  if (front == NULL) {
    front = newNode;
  }
  else {
    if (front->priority < newNode->priority) {
      temp->link = front;
      newNode->link = temp->link;
      front = temp->link;
    }
    else {
      newNode->link = front;
      front = newNode;
    }
  }
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
  if (front == NULL) {
    return NULL;
  }
  else {
    return front->data;
  }
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
  node* currentTop = new node();
  if (front == NULL) {
    currentTop = front;
  }
  else {
    currentTop->data = front->data;
    currentTop->link = this->front;
    currentTop = this->front;
    this->front = currentTop->link;
  }

}

/*
 * Print Priority Queue
 */
void PQueue::display()
{
  node *p1;
  p1 = front;
  while (p1 != NULL) {
    std::cout<<front->priority<<" "<<(char*)front->data<<std::endl;
    p1 = p1->link;
  }
	std::cout << std::endl;

}
	