#include <iostream>  
#include <fstream>  
#include <vector>  
#include <limits>  
#include <algorithm>  
#include "work.h"  

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
            assignment = perm; // Обновляем назначение  
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
//сложность двух  алгоритмов описать сложность как кол-во итераций или время от таблицы