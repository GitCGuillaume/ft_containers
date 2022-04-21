#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

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
            RandomAccessIterator(RandomAccessIterator const & rhs)
            {
                if (this != &rhs)
                    *this = rhs;
            };
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
            reference operator++()
            {
                _ptr++;
                return (this);
            }
            reference operator--()
            {
                _ptr--;
                return (this);
            }
            /* POSTFIX*/
            RandomAccessIterator operator++(It)
            {
                RandomAccessIterator tmp = *this;
                _ptr++;
                return (tmp);
            }
            reference operator+=(reference const rhs)
            {
                this->_ptr = this->_ptr + this->_ptr;
            }
            reference operator-=(reference const rhs)
            {
                this->_ptr = this->_ptr - this->_ptr;
            }
            It  operator+(difference_type n) const
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
            It  operator-(difference_type n) const
            {
                return (this->_ptr - n);
            }
            difference_type operator-(reference const rhs) const
            {
                    return (this->_ptr - rhs._ptr);
            }

            const reference operator--(It)
            {
                RandomAccessIterator tmp = *this;
                _ptr--;
                return (tmp);
            }
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
        if (*lhs != *rhs)
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator<(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return ((*lhs < *rhs) ? true : false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator>(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator1, class Iterator2>
    bool    operator<=(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return ((*lhs <= *rhs) ? true : false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator>=(const ft::RandomAccessIterator<Iterator1>& lhs, const ft::RandomAccessIterator<Iterator2>& rhs)
    {
        return (rhs <= lhs);
    }
    template<class Iter>
    RandomAccessIterator<Iter>  operator+(typename RandomAccessIterator<Iter>::difference_type n, const RandomAccessIterator<Iter>& it)
    {
        return *(it - n);
    }
    template<class Iter>
    RandomAccessIterator<Iter>  operator-(typename RandomAccessIterator<Iter>::difference_type n, const RandomAccessIterator<Iter>& it)
    {
        return *(it + n);
    }
}
#endif
