#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include "../library_headers/is_same.hpp"
#include <iostream>

namespace ft
{
    template<class It, class Container>
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
            //typedef It    iterator_type;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::value_type    value_type;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::difference_type    difference_type;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::reference    reference;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::pointer    pointer;
            typedef typename ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, It> >::iterator_category    iterator_category;

            RandomAccessIterator() : _ptr(){};
            //explicit RandomAccessIterator(const iterator_type it) : _ptr(it){}
            RandomAccessIterator(pointer ptr) : _ptr(ptr) {}
           // RandomAccessIterator(RandomAccessIterator const & rhs) : _ptr(rhs.base()){}
            /*
             *  Convert iterator to const_iterator
             *  iterator will choose non const function if container is not const
            */
            template<typename U>
            RandomAccessIterator(const RandomAccessIterator<U
                , typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value), Container>::type>& rhs) : _ptr(rhs.base()){}
            pointer   base() const
            {
                return (this->_ptr);
            }
            RandomAccessIterator & operator=(RandomAccessIterator const & rhs)
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
    template<class Iterator, class Container>
    bool    operator!=(const ft::RandomAccessIterator<Iterator, Container>& lhs, const ft::RandomAccessIterator<Iterator, Container>& rhs)
    {
        if (lhs.operator->() != rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator, class Container>
    bool    operator==(const ft::RandomAccessIterator<Iterator, Container>& lhs, const ft::RandomAccessIterator<Iterator, Container>& rhs)
    {
        if (lhs.operator->() == rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator, class Container>
    bool    operator<(const ft::RandomAccessIterator<Iterator, Container>& lhs, const ft::RandomAccessIterator<Iterator, Container>& rhs)
    {
        return ((lhs.operator->() < rhs.operator->()) ? true : false);
    }
    template<class Iterator, class Container>
    bool    operator>(const ft::RandomAccessIterator<Iterator, Container>& lhs, const ft::RandomAccessIterator<Iterator, Container>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator, class Container>
    bool    operator<=(const ft::RandomAccessIterator<Iterator, Container>& lhs, const ft::RandomAccessIterator<Iterator, Container>& rhs)
    {
        return ((lhs.operator->() <= rhs.operator->()) ? true : false);
    }
    template<class Iterator, class Container>
    bool    operator>=(const ft::RandomAccessIterator<Iterator, Container>& lhs, const ft::RandomAccessIterator<Iterator, Container>& rhs)
    {
        return (rhs <= lhs);
    }
    template<class Iterator, class Container>
    RandomAccessIterator<Iterator, Container>  operator+(typename RandomAccessIterator<Iterator, Container>::difference_type n, const RandomAccessIterator<Iterator, Container>& it)
    {
        return &*(it + n);
    }
    template<class Iterator, class Container>
    typename    RandomAccessIterator<Iterator, Container>::difference_type operator-(const RandomAccessIterator<Iterator, Container>& lhs, const RandomAccessIterator<Iterator, Container>& rhs)
    {
        return (lhs.base() - rhs.base());
    }

    /* CONST ITERATOR */
    template<class Iterator1, class Iterator2, class Container>
    bool    operator!=(const ft::RandomAccessIterator<Iterator1, Container>& lhs, const ft::RandomAccessIterator<Iterator2, Container>& rhs)
    {
        if (lhs.operator->() != rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator==(const ft::RandomAccessIterator<Iterator1, Container>& lhs, const ft::RandomAccessIterator<Iterator2, Container>& rhs)
    {
        if (lhs.operator->() == rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator<(const ft::RandomAccessIterator<Iterator1, Container>& lhs, const ft::RandomAccessIterator<Iterator2, Container>& rhs)
    {
        return ((lhs.operator->() < rhs.operator->()) ? true : false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator>(const ft::RandomAccessIterator<Iterator1, Container>& lhs, const ft::RandomAccessIterator<Iterator2, Container>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator<=(const ft::RandomAccessIterator<Iterator1, Container>& lhs, const ft::RandomAccessIterator<Iterator2, Container>& rhs)
    {
        return ((lhs.operator->() <= rhs.operator->()) ? true : false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator>=(const ft::RandomAccessIterator<Iterator1, Container>& lhs, const ft::RandomAccessIterator<Iterator2, Container>& rhs)
    {
        return (rhs <= lhs);
    }
    template<class Iterator, class Iterator2, class Container>
    typename    RandomAccessIterator<Iterator, Container>::difference_type operator-(const RandomAccessIterator<Iterator, Container>& lhs, const RandomAccessIterator<Iterator2, Container>& rhs)
    {
        return (lhs.base() - rhs.base());
    }
}
#endif
