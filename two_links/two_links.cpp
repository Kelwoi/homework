#include "Link.h"
#include <iostream>

int main()
{
    List<int> list;
    list.addHead(10);
    list.addHead(20);
    list.addHead(30);

    list.print();

    list.insertAt(15, 1);
    list.print();

    list.removeAt(2);
    list.print();

    size_t pos = list.findElement(15);
    cout << "Position of 15: " << pos << endl;

    int replacements = list.searchAndReplace(15, 50);
    cout << "Replacements: " << replacements << endl;
    list.print();

    list.reverse();
    list.print();
}


