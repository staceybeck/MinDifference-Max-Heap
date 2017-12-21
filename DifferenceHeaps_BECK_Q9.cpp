//
//
//  Created by Stacey Rivet on 12/20/17.
//  Copyright © 2017 Stacey Rivet Beck. All rights reserved.
//
//  This function uses max-heap to find the minimal difference between
//  any adjacent values in an unsorted array/vector array and returns those
//  two values as well as their minimal difference.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

template <class T>
T minDiff (vector<T> v1) {
    
    //defining difference values and temps
    T tempDiff = -1;
    T diff = 100;
    T topVal1, topVal2 = 0;
    T value1 = 0, value2 = 0;
    int i = 1;
    
    // using make_heap() from max-heap STL
    make_heap(v1.begin(), v1.end());
    
    while (i != 99) {
        
        //assign max value to temporary variable topVal1
        topVal1 = v1.front();
        
        //pop max value to end of array and ignore using .end()-i
        pop_heap(v1.begin(), v1.end()-i);

        //assign next largest value to topVal2
        topVal2 = v1.front();
        
        //calculate absolute difference between adjacent values
        tempDiff = abs(topVal2-topVal1);
        
        //compare if minimal difference is = 0 for base case
        if (abs(topVal2 - topVal1) == 0) {
            cout << "Minimal difference exists between pairs " << topVal2 << " and " << topVal1 << endl;
        }
        
        //comparison for minimal difference > 0, stores values in temp variables
        //stores lowest difference in diff
        if (tempDiff < diff) {
            diff = abs(topVal2-topVal1);
            value1 = topVal1;
            value2 = topVal2;
        }
        
        i++;
    }
    //for other cases where minimal difference != 0
    if (diff > 0)
        cout << "Minimal difference exists between pairs " << value1
        << " and " << value2 << endl << endl;
    
    return diff;
}

int main() {
    
    // Initializing a vector of ints
    vector<int> v1 = {44, 86, 11, 71, 61, 50, 46, 12, 6, 61, 72, 83, 35, 38, 33, 60, 33, 25, 84, 50, 8, 84, 60, 22, 39, 31, 51, 2, 63, 51, 67, 90, 32, 54, 87, 42, 7, 61, 3, 29, 19, 18, 66, 71, 35, 76, 7, 48, 41, 92, 48, 38, 100, 99, 2, 31, 94, 4, 12, 41, 98, 72, 47, 39, 5, 36, 83, 63, 48, 8, 50, 42, 67, 98, 12, 73, 81, 77, 49, 79, 6, 80, 45, 64, 97, 66, 97, 38, 53, 16, 75, 78, 21, 19, 64, 14, 27, 76, 69, 41};
    
    //initialize a vector of doubles
    vector<double> v2 = {49.3161, 86.8905, 11.3944, 53.6294, 59.8794, 5.248, 57.382, 25.2015, 86.4258, 48.5549, 94.7989, 57.5996, 85.2883, 27.2116, 19.64, 90.5718, 39.8861, 45.408, 98.9921, 28.1435, 84.0393, 50.0511, 92.8203, 88.198, 58.0723, 31.9946, 13.0681, 51.8656, 77.8169, 53.3708, 88.214, 81.7046, 41.7084, 72.053, 96.3368, 26.2633, 66.1523, 33.4011, 18.533, 77.7682, 73.4415, 68.1627, 5.96543, 91.8632, 67.7314, 69.389, 94.7273, 11.733, 32.503, 30.6049, 63.4401, 60.9486, 87.0579, 9.86099, 13.9387, 84.1796, 81.7646, 26.4441, 31.0737, 89.7086, 20.9977, 18.9619, 85.1366, 98.196, 69.5721, 70.8729, 10.2308, 85.6839, 76.1808, 81.6806, 46.8683, 49.4764, 55.5107, 55.575, 63.1231, 93.2853, 27.5485, 48.3143, 64.736, 40.3162, 30.3321, 19.1091, 7.37671, 94.1409, 60.4783, 61.3763, 38.4056, 58.1172, 75.3142, 8.45943, 43.21, 1.14745, 33.0515, 99.656, 11.3098, 16.9994, 11.3334, 77.7073, 86.2351, 35.1895};
    
    //call to minDiff for vector of ints
    int difference = minDiff(v1);
    cout << "The minimal difference value for INTS is: " << difference << endl << endl;
    
    //call to minDiff for vector of doubles
    double different = minDiff(v2);
    cout << "The minimal difference value for DOUBLES is: " << different << endl << endl;

    return 0;
}


/*
 
 Using max-heap we can run this algorithm at O(1), but for n values, we still need
 to compare adjacent values from 0 to n-1 to find the minimal value, O(n) worst case. 
 We could stop with the vector array of ints at value 2 and 2 since the absolute minimal 
 value is 0, in which we cannot get any smaller and this would run O(1) in the minDiff() 
 function. However, to be thorough, I wanted to print all of the pairs of values that also
 contain the minimal possible difference.
 
OUTPUT: 
 
 Minimal difference exists between pairs 98 and 98
 Minimal difference exists between pairs 97 and 97
 Minimal difference exists between pairs 84 and 84
 Minimal difference exists between pairs 83 and 83
 Minimal difference exists between pairs 76 and 76
 Minimal difference exists between pairs 72 and 72
 Minimal difference exists between pairs 71 and 71
 Minimal difference exists between pairs 67 and 67
 Minimal difference exists between pairs 66 and 66
 Minimal difference exists between pairs 64 and 64
 Minimal difference exists between pairs 63 and 63
 Minimal difference exists between pairs 61 and 61
 Minimal difference exists between pairs 61 and 61
 Minimal difference exists between pairs 60 and 60
 Minimal difference exists between pairs 51 and 51
 Minimal difference exists between pairs 50 and 50
 Minimal difference exists between pairs 50 and 50
 Minimal difference exists between pairs 48 and 48
 Minimal difference exists between pairs 48 and 48
 Minimal difference exists between pairs 42 and 42
 Minimal difference exists between pairs 41 and 41
 Minimal difference exists between pairs 41 and 41
 Minimal difference exists between pairs 38 and 38
 Minimal difference exists between pairs 38 and 38
 Minimal difference exists between pairs 35 and 35
 Minimal difference exists between pairs 33 and 33
 Minimal difference exists between pairs 31 and 31
 Minimal difference exists between pairs 19 and 19
 Minimal difference exists between pairs 12 and 12
 Minimal difference exists between pairs 12 and 12
 Minimal difference exists between pairs 8 and 8
 Minimal difference exists between pairs 7 and 7
 Minimal difference exists between pairs 6 and 6
 Minimal difference exists between pairs 2 and 2
 The minimal difference value for INTS is: 0
 
 Minimal difference exists between pairs 88.214 and 88.198
 
 The minimal difference value for DOUBLES is: 0.016
 
 Program ended with exit code: 0
 
 */
