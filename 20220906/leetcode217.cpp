//我的第一次尝试
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> temp;
        for(int i=0;i<nums.size();i++){
            if(temp.find(nums[i])!=temp.end())
                return true;
            else
                temp.insert(nums[i]);
        }
        return false;
    }
    //https://leetcode.cn/problems/contains-duplicate/solution/cun-zai-zhong-fu-yuan-su-by-leetcode-sol-iedd/
    //题解方法1
    //先排序，排序之后，如果前后两个数字大小相同，则说明重复
    bool bettersolution1(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0;i<n-1;i++){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }

    //题解方法2
    //插入哈希表unordered_set,若重复,则无法插入

    /* c++ std中set与unordered_set区别和map与unordered_map区别类似：
     * set基于红黑树实现，红黑树具有自动排序的功能，因此map内部所有的数据，
     * 在任何时候，都是有序的。
     * unordered_set基于哈希表，数据插入和查找的时间复杂度很低，几乎是常数时间，
     * 而代价是消耗比较多的内存，无自动排序功能。底层实现上，使用一个下标范围
     * 比较大的数组来存储元素，形成很多的桶，利用hash函数对key进行映射到不同区域进行保存。
     */

    bool bettersolution2(vector<int>& nums){
        unordered_set<int> temp;
        int n = nums.size();
        for (int i = 0;i<n;i++){
            if(temp.find(nums[i])!=temp.end())
                return true;
            else
                temp.insert(nums[i]);
        }
        return false;
    }


    
};


int main (){
    int a[] = {1,2,3,1};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    cout << solution.containsDuplicate(nums) << endl;
    cout << solution.bettersolution1(nums) << endl;
    cout << solution.bettersolution2(nums) << endl;
}