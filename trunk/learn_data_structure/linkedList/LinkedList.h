/*
    TODO: 
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifdef DEBUG
#include <iostream>
#endif

#include "../errors.h"

namespace vrcats
{
    template <class T>
    class SingleListNode
    {
        public:
            SingleListNode(T* content);
            T* d_content;
            SingleListNode* d_next;
            void hook(SingleListNode& previous);
    };
    template <class T>
    class DoubleListNode
    {
        public:
            DoubleListNode(T* content);
            T* d_content;
            DoubleListNode* d_previous, * d_next;
            void hook(DoubleListNode& previous);
    };
    template <class T> 
    class LinkedList
    {
       public:
            LinkedList<T>();
            virtual ~LinkedList();
            int clear();
            long length();
            T& operator[](long index);
            long find(T item, long from=1);
            int insert(T item, long before=-1);
            void operator<<(T item);
            int del(long index);
            int sort(bool smallerFirst=true);
#ifdef DEBUG
            void print();
#endif
       protected:
            long d_length;
            
    };
    template <class T> 
    class SingleLinkedList:public LinkedList<T>
    {
        public:
            SingleLinkedList<T>();
            virtual ~SingleLinkedList();
        protected:
            SingleListNode<T>* d_head, * d_tail;
    };
    template <class T> 
    class CircularList:public LinkedList<T>
    {
        public:
            CircularList<T>();
            virtual ~CircularList();
        protected:
            SingleListNode<T>* d_head;
    };
    template <class T> 
    class DoubleLinkedList:public LinkedList<T>
    {
        public:
            DoubleLinkedList<T>:LinkedList<T>();
            virtual ~DoubleLinkedList();
        protected:
            DoubleListNode<T>* d_head, * d_tail;
    };
/*
    template <class T>
    type className::function()
    {

    }
*/
}
#endif
