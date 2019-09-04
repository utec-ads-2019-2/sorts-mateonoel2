#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

    int partition (int arr[], int right, int left){
        int pivot = arr[left];
        int i = (right - 1);

        for (int j = right; j <= left - 1; j++){
            if (arr[j] <= pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[left]);
        return (i + 1);
    }

    void quickSort(int arr[], int right, int left){
        if (right < left){
            int pi = partition(arr, right, left);

            quickSort(arr, right, pi - 1);
            quickSort(arr, pi + 1, left);
        }
    }

    void execute() {
            quickSort(elements, 0, size-1);
        }

        inline string name() { return "QuickSort"; }
};

#endif