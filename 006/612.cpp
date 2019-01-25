/*
    排序
    時間複雜度: O(N^2)
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second < b.second;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_case, n_dna, i, j, dna_length, unsortedness;

    string str;
    cin >> n_case;
    while (n_case--) {
        cin >> dna_length >> n_dna;
        vector<pair<string, int>> dna;
        dna.reserve(n_dna);

        while (n_dna--) {
            unsortedness = 0;
            cin >> str;

            for (i = 0; i < dna_length; i++)
                for (j = i + 1; j < dna_length; j++)
                    if (str[i] > str[j])
                        unsortedness++;

            dna.push_back(make_pair(str, unsortedness));
        }

        stable_sort(dna.begin(), dna.end(), compare);

        for (const pair<string, int> &dna_data : dna)
            cout << dna_data.first << "\n";

        if (n_case)
            cout << "\n";
    }

    return 0;
}