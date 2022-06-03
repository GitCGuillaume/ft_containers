#ifndef MAP_HPP
# define MAP_HPP

#include "../iterators/RedBlackTree.hpp"
#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"
#include <stdexcept>

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
            typedef typename ft::RedBlackTree<value_type, map, key_type, mapped_type, Allocator>::BiDirectionnalIterator iterator;
            typedef typename ft::RedBlackTree<value_type, map, key_type, mapped_type, Allocator>::BiDirectionnalIterator const_iterator;
            //typedef ft::reverse_iterator<iterator>  reverse_iterator;
            //typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
            class   value_compare : public ft::binary_function<value_type, value_type, bool>
            {
                protected:
                    Compare comp;
                    value_compare(Compare C) : comp(C){}
                    bool    operator()(const value_type& lhs, const value_type& rhs) const
                    {
                        return (comp(lhs.first, rhs.first));
                    }
            };

            explicit    map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
                : _comp(comp), _allocator(alloc), _capacity_allocator(1)
            {
                _tree._iterator = new typename _RB_tree::node();
                _tree._iterator->colour = 0;
                _tree._iterator->pair = _allocator.allocate(1);
                _allocator.construct(_tree._iterator->pair, value_type()); //Call pair<>() constructor
            }
            template<class InputIt>
            map(InputIt first, InputIt second, const Compare& comp = Compare(),
                const Allocator& alloc = Allocator()) : _comp(comp), _allocator(alloc), _capacity_allocator(1)
            {
                _tree._iterator = new typename _RB_tree::node();
                _tree._iterator->colour = 0;
                _tree._iterator->pair = NULL;
                //_tree._iterator->pair = _allocator.allocate(1);
                //_allocator.construct(_tree._iterator->pair, value_type());
                while (first != second)
                {
                    _tree.normalInsert(*first);
                    first++;
                }
            }
            virtual ~map()
            {
                iterator    it = this->begin();
                iterator    ite = this->end();

                //std::cout << "it : " << *it << std::endl;
               // std::cout << "ite : " << *ite << std::endl;
               std::cout << "destructor" << std::endl;
                while (it != ite)
                    _tree.deleteNode((it++)->first);
            }
            size_type   size() const
            {
                size_type   i = 0;
                const_iterator    it = this->begin();
                const_iterator    ite = this->end();

                while (it != ite)
                {
                    i++;
                    it++;
                }
                return (i);
            }
            /*
            Elements Access
            */
            T&  at(const Key& key)
            {
                typename _RB_tree::node* new_node;
                new_node = _tree.search(key);
                if (!new_node)
                    throw std::out_of_range("map::at");
                return (new_node->pair->second);
            }
            T&  operator[](const Key& key)
            {
                ft::pair<key_type, mapped_type> new_pair(key, T());
                typename _RB_tree::node*   ret = _tree.normalInsert(new_pair);
                while (_tree._iterator->parent)
                        _tree._iterator = _tree._iterator->parent;
                return (ret->pair->second);
                
                /*typename _RB_tree::node* new_node;
                typename _RB_tree::node* res;
                new_node = new typename _RB_tree::node();
                new_node->pair = _allocator.allocate(1);
                _allocator.construct(new_node->pair, ft::pair<key_type, mapped_type>(key, T()));
                res = _tree.insertOperator(new_node);
                if (res)
                {
                    _allocator.destroy(new_node->pair);
                    _allocator.deallocate(new_node->pair, 1);
                    delete new_node;
                    while (_tree._iterator->parent)
                        _tree._iterator = _tree._iterator->parent;
                    return (res->pair->second);
                }
                return (new_node->pair->second);*/
            }
            iterator    begin()
            {
                return (iterator(_tree, _tree.begin()));
            }
            const_iterator    begin() const
            {
                return (const_iterator(_tree, _tree.begin()));
            }
            iterator    end()
            {
                /*_RB_tree*   ptr_tree = &_tree;
                //go to root in case it's not here
                while (ptr_tree->_iterator->parent)
                    ptr_tree->_iterator = ptr_tree->_iterator->parent;
                //go to rightest structure
                while (ptr_tree->_iterator->right)
                    ptr_tree->_iterator = ptr_tree->_iterator->right;*/    
                //return (iterator(_tree, ptr_tree->_iterator->right));
                return (const_iterator(_tree, _tree.end()));
            }
            const_iterator    end() const
            {
                return (const_iterator(_tree, _tree.end()));
            }

        private:
            typedef typename ft::RedBlackTree<value_type, map, key_type, mapped_type, Allocator>   _RB_tree;
            _RB_tree    _tree; //need to use RD iterator nodes somewhere
            Compare const  _comp;
            allocator_type	_allocator;
			size_type		_capacity_allocator;
    };
}

#endif