#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};


// 1st solution O(m*n)
void setZeroes(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    std::unordered_set<int> setRow;
    std::unordered_set<int> setCol;

    //std::unordered_map<std::pair<int, int>, int, pair_hash> map; 
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                setRow.insert(i);
                setCol.insert(j);
            }
        }
    }
    for (size_t i = 0; i < n; ++i){
        for (size_t j = 0; j < m; ++j){
            if (setRow.contains(i)){
                matrix[i][j] = 0;   
            }
            if (setCol.contains(j)){
                for (size_t x = 0; x < m; ++x){
                    matrix[x][j] = 0;
                }  
            }        
        }
    }
}

// 2ns solution w/ out unordered set
void setZeros(std::vector<std::vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<int>> visited = matrix; 
    for (size_t i = 0; i < n; ++i){
        for (size_t j = 0; j < m; ++j){
            if (matrix[i][j] == 0){
                for (size_t x = 0; x < m; ++x)
                {
                    visited[i][x] = 0;
                }  
            }
        }
    }
    for (size_t i = 0; i < n; ++i){
        for (size_t j = 0; j < m; ++j){
            if (matrix[i][j] == 0){
                for (size_t x = 0; x < n; ++x){
                    visited[x][j] = 0;
                } 
            }
        }
    }
    for (size_t i = 0; i < n; ++i){
        for (size_t j = 0; j < m; ++j){
            matrix[i][j] = visited[i][j];
        }
    }
}


int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    setZeroes(matrix);
}
