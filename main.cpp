#include <iostream>  
#include <fstream>  
#include <vector>  
#include "work.h"  

int main() {
    std::ifstream inputFile("input1.txt");
    std::ofstream outputFile("output1.txt");
    int n;
    inputFile >> n;

    std::vector<std::vector<int>> cost(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> cost[i][j];
        }
    }

    std::vector<int> assignment(n);

    // Полный перебор  
    int minCostBruteForce = findMinCost(cost, assignment);
    outputFile << "Brute force:\n";
    outputFile << "Minimal cost: " << minCostBruteForce << "\n";
    outputFile << "Workers arrangement: ";
    for (int i = 0; i < n; ++i) {
        outputFile << "Worker " << i + 1 << " job " << assignment[i] + 1 << "\n";
    }

    // Жадный алгоритм  
    std::vector<int> greedyAssignmentResult(n);
    int minCostGreedy = greedyAssignment(cost, greedyAssignmentResult);
    outputFile << "\nGreedy algorithm:\n";
    outputFile << "Minimal cost: " << minCostGreedy << "\n";
    outputFile << "Assignments: ";
    for (int i = 0; i < n; ++i) {
        outputFile << "Worker " << i + 1 << " job " << greedyAssignmentResult[i] + 1 << "\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}