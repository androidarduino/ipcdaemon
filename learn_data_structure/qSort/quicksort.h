#ifndef QSORT_H
#define QSORT_H

class QuickSort
{
    public:
        QuickSort(){}
        void sort(int* array, int length);
    private:
        void qsort(int* l, int low, int high);
        int partition(int* l, int low, int high);
};

void QuickSort::sort(int* array, int length)
{
    qsort(array, 0, length);
}

void QuickSort::qsort(int* l, int low, int high)
{
    if(low<high)
    {
        int pivotloc=partition(l, low, high);
        qsort(l, low, pivotloc-1);
        qsort(l, pivotloc+1, high);
    }
}

int QuickSort::partition(int* l, int low, int high)
{
    int pivotkey=l[low];
    while(low<high)
    {
        while(low<high&&l[high]>=pivotkey)
            high--;
        int t=l[low];
        l[low]=l[high];
        l[high]=t;
        while(low<high&&l[low]<=pivotkey)
            low++;
        t=l[low];
        l[low]=l[high];
        l[high]=t;
    }
    return low;
}

#endif
