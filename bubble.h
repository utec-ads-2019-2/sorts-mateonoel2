#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int j=0; j<size-1; j++){
                for(int i=0; i<size-1-j; i++){
                    if(elements[i] > elements[i+1]){
                        swap(elements[i], elements[i+1]);
                    }
                }
            }
        }

        inline string name() { return "BubbleSort"; }
};

#endif