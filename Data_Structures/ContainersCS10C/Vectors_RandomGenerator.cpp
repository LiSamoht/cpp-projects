/*
 Thomas Li
 CS10C
 08/28/2024
 Instructor: Dave Harden
 main.cpp

 This program generates a specified number of unique random integers within a given range.
 The program reads two integer inputs from the user: howMany (the number of unique integers to generate)
 and maxNum (the upper bound of the random integer range, exclusive). It then uses the UniqueRandomInts function
 to generate these unique random integers and tracks how many retries were needed due to duplicates.
 The generated integers are stored in a vector, and the number of retries is reported. 
 The program is seeded with a fixed value for reproducibility. The program expects two integers from the integer
 => howmany (number of unique random integers to generate) and maxNum (upper bound for random integer generation)
 The program outputs the unique random integers all separated by spaces.

*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;



void PrintNums(vector<int> nums, int size);
vector<int> UniqueRandomInts(unsigned int howMany, int maxNum, int& retries);


int main() {
    int howMany;
    int maxNum;
    int retries;

    cin >> howMany;
    cin >> maxNum;
    vector<int> uniqueInts;

    srand(641);                      // Seed random number generator for testing

    uniqueInts = UniqueRandomInts(howMany, maxNum, retries);
    PrintNums(uniqueInts, howMany);
    cout << "  [" << retries << " retries]" << endl;
}





// Print the integers in vector nums separated by a space
void PrintNums(vector<int> nums, int size) {
    for (int i = 0; i < size; ++i) {
        cout << nums.at(i) << " ";
    }
}



// Generate howMany unique random integers 0 <= N < maxNum and return in nums
vector<int> UniqueRandomInts(unsigned int howMany, int maxNum, int& retries) {
    int nextRand;
    retries = 0;
    set<int> alreadySeen;
    vector<int> nums;

    for (int i = 0; i < howMany; i++) {
        nextRand = rand() % (maxNum);
        if (alreadySeen.count(nextRand)) {
            retries++;
            i--; /*backtracking step. If we essentially fail an iteration of generating a unique rand int, backtrack again to return.*/
        }
        else {
            nums.push_back(nextRand);
            alreadySeen.insert(nextRand);
        }
    }

    return nums;
}




