#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int n;
    infile >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        infile >> points[i].x >> points[i].y;
    }

    double min_distance = numeric_limits<double>::max();
    Point min_point1, min_point2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double current_distance = distance(points[i], points[j]);
            if (current_distance < min_distance) {
                min_distance = current_distance;
                min_point1 = points[i];
                min_point2 = points[j];
            }
        }
    }

    outfile << "Minimum distance: " << min_distance << endl;
    outfile << "First point: (" << min_point1.x << ", " << min_point1.y << ")" << endl;
    outfile << "Second point: (" << min_point2.x << ", " << min_point2.y << ")" << endl;

    infile.close();
    outfile.close();

    return 0;
}
