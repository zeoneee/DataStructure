//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 1                      search.cpp
//
//  Implementation of a set of searching routines
//
//--------------------------------------------------------------------

template < class DT >
int linearSearch(DT keyList[], int numKeys,
    DT searchKey, int& index)

    // Linear search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns 0 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey
    // (or -1 if there is no such key).

{
    for (int i = 0; i < numKeys; i++) {
        if (keyList[i] == searchKey) {
            index = i;
            return 1;
        }
    }
    return -1;
}

//--------------------------------------------------------------------

template < class DT >
int binarySearch(DT keyList[], int numKeys,
    DT searchKey, int& index)

    // Binary search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns 0 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey
    // (or -1 if there is no such key).

{
    int start = 0;
    int end = numKeys - 1;
    int middle;

    while (start <= end) {
        middle = (start + end) / 2;
        if (keyList[middle] == searchKey) {
            index = middle;
            return 1;
        }
        else if (keyList[middle] > searchKey) {
            end = middle - 1;
        }
        else {  // searchKey >= keyList[middle]
            start = middle + 1;
        }
    }
    return -1;
}


