#include <bits/stdc++.h>
using namespace std;
//
// Created by Steve on 2021/10/28.
//

/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element
twice.
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]

在数组中找到 2 个数之和等于给定值的数字，结果返回 2 个数字在数组中的下标。
*/
class TwoSum {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        //使用hash存储 ,查询时间复杂度O(1)
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            //1.找到和为target的另一个数的值
            int pair = target - nums[i];
            //2.map中查询pair的索引是否存在
            if (m.count(pair)) {
                return {i, m[target - nums[i]]};
            }
            //3.map中找不到pair则将当前数字与索引放入map以便下次查询
            m[nums[i]] = i;
        }
        return {};
    }
};

