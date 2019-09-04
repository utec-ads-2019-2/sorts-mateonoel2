#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i = 1; i<size; i++){
                for(int j = i;j>0; j--){
                    if(elements[j]<elements[j-1]){
                        swap(elements[j], elements[j-1]);
                    }
                }
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif