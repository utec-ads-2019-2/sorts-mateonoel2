#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            int max = 0;

            for(int i=0; i<size; i++){
                if(max < elements[i]){
                    max = elements[i];
                }
            }

            int array1[max];

            for(int i=0; i<max; i++){
                array1[i]=0;
            }

            for(int i=0; i<size; i++){
                array1[elements[i]-1]+=1;
            }

            for(int i=1; i<max+1; i++){
               array1[i]+=array1[i-1];
            }

            int array2[size];

            for(int i=0; i<size; i++){
                array2[array1[elements[i]-1]-1]= elements[i];
                array1[elements[i]-1]-=1;
            }

            for(int i=0; i<size; i++){
                elements[i]=array2[i];
            }
        }

        inline string name() { return "CountingSort"; }
};

#endif