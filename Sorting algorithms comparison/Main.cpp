#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "Constants.cpp"

// Вывод вектора в консоль
void printVector(const std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << "\n";
}

// Копирование данных base в vector
void copyVector(std::vector<int> *vector, const std::vector<int> &base, int length) {
    vector->clear();
    for (int i = 0; i < length; ++i) {
        vector->push_back(base[i]);
    }
}

// Запись результатов теста
void writeResult(std::ofstream *file, int filler, int length, int sort, int64_t elapsed) {
    (*file) << sorts_names[sort] << "; " << lengths[length] << "; " << fillers_names[filler] << "; " << elapsed << "\n";
}

// Проведение одного теста
int64_t runTest(std::vector<int> *vector, int sort_index) {
    auto start = std::chrono::high_resolution_clock::now();
    sorts[sort_index](vector);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

// Проведение всех тестов
void runAllTests(std::ofstream *file, int loops = 1) {
    std::vector<int> vector, base;
    for (int filler_index = 0; filler_index < fillers.size(); ++filler_index) {
        fillers[filler_index](&base, 4100);
        for (int length_index = 0; length_index < lengths.size(); ++length_index) {
            for (int sort_index = 0; sort_index < sorts.size(); ++sort_index) {
                int64_t elapsed = 0;
                for (int i = 0; i < loops; ++i) {
                    copyVector(&vector, base, lengths[length_index]);
                    elapsed += runTest(&vector, sort_index);
                }
                writeResult(file, filler_index, length_index, sort_index, elapsed / loops);
            }
        }
    }
}

int main() {
    std::srand(std::time(nullptr));
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream file;
    file.open("results.csv");
    file << "Сортировка; Кол-во элементов; Тип массива; Время (Наносекунды)" << "\n";
    runAllTests(&file);
    file.close();

    auto end = std::chrono::high_resolution_clock::now();
    int64_t total_time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Total time = " << total_time << " seconds";
    return 0;
}

/**
 * ПиАА 2022, Кунин Илья Евгеньевич, БПИ203
 * CLION
 * Все сделано
 *
 * Общая идея решения:
 * Есть вектора lengths, fillers, sorts
 * lengths - все возможные длины массивов, которые будем замерять
 * fillers - функции-заполнители массива
 * sorts   - функции-сортировки массива
 *
 * Пробегаемся в тройном цикле по всем возможным вариантам и записываем результаты
 */

//    std::vector<int> vector, base;
//    int length = 100;                  // можно выбрать длину
//    fillRandomBig(&base, length);      // можно выбрать заполнение
//    copyVector(&vector, base, length);
//    printVector(vector);
//    bubbleSort(&vector);               // можно выбрать сортировку
//    printVector(vector);
