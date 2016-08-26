//
//  main.cpp
//  Generic Sorting using C++
//
//  Created by Harshavardhan K K on 26/08/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#include <iostream>
#include "Generic.h"
#include "Sorting.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    // sort_search__demo();
    return 0;
}

void sort_search__demo() {
    
    string array[10];
    
    for (int i = 0; i < 4; i++) {
        cout << "Enter string: ";
        cin >> array[i];
    }
    
    displayArray(array, 4);
    
    cout << "\nString to search: ";
    string key;
    cin >> key;
    
    Algorithm<string> string_search;
    cout << string_search.searchKey(array, key, 4) << endl;
    
    Algorithm<double> dob_search;
    double dob_array[100];
    
    for (int i = 0; i < 100; i++) {
        dob_array[i] = arc4random() % 103;
    }
    
    displayArray(dob_array, 100);
    double dob_key;
    cout << "Enter key: "; cin >> dob_key;
    cout << dob_search.searchKey(dob_array, dob_key, 100) << endl;

}
