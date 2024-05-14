#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void dfs(int i, int j, vector<vector<char>> & grid){
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1'){
        return;
    }

    grid[i][j] = '0';  // делаем марку что мы здесь уже прошли
    dfs(i+1, j, grid); // нижняя клетка
    dfs(i-1, j, grid); // вверхняя клетка
    dfs(i, j+1, grid); // правая клетка
    dfs(i, j-1, grid); // левая клекта
}

int numIsIslands(vector<vector<char>> & grid){
    /*
        Solve 1: depth first search
        поиск в глубину
        рекурсивный вызов методов проверки.
    */

    int countOfIsland {0};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j] == '1'){
                countOfIsland++;
                dfs(i, j, grid);
            }
        }       
    }
    return countOfIsland;
}

int main(int argc, char * argv[]){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int x = numIsIslands(grid);

    cout << x << endl;

    return 0;
}