/**
 * @file utilities.h
 * @brief Заголовочный файл с определениями функций для чтения, записи и расчета стоимости.
 *
 * Этот файл содержит объявления функций для работы с матрицей стоимости,
 * включая чтение данных из файла, выполнение жадного и полного перебора,
 * а также запись результатов в файл.
 */ 
#ifndef UTILITIES_H 
#define UTILITIES_H   

#include <vector>  

 /**
  * @brief Читает матрицу стоимости из файла.
  *
  * @param filename Имя файла для чтения.
  * @param cost Ссылка на матрицу стоимости (вектор векторов).
  * @param n Ссылка на переменную, где будет храниться количество работников/работ.
  */
void readFile(const std::string& filename, std::vector<std::vector<int>>& cost, int& n);

/**
 * @brief Находит минимальную стоимость распределения работ с помощью метода полного перебора.
 *
 * @param cost Константная ссылка на матрицу стоимости.
 * @param assignment Ссылка на вектор, где будет храниться распределение работ.
 * @return Минимальная стоимость.
 */
int findMinCost(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);

/**
 * @brief Находит распределение работ с минимальной стоимостью с помощью жадного алгоритма.
 *
 * @param cost Константная ссылка на матрицу стоимости.
 * @param assignment Ссылка на вектор, где будет храниться распределение работ.
 * @return Минимальная стоимость.
 */
int greedyAssignment(const std::vector<std::vector<int>>& cost, std::vector<int>& assignment);

/**
 * @brief Записывает результаты в выходной файл.
 *
 * @param filename Имя файла для записи результатов.
 * @param cost Ссылка на матрицу стоимости.
 * @param n Количество работников/работ.
 * @param minCostBruteForce Минимальная стоимость для метода полного перебора.
 * @param assignment Вектор, содержащий распределение работ для метода полного перебора.
 * @param minCostGreedyAssignment Минимальная стоимость для жадного алгоритма.
 * @param greedyAssignmentResult Вектор, содержащий распределение работ для жадного алгоритма.
 * @param durationBruteForce Время выполнения метода полного перебора в наносекундах.
 * @param durationGreedy Время выполнения жадного алгоритма в наносекундах.
 */
void writeFile(const std::string& filename, std::vector<std::vector<int>>& cost, int n, int minCostBruteForce, const std::vector<int>& assignment, int minCostGreedyAssignment, const std::vector<int>& greedyAssignmentResult, long long durationTimeBruteForce, long long durationGreedy);
#endif // UTILITIES_H