#include <vector>
#include <unordered_map>

using namespace std;

//暴力解法：（我写的
//嵌套遍历数组，尝试找到解

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result;
        for(int i = 0; i<size; i++){
            for(int j = i+1; j<size;j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

//优雅的解法：
/**
 * @brief 考虑不同数据结构的特性，使用哈希表来降低查找的时间复杂度
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};