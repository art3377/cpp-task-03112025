 #include <iostream>
#include <vector>
#include <stack>

int minimal_costumes(int N, int M, const std::vector<int>& parties) {
    std::stack<int> stk;
    int costumes_count = 0;

    for (int costume_type : parties) {
        // Remove costumes if the top one does not fit the party
        while (!stk.empty() && stk.top() != costume_type) {
            stk.pop();
        }
        // If there is no suitable costume on top, put on a new one
        if (stk.empty() || stk.top() != costume_type) {
            stk.push(costume_type);
            costumes_count++;
        }
    }

    return costumes_count;
}

int main() {
    int N, M;
    std::cout << "Welcome to the Halloween Party Costume Planner!\n";
    std::cout << "Please enter two integers (N and M):\n";
    std::cout << "- N (number of parties, 2 <= N < 100)\n";
    std::cout << "- M (number of costume types, 2 <= M < 100)\n";
    std::cout << "Example: 5 3\n";
    std::cin >> N >> M;

    if (N < 2 || N >= 100 || M < 2 || M >= 100) {
        std::cout << "Error: N and M must satisfy 2 <= N < 100, 2 <= M < 100.\n";
        return 1;
    }

    std::vector<int> parties(N);
    std::cout << "Now enter " << N << " integers for party costume types (from 1 to " << M << "):\n";
    std::cout << "Example: 1 2 3 2 1\n";
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

