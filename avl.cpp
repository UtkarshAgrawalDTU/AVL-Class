#include<iostream>
#include<cmath>
#include"avl.h"
using namespace std;

int main()
{
    avl a;
    a.insertNode(9);
    a.insertNode(5);
    a.insertNode(10);
    a.insertNode(0);
    a.insertNode(6);
    a.insertNode(11);
    a.insertNode(11);
    a.insertNode(-1);
    a.insertNode(1);
    a.insertNode(2);
    a.deleteNode(10);
    a.preorder();
    return 0;
}
