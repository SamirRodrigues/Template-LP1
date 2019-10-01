
#include <array>
#include <string>
#include <locale>
#include <ios>
#include <iostream>

class my_fr : public std::numpunct< char > {
protected:
    char do_decimal_point() const { return ','; }
    char do_thousands_sep() const { return '.'; }
    std::string do_grouping() const { return "\3"; }
    std::string do_truename() const { return "True";  }
    std::string do_falsename() const { return "False"; }
};


#include "include/atv.h"
#include "graal.h"


const bool cmp(const int &a, const int &b)
{
    return a < b; // If a < b return true else return false;
}

const bool predicate(const int &a)
{ 
    return a > 30;   
}

const bool test_equal(const int &a, const int &b)
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
    
    auto result = lp1::find( std::begin(A), std::end(A), 30, test_equal );

    std:: cout << std::endl  << "Result: " << *result << std::endl;
}



void q6()
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
    
    auto result1 = lp1::all_of( std::begin(A), std::end(A), predicate );
    auto result2 = lp1::any_of( std::begin(A), std::end(A), predicate );
    auto result3 = lp1::none_of( std::begin(A), std::end(A), predicate );

    std:: cout << std::endl;
    std:: cout << std::endl  << "Result 1: " << result1 << std::endl;
    std:: cout <<               "Result 2: " << result2 << std::endl;
    std:: cout <<               "Result 3: " << result3 << std::endl;
}

void q7()
{
    int A[50];
    int B[50];
    int C[60];       
    int count = 0;

    std::cout << "A: " << std::endl; 
    for(int & e : A) //Range for
    {
        e = count;
        count += 1;
        std::cout << e << " ";
    }
    count = 0;
    std::cout << std::endl << "B: " << std::endl; 
    for(int & e : B) //Range for
    {
        e = count;
        count += 2;
        std::cout << e << " ";
    }
    count = 0;
    std::cout << std::endl << "C: " << std::endl; 
    for(int & e : C) //Range for
    {
        e = count;
        count += 1;
        std::cout << e << " ";
    }

    auto result1 = lp1::equal( std::begin(A), std::end(A), std::begin(B), test_equal );
    std:: cout << std::endl  << "Result 1: " << result1 << std::endl;
    auto result2 = lp1::equal( std::begin(A), std::end(A), std::begin(C), std::end(C), test_equal );
    std:: cout << std::endl  << "Result 2: " << result2 << std::endl;
}

void q8()
{
    int A[11] = { 1,1,2,2,3,3,4,5,4,7,1};

    auto result = lp1::unique(std::begin(A), std::end(A), test_equal);
    std:: cout << std::endl  << "Result: " << *result << std::endl;
}

int main()
{
    std::cout.imbue(std::locale(std::locale(), new my_fr));
    std::cout << std::boolalpha;
    /*
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
    std::cout << std::endl;
    std::cout << ">>> QUESTION NUMBER 6 <<<" << std::endl;
    q6();
    std::cout << std::endl;
    std::cout << ">>> QUESTION NUMBER 7 <<<" << std::endl;
    q7();
    */
    std::cout << std::endl;
    std::cout << ">>> QUESTION NUMBER 8 <<<" << std::endl;
    q8();

    
    //std::cout << "Waiting to be Implemented" << std::endl;
    return 0;    
}