#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;

vector<int> dfs(vector<vector<int>> & land, unordered_set<string> & coord ,int i, int j){
    stack<pair<int, int>> stack;
    stack.push({i, j});
    coord.insert(to_string(i) + "," + to_string(j));
    
    int minRow = i, minCol = j;
    int maxRow = x, maxCol = y;
    
    while(!stack.empty()){
        auto current = stack.top();
        stack.pop();
        int curX = current.first;
        int curY = current.second;

        vector<pair<int, int>> direc = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        
        for (auto& dir : direc)
        {
            int nx = curX + dir.first;
            int ny = curY + dir.second;

            if (nx >= 0 && nx < land.size() && ny >= 0 && ny < land[0].size() &&
                    land[nx][ny] == 1 && visited.find(to_string(nx) + "," + to_string(ny)) == visited.end()) {
                    visited.insert(to_string(nx) + "," + to_string(ny));
                    stack.push({nx, ny});
                    minRow = min(minRow, nx);
                    minCol = min(minCol, ny);
                    maxRow = max(maxRow, nx);
                    maxCol = max(maxCol, ny);
            }

        }
        

    }
}
vector<vector<int>> findFarmLand(vector<vector<int>> & land){

    /*
        Solve 1: w/ depth first search
        [1,0,0],
        [0,1,1],
        [0,1,1]
    */
    vector<vector<int>> farms;
    unordered_set<string> coord;

    for (int i = 0; i < (int)land.size(); i++)
    {
        for (int j = 0; j < (int)land[0].size(); j++)
        {
            if (land[i][j] == 1 && coord.find(to_string(i) + "," + to_string(j))){
                vector<int> bounds = dfs(land, coord, i, j);
                farms.push_back(bounds);
            }
        }        
    }
    return farms;
}


int main(){
    vector<vector<int>> land = {
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1}
    };

    findFarmLand(land);
    
    return 0;
}