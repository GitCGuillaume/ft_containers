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
                return (&*(this->_current + 1));
            }
            reference  operator*() const
            {
                return (this->_current);
            }
            pointer  operator->() const
            {
                return (this->_current);
            }
            reference   operator[](std::size_t n) const
            {
                return (*(this->base()[-n - 1]));
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
            reverse_iterator    operator+(difference_type n) const
            {
                return (this->_current - n);
            }
            reverse_iterator    operator-(difference_type n) const
            {
                return (this->_current + n);
            }
            reverse_iterator&    operator+=(difference_type n)
            {
                return (this->_current - n);
            }
            reverse_iterator&   operator-=(difference_type n)
            {
                return (this->_current + n);
            }
        protected:
            pointer _current;
    };
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
        return ((lhs.base() < rhs.base()) ? true : false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Iterator1, class Iterator2>
    bool    operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return ((lhs.base() <= rhs.base()) ? true : false);
    }
    template<class Iterator1, class Iterator2>
    bool    operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (rhs <= lhs);
    }
    template<class Iter>
    reverse_iterator<Iter>  operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
        return (it.base() - n);
    }
    template<class Iter>
    reverse_iterator<Iter>  operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
        return (it.base() + n);
    }
}

#endif