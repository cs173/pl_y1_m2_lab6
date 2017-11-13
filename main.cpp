#include <iostream>
#include <cmath>

double const ACCURACY = 1e-9;

bool is_valid(int digit, int base) {
    return (abs(digit) <= (base - 1));
}

int main() {
    unsigned int b;
    double number, res10 = 0;

    // print program info
    std::cout << "----CONVERT NUMBERS TO DECIMAL----\n\n"
            "------------ATTENTION:------------\n"
            "• base should be in [2;9]\n"
            "• abs(number) should be <= 9.22e+9\n"
            "• accuracy = 1e-9\n"
            "----------------------------------\n\n";
    // input
    std::cout << "Enter base: ";
    if (!(std::cin >> b) || b < 2 || b > 9) {
        std::cerr << "Wrong base!\n";
        return 1;
    }

    std::cout << "Enter number to convert: ";
    if (!(std::cin >> number) || abs(number) > 9.22e+9) {
        std::cerr << "Wrong number!\n";
        return 2;
    }
    std::cout << "converting...\n\n";

    // shift comma to the end of number (considering accuracy = 1e-9) and convert fractional part
    int shift = 0;
    for (double factor = 1.0 / b; abs(number - floor(number)) > ACCURACY; factor /= b, ++shift) {
        number *= 10;
        int digit = (long long) (number) % 10;
        if (!is_valid(digit, b)) {
            std::cerr << "Wrong digit '" << abs(digit) << "' for base " << b << "!\n";
            return 3;
        }
        res10 += digit * factor;
    }
    // unshift and cast to long long
    long long entire_part = (long long) (number / pow(10, shift));
    // convert entire part
    for (int factor = 1; entire_part; factor *= b, entire_part /= 10) {
        int digit = int(entire_part % 10);
        if (!is_valid(digit, b)) {
            std::cerr << "Wrong digit '" << abs(digit) << "' for base " << b << "!\n";
            return 3;
        }
        res10 += digit * factor;
    }
    // output result
    std::cout << "--------------RESULT--------------\n"
            "Converted to base 10: " << res10 << "\n"
            "----------------------------------\n";
    return 0;
}
