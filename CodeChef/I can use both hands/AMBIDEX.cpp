#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int L, R, M;
        cin >> L >> R >> M;

        int pages = 0, codeLines = 0;

        if(M%L == 0){
            pages = M/L;
        }
        
        else{
            pages = M/L + 1;
        }
        
        codeLines = M/R;

        cout << pages + codeLines << endl;
    }

    return 0;
}
