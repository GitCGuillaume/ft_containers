#ifndef MAP_HPP
# define MAP_HPP

#include "../iterators/BidirectionalIterator.hpp"
#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"
/*
template<class It>
struct s_node
{
        It*      pair;
        struct s_node*  head = NULL;
        struct s_node*  left = NULL;
        struct s_node*  right = NULL;
        char    colour;
};
*/

/*
    struct s_node* _node is a pointer because std::allocator allocate return pointer.
*/
#include <iostream>
namespace ft
{
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
            typedef ft::BidirectionalIterator<value_type, map, key_type, mapped_type, Allocator> iterator;
            typedef ft::BidirectionalIterator<const value_type, map, key_type, mapped_type, Allocator> const_iterator;
            //typedef ft::reverse_iterator<iterator>  reverse_iterator;
            //typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

            explicit    map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
                : _comp(comp), _allocator(alloc), _capacity_allocator(0)
            {
                _tree._iterator = new typename ft::BidirectionalIterator<value_type, map, key_type, mapped_type, Allocator>::node();
                _tree._iterator->colour = 0;
                _tree._iterator->pair = _allocator.allocate(1);
                _allocator.construct(_tree._iterator->pair, value_type()); //Call pair<>() constructor
            }
            template<class InputIt>
            map(InputIt first, InputIt second, const Compare& comp = Compare(),
                const Allocator& alloc = Allocator())
            {
                
            }
            virtual ~map()
            {
                _allocator.destroy(_tree._iterator->pair);
                _allocator.deallocate(_tree._iterator->pair, 1);
                delete _tree._iterator;
                _tree._iterator = NULL;
                //need to clear with erase / clear whatever
            }
            /*
            Elements Access
            */
            T&  operator[](const Key& key)
            {
                typename ft::BidirectionalIterator<value_type, map, key_type, mapped_type, Allocator>::node* new_node;
                new_node = new typename ft::BidirectionalIterator<value_type, map, key_type, mapped_type, Allocator>::node();
                new_node->pair = _allocator.allocate(1);
                _allocator.construct(new_node->pair, ft::pair<key_type, mapped_type>(key, T()));
                std::cout << "&newNode : " << new_node << std::endl;
                _tree._insert(new_node);
                _tree._search(new_node);
                return (_tree._iterator->pair->second);
            }
            iterator    begin()
            {
                return (_tree._iterator);
            }
        private:
            typename ft::BidirectionalIterator<value_type, map, key_type, mapped_type, Allocator>    _tree; //need to use RD iterator nodes somewhere
            Compare const  _comp;
            allocator_type	_allocator;
			size_type		_capacity_allocator;
    };
}

#endif