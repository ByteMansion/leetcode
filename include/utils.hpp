/**
 * @brief   This file contains utilities used in other files.
 */
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void print_array(const vector<int> &array)
{
    if(array.empty() || array.size() <= 0) {
        cout << "[This array is empty!]" << endl;
        return;
    }

    size_t cnt = array.size();
    for(size_t index = 0; index < cnt; index++) {
        cout << array[index] << " ";
    }
    cout << endl;
}
