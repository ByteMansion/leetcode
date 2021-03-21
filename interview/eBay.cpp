
/**
 * @brief   eBay interview
 * 
 */
#include <vector>
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

#if 0
void zigsort(vector<int>& nums) {
    int n = nums.size();
    
    for(int i = 2; i < n; i++) {
        //
        if(nums[i-2] < nums[i-1]) {
            if(nums[i-1] < nums[i]) {
                swap(nums[i-1], nums[i]);
            }
        } else { 
            if(nums[i-1] > nums[i]) {
                swap(nums[i-1], nums[i]);
            }
        }
        
    }
}

int main()
{
    vector<int> nums = {1, 15, 10, 11, 14};

    zigsort(nums);

    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
#endif
class solution {

};

template <typename T>
unsigned long type_id() {
    static T t;
    return (unsigned long)&t;
}
int main()
{
    cout << type_id<int>() << endl;
    cout << type_id<string>() << endl;
    cout << "sizeof(solution): " << sizeof(solution) << endl;
    cout << type_id<solution>() << endl;
    cout << type_id<int>() << endl;
    cout << type_id<string>() << endl;
    

    return 0;
}