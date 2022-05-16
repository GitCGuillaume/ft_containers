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
            explicit    reverse_iterator(iterator_type it) : _current(it){}
            template<class U>
            reverse_iterator(const reverse_iterator<U>& rev_it) : _current(rev_it.base()){}
            /* cplusplus.com n'affiche pas de operator= mais cppreference si */
            template<class U>
            reverse_iterator &  operator=(const reverse_iterator& other)
            {
                if (this != &other)
                {
                    _current = other.base();
                }
                return (*this);
            }
            /* essayer de tester out of range */
            iterator_type   base() const
            {
                return (this->_current);
            }
            reference  operator*() const
            {
                Iter    tmp(this->_current);

                return (*--tmp);
            }
            pointer  operator->() const
            {
                return (&this->operator*());
            }
            reference   operator[](difference_type n) const
            {
                return ((this->base()[-n - 1]));
            }
            /* PRE */
            reverse_iterator&   operator++()
            {
                this->_current = this->_current - 1;
                return (*this);
            }
            reverse_iterator&   operator--()
            {
                this->_current = this->_current + 1;
                return (*this);
            }
            /* POST */
            reverse_iterator    operator++(int)
            {
                reverse_iterator    tmp = *this;

                this->_current = this->_current - 1;
                return (tmp);
            }
            reverse_iterator    operator--(int)
            {
                reverse_iterator    tmp = *this;

                this->_current = this->_current + 1;
                return (tmp);
            }
            /*
            *   -1 because a reverse iterator has always an offset of -1
            *   to it's base iterator
            */
            reverse_iterator    operator+(difference_type n) const
            {
                return (reverse_iterator(this->base() - n));
            }
            reverse_iterator    operator-(difference_type n) const
            {
                return (reverse_iterator(this->base() + n));
            }
            reverse_iterator&    operator+=(difference_type n)
            {
                this->_current -= n;
                return (*this);
            }
            reverse_iterator&   operator-=(difference_type n)
            {
                this->_current += n;
                return (*this);
            }
        protected:
            Iter _current;
    };

    template<class Iterator>
    bool    operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        if (lhs.base() == rhs.base())
            return true;
        return (false);
    }
    template<class Iterator>
    bool    operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        if (lhs.base() != rhs.base())
            return true;
        return (false);
    }
    template<class Iterator>
    bool    operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return ((rhs.base() < lhs.base()) ? true : false);
    }
    template<class Iterator>
    bool    operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator>
    bool    operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (!(lhs > rhs));
    }
    template<class Iterator>
    bool    operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (!(lhs < rhs));
    }
    /* rit = rit + ? */
    template<class Iter>
    reverse_iterator<Iter>  operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
        return (reverse_iterator<Iter>(it.base() - n));
    }
    template<class Iter>
    typename    reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
    /* PARTIE CONST ITERATOR */
    template<class Iterator1, class Iterator2>
    bool    operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        if (lhs.base() == rhs.base())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        if (lhs.base() != rhs.base())
            return true;
        return (false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return ((rhs.base() < lhs.base()) ? true : false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator1, class Iterator2>
    bool    operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (!(lhs > rhs));
    }
    template<class Iterator1, class Iterator2>
    bool    operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (!(lhs < rhs));
    }
    template<class Iter, class Iter2>
    typename    reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter2>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
}

#endif