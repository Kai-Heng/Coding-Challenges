/**
 * Given a grid of robot position, indicate if it is a valid time series
 * for the number of robots specified if robots can only travel up to 1 index
 * further than their position 1 step before.
 * 
 * Input format: an array of arrays of which each index can be 0 or 1.
 * An index corresponds to the physical location which is either occupied by a robot (1) or empty (0)
 * 
 * Ex:
 * Grid: [[1,0,0,1], [0,1,1,0]] is a valid time series for 2 robots because the first robot
 * moved from index 0 to index 1 and robot 2 moved from index 3 to index 2
 * 
 * Grid: [[1,0,0,0,1], [1,0,1,0,0]] is not valid because the second robot started at index 4 but
 * did not have a valid position on the next step
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool validatePath(vector<vector<int>> grid){
    for(int i = 0; i < grid.size() - 1; i++){
        int robot_count = 0;
        int next_grid_robot = 0;
        int last_index = -1;
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1){
                robot_count++;
                if(last_index < j - 1 && j > 0 && grid[i+1][j-1] == 1){
                    last_index = j - 1;
                }
                else if(last_index < j && grid[i+1][j] == 1){
                    last_index = j;
                }
                else if(last_index < j + 1 && j < grid[i].size() - 1 && grid[i+1][j+1] == 1){
                    last_index = j + 1;
                }
                else{
                    return false;
                }
                // if(j == 0 && !(grid[i][j] == grid[i+1][j+1] || grid[i][j] == grid[i+1][j])){
                //     return false;
                // }
                // else if(j == grid[i].size() - 1 && !(grid[i][j] == grid[i+1][j-1] || grid[i][j] == grid[i+1][j])) return false;
                // else if (!(grid[i][j] == grid[i+1][j-1] || grid[i][j] == grid[i+1][j+1] || grid[i][j] == grid[i+1][j])) return false;
            }
            if(grid[i+1][j] == 1){
                next_grid_robot++;
            }
        }

        if(robot_count != next_grid_robot){
            return false;
        }
    }


    return true;
}

int main(){
    // vector<vector<int>> grid = {{1,0,0,1}, {0,1,1,0}};
    //vector<vector<int>> grid = {{1,0,0,0,1}, {1,0,1,0,0}};

    vector<vector<vector<int>>> test_cases = {
        {{1,0,0,1}, {0,1,1,0}}, // Valid
        {{1,0,0,0,1}, {1,0,1,0,0}}, // Invalid
        {{1,0,0}, {1,0,0}}, // Valid, no movement
        {{1,0,0}, {0,0,1}}, // Invalid, jump too far
        {{1,0,1}, {1,0,1}}, // Valid, stationary
        {{1,0,1}, {0,1,0}}, // Invalid, only one position can be occupied by one robot
        {{1,1,0}, {0,1,1}}, // Valid, more robots than original
        {{0,0,0}, {0,1,0}}, // Invalid, robot appears out of nowhere
        {{1,0,1}, {0,0,1}}, // Invalid, a robot disappears
        {{1}, {1}}, // Valid, single column, single robot
        {{1}}, // Valid, single step
        {{0,0,0}, {0,0,0}}, // Valid, no robots
        {{1,0,0,0,0,1}, {0,1,0,0,1,0}}, // Valid, slow movement
        {{1,0,0,0,0,0,0,1}, {0,1,0,0,0,1,0,0}}, // Valid large grid
        {{1,0,0,0,1}, {0,0,1,0,0}}, // Invalid, robot disappears

        // Large grid cases
        {{1,0,0,0,0,0,0,1,0,0}, {0,1,0,0,0,0,1,0,0,0}, {0,0,1,0,0,1,0,0,0,0}}, // Valid large grid, slow movement
        {{1,0,0,1,0,0,0,1}, {0,1,0,0,1,0,0,1}, {0,0,1,0,0,1,0,0}}, // Invalid, multiple robots moving in sync
        {{1,0,0,0,1,0,0,1}, {0,1,0,1,0,0,1,0}, {0,0,1,0,1,0,0,1}}, // Valid, staggered movement
        
        // More robots cases
        {{1,1,1,0,0,0,1,1}, {0,1,1,1,0,1,0,1}, {0,0,1,1,1,0,1,0}}, // Invalid, one robot disappears
        {{1,1,1,0,0,1,1,0}, {0,0,1,1,1,0,0,1}, {1,0,0,1,0,1,1,0}}, // Invalid, one robot jumps too far
        
        // Edge cases with disappearing robots
        {{1,0,1,0,1}, {0,1,0,1,0}, {1,0,1,0,0}}, // Invalid, one robot disappears
        {{1,0,1,0,0}, {0,1,0,1,0}, {0,0,1,0,1}}, // Valid, alternating movements
        
        // Large grid with random gaps
        {{1,0,0,1,0,0,1,0,0,1}, {0,1,0,0,1,0,0,1,0,0}, {0,0,1,0,0,1,0,0,1,0}}, // Invalid, staggered movements
        {{1,0,0,1,1,0,1}, {1,1,1,0,0,1,0}},
    };

    for(vector<vector<int>> grid : test_cases){
        if(validatePath(grid)){
            cout << "True" << endl;
        }
        else{
            cout << "False" << endl;
        }
    }
    

    return 0;
}