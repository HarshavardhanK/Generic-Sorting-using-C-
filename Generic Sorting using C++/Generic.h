//
//  Generic.h
//  Algorithms
//
//  Created by Harshavardhan K K on 04/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#ifndef Generic_h
#define Generic_h

using namespace std;
#include <iostream>

template <typename T>

void print(T& value) {
    cout << value;
}

template <typename T>

void arrayCopy(T* array, T* dest_array, int sourcePos, int destPos, int length) {
    
    int j = 0;
    
    for (int i = sourcePos; i < length; i++) {
        dest_array[destPos + j] = array[i];
        j++;
    }
    
}


template <typename T>

void displayArray(T* array, int size) {
    
   // int l = sizeof(array) / sizeof(*array); // this might work on some compilers
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    
}

template <typename T>

void swapValue(T* value, T* anValue) {
    
    //
    
    T temp = *value;
    *value = *anValue;
    *anValue = temp;
}


#endif /* Generic_h */
