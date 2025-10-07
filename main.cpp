#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> vec = { 1,2,3,4,5,6,7,8 };

void func(int n, int m) {
    int temp = 0;
    for (int i = m-1; i > 0; i--) {
        if (vec.at(m-i) == n - i +1) {
            vec.at(m - i - 1) += 1;
            for (int j = m - i; j < m; j++) {
                vec.at(j) = vec.at(j - 1) + 1;
            }
            temp++;
            break;
        }
    }
    if (temp == 0) {
        vec.at(m - 1) += 1;
    }
}

int main() {

    cin >> N >> M;
    vec.resize(M);

    int count = 1;
    for(int i = 1; i <= M; i++) {
        count *= (N - i + 1);
    }
    for (int i = 1; i <= M; i++) {
        count /= i;
    }
    for (int i = 0; i < count-1; i++) {
        for (auto& j : vec) {
            cout << j << " ";
        }
        cout << endl;
        func(N, M);
    }

    return 0;
}
