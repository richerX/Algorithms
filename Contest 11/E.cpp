#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Interval {
    double start;
    double finish;
    double weight;

    Interval(double start, double finish, double weight) {
        this->start = start;
        this->finish = finish;
        this->weight = weight;
    }
};

// Поиск ближайшего непересекающегося интервала до данного (index)
int uns(const std::vector<Interval> &intervals, int index) {
    for (int i = index - 1; i > -1; --i) {
        if (intervals[i].finish <= intervals[index].start) {
            return i + 1;
        }
    }
    return 0;
}

double getSharedWeight(const std::vector<Interval> &intervals) {
    std::vector<double> array(intervals.size() + 1);
    array[0] = 0;
    for (int i = 1; i <= intervals.size(); ++i) {
        array[i] = std::max(intervals[i - 1].weight + array[uns(intervals, i - 1)], array[i - 1]);
    }
    return array[intervals.size()];
}

int main() {
    int n;
    double start, finish, weight;

    std::cin >> n;
    std::vector<Interval> vector;
    for (int i = 0; i < n; ++i) {
        std::cin >> start >> finish >> weight;
        vector.push_back(Interval(start, finish, weight));
    }
    std::sort(vector.begin(), vector.end(),
              [](const Interval &a, const Interval &b) -> bool { return a.finish < b.finish; });

    std::cout << std::setprecision(4);
    std::cout << getSharedWeight(vector);
    return 0;
}
