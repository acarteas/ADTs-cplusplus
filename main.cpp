#include <iostream>
#include <string>
#include "ADTs\BinarySearchTree.h"
#include "ADTs\AvlTree.h"

using namespace std;

int main(void)
{
    AvlTree<string> test{};
    test.addElement("abc");
    test.addElement("def");
    test.addElement("hij");
    return 0;
}