#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <iomanip>
#include <algorithm>

// Класс взят отсюда https://pastebin.com/MxQdP5s9
class BigInteger {
    // основание системы счисления (1 000 000 000)
    static const int kBase = 1000000000;

    // внутреннее хранилище числа
    std::vector<int> digits_;

    // знак числа
    bool is_negative_;

    void removeLeadingZeros();
    void shiftRight();

public:
    // класс-исключение, бросаемое при делении на ноль
    class DivideByZero : public std::exception {};

    BigInteger();
    BigInteger(std::string, bool check);
    BigInteger(signed int, bool check);

    friend std::ostream& operator<<(std::ostream&, const BigInteger&);
    operator std::string() const;
    const BigInteger operator+() const;
    const BigInteger operator-() const;
    const BigInteger operator++();
    const BigInteger operator++(int);
    const BigInteger operator--();
    const BigInteger operator--(int);
    friend bool operator==(const BigInteger&, const BigInteger&);
    friend bool operator<(const BigInteger&, const BigInteger&);
    friend bool operator!=(const BigInteger&, const BigInteger&);
    friend bool operator<=(const BigInteger&, const BigInteger&);
    friend bool operator>(const BigInteger&, const BigInteger&);
    friend bool operator>=(const BigInteger&, const BigInteger&);
    friend const BigInteger operator+(BigInteger, const BigInteger&);
    BigInteger& operator+=(const BigInteger&);
    friend const BigInteger operator-(BigInteger, const BigInteger&);
    BigInteger& operator-=(const BigInteger&);
    friend const BigInteger operator*(const BigInteger&, const BigInteger&);
    BigInteger& operator*=(const BigInteger&);
    friend const BigInteger operator/(const BigInteger&, const BigInteger&);
    BigInteger& operator/=(const BigInteger&);
    friend const BigInteger operator%(const BigInteger&, const BigInteger&);
    BigInteger& operator%=(const BigInteger&);
};

// создает длинное целое число со значением 0
BigInteger::BigInteger() {
    this->is_negative_ = false;
}

// создает длинное целое число из C++-строки
BigInteger::BigInteger(std::string str, bool check = false) {
    if (check) {
        return;
    }
    if (str.length() == 0) {
        this->is_negative_ = false;
    } else {
        if (str[0] == '-') {
            str = str.substr(1);
            this->is_negative_ = true;
        } else {
            this->is_negative_ = false;
        }

        for (int64_t i = str.length(); i > 0; i -= 9) {
            if (i < 9) {
                this->digits_.push_back(atoi(str.substr(0, i).c_str()));
            } else {
                this->digits_.push_back(atoi(str.substr(i - 9, 9).c_str()));
            }
        }

        this->removeLeadingZeros();
    }
}

// удаляет ведущие нули
void BigInteger::removeLeadingZeros() {
    while (this->digits_.size() > 1 && this->digits_.back() == 0) {
        this->digits_.pop_back();
    }

    if (this->digits_.size() == 1 && this->digits_[0] == 0) {
        this->is_negative_ = false;
    }
}

// печатает число в поток вывода
std::ostream& operator<<(std::ostream& os, const BigInteger& bi) {
    if (bi.digits_.empty()) {
        os << 0;
    } else {
        if (bi.is_negative_) {
            os << '-';
        }
        os << bi.digits_.back();
        char old_fill = os.fill('0');
        for (int64_t i = static_cast<int64_t>(bi.digits_.size()) - 2; i >= 0; --i) {
            os << std::setw(9) << bi.digits_[i];
        }
        os.fill(old_fill);
    }

    return os;
}

// сравнивает два числа на равенство
bool operator==(const BigInteger& left, const BigInteger& right) {
    if (left.is_negative_ != right.is_negative_) {
        return false;
    }
    if (left.digits_.empty()) {
        if (right.digits_.empty() || (right.digits_.size() == 1 && right.digits_[0] == 0)) {
            return true;
        } else {
            return false;
        }
    }

    if (right.digits_.empty()) {
        if (left.digits_.size() == 1 && left.digits_[0] == 0) {
            return true;
        } else {
            return false;
        }
    }

    if (left.digits_.size() != right.digits_.size()) {
        return false;
    }
    for (size_t i = 0; i < left.digits_.size(); ++i) {
        if (left.digits_[i] != right.digits_[i]) {
            return false;
        }
    }

    return true;
}

