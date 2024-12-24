/**
 * @file utilities.cpp
 * @brief Реализация функций для работы с матрицей стоимости.
 *
 * Этот файл содержит реализацию функций, описанных в utilities.h, включая чтение
 * данных из файла, расчет минимальной стоимости с помощью различных алгоритмов и запись
 * результатов в файл.
 */
#include <iostream>
#include <fstream>  
#include <vector>  
#include <limits>  
#include <algorithm>  
#include "utilities.h"  

void readFile(const std::string& filename, std::vector<std::vector<int>>& cost, int& n) {
    std::ifstream inputFile(filename);
    inputFile >> n;
    cost.resize(n, std::vector<int>(n));
    // Читаем матрицу стоимости из файла
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
    // Генерация всех перестановок и поиск минимальной стоимости 
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
    // Реализация жадного алгоритма для назначения работ
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

void writeFile(const std::string& filename, std::vector<std::vector<int>>& cost, int n, int minCostBruteForce, const std::vector<int>& assignment, int minCostGreedyAssignment, const std::vector<int>& greedyAssignmentResult, long long durationBruteForce, long long durationGreedy) {
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
    outputFile << "Execution time (Brute Force): " << durationBruteForce << " ns\n"; // Время выполнения в наносекундах
    outputFile << "Execution time (Greedy): " << durationGreedy << " ns\n"; // Время выполнения в наносекундах

    outputFile.close();
}