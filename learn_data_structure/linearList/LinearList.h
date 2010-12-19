/*
    TODO: 
        1. implement the sort function
        2. find out how much memory should be reallocated when the storage is insufficient
        3. check for memory leaks
        4. do more tests on this class, with various types and classes
        5. optimize towards better performance, use const/reference wherever possible
*/

#ifndef LINEARLIST_H
#define LINEARLIST_H

#ifdef DEBUG
#include <iostream>
#endif

#include "../errors.h"

namespace vrcats
{
    template <class T> class LinearList
    {
        public:
            LinearList<T>(long initialMaxLength=10);
            virtual ~LinearList();
            int resize(long newMaxLength);
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
            long d_length, d_maxLength;
            T* d_head;
    };
#ifdef DEBUG
    template <class T>
        void LinearList<T>::print()
        {
            std::cout<<std::endl<<"LinearList: "<<std::endl;
            std::cout<<"\tlength:\t\t"<<d_length<<std::endl;
            std::cout<<"\tmax length:\t"<<d_maxLength<<std::endl;
            std::cout<<"\titems:\t\t";
            for(int i=0;i<d_length;i++)
                std::cout<<d_head[i]<<", ";
            std::cout<<std::endl<<std::endl;
        }
#endif
    template <class T> 
        LinearList<T>::LinearList(long initialMaxLength)
        {
            try
            {
                d_head=new T[initialMaxLength];
            }
            catch(int e)
            {
                throw(Errors::unableToAllocateSpace());
            }
            d_length=0;
            d_maxLength=initialMaxLength;
        }
    template <class T>
        LinearList<T>::~LinearList()
        {
            delete[] d_head;
        }
    template <class T>
        int LinearList<T>::resize(long newMaxLength)
        {
            if(newMaxLength<d_length)
                return -1;//error, not enough space to hold current items
            try
            {
                T* new_head=new T[newMaxLength];
                //copy existing items to the new space
                for(long i=0;i<d_length;i++)
                    new_head[i]=d_head[i];/* shall we consider to use memcpy to replace this call, so that the type T does not have to implement the "=" operator? */
                delete[] d_head;
                d_head=new_head;
            }
            catch(int e)
            {
                //allocating error, return the error code
                throw(Errors::unableToAllocateSpace());
            }
            d_maxLength=newMaxLength;
            return 0;
        }
    template <class T>
        int LinearList<T>::clear()
        {
            d_length=0;
            return 0;
        }
    template <class T>
        long LinearList<T>::length()
        {
            return d_length;
        }
    template <class T>
        T& LinearList<T>::operator[](long index)
        {
            if(index>d_length||index<=0)
            {
                throw(Errors::indexOutOfRange());//throw exception if index out of range
            }
            return d_head[index-1];
        }
    template <class T>
        long LinearList<T>::find(T item, long from)
        {
            if(from<1||from>d_length)
                return -1;
            for(int i=from-1;i<d_length;i++)
                if(item==d_head[i])
                    return i+1;
            return -1;//not found
        }
    template <class T>
        int LinearList<T>::insert(T item, long before)
        {
            if(before==0)
                before=1;
            if(before>d_length+1||before<-1)
                return -1;//error: position incorrect
            if(before==-1)//appending mode
                before=d_length+1;
            //keep the items before before, and move the items after it by one
            for(long i=d_length;i>=before;i--)
                d_head[i]=d_head[i-1];
            d_head[before-1]=item;
            d_length++;
            return 0;//success
        }
    template <class T>
        void LinearList<T>::operator<<(T item)
        {
            insert(item);
        }
    template <class T>
        int LinearList<T>::del(long index)
        {
            if(d_length==0)
                return -1;//nothing to delete
            if(index>d_length||index<=0)
                return -1;//incorrect index
            //move all items after index by one item
            for(int i=index;i<d_length-1;i++)
                d_head[i-1]=d_head[i];
            d_length--;
            return 0;//success
        }
    template <class T>
        int LinearList<T>::sort(bool smallerFirst)
        {
            /* this requires T to implement operator ">" */
        }
}

#endif
