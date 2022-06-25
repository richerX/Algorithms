#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius;
};

double inaccuracy = 0.000001;
double infinity = 1'000'000'000;

Circle road1, road2;
Point start, finish;
std::vector<std::vector<double>> graph;
std::vector<Point> intersections;

double getDistance(Point point1, Point point2) {
    return std::sqrt(std::pow(point2.x - point1.x, 2) + std::pow(point2.y - point1.y, 2));
}

bool isOnCircle(Circle circle, Point point) {
    bool not_out = getDistance(circle.center, point) < circle.radius + inaccuracy;
    bool not_in = getDistance(circle.center, point) > circle.radius - inaccuracy;
    return not_in && not_out;
}

Circle getCircle(Point point) {
    if (isOnCircle(road1, point)) {
        return road1;
    }
    return road2;
}

// https://math.stackexchange.com/questions/1794943
double getDistOnCircle(Circle circle, Point point1, Point point2) {
    double dist = getDistance(point1, point2);
    double angle = 2 * std::asin(dist / (2 * circle.radius));
    return circle.radius * angle;
}

// Считать ввод пользователя
void getInput() {
    double a, b, c;

    std::cin >> a >> b >> c;
    road1 = Circle{Point{a, b}, c};

    std::cin >> a >> b >> c;
    road2 = Circle{Point{a, b}, c};

    std::cin >> a >> b;
    start = Point{a, b};

    std::cin >> a >> b;
    finish = Point{a, b};

    int n = 4;
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        graph[i].assign(n, infinity);
        graph[i][i] = 0;
    }
}

// https://e-maxx.ru/algo/circles_intersection
void getIntersectionPoints() {
    Circle circle1 = road1;
    Circle circle2 = road2;

    circle2.center.x -= circle1.center.x;
    circle2.center.y -= circle1.center.y;

    double r = circle1.radius;
    double a = -2 * circle2.center.x;
    double b = -2 * circle2.center.y;
    double c = std::pow(circle2.center.x, 2) + std::pow(circle2.center.y, 2);
    c += std::pow(circle1.radius, 2) - std::pow(circle2.radius, 2);

    double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
    if (c * c > r * r * (a * a + b * b) + inaccuracy) {
    } else if (std::abs(c * c - r * r * (a * a + b * b)) < inaccuracy) {
        intersections.push_back(Point{x0 + circle1.center.x, y0 + circle1.center.y});
    } else {
        double d = r * r - c * c / (a * a + b * b);
        double multi = std::sqrt(d / (a * a + b * b));
        double ax, ay, bx, by;
        ax = x0 + b * multi;
        bx = x0 - b * multi;
        ay = y0 - a * multi;
        by = y0 + a * multi;
        intersections.push_back(Point{ax + circle1.center.x, ay + circle1.center.y});
        intersections.push_back(Point{bx + circle1.center.x, by + circle1.center.y});
    }
}

// Заполнить граф точками и расстояниями
void fillGraph() {
    for (int i = 0; i < intersections.size(); ++i) {
        graph[0][i + 2] = getDistOnCircle(getCircle(start), start, intersections[i]);
        graph[i + 2][0] = getDistOnCircle(getCircle(start), start, intersections[i]);
        graph[1][i + 2] = getDistOnCircle(getCircle(finish), finish, intersections[i]);
        graph[i + 2][1] = getDistOnCircle(getCircle(finish), finish, intersections[i]);
    }

    if (intersections.size() == 2) {
        double dist1 = getDistOnCircle(road1, intersections[0], intersections[1]);
        double dist2 = getDistOnCircle(road1, intersections[0], intersections[1]);
        double min_dist = std::min(dist1, dist2);
        graph[2][3] = min_dist;
        graph[3][2] = min_dist;
    }

    if (isOnCircle(road1, start) && isOnCircle(road1, finish)) {
        graph[0][1] = getDistOnCircle(road1, start, finish);
        graph[1][0] = getDistOnCircle(road1, finish, start);
    }
    if (isOnCircle(road2, start) && isOnCircle(road2, finish)) {
        graph[0][1] = getDistOnCircle(road2, start, finish);
        graph[1][0] = getDistOnCircle(road2, finish, start);
    }
}

// Алгоритм Флойда-Уоршелла
void solve() {
    int n = graph.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != infinity && graph[k][j] != infinity) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

// Вывод ответа
void printAnswer() {
    if (graph[0][1] == infinity) {
        std::cout << -1 << "\n";
    } else {
        std::cout << graph[0][1] << "\n";
    }
}

int main() {
    getInput();
    getIntersectionPoints();
    fillGraph();
    solve();
    printAnswer();
    return 0;
}
