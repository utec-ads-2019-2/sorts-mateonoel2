#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i = 0; i<size; i++){
                int min = INT_MAX;
                int minpos = 0;
                for(int j = i; j<size;j++){
                    if(min > elements[j]){
                        min = elements[j];
                        minpos = j;
                    }
                }
                swap(elements[i],elements[minpos]);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif