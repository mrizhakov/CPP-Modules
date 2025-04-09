/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:09:04 by mrizakov          #+#    #+#             */
/*   Updated: 2025/04/09 01:09:05 by mrizakov         ###   ########.fr       */
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

#define ASSERT_CONTAINS(str, char_str, int_str, float_str, double_str) \
    { \
        std::cerr << "\nActual output: \n" << str << "\n"; \
        std::cerr << "\nExpected output: \n" << char_str << "\n" << int_str << "\n" << float_str << "\n" << double_str << "\n" << std::endl; \
        bool char_found = (str).find(char_str) != std::string::npos; \
        bool int_found = (str).find(int_str) != std::string::npos; \
        bool float_found = (str).find(float_str) != std::string::npos; \
        bool double_found = (str).find(double_str) != std::string::npos; \
        if (!(char_found && int_found && float_found && double_found)) { \
            std::cerr << "❌ ASSERTION FAILED at line " << __LINE__ << ": Mismatched output." << std::endl; \
            if (!char_found) std::cerr << "   Missing: " << char_str << std::endl; \
            if (!int_found) std::cerr << "   Missing: " << int_str << std::endl; \
            if (!float_found) std::cerr << "   Missing: " << float_str << std::endl; \
            if (!double_found) std::cerr << "   Missing: " << double_str << std::endl; \
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
    return true;
}

bool testFloatConversion() {
    OutputCapture capture;
    ScalarConverter::convert("42.5f");
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: \"*\"", "Int: 42", "Float: 42.5f", "Double: 42.5");
    return true;
}

bool testDoubleConversion() {
    OutputCapture capture;
    ScalarConverter::convert("42.1234");
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: \"*\"", "Int: 42", "Float: 42.1234f", "Double: 42.1234");
    return true;
}

bool testNonDisplayableChar() {
    OutputCapture capture;
    ScalarConverter::convert("1");
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: non-displayable", "Int: 1", "Float: 1.0f", "Double: 1");
    return true;
}

bool testEmptyString() {
    OutputCapture capture;
    ScalarConverter::convert("\n");
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: impossible", "Int: impossible", "Float: impossible", "Double: impossible");
    return true;
}

bool testInvalidInput() {
    OutputCapture capture;
    ScalarConverter::convert("hello");
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: impossible", "Int: impossible", "Float: impossible", "Double: impossible");
    return true;
}

bool testIntMaxValue() {
    OutputCapture capture;
    
    std::stringstream ss;
    ss << INT_MAX;

    std::string intMaxStr = ss.str();
    
    ScalarConverter::convert(intMaxStr);
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: impossible", "Int: 2147483647", "Float: 2.14748e+09.0f", "Double: 2.14748e+09.0");
    return true;
}

bool testIntMinValue() {
    OutputCapture capture;
    
    std::stringstream ss;
    ss << INT_MIN;
    std::string intMinStr = ss.str();
    
    ScalarConverter::convert(intMinStr);
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: impossible", "Int: -2147483648", "Float: -2.14748e+09.0f", "Double: -2.14748e+09.0");
    return true;
}

bool testIntOverflow() {
    OutputCapture capture;
    
    std::stringstream ss;
    ss << -21474836490;
    std::string intMinStr = ss.str();
    
    ScalarConverter::convert(intMinStr);
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: impossible", "Int: impossible", "Float: -2.14748e+10f", "Double: -2.14748e+10");
    return true;
}

bool testReallyBigNumber() {
    OutputCapture capture;
    
    std::stringstream ss;
    ss << DBL_MAX;
    std::string intMinStr = ss.str();
    
    ScalarConverter::convert(intMinStr);
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: impossible", "Int: impossible", "Float: impossible", "Double: 1.79769e+308");
    return true;
}

bool nanf() {
    OutputCapture capture;
    
    ScalarConverter::convert("nanf");
    std::string output = capture.getOutput();
    
    ASSERT_CONTAINS(output, "Char: impossible", "Int: nan", "Float: nanf", "Double: nan");
    return true;
}

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
        {"Char Conversion", testCharConversion},
        {"Float Conversion", testFloatConversion},
        {"Double Conversion", testDoubleConversion},
        {"Non-Displayable Char", testNonDisplayableChar},
        {"Empty String", testEmptyString},
        {"Invalid Input", testInvalidInput},
        {"INT_MAX Value", testIntMaxValue},
        {"INT_MIN Value", testIntMinValue},
        {"Int Overflow", testIntOverflow},
        {"Really Big Number", testReallyBigNumber},
        {"nanf", nanf}
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
