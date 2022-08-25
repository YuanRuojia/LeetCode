#include "L733.h"

/*
3 3
1 1 1 1 1 0 1 0 1
1 1 2
2 3
0 0 0 0 0 0
0 0 2
*/

void L733::test() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> image;
    for (int i = 0; i < x; i++) {
        vector<int> temp;
        for (int j = 0; j < y; j++) {
            int pix;
            cin >> pix;
            temp.emplace_back(pix);
        }
        image.emplace_back(temp);
    }

    int sr, sc, color;
    cin >> sr >> sc >> color;
    image = floodFill(image, sr, sc, color);
    cout << "done";
}

vector<vector<int>> L733::floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    int xlen = image.size();
    int ylen = image[0].size();
    int original = image[sr][sc];

    queue < pair<int, int> > fitpoints;
    pair<int, int> p(sr, sc);
    fitpoints.push(p);
    int visited = 0;
    while (!fitpoints.empty() && visited <= xlen * ylen) {
        pair<int, int> point = fitpoints.front();
        fitpoints.pop();
        visited++;

        image[point.first][point.second] = color;
        
        if (point.first - 1 >= 0 && image[point.first - 1][point.second] == original) { // ио
            fitpoints.push(make_pair(point.first - 1, point.second));
            image[point.first - 1][point.second] = color;
        }
        if (point.first + 1 < xlen && image[point.first + 1][point.second] == original) { // об
            fitpoints.push(make_pair(point.first + 1, point.second));
            image[point.first + 1][point.second] = color;
        }
        if (point.second - 1 >= 0 && image[point.first][point.second - 1] == original) { // вС
            fitpoints.push(make_pair(point.first, point.second - 1));
            image[point.first][point.second - 1] = color;
        }
        if (point.second + 1 < ylen && image[point.first][point.second + 1] == original) { // ср
            fitpoints.push(make_pair(point.first, point.second + 1));
            image[point.first][point.second + 1] = color;
        }
    }

    return image;
}
