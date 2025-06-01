#ifndef QUICK_H
#define QUICK_H

#include "SortTech.h"
#include "SortData.h"

template <class T, template <typename> class Container>
class Quick : public SortTech<T, Container> {
public:
    inline void sort(SortData<T>& data) override {
        quickSort(data, 0, data.size() - 1);
    }

private:
    void quickSort(SortData<T>& data, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(data, low, high);
            quickSort(data, low, pivotIndex - 1);
            quickSort(data, pivotIndex + 1, high);
        }
    }

    int partition(SortData<T>& data, int low, int high) {
        T pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (data[j] < pivot) {
                ++i;
                data.swap(i, j);
            }
        }

        data.swap(i + 1, high);
        return i + 1;
    }
};

#endif
