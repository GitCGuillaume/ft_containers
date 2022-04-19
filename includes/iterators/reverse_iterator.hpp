#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template<class Iter> class  reverse_iterator
    {
        public:
            typedef Iter    iterator_type;
            typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type    value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type   difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer       pointer;
            typedef typename ft::iterator_traits<Iter>::reference     reference;
            reverse_iterator(){};
            explicit    reverse_iterator(iterator_type it) : iterator_type(it)
            {
                return ;
            }
            template<class U>
            reverse_iterator(const reverse_iterator<U>& rev_it) //: iterator_type(rev_it.iterator_type), iterator_category(rev_it.iterator_category),
            //    value_type(rev_it.value_type), difference_type(rev_it.difference_type), pointer(rev_it.pointer), reference(rev_it.reference)
            {
                return ;
            }
            template<class U>
            reverse_iterator &  operator=(const reverse_iterator<U>& other)
            {
                if (this != &other)
                    *this = other;
                return (*this);
            }
            /* essayer de tester out of range */
            iterator_type   base() const
            {
                return ();
            }

        private:
            
    };
}

#endif