#ifndef ATV1_H
#define ATV1_H

#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

namespace lp1
{
    template < typename Itr,  typename Compare >
    /*TYPE*/std::pair<Itr,Itr> /*FUNCTION*/minmax( Itr first, Itr last, Compare cmp )
    {
        Itr min = first;
        Itr max = first;
        while(first != last)
        {
            if (cmp(*first,*min))
            {
                min = first;
            }
            else if (cmp (*max, *first))
            {
                max = first;
            }
            
            
            first += 1;
        }
        return std::make_pair(min,max);
    }

    template < typename Itr >    
    void reverse( Itr first, Itr last )
    {
        while(first != last)
        {
            std::swap(*first,*(last-1));
            last -= 1;
            first += 1;
        }
    }

    template < typename Itr >    
    Itr copy( Itr first, Itr last, Itr d_first)
    {
        while(first != last)
        {
            *d_first = *first;
            d_first++;
            first++;
        }

        return d_first;
    }

    template < typename Itr, typename Predicate >
    Itr find_if( Itr first, Itr last, Predicate p)
    {
        while(first != last)
        {
            if (p(*first))
            {
                break;
            } 

            first++;
        }

        return first;
    }

    template < typename Itr, typename T, typename Equal >
    Itr find( Itr first, Itr last, const T & value, Equal eq )
    {
        while(first != last)
        {
            if (eq(*first, value))
            {
                break;
            } 

            first++;
        }

        return first;
    }

    template < typename Itr, typename Predicate >
    bool all_of( Itr first, Itr last, Predicate p )
    {
        if(first == last){return true;}

        while(first != last)
        {
            if (!p(*first))
            {
                return false;
            } 

            first++;
        }

        return true;
    }

    template < typename Itr, typename Predicate >
    bool any_of( Itr first, Itr last, Predicate p )
    {
        if(first == last){return true;}

        while(first != last)
        {
            if (!p(*first))
            {
                return false;
            } 

            first++;
        }
        
        return true;
    }

    template < typename Itr, typename Predicate >
    bool none_of( Itr first, Itr last, Predicate p )
    {
        if(first == last){return true;}

        while(first != last)
        {
            if (p(*first))
            {
                return false;
            } 

            first++;
        }

        return true;
    }

    template <typename Itr, typename Equal>
    bool equal(Itr first1, Itr last1, Itr first2, Equal eq)
    {
        while(first1 < last1)
        {
            if(!eq(*first1, *first2))
            {
                return false;                
            }

            first1++;
            first2++;
        }

        return true;
    }

    template <typename Itr, typename Equal>
    bool equal (Itr first1, Itr last1, Itr first2, Itr last2, Equal eq)
    {
        if(last1-first1 != last2-first2)
        {
            return false;
        }

        while(first1 != last1)
        { 
            if(!eq(*first1, *first2))
            {
                return false;
            }                
            
            first1++;
            first2++;
        }

        return true;
    }

    template<typename Itr, typename Equal>
    Itr unique(Itr first1, Itr last1, Equal eq)
    {        
        Itr inicio = first1;
        Itr auxiliar = first1 + 1;

        int size1 = (last1 - 1) - inicio;
        int array2[size1];

        Itr ponteiro = first1; 
        Itr first2 = &array2[0];
        Itr inicio2 = &array2[0];
        Itr last2 = &array2[size1];

        while(inicio < last1)
        {
            if (auxiliar != inicio && eq(*auxiliar,*inicio))
            {
                *last2 = *inicio;
                last2--;
                inicio++;
                auxiliar = first1;
            }
            else if(auxiliar == last1 && !eq(*auxiliar,*inicio))
            {
                *first2 = *inicio;
                first2++;
                inicio++;
                auxiliar = first1;
                ponteiro++;                
            }
            else
            {
                auxiliar++;
            }
        }
        
        for (int i = 0; i <= size1; i++)
        {
            *first1 = *inicio2;
            std::cout << *first1 << " ";
            first1++;
            inicio2++;
        }

        return ponteiro;
    }
}

#endif