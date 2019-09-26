#include <iostream>
#include <vector>
#include <iterator>

#include "include/atv.h"
const bool cmp(const int &a, const int &b)
{
    return a < b; // If a < b return true else return false;
}

const bool predicate(const int &a)
{ 
    return a > 30;   
}

const bool equal(const int &a, const int &b)
{ 
    return a == b;   
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

void q3()
{
    int A[50];
    int B[50];
    int count = 0;

    std::cout << "A: " << std::endl; 
    for(int & e : A) //Range for
    {
        e = count;
        count += 1;
        std::cout << e << " ";
    }
    
    auto last_B = lp1::copy(std::begin(A), std::end(A), std::begin(B));

    std:: cout << std::endl << *last_B-1;

    std::cout << std::endl << "A Copied (B) : " << std::endl;
    for(int & e : B) //Range for
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;


    for (size_t i = count; i > 0 ; i--)
    {
        *(last_B-1) = 0;
        last_B--;
    }
    

    for(int & e : B) //Range for
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void q4()
{
    int A[50];    
    int count = 0;

    std::cout << "A: " << std::endl; 
    for(int & e : A) //Range for
    {
        e = count;
        count += 1;
        std::cout << e << " ";
    }
    
    auto result = lp1::find_if( std::begin(A), std::end(A), predicate );

    std:: cout << std::endl  << "Result: " << *result << std::endl;

}

void q5()
{
    int A[50];    
    int count = 0;

    std::cout << "A: " << std::endl; 
    for(int & e : A) //Range for
    {
        e = count;
        count += 1;
        std::cout << e << " ";
    }
    
    auto result = lp1::find( std::begin(A), std::end(A), 30, equal );

    std:: cout << std::endl  << "Result: " << *result << std::endl;
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
    q3();
    std::cout << std::endl;
    std::cout << ">>> QUESTION NUMBER 4 <<<" << std::endl;
    q4();
    std::cout << std::endl;
    std::cout << ">>> QUESTION NUMBER 5 <<<" << std::endl;
    q5();
    return 0;    
}