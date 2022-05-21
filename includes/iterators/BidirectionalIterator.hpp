#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include "../library_headers/is_same.hpp"
#include <iterator>

/*
        The iterator receive a ft::pair<>, but alone it won't do anything
        So need to create nodes for rotation + branches / leaves / whatever
*/

template<class T>
struct s_node
{
        T      pair;
        struct s_node*  head = NULL;
        struct s_node*  left = NULL;
        struct s_node*  right = NULL;
        char    colour;
};

namespace ft
{
        template<class It, class Container>
        class   BidirectionalIterator
        {
                public:
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::value_type    value_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::difference_type    difference_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::reference    reference;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::pointer    pointer;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::iterator_category    iterator_category;
                        typedef  s_node<pointer>       node;
                        BidirectionalIterator()
                        {
                                _iterator = node();
                        }
                        ~BidirectionalIterator()
                        {
                                //delete _iterator;
                        }
                        BidirectionalIterator(node* iterator) : _iterator(iterator){}
                        reference operator*() const
                        {
                                return (*_iterator->pair);
                        }
                        pointer operator->()
                        {
                                return (_iterator->pair);
                        }
                        node*  _iterator; // struct stocked here, used to iterate
        };
}

#endif