#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include "../library_headers/is_same.hpp"

namespace ft
{
    template<class It, class Container>
    class random_access_iterator
    {
        /*Oublie pas de test les const */
        /*
            https://en.cppreference.com/w/cpp/named_req/random_access_iterator
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

            random_access_iterator() : _ptr(){};
            random_access_iterator(pointer ptr) : _ptr(ptr) {}
            /*
             *  Convert iterator to const_iterator
             *  iterator will choose non const function if container is not const
            */
            template<typename U>
            random_access_iterator(const random_access_iterator<U
                , typename ft::enable_if<ft::is_same<U, typename Container::value_type>::value, Container>::type>& rhs) : _ptr(rhs.base()){}
            pointer   base() const
            {
                return (this->_ptr);
            }
            random_access_iterator & operator=(random_access_iterator const & rhs)
            {
                if (this != &rhs)
                    this->_ptr = rhs.base();
                return (*this);
            };
            virtual ~random_access_iterator(){};
            reference operator*() const
            {
                return (*_ptr);
            }
            pointer operator->() const
            {
                return (_ptr);
            }
            /* PREFIX */
            random_access_iterator& operator++()
            {
                ++_ptr;
                return (*this);
            }
            random_access_iterator& operator--()
            {
                --_ptr;
                return (*this);
            }
            /* POSTFIX*/
            random_access_iterator operator++(int)
            {
                random_access_iterator tmp(*this);
                ++_ptr;
                return (tmp);
            }
            random_access_iterator   operator--(int)
            {
                random_access_iterator tmp(*this);
                --_ptr;
                return (tmp);
            }
            random_access_iterator& operator+=(const difference_type n)
            {
                this->_ptr += n;
                return (*this);
            }
            random_access_iterator& operator-=(const difference_type n)
            {
                this->_ptr -= n;
                return (*this);
            }
            random_access_iterator    operator+(const difference_type n) const
            {
                return (_ptr + n);
            }
            /* https://en.cppreference.com/w/cpp/named_req/random_access_iterator
            b - a */
            random_access_iterator  operator-(const difference_type n) const
            {
                return (_ptr - n);
            }
            difference_type operator-(random_access_iterator const & rhs) const
            {
                return (_ptr - rhs._ptr);
            }
            reference   operator[](std::size_t n) const
            {
                return (*(_ptr + n));
            }
            /* https://en.cppreference.com/w/cpp/named_req/EqualityComparable */
        protected:
            pointer _ptr;
    };
    template<class Iterator, class Container>
    bool    operator!=(const ft::random_access_iterator<Iterator, Container>& lhs, const ft::random_access_iterator<Iterator, Container>& rhs)
    {
        if (lhs.operator->() != rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator, class Container>
    bool    operator==(const ft::random_access_iterator<Iterator, Container>& lhs, const ft::random_access_iterator<Iterator, Container>& rhs)
    {
        if (lhs.operator->() == rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator, class Container>
    bool    operator<(const ft::random_access_iterator<Iterator, Container>& lhs, const ft::random_access_iterator<Iterator, Container>& rhs)
    {
        return ((lhs.operator->() < rhs.operator->()) ? true : false);
    }
    template<class Iterator, class Container>
    bool    operator>(const ft::random_access_iterator<Iterator, Container>& lhs, const ft::random_access_iterator<Iterator, Container>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator, class Container>
    bool    operator<=(const ft::random_access_iterator<Iterator, Container>& lhs, const ft::random_access_iterator<Iterator, Container>& rhs)
    {
        return ((lhs.operator->() <= rhs.operator->()) ? true : false);
    }
    template<class Iterator, class Container>
    bool    operator>=(const ft::random_access_iterator<Iterator, Container>& lhs, const ft::random_access_iterator<Iterator, Container>& rhs)
    {
        return (rhs <= lhs);
    }
    template<class Iterator, class Container>
    random_access_iterator<Iterator, Container>  operator+(typename random_access_iterator<Iterator, Container>::difference_type n, const random_access_iterator<Iterator, Container>& it)
    {
        return &*(it + n);
    }
    template<class Iterator, class Container>
    typename    random_access_iterator<Iterator, Container>::difference_type operator-(const random_access_iterator<Iterator, Container>& lhs, const random_access_iterator<Iterator, Container>& rhs)
    {
        return (lhs.base() - rhs.base());
    }

    /* CONST ITERATOR */
    template<class Iterator1, class Iterator2, class Container>
    bool    operator!=(const ft::random_access_iterator<Iterator1, Container>& lhs, const ft::random_access_iterator<Iterator2, Container>& rhs)
    {
        if (lhs.operator->() != rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator==(const ft::random_access_iterator<Iterator1, Container>& lhs, const ft::random_access_iterator<Iterator2, Container>& rhs)
    {
        if (lhs.operator->() == rhs.operator->())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator<(const ft::random_access_iterator<Iterator1, Container>& lhs, const ft::random_access_iterator<Iterator2, Container>& rhs)
    {
        return ((lhs.operator->() < rhs.operator->()) ? true : false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator>(const ft::random_access_iterator<Iterator1, Container>& lhs, const ft::random_access_iterator<Iterator2, Container>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator<=(const ft::random_access_iterator<Iterator1, Container>& lhs, const ft::random_access_iterator<Iterator2, Container>& rhs)
    {
        return ((lhs.operator->() <= rhs.operator->()) ? true : false);
    }
    template<class Iterator1, class Iterator2, class Container>
    bool    operator>=(const ft::random_access_iterator<Iterator1, Container>& lhs, const ft::random_access_iterator<Iterator2, Container>& rhs)
    {
        return (rhs <= lhs);
    }
    template<class Iterator, class Iterator2, class Container>
    typename    random_access_iterator<Iterator, Container>::difference_type operator-(const random_access_iterator<Iterator, Container>& lhs, const random_access_iterator<Iterator2, Container>& rhs)
    {
        return (lhs.base() - rhs.base());
    }
}
#endif
