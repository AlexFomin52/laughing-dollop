#include <iostream>  
#include <fstream>  
#include <vector>  
#include <limits>  
#include <algorithm>  
#include "work.h"  

void readFile(const std::string& filename, std::vector<std::vector<int>>& cost, int& n) {
    std::ifstream inputFile(filename);
    inputFile >> n;
    cost.resize(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> cost[i][j];
        }
    }
    inputFile.close();
}

int findMinCost(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment) {
    int n = cost.size();
    int minCost = std::numeric_limits<int>::max();
    std::vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }

    do {
        int currentCost = 0;
        for (int i = 0; i < n; ++i) {
            currentCost += cost[i][perm[i]];
        }
        if (currentCost < minCost) {
            minCost = currentCost;
            assignment = perm; 
        }
    } while (std::next_permutation(perm.begin(), perm.end()));

    return minCost;
}

int greedyAssignment(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment) {
    int n = cost.size();
    std::vector<bool> assigned(n, false);
    int totalCost = 0;

    for (int i = 0; i < n; ++i) {
        int minCost = std::numeric_limits<int>::max();
        int jobIndex = -1;

        for (int j = 0; j < n; ++j) {
            if (!assigned[j] && cost[i][j] < minCost) {
                minCost = cost[i][j];
                jobIndex = j;
            }
        }

        assignment[i] = jobIndex;
        assigned[jobIndex] = true;
        totalCost += minCost;
    }

    return totalCost;
}

void writeFile(const std::string& filename, std::vector<std::vector<int>>& cost, int n, int minCostBruteForce, const std::vector<int>& assignment, int minCostGreedyAssignment, const std::vector<int>& greedyAssignmentResult) {
    std::ofstream outputFile(filename);
    outputFile << "Brute force:\n";
    outputFile << "Minimal cost: " << minCostBruteForce << "\n";
    outputFile << "Workers arrangement: ";
    for (int i = 0; i < n; ++i) {
        outputFile << "Worker " << i + 1 << " job " << assignment[i] + 1 << "\n";
    }
    outputFile << "\nGreedy algorithm:\n";
    outputFile << "Minimal cost: " << minCostGreedyAssignment << "\n";
    outputFile << "Assignments: ";
    for (int i = 0; i < n; ++i) {
        outputFile << "Worker " << i + 1 << " job " << greedyAssignmentResult[i] + 1 << "\n";
    }

    outputFile.close();
}