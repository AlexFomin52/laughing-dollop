/**
 * @file main.cpp
 * @brief Основная программа для расчета минимальной стоимости распределения работ.
 *
 * Программа читает матрицу стоимости из файла, выполняет два способа распределения работ
 * (жадный алгоритм и метод полного перебора) и записывает результаты в выходной файл,
 * включая время выполнения каждого метода.
 */

 // Подключаем необходимые библиотеки
#include <iostream>  
#include <fstream>  
#include <vector>  
#include <ctime>
#include <chrono>
#include "utilities.h"  

int main() {
    
    int n; ///< количество работников/работ

    std::vector<std::vector<int>> cost; ///< матрица стоимости назначений

    readFile("input.txt", cost, n);

    std::vector<int> assignment(n); ///< массив для хранения результата полного перебора
    // Измеряем время выполнения findMinCost
    auto startBruteForce = std::chrono::high_resolution_clock::now();
    int minCostBruteForce = findMinCost(cost, assignment);
    auto endBruteForce = std::chrono::high_resolution_clock::now();

    auto durationBruteForce = std::chrono::duration_cast<std::chrono::nanoseconds>(endBruteForce - startBruteForce).count();

    std::vector<int> greedyAssignmentResult(n); ///< массив для хранения результата жадного алгоритма
    // Измеряем время выполнения greedyAssignment
    auto startGreedy = std::chrono::high_resolution_clock::now();
    int minCostGreedy = greedyAssignment(cost, greedyAssignmentResult);
    auto endGreedy = std::chrono::high_resolution_clock::now();

    auto durationGreedy = std::chrono::duration_cast<std::chrono::nanoseconds>(endGreedy - startGreedy).count();
    
    // Записываем результаты в выходной файл
    writeFile("output.txt", cost, n, minCostBruteForce, assignment, minCostGreedy, greedyAssignmentResult, durationBruteForce, durationGreedy);

    return 0;
}