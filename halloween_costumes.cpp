// File name: halloween_costumes.cpp

#include <iostream>
#include <vector>

int minimal_costumes(int N, int M, const std::vector<int>& parties) {
    std::vector<int> costumes_prep(M + 1, 0); // Amount of purchased costumes for each type
    std::vector<int> stack; // Current stack of worn costumes

    for (int i = 0; i < N; ++i) {
        int type = parties[i];

        // Check if the required costume type is already on top
        if (!stack.empty() && stack.back() == type) {
            // Costume of the required type is already on top, do nothing
        } else {
            // Look for the required type deeper in the stack, remove costumes above it if present
            int pos = -1;
            for (int j = (int)stack.size() - 1; j >= 0; --j) {
                if (stack[j] == type) {
                    pos = j;
                    break;
                }
            }
            if (pos != -1) {
                // Remove all costumes above the found position
                stack.erase(stack.begin() + pos + 1, stack.end());
            } else {
                // Costume of required type is not present, purchase a new one
                costumes_prep[type]++;
            }
            // Put the required type on top of the stack
            stack.push_back(type);
        }
    }
    int total = 0;
    for (int i = 1; i <= M; ++i) total += costumes_prep[i];
    return total;
}

int main() {
    int N, M;
    std::cout << "Welcome to the Halloween Costume Calculator!\n";
    std::cout << "Please enter two integers separated by a space:\n";
    std::cout << "N - number of parties (2 <= N < 100)\n";
    std::cout << "M - number of costume types (2 <= M < 100)\n";
    std::cout << "Example: 7 3\n";
    std::cin >> N >> M;

    if (N < 1 || N > 100 || M < 1 || M > 100) {
        std::cout << "Error: N and M must satisfy 1 <= N <= 100, 1 <= M <= 100.\n";
        return 1;
    }

    std::vector<int> parties(N);
    std::cout << "Now enter the sequence of costumes for each party, separated by spaces:\n";
    std::cout << "(each value should be an integer between 1 and " << M << ")\n";
    std::cout << "Example: 1 2 1 1 3 2 1\n";
    for (int i = 0; i < N; i++) {
        std::cin >> parties[i];
        if (parties[i] < 1 || parties[i] > M) {
            std::cout << "Error: Costume type must be between 1 and " << M << ".\n";
            return 1;
        }
    }

    int result = minimal_costumes(N, M, parties);

    std::cout << "Minimum number of costumes required: " << result << std::endl;

    return 0;
}