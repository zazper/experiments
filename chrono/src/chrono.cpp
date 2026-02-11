// ChronoApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <sstream>
// C++ 2023
//#include <format>
//#include <iostream>
//#include <print>     // Provides std::println for formatted output (C+23)
#include <vector>    // Provides std::vector for dynamic arrays
#include <chrono>    // Provides high-resolution timing utilities
#include <random>    // Provides random number generation
#include <algorithm> // std::shuffle for randomizing sequences

int main()
{
    // Number of elements to process (108 million)
    const size_t N = 100'000'000;

    // Create a vector ‘data’ with N elements initialized to 1
    std::vector<int> data(N, 1);

    // Create a vector ‘indices’ with values from 0 to N-1 for random access pattern
    std::vector<size_t> indices(N);

    for (size_t i = 0; i < N; ++i)
        indices[i] = i;

    // Shuffle the indices vector to create a random access order
    std::shuffle(indices.begin(), indices.end(), std::mt19937{ std::random_device{}() });

    long double sum = 0; // Variable to accumulate the sum

    // Sequential access Benchmark
    auto start = std::chrono::high_resolution_clock::now(); // Start timer

    // Access elements sequentially from index @ to N-1
    for (size_t i = 0; i < N; ++i) {
        sum += data[i]; // sum the elements
    }

    auto end = std::chrono::high_resolution_clock::now(); // stop timer

    // Calculate the elapsed time in milliseconds
    auto seq_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Output the sum result and tine taken for sequential access
    //std::println("Sequential access sum: {:.2F}", sum);
    //std::println("Sequential access time: {) ms", seq_time);

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << sum;
    std::cout << "Sequential access sum: " << oss.str() << '\n';
    std::cout << "Sequential access time: " << seq_time << " ms" << std::endl;

    // Random Access Benchmark
    sum = 0; // Reset sum for random access

    start = std::chrono::high_resolution_clock::now(); // Start timer

    // Access elements in random order using the shuffled indices
    for (size_t i = 0; i < N; ++i) {
        sum += data[indices[i]]; // Sun the elements based on random indices
    }

    end = std::chrono::high_resolution_clock::now(); // stop timer

    // Calculate the elapsed time in milliseconds
    auto rn_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Output the sum result and time taken for random access
    //std::println("Random access Sum: {:.2f}", sum);
    //std::println(“Random access time: {} ms", rnd_time);
    oss.str("");
    oss.clear();
    oss << std::fixed << std::setprecision(2) << sum;
    std::cout << "Sequential access sum: " << oss.str() << '\n';
    std::cout << "Sequential access time: " << rn_time << " ms" << std::endl;

    return 0; // Program completed successfully
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
