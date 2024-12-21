#include <iostream>  
#include <fstream>  
#include <vector>  
#include "work.h"  

int main() {

    int n;

    std::vector<std::vector<int>> cost;

    readFile("input.txt", cost, n);

    std::vector<int> assignment(n);

    int minCostBruteForce = findMinCost(cost, assignment);

    std::vector<int> greedyAssignmentResult(n);
    
    int minCostGreedy = greedyAssignment(cost, greedyAssignmentResult);
    
    writeFile("output.txt", cost, n, minCostBruteForce, assignment, minCostGreedy, greedyAssignmentResult);
    

    return 0;
}