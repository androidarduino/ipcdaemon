#include "quicksort.h"
#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv)
{
    int samples[10000];
    srand(time(0));
    for(int i=0;i<sizeof(samples)/sizeof(int);i++)
        samples[i]=rand()%50000;
    QuickSort sorter;
    sorter.sort(samples, sizeof(samples)/sizeof(int));
    std::cout<<std::endl;
    for(int i=0;i<sizeof(samples)/sizeof(int);i++)
        std::cout<<i<<":\t"<<samples[i]<<std::endl;
}
