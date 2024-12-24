/**
 * @file main.cpp
 * @brief �������� ��������� ��� ������� ����������� ��������� ������������� �����.
 *
 * ��������� ������ ������� ��������� �� �����, ��������� ��� ������� ������������� �����
 * (������ �������� � ����� ������� ��������) � ���������� ���������� � �������� ����,
 * ������� ����� ���������� ������� ������.
 */

 // ���������� ����������� ����������
#include <iostream>  
#include <fstream>  
#include <vector>  
#include <ctime>
#include <chrono>
#include "utilities.h"  

int main() {
    
    int n; ///< ���������� ����������/�����

    std::vector<std::vector<int>> cost; ///< ������� ��������� ����������

    readFile("input.txt", cost, n);

    std::vector<int> assignment(n); ///< ������ ��� �������� ���������� ������� ��������
    // �������� ����� ���������� findMinCost
    auto startBruteForce = std::chrono::high_resolution_clock::now();
    int minCostBruteForce = findMinCost(cost, assignment);
    auto endBruteForce = std::chrono::high_resolution_clock::now();

    auto durationBruteForce = std::chrono::duration_cast<std::chrono::nanoseconds>(endBruteForce - startBruteForce).count();

    std::vector<int> greedyAssignmentResult(n); ///< ������ ��� �������� ���������� ������� ���������
    // �������� ����� ���������� greedyAssignment
    auto startGreedy = std::chrono::high_resolution_clock::now();
    int minCostGreedy = greedyAssignment(cost, greedyAssignmentResult);
    auto endGreedy = std::chrono::high_resolution_clock::now();

    auto durationGreedy = std::chrono::duration_cast<std::chrono::nanoseconds>(endGreedy - startGreedy).count();
    
    // ���������� ���������� � �������� ����
    writeFile("output.txt", cost, n, minCostBruteForce, assignment, minCostGreedy, greedyAssignmentResult, durationBruteForce, durationGreedy);

    return 0;
}