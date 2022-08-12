/**
 * @file huawei5.cpp
 * 
 * 某商城举办了一个促销活动，如果某顾客是某一秒内第一个下单的顾客（可能是多个人）,
 * 则可以获取免单。请你编程计算有多少顾客可以获取免单。
 * 
 * 解答要求 时间限制：3000ms, 内存限制：64MB
 * 输入: 输入为n行数据，每一行表示一位顾客的下单时间。
 * 以（年-月-日 时-分-秒.毫秒）yyyy-MM-dd HH:mm:ss.ﬀf形式给出。
 * 
 * 0<n<50000 2000<yyyy<2020 0<MM<=12 0<dd<=28 0<=HH<=23 0<=mm<=59 0<=ss<=59 0<=ﬀf<=999
 * 所有输入保证合法。
 * 
 * 输出: 输出一个整数，表示有多少顾客可以获取免单。
 * 
 * 注意：在同 1 秒，可能存在多个毫秒数一样的时间。
 */
#include "utils.hpp"
#include <string>
#include <map>

using namespace std;

struct MilliSecond {
    string milli;
    int count;

    MilliSecond(string s, int c): milli(s), count(c) {}
};

int getFreeCount(vector<string>& customers)
{
    sort(customers.begin(), customers.end());

    int result = 0;
    map<string, MilliSecond> mTimeToMilli;
    for(auto& customer: customers) {
        string time = customer.substr(0, 19);
        string milli = customer.substr(20, 3);
        if(mTimeToMilli.find(time) == mTimeToMilli.end()) {
            MilliSecond second(milli, 1);
            mTimeToMilli.insert(make_pair(time, second));
            result += 1;
        } else {
            auto second = (mTimeToMilli.find(time))->second;
            if(second.milli == milli) {
                second.count++;
                result++;
            } else {
                second.milli = milli;
                second.count = 1;
            }
        }
    }
    return result;
}

int main()
{
    string str;
    vector<string> customers;
    while(getline(cin, str)) {
        customers.push_back(str);
    }
    cout << getFreeCount(customers) << endl;

    return 0;
}