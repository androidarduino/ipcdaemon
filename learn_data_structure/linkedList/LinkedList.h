/*
    TODO:
    1. consider to make ListNode a private class, or add LinkedList as a friend of it, making all members protected to avoid exposing them
    2. take the advantages of double linked list and circular linked list to improve performance
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
    class ListNode
    {
        public:
            ListNode(T* content);
            virtual ~ListNode();
            void hook(ListNode* previous);
            T d_content;
            ListNode* d_previous, * d_next;
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
            ListNode<T>* d_head, * d_tail;
    };
    template <class T>
    class CircularList:public LinkedList<T>
    {
        public:
            CircularList<T>();
            virtual ~CircularList();
    };
    template <class T>
    class DoubleLinkedList:public LinkedList<T>
    {
        public:
            DoubleLinkedList<T>:LinkedList<T>();
            virtual ~DoubleLinkedList();
    };

    template <class T>
    ListNode<T>::ListNode(T* content)
    {
        d_previous=0;
        d_next=0;
        d_content=*content;
    }
    template <class T>
    ListNode<T>::~ListNode()
    {
        //delete d_content;
    }
    template <class T>
    void ListNode<T>::hook(ListNode* previous)
    {
        d_previous=previous;
        previous->d_next=this;
    }
    template <class T>
    LinkedList<T>::LinkedList()
    {
        //init member variables
        d_head=0;
        d_tail=0;
        d_length=0;
    }
    template <class T>
    LinkedList<T>::~LinkedList()
    {
        clear();
    }
    template <class T>
    int LinkedList<T>::clear()
    {
        //delete all items
        for(int i=1;i<=d_length;i++)
        {
            ListNode<T>* next=d_head->d_next;
            delete d_head;
            d_head=next;
        }
        d_length=0;
        return 0;
    }
    template <class T>
    long LinkedList<T>::length()
    {
        return d_length;
    }
    template <class T>
    T& LinkedList<T>::operator[](long index)
    {
        //check parameter
        if(index<1||index>d_length)
            throw(Errors::indexOutOfRange());
        //return item with index speicified
        //TODO: optimize using d_tail
        ListNode<T>* p=d_head;
        for(int i=1;i<index;i++)
            p=p->d_next;
        return p->d_content;
    }
    template <class T>
    long LinkedList<T>::find(T item, long from)
    {
        if(from<1||from>d_length)
            throw(Errors::indexOutOfRange());
        ListNode<T>* p=d_head;
        for(int i=1;i<from;i++)
            p=p->d_next;
        while(p!=0)
        {
            if(p->d_content==item)
                return from;
            from++;
            p=p->d_next;
        }
        return -1;
    }
    template <class T>
    int LinkedList<T>::insert(T item, long before)
    {
        //create the new item
        ListNode<T>* newNode;
        try
        {
            newNode=new ListNode<T>(&item);
        }
        catch(int e)
        {
            throw(Errors::unableToAllocateSpace());
        }
        if(before==0||before==1)
        {
            if(d_head!=0)
                d_head->hook(newNode);
            d_head=newNode;
            d_length++;
            return 0;
        }
        if(before==-1||before>d_length)
            before=d_length+1;

        ListNode<T>* p=d_head;
        for(int i=1;i<before-1;i++)
            p=p->d_next;
        ListNode<T>* oneBeforeBefore=p;
        ListNode<T>* Before=0;
        if(p!=0)
            Before=p->d_next;
        //hook new item to the one 1 before before
        if(oneBeforeBefore!=0)
            newNode->hook(oneBeforeBefore);
        else
            d_head=newNode;
        //hook before to the new item if it is not pass the tail
        if(Before!=0)
            Before->hook(newNode);
        else
            d_tail=newNode;
        d_length++;
    }
    template <class T>
    void LinkedList<T>::operator<<(T item)
    {
        insert(item);
    }
    template <class T>
    int LinkedList<T>::del(long index)
    {
        //check parameter
        if(d_length==0)
            return -1;//nothing to delete
        if(index>d_length||index==-1)//index==-1 means deleting the last one
            index=d_length;
        if(index<1)
            index=1;
        //delete item with index specified
        ListNode<T>* p=d_head;
        if(index==1)
        {
            d_head=p->d_next;
            delete p;
            d_length--;
            return 0;
        }
        for(int i=1;i<index-1;i++)
            p=p->d_next;
        //hook next to previous if both available
        ListNode<T>* previous=p;
        p=p->d_next;
        ListNode<T>* next=p->d_next;
        if(next!=0)
            next->hook(previous);
        delete p;
        d_length--;
    }
    template <class T>
    int LinkedList<T>::sort(bool)
    {
    }
    template <class T>
    void LinkedList<T>::print()
    {
        ListNode<T>* p=d_head;
        std::cout<<std::endl<<"LinkedList: "<<std::endl;
        for(int i=1;i<=d_length;i++)
        {
            std::cout<<p->d_content<<", ";
            p=p->d_next;
        }
        std::cout<<std::endl<<std::endl;
    }
}
#endif
