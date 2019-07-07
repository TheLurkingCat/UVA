/*
    矩陣快速冪
*/
#include <iostream>
#include <vector>

using namespace std;

int mod;

class matrix {
   public:
    vector<vector<long long>> mat;

    matrix(vector<vector<long long>>& d) {
        mat = d;
    }
    matrix(int a, int b, int c, int d) {
        mat = vector<vector<long long>>(2, vector<long long>(2, 0));
        mat[0][0] = a;
        mat[0][1] = b;
        mat[1][0] = c;
        mat[1][1] = d;
    }
    matrix operator*(const matrix& other) {
        vector<vector<long long>> temp(2, vector<long long>(2, 0));
        temp[0][0] = (mat[0][0] * other.mat[0][0] % mod + mat[0][1] * other.mat[1][0] % mod) % mod;
        temp[0][1] = (mat[0][0] * other.mat[0][1] % mod + mat[0][1] * other.mat[1][1] % mod) % mod;
        temp[1][0] = (mat[1][0] * other.mat[0][0] % mod + mat[1][1] * other.mat[1][0] % mod) % mod;
        temp[1][1] = (mat[1][0] * other.mat[0][1] % mod + mat[1][1] * other.mat[1][1] % mod) % mod;
        return matrix(temp);
    }
    matrix operator^(int exp) {
        matrix ret(1, 0, 0, 1);
        while (exp) {
            if (exp & 1)
                ret = ret * *this;
            *this = *this * *this;
            exp >>= 1;
        }
        return ret;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0)
            cout << "0\n";
        else {
            mod = 1 << m;
            cout << ((matrix(1, 1, 1, 0) ^ (n - 1)) * matrix(1, 1, 1, 1)).mat[1][1] << "\n";
        }
    }
}