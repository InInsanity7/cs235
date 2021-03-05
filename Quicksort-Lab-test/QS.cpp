#include "QS.h"
#include <sstream>

QS::~QS() {delete [] ptr;}
    
bool QS::createArray(int capacity) {

    if (capacity < 0) {
        std::cout << "invalid capacity" << std::endl;
        return false;
    }
    if (ptr != nullptr) {
        delete [] ptr;
        ptr = nullptr;
    }
    ptr = new int[capacity];
    this->capacity = capacity;
    addIndex = 0;

    return true;
}

bool QS::addToArray(int value) {
    if (addIndex < capacity) {
        ptr[addIndex] = value; 
        ++addIndex;
        return true;
    }
    else {
        return false;
    }
}

int QS::getSize() const {return addIndex;}

void QS::clear() {
    for (int i = 0; i < addIndex; i++) {
        ptr[i] = 0;
    }
    addIndex = 0;

}

std::string QS::getArray() const {
    std::stringstream ss;
    std::string array;

    for (int i = 0; i < addIndex; i++) {
        ss << ptr[i];
        if (i < addIndex - 1) {
            ss << ",";
        }
    }

    ss >> array;
    return array;
}

int QS::medianOfThree(int left, int right) {
    if (addIndex == 0 || left < 0
        || right >= addIndex || left >= right) {
        
        return -1;
    }

    int middle = left + (right-left)/2;
    int tmp;

    if (ptr[left] > ptr[middle]) {
        tmp = ptr[left];
        ptr[left] = ptr[middle];
        ptr[middle] = tmp;
    }
    if (ptr[left] > ptr[right]) {
        tmp = ptr[left];
        ptr[left] = ptr[right];
        ptr[right] = ptr[middle];
        ptr[middle] = tmp;
    }
    else if (ptr[middle] > ptr[right]) {
        tmp = ptr[middle];
        ptr[middle] = ptr[right];
        ptr[right] = tmp;
    }
    return middle;
}

int QS::partition(int left, int right, int pivotIndex) {
    if (addIndex == 0 || left < 0
        || right >= addIndex || left >= right
        || pivotIndex < left || pivotIndex > right) {
        
        return -1;
    }

    int tmp;
    int up = left + 1;
    int down = right; 

    //exchanging median with first
    tmp = ptr[left];
    ptr[left] = ptr[pivotIndex];
    ptr[pivotIndex] = tmp;

    //swapping while up not crossed down
    do {
        while (ptr[up] <= ptr[left] && up < right) {
            ++up;
        }
        while (ptr[down] > ptr[left] && down > left) {
            --down;
        } 
        if (up < down) {
            //swap within partition
            tmp = ptr[up];
            ptr[up] = ptr[down];
            ptr[down] = tmp;
        }
    } while (up < down);

    //exchanging value: pivot and partition
    tmp = ptr[left];
    ptr[left] = ptr[down];
    ptr[down] = tmp;

    return down;   
}
void QS::quickSort(int first, int last) {
    if (last - first < 1) {
        return;
    }

    int pivot = this->medianOfThree(first, last);
    pivot = this->partition(first, last, pivot);

    this->quickSort(first, pivot-1);
    this->quickSort(pivot + 1, last);
}

void QS::sortAll() {
    if (addIndex > 0) {
        this->quickSort(0,addIndex - 1);
    }
}
