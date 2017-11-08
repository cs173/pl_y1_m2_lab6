#include <iostream>
#include <cmath>

bool is_valid(int digit, int base) {
    if (abs(digit) > base - 1) {
        std::cerr << "Wrong digit '" << abs(digit) << "' for base" << base << "!\n";
        return true;
    }
    return false;
}

int main() {
    unsigned int b;
    double number, res10 = 0;

    // print program info
    std::cout << "----CONVERT NUMBERS TO DECIMAL----\n\n"
            "------------ATTENTION:------------\n"
            "• base should be in [2;9)\n"
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
    if (!(std::cin >> number)) {
        std::cerr << "Number is out of range!\n";
        return 2;
    }
    if (abs(number) > 9.22e+9) {
        std::cerr << "Wrong number!\n";
        return 2;
    }
    std::cout << "converting...\n\n";

    // shift comma to the end of number (considering accuracy = 1e-9) and convert fractional part
    int shift = 0;
    for (double power = 1.0 / b; number != floor(number); power /= b, ++shift) {
        number *= 10;
        auto digit = int((long long) (number) % 10);
        if (!is_valid(digit, b)) {
            return 3;
        }
        res10 += digit * power;
    }

    auto entire_part = (long long) (number / pow(10, shift));

    for (int power = 1; entire_part; power *= b, entire_part /= 10) {
        auto digit = int(entire_part % 10);
        if (!is_valid(digit, b)) {
            return 3;
        }
        res10 += digit * power;
    }

    // output result
    std::cout << "--------------RESULT--------------\nConverted to base10: " << res10 << "\n"
            "----------------------------------";
    return 0;
}
