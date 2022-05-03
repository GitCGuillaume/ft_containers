#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
#include "iterator_traits.hpp"
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
        public:
            typedef It		value_type;
            typedef typename std::ptrdiff_t	difference_type;
            typedef value_type&		reference;
            typedef value_type*		pointer;
            typedef std::random_access_iterator_tag	iterator_category;
            RandomAccessIterator(){};
            RandomAccessIterator(pointer ptr)
            {
                this->_ptr = ptr;
            }
            RandomAccessIterator(RandomAccessIterator const & rhs) : _ptr(rhs.base()){}
            pointer base() const
            {
                return (this->_ptr);
            }
            /* Tester deep copy plus tard */
            RandomAccessIterator & operator=(RandomAccessIterator const & rhs)
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
            /*difference_type operator-(reference const rhs) const
            {
                std::cout << "this->ptr= " << this->_ptr << std::endl;
                    return (this->_ptr - rhs._ptr);
            }*/
            reference   operator[](std::size_t n) const
            {
                return (*(this->_ptr + n));
            }
            /* https://en.cppreference.com/w/cpp/named_req/EqualityComparable */
        private:
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
