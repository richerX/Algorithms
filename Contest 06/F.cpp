#include <vector>
#include <iostream>
#include <utility>

class Student;

class Ski {
    friend int compare(const Student &student, const Ski &ski);

    friend class ReadWriter;

public:
    int id;

private:
    int length_;
};

class Student {
    friend int compare(const Student &student, const Ski &ski);

    friend class ReadWriter;

public:
    int id;

private:
    int height_;
};

int compare(const Student &student, const Ski &ski) {
    if (ski.length_ < student.height_ + 5) {
        return -1;
    }
    if (ski.length_ > student.height_ + 5) {
        return 1;
    }
    return 0;
}

class ReadWriter {
public:
    ReadWriter() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }

    int readInt() {
        int n;
        std::cin >> n;
        return n;
    }

    void readStudents(std::vector<Student> *arr) {
        char ch;
        for (size_t i = 0; i < arr->size(); ++i) {
            std::cin >> (*arr)[i].id >> (*arr)[i].height_ >> ch;
        }
    }

    void readSkis(std::vector<Ski> *arr) {
        char ch;
        for (size_t i = 0; i < arr->size(); ++i) {
            std::cin >> (*arr)[i].id >> (*arr)[i].length_ >> ch;
        }
    }

    void writeStudentsAndSkis(const std::vector<Student> &students, const std::vector<Ski> &skis) {
        for (size_t i = 0; i < students.size(); ++i) {
            std::cout << students[i].id << ' ' << skis[i].id << "; ";
        }
    }
};

std::pair<int, int> getPivot(std::vector<Student> *vector, int begin, int end) {
    int pivot = (*vector)[(begin + end) / 2].id;
    while (begin <= end) {
        while ((*vector)[begin].id < pivot) {
            begin++;
        }
        while ((*vector)[end].id > pivot) {
            end--;
        }
        if (begin <= end) {
            std::swap((*vector)[begin++], (*vector)[end--]);
        }
    }
    return std::pair<int, int>(begin, end);
}

void quickSort(std::vector<Student> *vector, int begin, int end) {
    if (begin < end) {
        auto pivot = getPivot(vector, begin, end);
        quickSort(vector, begin, pivot.second);
        quickSort(vector, pivot.first, end);
    }
}

int getPerfectSki(std::vector<Student> *students, std::vector<Ski> *skis, int student) {
    int answer = student, comparison;
    for (int i = student; i < (*skis).size(); ++i) {
        comparison = compare((*students)[student], (*skis)[i]);
        if (comparison == 1) {
            answer = i;
        } else if (comparison == 0) {
            return i;
        }
    }
    return answer;
}

void findPairs(std::vector<Student> *students, std::vector<Ski> *skis) {
    quickSort(students, 0, (*students).size() - 1);
    for (int i = 0; i < (*students).size(); ++i) {
        int perfect = getPerfectSki(students, skis, i);
        std::swap((*skis)[i], (*skis)[perfect]);
    }
}

int main() {
    ReadWriter rw;

    int n = rw.readInt();

    std::vector<Student> students(n);
    std::vector<Ski> skis(n);

    rw.readStudents(&students);
    rw.readSkis(&skis);

    findPairs(&students, &skis);

    rw.writeStudentsAndSkis(students, skis);
    return 0;
}
