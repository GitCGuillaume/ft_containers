#ifndef MAP_HPP
# define MAP_HPP

#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"

template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
class map
{

};

#endif