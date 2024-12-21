#ifndef WORK_H  
#define WORK_H  

#include <vector>  
void readFile(const std::string& filename, std::vector<std::vector<int>>& cost, int& n);
int findMinCost(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);
int greedyAssignment(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);
void writeFile(const std::string& filename, std::vector<std::vector<int>>& cost, int n, int minCostBruteForce, const std::vector<int>& assignment, int minCostGreedyAssignment, const std::vector<int>& greedyAssignmentResult);
#endif 