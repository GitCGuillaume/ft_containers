#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include <iostream>

namespace ft
{
    template<class It>
    class RandomAccessIterator
    {
        /*Oublie pas de test les const */
        /*
            https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
            value_type, the type denoted by std::iterator_traits<It>::value_type
            [...]
        */
        /* Use ft::iterator into iterator_traits to use iterator_traits types (is this dispatch tag?) correctly */
        public:
            typedef It    iterator_type;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::value_type    value_type;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::difference_type    difference_type;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::reference    reference;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::pointer    pointer;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::iterator_category    iterator_category;

            RandomAccessIterator(){};
            explicit RandomAccessIterator(iterator_type it) : _ptr(it){}
            RandomAccessIterator(pointer ptr)
            {
                this->_ptr = ptr;
            }
            //template<class U>
            RandomAccessIterator(const RandomAccessIterator & rhs) : _ptr(rhs.base()){}
            const pointer   base() const
            {
                return (this->_ptr);
            }
            /* Tester deep copy plus tard */
            //template<class U>
            RandomAccessIterator & operator=(const RandomAccessIterator & rhs)
            {
                if (this != &rhs)
                    this->_ptr = rhs.base();
                return (*this);
            };
            virtual ~RandomAccessIterator(){};
            reference operator*() const
            {
                return (*this->_ptr);
            }
            pointer operator->() const
            {
                return (this->_ptr);
            }
            /* PREFIX */
            RandomAccessIterator& operator++()
            {
                _ptr++;
                return (*this);
            }
            RandomAccessIterator& operator--()
            {
                _ptr--;
                return (*this);
            }
            /* POSTFIX*/
            RandomAccessIterator operator++(int)
            {
                RandomAccessIterator tmp = *this;
                _ptr++;
                return (tmp);
            }
            RandomAccessIterator   operator--(int)
            {
                RandomAccessIterator tmp = *this;
                _ptr--;
                return (tmp);
            }
            RandomAccessIterator& operator+=(const difference_type n)
            {
                this->_ptr += n;
                return (*this);
            }
            RandomAccessIterator& operator-=(const difference_type n)
            {
                this->_ptr -= n;
                return (*this);
            }
            RandomAccessIterator    operator+(const difference_type n) const
            {
                return (this->_ptr + n);
            }
            //Peut être pas bersoin de la partie dif +
            /*difference_type  operator+(reference const rhs) const
            {
                return (this->_ptr + rhs._ptr);
            }*/
             /* https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
            b - a */
            RandomAccessIterator  operator-(const difference_type n) const
            {
                return (this->_ptr - n);
            }
            difference_type operator-(RandomAccessIterator const & rhs) const
            {
                return (this->_ptr - rhs._ptr);
            }
            reference   operator[](std::size_t n) const
            {
                return (*(this->_ptr + n));
            }
            /* https://en.cppreference.com/w/cpp/named_req/EqualityComparable */
        protected:
            pointer _ptr;
    };
    template<class Iterator1, class Iterator2>
    bool    operator!=(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        if (lhs.operator->() != rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator==(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        if (lhs.operator->() == rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator<(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return ((lhs.operator->() < rhs.operator->()) ? true : false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator>(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator1, class Iterator2>
    bool    operator<=(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return ((lhs.operator->() <= rhs.operator->()) ? true : false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator>=(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return (rhs <= lhs);
    }
    template<class Iterator>
    RandomAccessIterator<Iterator>  operator+(typename RandomAccessIterator<Iterator>::difference_type n, const RandomAccessIterator<Iterator>& it)
    {
        return &*(it + n);
    }
    template<class Iterator>
    typename    RandomAccessIterator<Iterator>::difference_type operator-(const RandomAccessIterator<Iterator>& lhs, const RandomAccessIterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
}
#endif
