#include <iostream>
#include <vector>

using namespace std;


bool validPath(int n, vector<vector<int>> & edges, int source, int destination) {

        /*
            Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
            Output: true
            Explanation: There are two paths from vertex 0 to vertex 2:
            - 0 → 1 → 2
            - 0 → 2

            Solve 1:
            [0,1]*,
            [1,2],
            [2,0]
        */

        vector<bool> visited (n, false);
        visited[source] = true;

        bool trig {true};
        while(trig){
            trig = false;
            for (const vector<int> & edge : edges){
                cout << "visited[edge[0]] " << visited[edge[0]] << "; visited[edge[1]] " << visited[edge[1]] << endl;
                cout << "edge - [" << edge[0] << "]" << "[" << edge[1] << "]" << endl;
                if(visited[edge[0]] != visited[edge[1]]){
                    visited[edge[0]] = true;
                    visited[edge[1]] = true;
                    trig = true;
                }
                cout << "xxxx - visited[edge[0]] " << visited[edge[0]] << "visited[edge[1]]" << visited[edge[1]] << endl;
                cout << "xxxx - edge[0] - " << edge[0] << " edge[1]" << edge[1] << endl;
                if (visited[destination])
                {
                    return true;
                }

            }
        }
        return false;
}


int main(){
    int src {0};
    int dst {2};
    int n {3};

    vector<vector<int>> edge {
        {0, 1},
        {1, 2},
        {2, 0}
    };
    

    auto x = validPath(n, edge, src, dst);
    cout << x << endl;

    return 0;
}