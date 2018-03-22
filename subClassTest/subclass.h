#ifndef SUBCLASS_H
#define SUBCLASS_H

#include <iostream>
using std::cout; using std::endl;

class FatherClass
{
public:
    FatherClass() { cout << "construct FatherClass().\n"; }
    ~FatherClass() { cout << "deconstruct FatherClass().\n"; }
};

class ChildrenClass : FatherClass
{
public:
    ChildrenClass() : FatherClass() { cout << "construct ChildrenClass().\n"; }
    //ChildrenClass() { cout << "construct ChildrenClass().\n"; }
    ~ChildrenClass() { cout << "deconstruct ChildrenClass().\n"; }
};
#endif // SUBCLASS_H
