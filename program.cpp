#include <iostream>
#include <cmath>
#include <concepts>

using namespace std;

template <typename T>
concept Numeric = is_arithmetic_v<T>;

template <Numeric T>
T add(T a, T b);

template <Numeric T>
T subtract(T a, T b);

template <Numeric T>
T multiply(T a, T b);

template <Numeric T>
T divide(T a, T b);

template <Numeric T>
T power(T base, T exponent);

template <Numeric T>
T nth_root(T value, T n);

template <Numeric T>
T log_base(T value, T base);

template <Numeric T>
void scientific_operations();

template <Numeric T>
T add(T a, T b) {
    return a + b;
}

template <Numeric T>
T subtract(T a, T b) {
    return a - b;
}

template <Numeric T>
T multiply(T a, T b) {
    return a * b;
}

template <Numeric T>
T divide(T a, T b) {
    if (b == 0) {
        throw runtime_error("Division by zero is undefined.");
    }
    return a / b;
}

template <Numeric T>
T power(T base, T exponent) {
    return pow(base, exponent);
}

template <Numeric T>
T nth_root(T value, T n) {
    if (n == 0) {
        throw runtime_error("Zeroth root is undefined.");
    }
    return pow(value, 1 / n);
}

template <Numeric T>
T log_base(T value, T base) {
    if (value <= 0 || base <= 0 || base == 1) {
        throw runtime_error("Invalid input for logarithm.");
    }
    return log(value) / log(base);
}

template <Numeric T>
void scientific_operations() {
    int choice;
    T a, b;
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
            switch (choice) {
            case 1:
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                cout << "Result: " << add(a, b) << "\n";
                break;
            case 2:
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                cout << "Result: " << subtract(a, b) << "\n";
                break;
            case 3:
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                cout << "Result: " << multiply(a, b) << "\n";
                break;
            case 4:
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                cout << "Result: " << divide(a, b) << "\n";
                break;
            case 5:
                cout << "Enter the base: ";
                cin >> a;
                cout << "Enter the exponent: ";
                cin >> b;
                cout << "Result: " << power(a, b) << "\n";
                break;
            case 6:
                cout << "Enter angle in radians: ";
                cin >> a;
                cout << "Result: " << sin(a) << "\n";
                break;
            case 7:
                cout << "Enter angle in radians: ";
                cin >> a;
                cout << "Result: " << cos(a) << "\n";
                break;
            case 8:
                cout << "Enter angle in radians: ";
                cin >> a;
                cout << "Result: " << tan(a) << "\n";
                break;
            case 9:
                cout << "Enter value: ";
                cin >> a;
                cout << "Result: " << asin(a) << "\n";
                break;
            case 10:
                cout << "Enter value: ";
                cin >> a;
                cout << "Result: " << acos(a) << "\n";
                break;
            case 11:
                cout << "Enter value: ";
                cin >> a;
                cout << "Result: " << atan(a) << "\n";
                break;
            case 12:
                cout << "Enter number: ";
                cin >> a;
                cout << "Result: " << sqrt(a) << "\n";
                break;
            case 13:
                cout << "Enter number: ";
                cin >> a;
                cout << "Result: " << cbrt(a) << "\n";
                break;
            case 14:
                cout << "Enter the number: ";
                cin >> a;
                cout << "Enter the root value: ";
                cin >> b;
                cout << "Result: " << nth_root(a, b) << "\n";
                break;
            case 15:
                cout << "Enter the number: ";
                cin >> a;
                cout << "Enter the base value: ";
                cin >> b;
                cout << "Result: " << log_base(a, b) << "\n";
                break;
            case 0:
                cout << "Exiting program !\n";
                break;
            default:
                cout << "Invalid choice.\n";
            }
        } catch (const exception &e) {
            cerr << e.what() << "\n";
        }
    } while (choice != 0);
}

int main() {
    scientific_operations<double>();
    return 0;
}
