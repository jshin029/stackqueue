#include <iostream>
using namespace std;

class Node {
  //array is doubly linked list
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
      this->data = data;
      this->next = NULL;
      this->prev = NULL;
    }
};

class stackQueue {
  Node* sHead;  //stack head
  Node* sTail;  //stack tail
  Node* qHead;  //queue head
  Node* qTail;  //queue tail

  int stackSize = 0;
  int queueSize = 50;
  int arr[100];

  public:
    void push(int element){
      if (stackSize == 0){
        //half the array is allocated to the stack
        Node* temp = new Node(element);

        //set both head and tail when stack is empty
        sHead = temp;
        sTail = temp;
        stackSize++;
      }
      else if (stackSize != 49){
        Node* temp = new Node(element);
        temp->prev = sTail;
        sTail->next = temp;
        sTail = temp;
        stackSize++;
      }
      else {
        cout << "Stack is full, element was not added";
      }
    }

    int pop(){
      if (stackSize == 0){
        cout << "Stack is empty, no element was popped: ";
        return 0;
      }
      else if (sHead == sTail){
        //case when only one node exists in queue
        int nodeData = sHead->data;
        delete sHead;
        sHead = NULL;
        sTail = NULL;
        stackSize--;
        return nodeData;
      }
      else {
        //stack removes from tail LIFO
        Node* removingNode = sTail;
        int removingNodeData = sTail->data;
        sTail = sTail->prev;
        delete removingNode;
        stackSize--; //decrement stackSize since node was removed
        return removingNodeData;
      }
    }

    void enqueue(int element){
      if (queueSize == 50){
        //the other half is allocated to the queue
        Node* temp = new Node(element);
        qHead = temp;
        qTail = temp;
        queueSize++;
      }
      else if (queueSize != 99){
        //case when only one node exists in queue
        Node* temp = new Node(element);
        temp->prev = qTail;
        qTail->next = temp;
        qTail = temp;
        queueSize++;
      }
      else {
        cout << "Queue is full, element was not added";
      }
      return;
    }

    int dequeue(){
      if (queueSize == 50){
        cout << "Queue is empty, no element was popped: ";
        return 0;
      }
      else if (qHead == qTail){
        int nodeData = qHead->data;
        delete qHead;
        qHead = NULL;
        qTail = NULL;
        queueSize--;
        return nodeData;
      }
      else {
        Node* removingNode = qHead;
        int removingNodeData = qHead->data;
        qHead = qHead->next;
        delete removingNode;
        queueSize--;
        return removingNodeData;
      }
    }
};


int main(){
  stackQueue *temp  = new stackQueue();
  temp->enqueue(3);
  temp->enqueue(4);
  cout << temp->dequeue() << endl;
  cout << temp->dequeue() << endl;
  cout << temp->dequeue() << endl;

  temp->push(1);
  temp->push(2);
  cout << temp->pop() << endl;
  cout << temp->pop() << endl;
  cout << temp->pop() << endl;

}
