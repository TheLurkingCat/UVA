/*
    佇列
    時間複雜度(ENQUEUE): O(1)
    時間複雜度(DEQUEUE): O(1)
*/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, n, scenario = 1, n_teammate, id, team_number;
    string str;

    while (cin >> n && n) {
        unordered_map<int, int> team;
        queue<queue<int>> team_queue;
        vector<queue<int>*> team_position(n, NULL);

        // 建立 team 表(編號對應組別)
        for (i = 0; i < n; i++) {
            cin >> n_teammate;
            while (n_teammate-- && cin >> id)
                team[id] = i;
        }

        cout << "Scenario #" << scenario++ << "\n";

        while (cin >> str && str != "STOP") {
            if (str == "DEQUEUE") {
                cout << team_queue.front().front() << "\n";                  // 最前面的元素是第一組的第一人
                if (team_queue.front().size() == 1) {                        // 那一組要沒人了
                    team_position[team[team_queue.front().front()]] = NULL;  // 新的組員沒有預設位置
                    team_queue.pop();                                        // 整組刪掉
                } else                                                       // 如果人還很多
                    team_queue.front().pop();                                // 第一個離開就好
            } else {
                cin >> id;
                team_number = team[id];
                if (team_position[team_number] == NULL) {             // 新的一組進來
                    team_queue.push(queue<int>({id}));                // 按照規則排最後
                    team_position[team_number] = &team_queue.back();  // 紀錄這組的位置
                } else                                                // 已經有組員了
                    team_position[team_number]->push(id);             // 插隊
            }
        }
        cout << "\n";
    }
}