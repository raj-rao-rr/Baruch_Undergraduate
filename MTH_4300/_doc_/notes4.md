# Class Framework
A class is used to specify the form of an object and it combines data representation and methods for manipulating that data into one neat package. The data and functions within a class are called members of the class. When you define a class, you define a blueprint for a data type, that is, what an object of the class will consist of and what operations can be performed on such an object.

```
class Box {
   public:
      double length;                              // Length of a box
      double width;                               // Width of a box
      double height;                              // Height of a box
      
      // default constructor
      Box(const double & =2.0, const double & =2.0, const double & =2.0);
      Box(const Box &);                           // copy constructor
      void operator=(const Box &);                // copy assignment
      ~TwoNumbers();                              // deconstructor
    private:
      void area();                                // computes the surface area of a given box
      void volume();                              // computes the volume of a given box
};

Box::Box(const double &x, const double &y, const double &z){
  length = x;
  width = y;
  height = z;
}

Box::Box(const Box &copyFrom){
  length = copyFrom.x;
  width = copyFrom.y;
  height = copyFrom.z;
}

void Box::operator=(const Box &assignFrom){
  // check to see if memory location is different
  if(&assignFrom != this){
    length = copyFrom.x;
    width = copyFrom.y;
    height = copyFrom.z;
  }
}

Box::~Box(){
  length = 0; 
  width = 0;
  height = 0;
}

void Box::area(){
  return (2 * length * width) + (2 * width * height) + (2 * height * length);
}

void Box::volume(){
  return length * width * height;
}

```

A few concepts for the declaration and implementation of classes are as follows:

**public** flag determines the access attributes of the members of the class, with public being unrestricted access 
**private** flag represent the restricted access of the class, e.g. immutable variables or static functions 

### Default constructor
To initialize a set of values for a given class we create a default constructor, which as follows:

```
class NAME {
  // initializing default constructor 
  class (const type &);                 
};

classobj::classobj(const type & params){
  // make changes to initialize values for default constructor
}
```

### Copy constructor
It is often convenient to copy one object to another. Or, to create a new object that looks exactly the same as the old object.

```
class NAME {
  // initializing constructor 
  classobj (const classobj &);                 
};

classobj::classobj(const classobj & params){
  // make changes to move constructor 
}
```

### Copy assignment
The command `class name = classobj`; creates an object `name` by calling copy-constructor. On the other hand, in order to be able to use a command `name = classobj` after the object `name` is initialized, we would need an assignment operator. 

```
class NAME {
  // initializing constructor assignment
  void operator = (const class &);                 
};

void classobj::operator=(const classobj & params){
  // make changes to copy constructor assignment
}
```

In practice the attributes of objects are not only a few single variables, but quite complex and large data structures. Copying and destroying such structures could take a lot of time, so we opt to move resources instead of copying them from a base case where we simply reassign the pointer location in memory. These are coined the [**move constructor**](https://en.cppreference.com/w/cpp/language/move_constructor) and [**move assignment**](https://en.cppreference.com/w/cpp/language/move_assignment) operator. 
