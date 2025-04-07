/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:13:37 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/08 00:05:40 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <climits>

// Simple test result counter
class TestResults {
private:
    int passed;
    int failed;
    
public:
    TestResults() : passed(0), failed(0) {}
    
    void incrementPassed() { passed++; }
    void incrementFailed() { failed++; }
    
    int getPassed() const { return passed; }
    int getFailed() const { return failed; }
    int getTotal() const { return passed + failed; }
    
    bool allPassed() const { return failed == 0; }
};

// Output capture class
class OutputCapture {
private:
    std::stringstream buffer;
    std::streambuf* oldBuffer;
    
public:
    OutputCapture() {
        oldBuffer = std::cout.rdbuf(buffer.rdbuf());
    }
    
    ~OutputCapture() {
        std::cout.rdbuf(oldBuffer);
    }
    
    std::string getOutput() {
        return buffer.str();
    }
    
    void clear() {
        buffer.str("");
    }
};

// Macros for test assertions
#define ASSERT_TRUE(condition) \
    if (!(condition)) { \
        std::cerr << "❌ Assertion failed: " #condition << " at line " << __LINE__ << std::endl; \
        return false; \
    }

// #define ASSERT_CONTAINS(str, substr) \
//     { \
//         std::cerr << "\nActual output: \n" << str << "'\n"; \
//         if ((str).find(substr) == std::string::npos) { \
//             std::cerr << "  ASSERTION FAILED at line " << __LINE__ << std::endl; \
//             return false; \
//         } \
//         std::cerr << "  ✅ Passed test\n"; \
//     }

#define ASSERT_CONTAINS(str, char_str, int_str, float_str, double_str) \
    { \
        std::cerr << "\nActual output: \n" << str << "\n"; \
        std::cerr << "\nExpected output: \n" << char_str << "\n" << int_str << "\n" << float_str << "\n" << double_str << "\n" << std::endl; \
        if ((str).find(char_str) == std::string::npos \
            && (str).find(int_str) == std::string::npos \
            && (str).find(float_str) == std::string::npos \
            && (str).find(double_str) == std::string::npos) { \
            std::cerr << "❌ ASSERTION FAILED at line " << __LINE__ << std::endl; \
            return false; \
        } \
        std::cerr << "✅ Passed test\n"; \
    }

// Test functions
bool testIntegerConversion() {
    OutputCapture capture;
    ScalarConverter::convert("42");
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: \"*\"", "Int: 42", "Float: 42", "Double: 42");
    return true;
}

bool testCharConversion() {
    OutputCapture capture;
    
    ScalarConverter::convert("a");
    
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: \"a\"", "Int: 97", "Float: 97", "Double: 97");
    // ASSERT_CONTAINS(output, "Int: 97");
    // ASSERT_CONTAINS(output, "Float: 97");
    // ASSERT_CONTAINS(output, "Double: 97");
    return true;
}

// bool testFloatConversion() {
//     OutputCapture capture;
//     ScalarConverter::convert("42.5f");
//     std::string output = capture.getOutput();
    
//     ASSERT_CONTAINS(output, "Float: 42.5");
//     ASSERT_CONTAINS(output, "Double: 42.5");
//     return true;
// }

// bool testDoubleConversion() {
//     OutputCapture capture;
//     ScalarConverter::convert("42.5");
//     std::string output = capture.getOutput();
    
//     ASSERT_CONTAINS(output, "Float: 42.5");
//     ASSERT_CONTAINS(output, "Double: 42.5");
//     return true;
// }

// bool testNonDisplayableChar() {
//     OutputCapture capture;
//     ScalarConverter::convert("1");  // ASCII 1 is non-displayable
//     std::string output = capture.getOutput();
    
//     ASSERT_CONTAINS(output, "Char: non-displayable");
//     return true;
// }

// bool testEmptyString() {
//     OutputCapture capture;
//     ScalarConverter::convert("");
//     std::string output = capture.getOutput();
    
//     ASSERT_CONTAINS(output, "impossible");
//     return true;
// }

// bool testInvalidInput() {
//     OutputCapture capture;
//     ScalarConverter::convert("hello");
//     std::string output = capture.getOutput();
    
//     ASSERT_CONTAINS(output, "impossible");
//     return true;
// }

// bool testIntMaxValue() {
//     OutputCapture capture;
    
//     // Convert INT_MAX to string in C++98 style
//     std::stringstream ss;
//     ss << INT_MAX;
//     std::string intMaxStr = ss.str();
    
//     ScalarConverter::convert(intMaxStr);
//     std::string output = capture.getOutput();
    
//     ASSERT_CONTAINS(output, intMaxStr);
//     return true;
// }

// bool testIntMinValue() {
//     OutputCapture capture;
    
//     // Convert INT_MIN to string in C++98 style
//     std::stringstream ss;
//     ss << INT_MIN;
//     std::string intMinStr = ss.str();
    
//     ScalarConverter::convert(intMinStr);
//     std::string output = capture.getOutput();
    
//     ASSERT_CONTAINS(output, intMinStr);
//     return true;
// }

// Main function to run all tests
int main(int argc, char *argv[]) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    
    TestResults results;
    
    std::cout << "Running ScalarConverter tests...\n";
    std::cout << "==============================\n";
    
    // Define and run tests
    struct TestCase {
        const char* name;
        bool (*function)();
    };
    
    TestCase tests[] = {
        {"Integer Conversion", testIntegerConversion},
        {"Char Conversion", testCharConversion}
        // {"Float Conversion", testFloatConversion},
        // {"Double Conversion", testDoubleConversion},
        // {"Non-Displayable Char", testNonDisplayableChar},
        // {"Empty String", testEmptyString},
        // {"Invalid Input", testInvalidInput},
        // {"INT_MAX Value", testIntMaxValue},
        // {"INT_MIN Value", testIntMinValue}
    };
    
    int testCount = sizeof(tests) / sizeof(tests[0]);
    
    for (int i = 0; i < testCount; i++) {
        std::cout << "Test: " << tests[i].name << " ... ";
        if (tests[i].function()) {
            std::cout << "PASSED\n";
            results.incrementPassed();
        } else {
            std::cout << "FAILED\n";
            results.incrementFailed();
        }
    }
    
    // Print summary
    std::cout << "==============================\n";
    std::cout << "Results: " << results.getPassed() << " passed, "
              << results.getFailed() << " failed\n";
    std::cout << "Total: " << results.getTotal() << " tests\n";
    
    return results.allPassed() ? 0 : 1;
}
