#include <vector>

using std::vector;
using std::size_t;

class Solution
{
private:
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> ret;
        ret.reserve(2);
        size_t size = numbers.size();
        for(size_t i = 0; i < size; i++)
        {
            for(size_t j = 0; j < size; j++)
            {
                if(j == i) continue;
                if(numbers[i] + numbers[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        
        return ret;
    }
};

int main()
{
    return 0;
}