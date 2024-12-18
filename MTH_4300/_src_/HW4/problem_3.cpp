#include <iostream>


// linked node class constructor
class Listnode{
public:
   double content;
   Listnode *next;
};

// clearing the memory from linked list
void delete_list(Listnode *arr){
   // if the next term is not nullptr we delete contents

   if (arr != nullptr){
    // calling recursively the following will delete the elements in set, starting from the last term
    delete_list((*arr).next);
    delete arr;
   }
}

// modifies the list (delete the first occurence of element)
void modify_list(Listnode *arr, int *l, int d){
	int shift = 0, itter = 0, count = 0, pos=0;

  // store a tempory linked list to keep track of the number of occurences
  Listnode *temp;
  temp = arr;

  // returns the number of times the select number (d) occurs
  while ((itter <= *l) && (temp != nullptr)){
    if ((*temp).content == d){
      ++count;
    }
    ++itter;
    temp = (*temp).next;
  }

  itter = 0;

	// itterate thorugh the linked list
  while ((itter <= *l) && (arr != nullptr)){
    // once a shift is made, then we shift the entire list forward 
   	if (shift == 0){
     	if ((*arr).content == d){
        ++pos;
        // check to see if this is the last positional element (d)
        if (pos == count){
          // if the element in the list is found, we will shift all elements back
         	(*arr).content = (*(*arr).next).content;
  				// reduce the total length of linked-list
         	--(*l);
         	++shift;
        }
     	}
   	}
   	else{
			// continue shifting elements if the element was found
     	(*arr).content = (*(*arr).next).content;
   	}
		 //assign tail to the next element from the object value
   	arr = (*arr).next;
   	++itter;
   	}
}


int main(){
   int input, delete_term;
   int *length;
   length = new int;
	 // intantiate the linked-list nodes for to keep track of the first and last elements
   Listnode *head, *tail;

   std::cout << "Input an integer value, input (-9) to stop" << "\n";
   std::cin >> input;

   //////////////////////////////////////
   // Constructing the linked lists
   /////////////////////////////////////

   head = new Listnode;
   // access the values of the pointer (assign the content to the user input)
   (*head).content = input;
	 // assign the address of the next term as nullptr (signals end of pointer)
   (*head).next = nullptr;

   // assign the tail to the head address (we will update this)
   tail = head;
   while (input != -9){
    std::cin >> input;

    if (input != -9){

      // assign the tail variable next to a new address
      (*tail).next = new Listnode;

      // we then access our new memory location by assigning our pointer tail
      // to the address of the newly created ListNode
      tail = (*tail).next;

      // follow a similar path by adjusting the contents of the new tail
      (*tail).content = input;
      (*tail).next = nullptr;
      (*length)+=1;
    }
   }

   std::cout << "\n";
   std::cout << "Input a number, if present that number is deleted from list" << "\n";
   std::cin >> delete_term;
   std::cout << "\n";

   /////////////////////////////////////
   // Printing out the linked lists
   /////////////////////////////////////
   long counter = 0;

   // assign the tail function to the original head sequence allowing linking
   tail=head;

   // modifying the existing list, deleting a single term occurrence
   modify_list(tail, length, delete_term);

   // successive prints the contents found in each tail and moves to the next term
   while ((counter <= *length) && (tail != nullptr)){
		 std::cout << (*tail).content << " ";
		 tail = (*tail).next; //assign tail to the next element from the object value
		 ++counter;
   }

   // used to clear the memory occupied from the program
   delete_list(tail);
   std::cout << "\n";
   std::cout << "Memory allocated to list has been deleted";
   std::cout << "\n";
   return 0;
}
