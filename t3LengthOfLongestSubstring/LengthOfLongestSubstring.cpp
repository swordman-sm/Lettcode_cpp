#include <bits/stdc++.h>

using namespace std;

//
// Created by Steve on 2021/11/3.
//
class LengthOfLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        //使用hash存储 ,查询时间复杂度O(1)
        unordered_map<char, int> m;
        int length = 0;
        for (int start = 0, end = 0; end < s.length(); end++) {
            char &ce = s[end];
            if (m.count(ce)) {
                start = max(start, m[ce]);
            }
            length = max(length, end - start + 1);
            m[ce] = end + 1;
        }
        return length;
    }

};
