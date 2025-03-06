#include <iostream>

#define WIDTH 6
#define HEIGHT 6
int array[WIDTH][HEIGHT];

using std::cin;
using std::cout;
    
int main()
{
    for(size_t i = 0; i < WIDTH; i++)
    {
        for(size_t j = 0; j < HEIGHT; j++)
        {
            cin >> array[j][i];
        }
    }
    int max = -100000000;
    for(size_t i = 0; i < WIDTH - 2; i++)
    {
        for(size_t j = 0; j < HEIGHT - 2; j++)
        {
            // Hourglass starts with (i, j)
            int csum = array[i][j] + array[i + 1][j] + array[i + 2][j]
                + array[i + 1][j + 1]
                + array[i][j + 2] + array[i + 1][j + 2] + array[i + 2][j + 2];
            if(csum > max) max = csum;
        }
    }
    std::cout << max;
}

/*
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
*/