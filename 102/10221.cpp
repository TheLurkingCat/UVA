/*
    數學題
*/
#include <cmath>
#include <iomanip>
#include <iostream>
#define pi 3.1415926535897932

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    double satellite, angle, arc, chord, radius;
    char unit;
    while (cin >> satellite >> angle >> unit) {
        cin.ignore(1024, '\n');
        if (angle > 180)
            angle = 360 - angle;
        if (unit == 'm')
            angle /= 60;

        radius = 6440 + satellite;
        arc = 2 * pi * radius * angle / 360;
        chord = sqrt(2 * radius * radius * (1 - cos(pi * angle / 180)));
        cout << setprecision(6) << fixed << arc << " " << chord << "\n";
    }
}