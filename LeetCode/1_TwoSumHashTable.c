#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution
{
public:
    vector<int> twoSum(vector<int> numbers, int target)
    {
        unordered_map<int, int> map;
        for(size_t i = 0; i < numbers.size(); i++)
        {
            map[numbers[i]] = i;
        }
        
        for(size_t i = 0; i < numbers.size(); i++)
        {
            auto search = map.find(target - numbers[i]);
            if(search != map.end() && search->second != i)
            {
                vector<int> ret;
                ret.push_back(i);
                ret.push_back(search->second);
                return ret;
            }
        }
        
        vector vec;
        return vec;
    }
};

int main()
{
    return 0;
}