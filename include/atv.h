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

}

#endif