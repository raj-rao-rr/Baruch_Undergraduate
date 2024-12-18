#include <iostream>

// construct the stack node
class node{
 public:
 int content;
 node *next;
};

// allow for appending to top of the stack
node *push(node *top, int x){
 node *nTop;
 nTop = new node;
 (*nTop).content = x;
 (*nTop).next = top;
 return nTop;
}

// enable deleting the top of the stack node
node *pop(node *top){
 if (top != NULL){
   node *nTop;
   nTop = (*top).next;
   delete top;
   return nTop;
 }
 return NULL;
}

// outputs the stack from the bottom using recurssion
void printS(node *top){
 if (top != NULL){
   printS((*top).next);
   std::cout << (*top).content << " ";
 }
}

int main() {
 int uI = 0;
 node *head;
 head = NULL;

 // check to see whether termination input of -9 is provided
 while (uI != -9){
   std::cin >> uI;
   if (uI != -9){
     if (uI < 0){
       // when we reach a negative number we simply delete
       // the number of elements -X
       for (int i = 0; i < -uI; ++i){
         head = pop(head);
       }
     }

     // always push non-negative numbers to the stack
     if(uI >= 0){
       head = push(head, uI);
     }

   }
 }

 // finally outputs modified sequence
 printS(head);
 std::cout << "\n";
 return 0;
}
