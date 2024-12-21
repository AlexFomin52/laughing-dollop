#ifndef WORK_H  
#define WORK_H  

#include <vector>  

int findMinCost(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);
int greedyAssignment(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);

#endif 