#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> vec1(N);
    std::vector<int> vec2(M);

    for (int i = 0; i < N; i++) {
        std::cin >> vec1[i];
    }

    for (int i = 0; i < M; i++) {
        std::cin >> vec2[i];
    }

    if (std::is_sorted(vec1.begin(), vec1.end()) && std::is_sorted(vec2.begin(), vec2.end())) {
        std::vector<int> merged(N + M);
        std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), merged.begin());

        for (int i = 0; i < N + M; i++) {
            std::cout << merged[i] << " ";
        }
    } else {
        if (N > M) {
            std::reverse(vec1.begin(), vec1.end());
            for (int i = 0; i < N; i++) {
                std::cout << vec1[i] << " ";
            }
        } else {
            std::reverse(vec2.begin(), vec2.end());
            for (int i = 0; i < M; i++) {
                std::cout << vec2[i] << " ";
            }
        }
    }

    return 0;
}