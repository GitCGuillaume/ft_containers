#ifndef MAP_HPP
# define MAP_HPP

#include "../iterators/BidirectionalIterator.hpp"
#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"

template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
    public:
        typedef Key key_type;
        typedef T   mapped_type;
        typedef ft::pair<const Key, T> value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t  difference_type;
        typedef Compare key;
        typedef Allocator   allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename Allocator::pointer  pointer;
        typedef typename Allocator::const_pointer    const_pointer;
        //typedef ft::LegacyBidirectionalIterator<value_type, map> iterator;
        //typedef ft::LegacyBidirectionalIterator<const value_type, map> const_iterator;
        //typedef ft::reverse_iterator<iterator>  reverse_iterator;
        //typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
};

#endif