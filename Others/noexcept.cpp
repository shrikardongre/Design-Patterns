#include <iostream>
#include <stdexcept> // For std::runtime_error

// This function promises not to throw, and it keeps that promise.
void safe_function() noexcept {
    std::cout << "1. This safe function is running." << std::endl;
}

// This function promises not to throw, but it will break that promise.
void unsafe_function() noexcept {
    std::cout << "3. This unsafe function is running and about to throw..." << std::endl;
    throw std::runtime_error(" Broken promise!"); // This will cause std::terminate
}

int main() {
    safe_function();
    std::cout << "2. Safe function finished successfully." << std::endl;

    // We use a try/catch block to show that it CANNOT catch the exception
    // from a noexcept function. The program will crash instead.
    try {
        unsafe_function();
        // This line will never be reached
        std::cout << "This message will never appear." << std::endl;
    } catch (const std::exception& e) {
        // This block will also never be reached
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0; // The program terminates before it can return
}