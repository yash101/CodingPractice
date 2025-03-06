#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
    
int main()
{
    int n, rot;
    cin >> n;
    cin >> rot;
    
    vector<int> vec;
    vec.reserve(n);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    rot = rot % n;
    
    vector<int> temp;
    temp.reserve(rot);
    
    // Put the first n_rot values into a temporary array
    for(size_t i = 0; i < rot; i++)
    {
        temp[i] = vec[i];
    }

    // Pull each value to the left, rot spaces
    for(size_t i = 0; i < vec.size() - rot; i++)
    {
        vec[i] = vec[i + rot];
    }
    
    int k = 0;
    for(size_t i = vec.size() - 1; i > vec.size() - rot - 1; i--)
    {
        vec[i] = temp[rot - k++ - 1];
    }
        
    for(size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    
    return 0;
}