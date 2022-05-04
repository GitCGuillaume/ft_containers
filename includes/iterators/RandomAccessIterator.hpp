#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
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
            typedef std::random_access_iterator_tag	iterator_category;

            RandomAccessIterator(){};
            explicit RandomAccessIterator(iterator_type it) : _ptr(it._ptr){std::cout << "iterator_type it" << std::endl;}
            RandomAccessIterator(pointer ptr)
            {
                this->_ptr = ptr;
            }
            template<class U>
            RandomAccessIterator(RandomAccessIterator<U> const & rhs) : _ptr(rhs.base()){std::cout << "random copy" << std::endl;}
            pointer base() const
            {
                return (this->_ptr);
            }
            /* Tester deep copy plus tard */
            template<class U>
            RandomAccessIterator & operator=(RandomAccessIterator<U> const & rhs)
            {
                if (this != &rhs)
                {
                    this->_ptr = rhs._ptr;
                }
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
            reference operator+=(difference_type n)
            {
                return (this->_ptr = this->_ptr + n);
            }
            reference operator-=(difference_type n)
            {
                return (this->_ptr = this->_ptr - n);
            }
            RandomAccessIterator    operator+(difference_type n) const
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
            RandomAccessIterator  operator-(difference_type n) const
            {
                return (this->_ptr - n);
            }
            difference_type operator-(reference const rhs) const
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
        return (rhs.operator->() - lhs.operator->());
    }
}
#endif
