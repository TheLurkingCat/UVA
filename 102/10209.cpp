/*
    數學題
*/
#include <iomanip>
#include <iostream>
#define pi 3.1415926535897932
#define sqrt_3 1.7320508075688773

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    double edge, striped, dotted, rest;
    while (cin >> edge) {
        double area = edge * edge;
        rest = area * (4 - 2 * pi / 3 - sqrt_3);
        dotted = (4 - pi) * area - 2 * rest;
        striped = area - dotted - rest;
        cout << setprecision(3) << fixed << striped << " " << dotted << " " << rest << "\n";
    }
}