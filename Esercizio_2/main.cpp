#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <unistd.h>
#include <numeric>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace std::chrono;
using namespace SortLibrary;

//function to generate a vector of random integers
vector<int> generateRandomVector(int size) {
    vector<int> randomVector(size);

    for (int i = 0; i < size; ++i) {
        randomVector[i] = rand();
    }

    return randomVector;
}

//function to generate a vector of increasing integers
vector<int> generateIncreasingVector(int size) {
    vector<int> increasingVector(size);
    int n = 1;
    generate(increasingVector.begin(), increasingVector.end(), [&n]() { return n++; });
    return increasingVector;
}

//function to generate a vector of decreasing integers
vector<int> generateDecreasingVector(int size) {
    vector<int> decreasingVector(size);
    int n = size;
    generate(decreasingVector.begin(), decreasingVector.end(), [&n]() { return n--; });
    return decreasingVector;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        cerr << "Error: Insufficient command-line arguments." << endl;
        return 1;
    }

    //gestione dell'errore
    vector<int> dimensions;
    for (int i = 1; i < argc; ++i) {
        try {
            int dim = stoi(argv[i]); //string to int
            dimensions.push_back(dim);
        } catch (const invalid_argument& e) {
            cerr << "Error: Invalid argument. Please provide an integer for vector size." << endl;
            return 1;
        }
    }

    for (int dim : dimensions) {
        cout << "Dimension: " << dim << endl;



        //generate and print random vector
        vector<int> randomVector = generateRandomVector(dim);
        cout << "Random Vector:" << endl;
        for (int i = 0; i < dim; ++i) {
            cout << randomVector[i] << " ";
        }
        cout << endl;

        //generate and print increasing vector
        vector<int> increasingVector = generateIncreasingVector(dim);
        cout << "Increasing Vector:" << endl;
        for (int i = 0; i < dim; ++i) {
            cout << increasingVector[i] << " ";
        }
        cout << endl;

        //generate and print decreasing vector
        vector<int> decreasingVector = generateDecreasingVector(dim);
        cout << "Decreasing Vector:" << endl;
        for (int i = 0; i < dim; ++i) {
            cout << decreasingVector[i] << " ";
        }
        cout << endl;

        //Test BubbleSort
        vector<int> randomVectorBubble = randomVector; //copy
        steady_clock::time_point t_begin = steady_clock::now();
        BubbleSort(randomVectorBubble);
        steady_clock::time_point t_end = steady_clock::now();
        double bubbleRandomTime = duration_cast<microseconds>(t_end - t_begin).count();

        vector<int> increasingVectorBubble = increasingVector; //copy
        t_begin = steady_clock::now();
        BubbleSort(increasingVectorBubble);
        t_end = steady_clock::now();
        double bubbleIncreasingTime = duration_cast<microseconds>(t_end - t_begin).count();

        vector<int> decreasingVectorBubble = decreasingVector; //copy
        t_begin = steady_clock::now();
        BubbleSort(decreasingVectorBubble);
        t_end = steady_clock::now();
        double bubbleDecreasingTime = duration_cast<microseconds>(t_end - t_begin).count();

        //Test MergeSort
        vector<int> randomVectorMerge = randomVector;
        t_begin = steady_clock::now();
        MergeSort(randomVectorMerge);
        t_end = steady_clock::now();
        double mergeRandomTime = duration_cast<microseconds>(t_end - t_begin).count();

        vector<int> increasingVectorMerge = increasingVector;
        t_begin = steady_clock::now();
        MergeSort(increasingVectorMerge);
        t_end = steady_clock::now();
        double mergeIncreasingTime = duration_cast<microseconds>(t_end - t_begin).count();

        vector<int> decreasingVectorMerge = decreasingVector;
        t_begin = steady_clock::now();
        MergeSort(decreasingVectorMerge);
        t_end = steady_clock::now();
        double mergeDecreasingTime = duration_cast<microseconds>(t_end - t_begin).count();


        cout << "BubbleSort Time of random vector (dim:"<<dim<<"): " << bubbleRandomTime << " microseconds" << endl;
        cout << "BubbleSort Time of increasing vector (dim:"<<dim<<"): " << bubbleIncreasingTime << " microseconds" << endl;
        cout << "BubbleSort Time of decreasing vector(dim:"<<dim<<"): " << bubbleDecreasingTime << " microseconds" << endl;

        cout << "MergeSort Time of random vector (dim:"<<dim<<"): "  << mergeRandomTime << " microseconds" << endl;
        cout << "MergeSort Time of increasing vector (dim:"<<dim<<"): "  << mergeIncreasingTime << " microseconds" << endl;
        cout << "MergeSort Time of increasing vector (dim:"<<dim<<"): "  << mergeDecreasingTime << " microseconds" << endl;

    }

    return 0;
}
