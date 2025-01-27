
#include "Link.h"
#include <iostream>

int main()
{
    FwdList<int> list1, list2;

    list1.addHead(1);
    list1.addTail(2);
    list1.addTail(3);

    list2.addHead(3);
    list2.addTail(4);
    list2.addTail(5);

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    FwdList<int> clonedList = list1.Clone();
    cout << "Cloned List 1: ";
    clonedList.print();

    FwdList<int> combinedList = list1 + list2;
    cout << "Combined List: ";
    combinedList.print();

    FwdList<int> intersectionList = list1 * list2;
    cout << "Intersection of List 1 and List 2: ";
    intersectionList.print();
}


