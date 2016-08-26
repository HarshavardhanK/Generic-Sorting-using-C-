//
//  Sorting.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 25/08/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

// ********************************** IT IS ASSUMED THAT YOU KNOW SORTING ALGORITHMS ***************************************

#include <stdio.h>
#include <iostream>
#include "Generic.h"

template <typename T>

class Algorithm {
    
public:
    
    void insertionSort(T* array, int size) {
        
        /*
         
         Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
         
         */
        
        for (int i = 0; i < size; i++) {
            
            int j = i;
            int num = array[j];
            
            while(j > 0 && num < array[j-1]) {
                swapValue(&array[j], &array[j-1]);
                j--;
            }
            
            array[j] = num;
        }
        
        // for each iteration, num is the loop invariant.
    }
    
    void selectionSort(T* array, int size) {
        
        /*
         
         The algorithm divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.
         
         */
        
        int minIndex = 0;
        
        for (int i = 0; i < size - 1; i++) {
            minIndex = i;
            
            for (int j = i + 1; j < size; j++) {
                
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            
            if (minIndex != i) {
                swapValue(&array[i], &array[minIndex]);
            }
        }
    }
    
    void mergeSort(T* array, int left, int right) {
        
        /*
         Conceptually, a merge sort works as follows:
         
         1. Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
         2. Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
         
         
         
         */
        
        
        if (left < right) {
            int mid = (right + left) / 2;
            
            mergeSort(array, left, mid);
            mergeSort(array, mid, right);
            merge(array, left, mid, right);
        }
        
    }
    
    void merge(T* array, int first, int mid, int last) {
        
        // merge the left half, and the right half
        
        int left = first;
        int right = mid + 1;
        int temp = 0;
        
        int arr[last - first + 1];
        
        while (left <= mid && right <= last) {
            
            if (array[left] < array[right]) {
                arr[temp++] = array[left++];
                
            } else {
                arr[temp++] = array[right++];
            }
        }
        
        // put the remaining pieces into the temporary array
        
        while (left <= mid) {
            arr[temp++] = array[left++];
        }
        
        while (right <= last) {
            arr[temp++] = array[right++];
        }
        
        // copy the elements of the temporary into the original array
        
        for (int i = 0; i < temp; i++) {
            array[i + first] = array[i];
        }
        
        // TA-DA you just did the merge sort
    }
    
    int searchKey(T* array, T key, int size) {
        
        selectionSort(array, size);
        displayArray(array, size);
        
        cout << "The search index is according to the sorted array\n";
        
        return binarySearch(array, key, 0, size);
        
    }
    
    int linearSearch(T* array, T key, int size) {
        
        for(int i = 0; i < size; i++) {
            
            if (array[i] == key) {
                return i;
            }
        }
        
        return -1;
    }
    
    int binarySearch(T* array, T key, int left, int right) {
        
        if (left > right) {
            return -1;
        }
        
        int mid = (right + left) / 2;
        T ele = array[mid];
        
        if (key < ele) {
            return binarySearch(array, key, left, mid - 1);
            
        } else if(key > ele) {
            return binarySearch(array, key, mid + 1, right);
            
        } else if(key == ele) {
            return mid;
        }
        
        return -1;
    }
    
    
};




