/*
    BFS
    時間複雜度: O(N)
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n_employee, n_source, source, n_friend, friends, n_notice, day_now;
    queue<pair<int, int>> spreading;

    while (cin >> n_employee) {
        vector<vector<int>> adjadency_list(n_employee);

        for (int i = 0; i < n_employee; i++) {
            cin >> n_friend;
            while (n_friend--) {
                cin >> friends;
                adjadency_list[i].emplace_back(friends);
            }
        }

        cin >> n_source;
        while (n_source--) {
            cin >> source;

            if (adjadency_list[source].empty())
                cout << "0\n";
            else {
                vector<bool> unvisited(n_employee, true);
                vector<int> noticed;
                noticed.reserve(n_employee);

                day_now = n_notice = 0;
                unvisited[source] = false;
                spreading.push(make_pair(source, 0));

                while (!spreading.empty()) {
                    pair<int, int>& now = spreading.front();
                    spreading.pop();

                    if (day_now == now.second) {
                        noticed.emplace_back(n_notice);
                        n_notice = 0;
                        day_now++;
                    }

                    for (const int& n : adjadency_list[now.first])
                        if (unvisited[n]) {
                            unvisited[n] = false;
                            spreading.push(make_pair(n, day_now));
                            n_notice++;
                        }
                }

                vector<int>::iterator&& it = max_element(noticed.begin(), noticed.end());
                cout << *it << " " << distance(noticed.begin(), it) << "\n";
            }
        }
    }
}