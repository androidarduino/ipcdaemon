#ifndef LINEARLIST_H
#define LINEARLIST_H
namespace vrcats.com
{
    template <class T> class LinearList
    {
        public:
            LinearList(long initialMaxLength=0);
            virtual ~LinearList();
            int resize(long newMaxLength);
            int clear();
            long length();
            <T&> getItem(long index);
            long getIndex(<T&> item);
            int insert(long before, <T&> item);
            int del(long index);
            int sort(bool smallerFirst=true);
        private:
            long d_length;
            <T> d_head[];
    };
}

#endif
