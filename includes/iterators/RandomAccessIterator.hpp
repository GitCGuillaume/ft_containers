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
            typedef It&		reference;
            typedef It*		pointer;
            typedef std::random_access_iterator_tag	iterator_category;
            RandomAccessIterator(){};
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
                    *this->_ptr = rhs->_ptr;
                }
                return (*this);
            };
            ~RandomAccessIterator(){};
            reference operator*()
            {
                return (*this->_ptr);
            }
            pointer operator->()
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
            It operator++(It)
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
            It  operator+(difference_type n)
            {
                return (this->_ptr + n);
            }
            //Peut être pas bersoin de la partie dif +
            /*difference_type  operator+(reference const rhs)
            {
                return (this->_ptr + rhs._ptr);
            }*/
             /* https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
            b - a */
            It  operator-(difference_type n)
            {
                return (this->_ptr - n);
            }
            difference_type operator-(reference const rhs)
            {
                    return (this->_ptr - rhs._ptr);
            }

            const reference operator--(It)
            {
                RandomAccessIterator tmp = *this;
                _ptr--;
                return (tmp);
            }
            reference   operator[](std::size_t n)
            {
                return (*(this->_ptr + n));
            }
            /* https://en.cppreference.com/w/cpp/named_req/EqualityComparable */
            bool    operator==(reference const rhs)
            {
                if (this->_ptr == rhs._ptr)
                    return (true);
                return (false);
            }
            bool    operator!=(reference const rhs)
            {
                if (this->_ptr != rhs._ptr)
                    return (true);
                return (false);
            }
            bool    operator>(reference const rhs)
            {
                return ((this->_ptr > rhs._ptr) ? true : false);
            }
            bool    operator<(reference const rhs)
            {
                return ((this->_ptr < rhs._ptr) ? true : false);
            }
            bool    operator>=(reference const rhs)
            {
                return ((this->_ptr >= rhs._ptr) ? true : false);
            }
            bool    operator<=(reference const rhs)
            {
                 return ((this->_ptr <= rhs._ptr) ? true : false);
            }
        private:
            pointer _ptr;
    };
}
#endif
