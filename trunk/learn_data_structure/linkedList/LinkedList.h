/*
    TODO:
    1. consider to make ListNode a private class, or add LinkedList as a friend of it, making all members protected to avoid exposing them
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
            T* d_content;
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
    ListNode::ListNode(T* content)
    {
        d_previous=0;
        d_next=0;
        d_content=content;
    }
    template <class T>
    ListNode::~ListNode()
    {
        delete d_content;
    }
    template <class T>
    void ListNode::hook(ListNode* previous)
    {
        d_previous=previous;
        previous.d_next=this;
    }
    template <class T>
    LinkedList::LinkedList()
    {
        //init member variables
        d_head=0;
        d_tail=0;
        d_length=0;
    }
    template <class T>
    LinkedList::~LinkedList()
    {
        clear();
    }
    template <class T>
    int LinkedList::clear()
    {
        //delete all items
        while(d_head!=0)
        {
            ListNode* next=d_head->d_next;
            delete d_head;
            d_head=next;
        }
        d_length=0;
        return 0;
    }
    template <class T>
    long LinkedList::length()
    {
        return d_length;
    }
    template <class T>
    T& LinkedList::operator[](long index)
    {
        //check parameter
        if(index<1||index>d_length)
            throw(Errors::indexOutOfRange());
        //return item with index speicified
        //TODO: optimize using d_tail
        ListNode* p=d_head;
        for(int i=1;i<index;i++)
            p=p->d_next;
        return *(p->d_content);
    }
    template <class T>
    long LinkedList::find(T item, long from)
    {
        if(from<1||from>d_length)
            throw(Errors::indexOutOfRange());
        ListNode* p=d_head;
        for(int i=1;i<before;i++)
            p=p->d_next;
        while(p!=0)
        {
            if(*(p->d_content)==item)
                return before;
            before++;
            p=p->d_next;
        }
        return -1;
    }
    template <class T>
    int LinkedList::insert(T item, long before=-1)
    {
        if(before==-1)
            before=d_length+1;
        //create the new item
        try
        {
            ListNode* newNode=new ListNode(&T);
        }
        catch(int e)
        {
            throw(Errors::unableToAllocateSpace());
        }
        ListNode* p=d_head;
        for(int i=1;i<before-1;i++)
            p=p->d_next;
        ListNode* oneBeforeBefore=p;
        ListNode* Before=p->d_next;
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
    }
    template <class T>
    void LinkedList::operator<<(T item)
    {
        insert(T);
    }
    template <class T>
    int LinkedList::del(long index)
    {
        //check parameter
        //delete item with index specified
        ListNode* p=d_head;
        for(int i=1;i<index-1;i++)
            p=p->d_next;
        //hook next to previous if both available
        ListNode* previous=p;
        p=p->d_next;
        ListNode* next=p->next;
        if(next!=0)
            next->hook(previous);
        delete p;
    }
    template <class T>
    int LinkedList::sort(bool)
    {
    }
}
#endif
