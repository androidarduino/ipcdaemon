#define DEBUG
#include <iostream>
#include "LinkedList.h"
using namespace vrcats;
/*
    The purpose of this file is to test the class
*/
int main()
{
    //creation
    LinkedList<int> list;
    //insert
    std::cout<<"insert 3"<<std::endl;
    list.insert(3);
    list.print();
    std::cout<<"insert 2"<<std::endl;
    list<<2;
    list.print();
    std::cout<<"insert 1"<<std::endl;
    list<<1;
    list.print();
    std::cout<<"insert 4, 2"<<std::endl;
    list.insert(4,2);
    list.print();
    std::cout<<"insert 5, 0"<<std::endl;
    list.insert(5,0);
    list.print();
    std::cout<<"insert 6, 1"<<std::endl;
    list.insert(6,1);
    list.print();
    std::cout<<"insert 7, 20"<<std::endl;
    list.insert(7, 20);
    list.print();
    //find
    std::cout<<"Found 4 at: "<<list.find(4)<<std::endl;
    std::cout<<"Found 5 from 2 at: "<<list.find(5,2)<<std::endl;
    std::cout<<"Found 7 at: "<<list.find(7)<<std::endl<<std::endl;
    //del
    std::cout<<"del 3"<<std::endl;
    list.del(3);
    list.print();
    std::cout<<"del 0"<<std::endl;
    list.del(0);
    list.print();
    std::cout<<"del 7"<<std::endl;
    list.del(7);
    list.print();
    std::cout<<"del 1"<<std::endl;
    list.del(1);
    list.print();
    std::cout<<"del 3"<<std::endl;
    list.del(3);
    list.print();
    //sort
    //not implemented yet
    //length
    std::cout<<"Length is: "<<list.length()<<std::endl;
    //[]
    std::cout<<"insert 33 at 2, and 66 at tail"<<std::endl;
    list.insert(33, 2);
    list.insert(66);
    list.print();
    std::cout<<"item 1,2,3 are: "<<list[1]<<", "<<list[2]<<", "<<list[3]<<std::endl;
    //resize
    //clear
    std::cout<<"clear the list"<<std::endl;
    list.clear();
    list.print();
    return 0;

}
