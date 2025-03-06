#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::size_t> map;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string buf;
        std::cin >> buf;
        map[buf]++;
    }
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string buf;
        std::cin >> buf;
        std::cout << map[buf] << std::endl;
    }
    return 0;
}