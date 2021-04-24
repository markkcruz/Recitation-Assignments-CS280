#include <iostream>
using namespace std;

// Write a recursive C++ function that performs linear search, called recLinSearch, that takes an integer array A and two subscripts, low and
// high, and a key as arguments. It returns true if the key is found in the elements A[low]...A[high]; otherwise, it returns false.The signature of the function is:

bool recLinearSearch ( const int a[ ],  int   low, int   high, int   key);

// array of n length, iterate from array r, r[0] to r[n]
// so r, r[0] , r[7]
int main()
{
    int myArray[] = { 125, 23, 300, 54, 75, 49, 36, 17};
    int keys1[] = {125, 17, 25 }; // low = 0 , high = 7 {125, 17, 25 };
    int keys2[] = {300, 36, 70 };
    int low, high;
    bool flag;

    // 125, 23, 300, 54, 75, 49, 36, 17
    low = 0; high = 7;
    for(int i = 0; i < 3 ; i++)
    {
        flag = recLinearSearch(myArray, low, high, keys1[i]);
        if (flag)
            cout << "The key value " << keys1[i] << " is found in the specified range " << low << "-" << high << endl;
        else
            cout << "The key value " << keys1[i] << " is not found in the specified range " << low << "-" << high << endl;
    }


    // 300, 54, 75, 49, 36
    low = 2; high = 6;
    for(int i = 0; i < 3 ; i++)
    {
        flag = recLinearSearch(myArray, low, high, keys2[i]);
        if (flag)
            cout << "The key value " << keys2[i] << " is found in the specified range " << low << "-" << high << endl;
        else
            cout << "The key value " << keys2[i] << " is not found in the specified range " << low << "-" << high << endl;
    }

    return 0;
}


bool recLinearSearch ( const int a[],  int low, int high, int key) {


    // Step one, figure out the problem. Then divide that to base cases, general text.
    // When making a recursive call, theres should be a bit in your code which changes the arguments
    // base case

    // { 125, 23, 300, 54, 75, 49, 36, 17};
    // {125, 17, 25 };

    // BASE CASE for going down
    if (a[low] == key) {
        return true;
    }

    // when low == high BASE CASE If we failed to find any in the array
    if (low == high) {
        return false;
    }

    // Rec call
    return recLinearSearch(a, low + 1, high, key);

    // Key is the int we are checking
    // recu
}