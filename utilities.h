/**
 * @file utilities.h
 * @brief ������������ ���� � ������������� ������� ��� ������, ������ � ������� ���������.
 *
 * ���� ���� �������� ���������� ������� ��� ������ � �������� ���������,
 * ������� ������ ������ �� �����, ���������� ������� � ������� ��������,
 * � ����� ������ ����������� � ����.
 */ 
#ifndef UTILITIES_H 
#define UTILITIES_H   

#include <vector>  

 /**
  * @brief ������ ������� ��������� �� �����.
  *
  * @param filename ��� ����� ��� ������.
  * @param cost ������ �� ������� ��������� (������ ��������).
  * @param n ������ �� ����������, ��� ����� ��������� ���������� ����������/�����.
  */
void readFile(const std::string& filename, std::vector<std::vector<int>>& cost, int& n);

/**
 * @brief ������� ����������� ��������� ������������� ����� � ������� ������ ������� ��������.
 *
 * @param cost ����������� ������ �� ������� ���������.
 * @param assignment ������ �� ������, ��� ����� ��������� ������������� �����.
 * @return ����������� ���������.
 */
int findMinCost(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);

/**
 * @brief ������� ������������� ����� � ����������� ���������� � ������� ������� ���������.
 *
 * @param cost ����������� ������ �� ������� ���������.
 * @param assignment ������ �� ������, ��� ����� ��������� ������������� �����.
 * @return ����������� ���������.
 */
int greedyAssignment(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);

/**
 * @brief ���������� ���������� � �������� ����.
 *
 * @param filename ��� ����� ��� ������ �����������.
 * @param cost ������ �� ������� ���������.
 * @param n ���������� ����������/�����.
 * @param minCostBruteForce ����������� ��������� ��� ������ ������� ��������.
 * @param assignment ������, ���������� ������������� ����� ��� ������ ������� ��������.
 * @param minCostGreedyAssignment ����������� ��������� ��� ������� ���������.
 * @param greedyAssignmentResult ������, ���������� ������������� ����� ��� ������� ���������.
 * @param durationBruteForce ����� ���������� ������ ������� �������� � ������������.
 * @param durationGreedy ����� ���������� ������� ��������� � ������������.
 */
void writeFile(const std::string& filename, std::vector<std::vector<int>>& cost, int n, int minCostBruteForce, const std::vector<int>& assignment, int minCostGreedyAssignment, const std::vector<int>& greedyAssignmentResult, long long durationTimeBruteForce, long long durationGreedy);
#endif // UTILITIES_H