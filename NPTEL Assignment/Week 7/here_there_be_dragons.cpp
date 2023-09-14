#include <iostream>
#include <vector>
using std::vector, std::endl, std::cout, std::cin;

int minDist();

int main(){
    int R, C, D, K;
    cin >> R >> C >> K >> D;

    vector<vector<bool>>grid(R, vector<bool>(C, false));
    vector<bool> pos(R, false);

    for(int i=0; i<D; i++){
        int r, c;
        cin >> r >> c;
        grid[r][c] = true;
        pos[r] = true;
    }

    return 0;
}