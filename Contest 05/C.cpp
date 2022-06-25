#include <iostream>

class Node {
public:
    int value;
    Node *left;
    Node *right;

    explicit Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Heap {
public:
    Node *top;
    size_t count;

    // Конструктор по умолчанию.
    Heap() {
        top = nullptr;
        count = 0;
    }

    // Конструктор, принимающий два итератора, первый из которых указывает на первый элемент
    // последовательности, второй указывает на элемент, следующий за последним элементом.
    // Каждый элемент последовательности имеет тип ValueType.

    // Конструктор, принимающий список инициализации std::initializer_list<ValueType>,
    // что позволяет писать Heap<int> heap{1, 3, 5}.

    // Конструктор копирования и конструктор перемещения.
    Heap(const Heap &other) {
        top = nullptr;
        count = 0;
        copyNodes(other.top);
    }

    // Оператор присваивания, копирующий и перемещающий.
    Heap &operator=(const Heap &other) {
        if (this != &other) {
            destructor(this->top);
            this->top = nullptr;
            this->count = 0;
            copyNodes(other.top);
        }
        return *this;
    }

    // Деструктор.
    ~Heap() {
        destructor(top);
        top = nullptr;
    }

    // Константный метод size, возвращающий количество элементов в куче.
    size_t size() const {
        return count;
    }

    // Константный метод empty, возвращающий true, если куча пустая, и false в противном случае.
    bool empty() const {
        return count == 0;
    }

    // Метод insert, который добавляет элемент в кучу.
    void insert(int value) {
        ;
    }

    // Метод extract, который достает из кучи наибольший элемент (удалив его при этом).
    void extract() {
        ;
    }

    // Группа print методов

    void print(Node *current = nullptr) {
        if (current == nullptr) {
            current = top;
        }

        std::string left = current->left == nullptr ? "_" : std::to_string(current->left->value);
        std::string right = current->right == nullptr ? "_" : std::to_string(current->right->value);
        std::cout << current->value << " -> " << left << " " << right;

        if (current->left != nullptr) {
            print(current->left);
        }
        if (current->right != nullptr) {
            print(current->right);
        }
    }

private:
    void copyNodes(Node *current) {
        if (current != nullptr) {
            insert(current->value);
            copyNodes(current->left);
            copyNodes(current->right);
        }
    }

    void destructor(Node *current) {
        if (current != nullptr) {
            destructor(current->left);
            destructor(current->right);
            delete current;
        }
    }

    bool equals(Node *first, Node *second) const {
        return !(first->value < second->value) && !(second->value < first->value);
    }
};

int main() {
    Heap<int> tree = Heap<int>();

    int array[100] {5, 46, 81, 4, 75, 80, 53, 55, 47, 66, 16, 42, 96, 97, 12, 88, 34, 100, 17,
                   83, 40, 14, 44, 1, 47, 1, 4, 46, 2, 66, 72, 17, 50, 50, 14, 19, 7, 90, 4, 48,
                   50, 18, 12, 94, 97, 74, 63, 95, 22, 21};
    for (int element : array) {
        if (element != 0) {
            tree.insert(element);
        }
    }
    tree.print();
    std::cout << "\n";

    for (int i = 0; i < tree.count; i++) {
        std::cout << tree.traversal()[i] << " ";
    }

    return 0;
}
