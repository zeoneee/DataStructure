//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------

template < class DT >
void selectionSort(DT keyList[], int numKeys)

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
    for (int i = 0; i < numKeys - 1; i++) {
        for (int j = i + 1; j < numKeys; j++) {
            if (keyList[i] > keyList[j]) {
                DT temp = keyList[i];
                keyList[i] = keyList[j];
                keyList[j] = temp;
            }
        }
   }
}

//--------------------------------------------------------------------

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right);

template < class DT >
void quickSort(DT keyList[], int numKeys)

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList, numKeys, 0, numKeys - 1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void quickPartition(DT keyList[], int numKeys,
    int left, int right)

    // Recursive partner of the quickSort routine. Partitions the array
    // entries between left and right into two subarrays. One subarray
    // contains the keys that are less than or equal to splitValue, and
    // the other contains the keys that are greater than splitValue.
    // Recursively sorts each of these subarrays.

{
    DT pivot = keyList[(left + right) / 2];
    int start = left;
    int end = right;
    DT temp;

    while (left <= right) {
        while (keyList[left] < pivot) { // 제자리가 아닌 애를 찾는거 = pivot보다 크거나 같은 애를 찾는 것 
            left++;
        }
        while (keyList[right] > keyList[left]) {
            right--;
        }
        if (left <= right) {
            temp = keyList[left]; 
            keyList[left] = keyList[right];
            keyList[right] = temp;

            // left > right이기 전까지 계속 
            left++;
            right--;
        }
    } 

    // left > right인 상태 
    if (start < right) {    // 자리 바꿨으니까 
        quickPartition(keyList, numKeys, start, right);
    }if (left < end) {
        quickPartition(keyList, numKeys, left, end);
    }
}

//--------------------------------------------------------------------

template < class DT >
void bubbleSort(DT keyList[], int numKeys)

{
    for (int i = 0; i < numKeys - 1; i++) {
        for (int j = numKeys - 1; j > i; j--) {
            if (keyList[j] < keyList[j - 1]) {
                DT temp = keyList[j];
                keyList[j] = keyList[j - 1];
                keyList[j - 1] = temp;
            }
        }
    }
}
