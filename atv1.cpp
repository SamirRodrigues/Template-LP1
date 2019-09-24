#include <iostream>
#include <vector>
#include <iterator>

#include "atv1.h"
const bool cmp(const int &a, const int &b)
{
    return a < b; // If a < b return true else return false;
}

void q1()
{
    int A[50];
    int count = 0;

    for(int & e : A) //Range for
    {
        e = count;
        count += 1;
        std::cout << e << " ";
    }

    std::pair<int *, int *> result; 

    result = lp1::minmax( std::begin(A), std::end(A), cmp);

    std::cout << std::endl;
    std::cout << std::endl << "Min >>> " << *result.first 
              << std::endl << "Max >>> " << *result.second 
              << std::endl;
}

void q2()
{
    int A[50];
    int count = 0;

    std::cout << "Normal: " << std::endl; 
    for(int & e : A) //Range for
    {
        e = count;
        count += 1;
        std::cout << e << " ";
    }
    
    lp1::reverse(std::begin(A), std::end(A));

    std::cout << std::endl << "Reverse: " << std::endl;
    for(int & e : A) //Range for
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::cout << std::endl;
    std::cout << " >>> QUESTION NUMBER 1 <<<" << std::endl;
    q1();
    std::cout << std::endl;
    std::cout << ">>> QUESTION NUMBER 2 <<<" << std::endl;
    q2();
    std::cout << std::endl;
    std::cout << ">>> QUESTION NUMBER 3 <<<" << std::endl;
    //q3();
    return 0;    
}