// возвращает копию переданного числа
const BigInteger BigInteger::operator+() const {
    return BigInteger(*this);
}

// возвращает переданное число с другим знаком
const BigInteger BigInteger::operator-() const {
    BigInteger copy(*this);
    copy.is_negative_ = !copy.is_negative_;
    return copy;
}

// проверяет, является ли левый операнд меньше правого
bool operator<(const BigInteger& left, const BigInteger& right) {
    if (left == right) {
        return false;
    }
    if (left.is_negative_) {
        if (right.is_negative_) {
            return ((-right) < (-left));
        } else {
            return true;
        }
    } else if (right.is_negative_) {
        return false;
    } else {
        if (left.digits_.size() != right.digits_.size()) {
            return left.digits_.size() < right.digits_.size();
        } else {
            for (int64_t i = left.digits_.size() - 1; i >= 0; --i) {
                if (left.digits_[i] != right.digits_[i]) {
                    return left.digits_[i] < right.digits_[i];
                }
            }

            return false;
        }
    }
}

// сравнивает два числа на неравенство
bool operator!=(const BigInteger& left, const BigInteger& right) {
    return !(left == right);
}

// проверяет, является ли левый операнд меньше либо равен правого
bool operator<=(const BigInteger& left, const BigInteger& right) {
    return (left < right || left == right);
}

// проверяет, является ли левый операнд больше правого
bool operator>(const BigInteger& left, const BigInteger& right) {
    return !(left <= right);
}

// проверяет, является ли левый операнд больше либо равен правого
bool operator>=(const BigInteger& left, const BigInteger& right) {
    return !(left < right);
}

// складывает два числа
const BigInteger operator+(BigInteger left, const BigInteger& right) {
    if (left.is_negative_) {
        if (right.is_negative_) {
            return -(-left + (-right));
        } else {
            return right - (-left);
        }
    } else if (right.is_negative_) {
        return left - (-right);
    }
    int carry = 0;
    for (size_t i = 0; i < std::max(left.digits_.size(), right.digits_.size()) || carry != 0; ++i) {
        if (i == left.digits_.size()) {
            left.digits_.push_back(0);
        }
        left.digits_[i] += carry + (i < right.digits_.size() ? right.digits_[i] : 0);
        carry = left.digits_[i] >= BigInteger::kBase;
        if (carry != 0) {
            left.digits_[i] -= BigInteger::kBase;
        }
    }

    return left;
}

// прибавляет к текущему числу новое
BigInteger& BigInteger::operator+=(const BigInteger& value) {
    return *this = (*this + value);
}

// преобразует число к строке
BigInteger::operator std::string() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

// преобразует signed int к big_integer
BigInteger::BigInteger(signed int i, bool check = false) {
    if (check) {
        return;
    }
    if (i < 0) {
        this->is_negative_ = true;
    } else {
        this->is_negative_ = false;
    }
    this->digits_.push_back(std::abs(i) % BigInteger::kBase);
    i /= BigInteger::kBase;
    if (i != 0) {
        this->digits_.push_back(std::abs(i));
    }
}

// постфиксный инкремент
const BigInteger BigInteger::operator++(int) {
    *this += 1;
    return *this - 1;
}

// префиксный декремент
const BigInteger BigInteger::operator--() {
    return *this -= 1;
}

// постфиксный декремент
const BigInteger BigInteger::operator--(int) {
    *this -= 1;
    return *this + 1;
}

