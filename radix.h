#ifndef RADIX_H
#define RADIX_H

#include "sort.h"
#include <vector>

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}


        void countingSort(int arr[], int n, int exp){
            int output[n];
            int i, count[10] = {0};

            for (i = 0; i < n; i++){
                count[ (arr[i]/exp)%10 ]++;
            }

            for (i = 1; i < 10; i++){
                count[i] += count[i - 1];
            }

            for (i = n - 1; i >= 0; i--){
                output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
                count[ (arr[i]/exp)%10 ]--;
            }

            for (i = 0; i < n; i++){
                arr[i] = output[i];
            }
        }


    void execute() {
            int max = 0;

            for(int i=0; i<size; i++){
                if(max < elements[i]){
                    max = elements[i];
                }
            }

            for(int exp=1; max/exp>0; exp*=10){
                countingSort(elements, size, exp);
            }
        }

        inline string name() { return "RadixSort"; }
};

#endif