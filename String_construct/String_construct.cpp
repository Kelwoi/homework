
#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    String s1;                      
    String s2(50);                  
    String s3("Hello, world!");     

    s1.input();                    
    s1.output();                   
    s2.output();                    
    s3.output();                    

    std::cout << "Total objects created: " << String::getObjectCount() << std::endl;

    return 0;
}


