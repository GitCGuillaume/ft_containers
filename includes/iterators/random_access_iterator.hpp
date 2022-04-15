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
        private:
            typedef typename ft::iterator_traits<It>::value_type    value_type;
            typedef typename ft::iterator_traits<It>::difference_type   difference_type;
            typedef typename ft::iterator_traits<It>::reference     reference;
            typedef typename ft::iterator_traits<It>::pointer       pointer;
            typedef typename ft::iterator_traits<It>::iterator_category iterator_category;
            pointer ptr;

        public:
            RandomAccessIterator();
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
                    *this->ptr = rhs->ptr;
                }
                return (*this);
            };
            ~RandomAccessIterator();
            pointer operator*()
            {
                return (*this->ptr);
            }
            pointer operator->()
            {
                return (this->ptr);
            }
            /* PREFIX */
            reference operator++()
            {
                ptr++;
                return (this);
            }
            reference operator--()
            {
                ptr--;
                return (this);
            }
            /* POSTFIX*/
            It operator++(It)
            {
                RandomAccessIterator tmp = *this;
                ptr++;
                return (tmp);
            }

            reference operator+=(reference const rhs)
            {
                this->ptr = this->ptr + this->ptr;
            }
            reference operator-=(reference const rhs)
            {
                this->ptr = this->ptr - this->ptr;
            }
            It  operator+(difference_type n)
            {
                return (this->ptr + n);
            }
            //Peut être pas bersoin de la partie dif +
            /*difference_type  operator+(reference const rhs)
            {
                return (this->ptr + rhs.ptr);
            }*/
             /* https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
            b - a */
            It  operator-(difference_type n)
            {
                return (this->ptr - n);
            }
            difference_type operator-(reference const rhs)
            {
                    return (this->ptr - rhs.ptr);
            }

            const reference operator--(It)
            {
                RandomAccessIterator tmp = *this;
                ptr--;
                return (tmp);
            }
            reference   operator[](std::size_t n)
            {
                return (*(this->ptr + n));
            }
            /* https://en.cppreference.com/w/cpp/named_req/EqualityComparable */
            bool    operator==(reference const rhs)
            {
                if (this->ptr == rhs.ptr)
                    return (true);
                return (false);
            }
            bool    operator!=(reference const rhs)
            {
                if (this->ptr != rhs.ptr)
                    return (true);
                return (false);
            }
            bool    operator>(reference const rhs)
            {
                return ((this->ptr > rhs.ptr) ? true : false);
            }
            bool    operator<(reference const rhs)
            {
                return ((this->ptr < rhs.ptr) ? true : false);
            }
            bool    operator>=(reference const rhs)
            {
                return ((this->ptr >= rhs.ptr) ? true : false);
            }
            bool    operator<=(reference const rhs)
            {
                 return ((this->ptr <= rhs.ptr) ? true : false);
            }
    };
}
#endif
