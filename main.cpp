#include <iostream>
#include "classes.hpp"
using std::string;

int main()
{
    Record record1 = Record("Devo", "Duty Now For The Future", "Rock", 1978);
    record1.printDetails();
    return 0;
}