#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
    int N, M;
    int res = 0;
    cin >> N >> M;
    
    vector<vector<int>> map(N);
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            map[i].push_back(temp);
        }
    }

    //****
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M - 4; j++) {
            int temp = 0;
            temp += map[i][j]; temp += map[i][j+1]; temp += map[i][j+2]; temp += map[i][j+3];
            res = (res > temp) ? res : temp;
        }
    }

    /*
        *
        *
        * 
        * 
    */
    for (int i = 0; i <= N-4; i++) {
        for (int j = 0; j < M; j++) {
            int temp = 0;
            temp += map[i][j]; temp += map[i+1][j]; temp += map[i+2][j]; temp += map[i + 3][j];
            res = (res > temp) ? res : temp;
        }
    }

    /*
        **
        **
    */
    for (int i = 0; i <= N -2; i++) {
        for (int j = 0; j <= M-2; j++) {
            int temp = 0;
            temp += map[i][j]; temp += map[i + 1][j]; temp += map[i][j+1]; temp += map[i + 1][j+1];
            res = (res > temp) ? res : temp;
        }
    }

    







    for (int i = 0; i <= N - 2; i++) {
        for (int j = 0; j <= M - 3; j++) {
            /*
                *
                ***
            */
            int temp = 0;
            temp += map[i][j]; temp += map[i + 1][j]; temp += map[i+1][j + 1]; temp += map[i + 1][j + 2];
            res = (res > temp) ? res : temp;
            /*
                  *
                ***
            */
            temp = 0;
            temp += map[i][j+2]; temp += map[i + 1][j]; temp += map[i + 1][j + 1]; temp += map[i + 1][j + 2];
            res = (res > temp) ? res : temp;
            /*
                ***
                  *
            */
            temp = 0;
            temp += map[i][j]; temp += map[i][j + 1]; temp += map[i][j + 2]; temp += map[i + 1][j + 2];
            res = (res > temp) ? res : temp;
            /*
               ***
               *
           */
            temp = 0;
            temp += map[i][j]; temp += map[i][j + 1]; temp += map[i][j + 2]; temp += map[i + 1][j];
            res = (res > temp) ? res : temp;


            /*
                 **
                **
            */
            temp = 0;
            temp += map[i + 1][j]; temp += map[i + 1][j + 1]; temp += map[i][j + 1]; temp += map[i][j + 2];
            res = (res > temp) ? res : temp;
            /*
                **
                 **
            */
            temp = 0;
            temp += map[i][j]; temp += map[i][j + 1]; temp += map[i+1][j + 1]; temp += map[i + 1][j + 2];
            res = (res > temp) ? res : temp;


            /*
                ***
                 *
            */
            temp = 0;
            temp += map[i][j]; temp += map[i][j + 1]; temp += map[i][j + 2]; temp += map[i + 1][j + 1];
            res = (res > temp) ? res : temp;
            /*
                 *
                ***
            */
            temp = 0;
            temp += map[i][j +1]; temp += map[i + 1][j]; temp += map[i + 1][j + 1]; temp += map[i + 1][j + 2];
            res = (res > temp) ? res : temp;

            
        }
    }
    




    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= M - 2; j++) {
            /*
                **
                *
                *
            */
            int temp = 0;
            temp += map[i][j]; temp += map[i + 1][j]; temp += map[i][j + 1]; temp += map[i + 2][j];
            res = (res > temp) ? res : temp;
            /*
                **
                 *
                 *
            */
            temp = 0;
            temp += map[i][j]; temp += map[i + 1][j+1]; temp += map[i][j + 1]; temp += map[i + 2][j+1];
            res = (res > temp) ? res : temp;
            /*
                 *
                 *
                **
            */
            temp = 0;
            temp += map[i][j+1]; temp += map[i + 1][j+1]; temp += map[i+2][j]; temp += map[i + 2][j+1];
            res = (res > temp) ? res : temp;
            /*
               *
               *
               **
           */
            temp = 0;
            temp += map[i][j]; temp += map[i + 1][j]; temp += map[i + 2][j]; temp += map[i + 2][j + 1];
            res = (res > temp) ? res : temp;


            /*
                 *
                **
                *
            */
            temp = 0;
            temp += map[i][j+1]; temp += map[i + 1][j]; temp += map[i + 1][j + 1]; temp += map[i + 2][j];
            res = (res > temp) ? res : temp;
            /*
                *
                **
                 *
            */
            temp = 0;
            temp += map[i][j]; temp += map[i + 1][j]; temp += map[i + 1][j + 1]; temp += map[i + 2][j + 1];
            res = (res > temp) ? res : temp;

            /*
               *
               **
               *
           */
            temp = 0;
            temp += map[i][j]; temp += map[i + 1][j]; temp += map[i + 1][j + 1]; temp += map[i + 2][j];
            res = (res > temp) ? res : temp;
            /*
                *
               **
                *
           */
            temp = 0;
            temp += map[i][j+1]; temp += map[i + 1][j]; temp += map[i + 1][j + 1]; temp += map[i + 2][j + 1];
            res = (res > temp) ? res : temp;
        }
    }

    
    cout << res;
    

    return 0;
}