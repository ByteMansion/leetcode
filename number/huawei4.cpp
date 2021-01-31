/**
 * @file huawei4.cpp
 * @brief 
 * 
 *  有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
 * 答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，
 * 这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
 * 如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
 * 
 */
#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int getMaxBottles(int num)
{
    if(num < 2) {
        return 0;
    }
    int result = 0;
    while(num/3) {
        result += num / 3;
        num = num / 3 + num % 3;
    }
    if(num == 2) {
        result += 1;
    }
    return result;
}
 
int main()
{
    int num;
    vector<int> results;
    while(cin >> num) {
        if(num == 0) {
            break;
        }
        results.push_back(getMaxBottles(num));
    }
    for(auto val: results) {
        cout << val << endl;
    }
     
    return 0;
}