// вычитает два числа
const BigInteger operator-(BigInteger left, const BigInteger& right) {
    if (right.is_negative_) {
        return left + (-right);
    } else if (left.is_negative_) {
        return -(-left + right);
    } else if (left < right) {
        return -(right - left);
    }
    int carry = 0;
    for (size_t i = 0; i < right.digits_.size() || carry != 0; ++i) {
        left.digits_[i] -= carry + (i < right.digits_.size() ? right.digits_[i] : 0);
        carry = left.digits_[i] < 0;
        if (carry != 0) {
            left.digits_[i] += BigInteger::kBase;
        }
    }

    left.removeLeadingZeros();
    return left;
}

// вычитает из текущего числа новое
BigInteger& BigInteger::operator-=(const BigInteger& value) {
    return *this = (*this - value);
}

// перемножает два числа
const BigInteger operator*(const BigInteger& left, const BigInteger& right) {
    BigInteger result;
    result.digits_.resize(left.digits_.size() + right.digits_.size());
    for (size_t i = 0; i < left.digits_.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < right.digits_.size() || carry != 0; ++j) {
            int64_t cur =
                result.digits_[i + j] +
                left.digits_[i] * 1LL * (j < right.digits_.size() ? right.digits_[j] : 0) + carry;
            result.digits_[i + j] = static_cast<int>(cur % BigInteger::kBase);
            carry = static_cast<int>(cur / BigInteger::kBase);
        }
    }

    result.is_negative_ = left.is_negative_ != right.is_negative_;
    result.removeLeadingZeros();
    return result;
}

// домножает текущее число на указанное
BigInteger& BigInteger::operator*=(const BigInteger& value) {
    return *this = (*this * value);
}

//// сдвигает все разряды на 1 вправо (домножает на BASE)
void BigInteger::shiftRight() {
    if (this->digits_.empty()) {
        this->digits_.push_back(0);
        return;
    }
    this->digits_.push_back(this->digits_[this->digits_.size() - 1]);
    for (size_t i = this->digits_.size() - 2; i > 0; --i) {
        this->digits_[i] = this->digits_[i - 1];
    }
    this->digits_[0] = 0;
}

// делит два числа
const BigInteger operator/(const BigInteger& left, const BigInteger& right) {
    if (right == 0) {
        throw BigInteger::DivideByZero();
    }
    BigInteger b = right;
    b.is_negative_ = false;
    BigInteger result, current;
    result.digits_.resize(left.digits_.size());
    for (int64_t i = static_cast<int64_t>(left.digits_.size()) - 1; i >= 0; --i) {
        current.shiftRight();
        current.digits_[0] = left.digits_[i];
        current.removeLeadingZeros();
        int x = 0, l = 0, r = BigInteger::kBase;
        while (l <= r) {
            int m = (l + r) / 2;
            BigInteger t = b * m;
            if (t <= current) {
                x = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        result.digits_[i] = x;
        current = current - b * x;
    }

    result.is_negative_ = left.is_negative_ != right.is_negative_;
    result.removeLeadingZeros();
    return result;
}

// делит текущее число на указанное
BigInteger& BigInteger::operator/=(const BigInteger& value) {
    return *this = (*this / value);
}

// возвращает остаток от деления двух чисел
const BigInteger operator%(const BigInteger& left, const BigInteger& right) {
    BigInteger result = left - (left / right) * right;
    if (result.is_negative_) {
        result += right;
    }
    return result;
}

// присваивает текущему числу остаток от деления на другое число
BigInteger& BigInteger::operator%=(const BigInteger& value) {
    return *this = (*this % value);
}

BigInteger total = 0, increment;

int getNextDigit(int n, int remnant, int empty_slots, BigInteger k) {
    increment = 1;
    for (int digit = remnant; digit >= 0; --digit) {
        if (total + increment >= k) {
            return digit;
        }
        total += increment;
        increment *= (empty_slots - 1) + (remnant - digit + 1);
        increment /= (remnant - digit + 1);
    }

    return n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, remnant, digit;
    std::string position;
    std::cin >> n >> m >> position;
    BigInteger k = BigInteger(position);

    remnant = n;
    for (int series = 1; series <= m; ++series) {
        digit = getNextDigit(n, remnant, m - series, k);
        remnant -= digit;
        std::cout << digit;
        if (series != m) {
            std::cout << " ";
        }
    }

    return 0;
}
