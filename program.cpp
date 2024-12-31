#include <iostream>
#include <cmath>
#include <concepts>

using namespace std;

template <typename T>
concept Numeric = is_arithmetic_v<T>;

template <typename T>
T get_input(const string &prompt) {
    T value;
    cout << prompt;
    cin >> value;
    return value;
}

template <Numeric T>
class ScientificCalculator {
public:
    T add(T a, T b) { return a + b; }
    T subtract(T a, T b) { return a - b; }
    T multiply(T a, T b) { return a * b; }
    T divide(T a, T b) {
        if (b == 0) {
            throw runtime_error("Division by zero is undefined.");
        }
        return a / b;
    }
    T power(T base, T exponent) { return pow(base, exponent); }
    T nth_root(T value, T n) {
        if (n == 0) {
            throw runtime_error("Zeroth root is undefined.");
        }
        return pow(value, 1 / n);
    }
    T log_base(T value, T base) {
        if (value <= 0 || base <= 0 || base == 1) {
            throw runtime_error("Invalid input for logarithm.");
        }
        return log(value) / log(base);
    }
    void scientific_operations() {
        int choice;
        do {
            cout << "\nScientific Calculator\n";
            cout << "0. Exit\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "5. Power\n";
            cout << "6. Sin\n";
            cout << "7. Cosine\n";
            cout << "8. Tangent\n";
            cout << "9. Inverse Sin\n";
            cout << "10. Inverse Cosine\n";
            cout << "11. Inverse Tangent\n";
            cout << "12. Square Root\n";
            cout << "13. Cube Root\n";
            cout << "14. Nth Root\n";
            cout << "15. Logarithm (base x)\n";
            cout << "Enter your choice: ";
            cin >> choice;

            try {
                T a, b, result;
                switch (choice) {
                case 1:
                    a = get_input<T>("Enter the first number: ");
                    b = get_input<T>("Enter the second number: ");
                    result = add(a, b);
                    break;
                case 2:
                    a = get_input<T>("Enter the first number: ");
                    b = get_input<T>("Enter the second number: ");
                    result = subtract(a, b);
                    break;
                case 3:
                    a = get_input<T>("Enter the first number: ");
                    b = get_input<T>("Enter the second number: ");
                    result = multiply(a, b);
                    break;
                case 4:
                    a = get_input<T>("Enter the first number: ");
                    b = get_input<T>("Enter the second number: ");
                    result = divide(a, b);
                    break;
                case 5:
                    a = get_input<T>("Enter the base: ");
                    b = get_input<T>("Enter the exponent: ");
                    result = power(a, b);
                    break;
                case 6:
                    a = get_input<T>("Enter angle in radians: ");
                    result = sin(a);
                    break;
                case 7:
                    a = get_input<T>("Enter angle in radians: ");
                    result = cos(a);
                    break;
                case 8:
                    a = get_input<T>("Enter angle in radians: ");
                    result = tan(a);
                    break;
                case 9:
                    a = get_input<T>("Enter value: ");
                    result = asin(a);
                    break;
                case 10:
                    a = get_input<T>("Enter value: ");
                    result = acos(a);
                    break;
                case 11:
                    a = get_input<T>("Enter value: ");
                    result = atan(a);
                    break;
                case 12:
                    a = get_input<T>("Enter number: ");
                    result = sqrt(a);
                    break;
                case 13:
                    a = get_input<T>("Enter number: ");
                    result = cbrt(a);
                    break;
                case 14:
                    a = get_input<T>("Enter the number: ");
                    b = get_input<T>("Enter the root value: ");
                    result = nth_root(a, b);
                    break;
                case 15:
                    a = get_input<T>("Enter the number: ");
                    b = get_input<T>("Enter the base value: ");
                    result = log_base(a, b);
                    break;
                case 0:
                    cout << "Exiting program!\n";
                    continue;
                default:
                    cout << "Invalid choice.\n";
                    continue;
                }
                cout << "Result: " << result << "\n";
            } catch (const exception &e) {
                cerr << "Error: " << e.what() << "\n";
            }
        } while (choice != 0);
    }
};

int main() {
    ScientificCalculator<double> calculator;
    calculator.scientific_operations();
    return 0;
}
