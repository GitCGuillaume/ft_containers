#ifndef MAP_HPP
# define MAP_HPP

#include "../iterators/RedBlackTree.hpp"
#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"
#include <stdexcept>
#include <limits>

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
            typedef Compare key_compare;
            typedef Allocator   allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef typename Allocator::pointer  pointer;
            typedef typename Allocator::const_pointer    const_pointer;
            typedef typename ft::RedBlackTree<value_type, map, key_type, mapped_type, key_compare, Allocator>::BiDirectionnalIterator iterator;
            typedef typename ft::RedBlackTree<value_type, map, key_type, mapped_type, key_compare, Allocator>::BiDirectionnalIterator const_iterator;
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
                _tree._iterator = NULL;
                //_tree._iterator = new typename _RB_tree::node();
                //_tree._iterator->colour = 0;
                //_tree._iterator->pair = NULL;
                //_tree._iterator->pair = _allocator.allocate(1);
                //_allocator.construct(_tree._iterator->pair, value_type()); //Call pair<>() constructor
            }
            template<class InputIt>
            map(InputIt first, InputIt second, const Compare& comp = Compare(),
                const Allocator& alloc = Allocator()) : _comp(comp), _allocator(alloc), _capacity_allocator(1)
            {
                _tree._iterator = new typename _RB_tree::node();
                _tree._iterator->parent = NULL;
                _tree._iterator->left = NULL;
                _tree._iterator->right = NULL;
                _tree._iterator->pair = NULL;
                _tree._iterator->colour = 0;
                //_tree._iterator->pair = _allocator.allocate(1);
                //_allocator.construct(_tree._iterator->pair, value_type());
                this->insert(first, second);
            }
            map(const map& other)
            {
                _comp = other._comp;
                _allocator = other._allocator;
                _capacity_allocator = other._capacity_allocator;
                //FONCTION INSERT RANGE
                this->insert(other.begin(), other.end());
            }
            map&    operator=(const map& other)
            {
                if (this != &other)
                {
                    this->clear();
                    _comp = other._comp;
                    _allocator = other._allocator;
                    _capacity_allocator = other._capacity_allocator;
                    this->insert(other.begin(), other.end());
                }
                return (*this);
            }
            allocator_type  get_allocator() const
            {
                return (_allocator);
            }
            virtual ~map()
            {
                iterator    it = this->begin();
                iterator    ite = this->end();

                //if (_tree._iterator)
                while (it != ite)
                    _tree.deleteNode((it++)->first);
            }
            bool    empty() const
            {
                if (this->begin() == this->end())
                    return (true);
                return (false);
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
            size_type   max_size() const
            {
                return (std::numeric_limits<size_type>::max() / sizeof(typename _RB_tree::node));
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
                if (!_tree._iterator || !_tree._iterator->pair)
                    iterator(_tree, _tree.end());
                return (iterator(_tree, _tree.begin()));
            }
            const_iterator    begin() const
            {
                if (!_tree._iterator || !_tree._iterator->pair)
                    const_iterator(_tree, _tree.end());
                return (const_iterator(_tree, _tree.begin()));
            }
            iterator    end()
            {
                return (iterator(_tree, _tree.end()));
            }
            const_iterator    end() const
            {
                return (const_iterator(_tree, _tree.end()));
            }
            void    clear()
            {
                iterator    it = this->begin();
                iterator    ite = this->end();

                while (it != ite)
                    _tree.deleteNode((it++)->first);
            }
            ft::pair<iterator, bool>   insert(const value_type& value)
            {
                iterator  it;
                typename _RB_tree::node*    new_node = _tree.insert(value);

                if (new_node)
                    it = iterator(_tree, new_node);
                else
                {
                    it = iterator(_tree, _tree._iterator);
                    while (_tree._iterator->parent)
                        _tree._iterator = _tree._iterator->parent;
                    return (ft::make_pair(it, 0));
                }
                return (ft::make_pair(it, 1));
            }
            /* hint is suggestion as to where to start the search */
            iterator    insert(iterator hint, const value_type& value)
            {
                iterator    it;

                _tree.search(hint->first);
                typename _RB_tree::node*    new_node = _tree.insert(value);
                if (!new_node)
                {
                    it = iterator(_tree, _tree._iterator);
                    while (_tree._iterator->parent)
                        _tree._iterator = _tree._iterator->parent;
                    return (it);
                }
                it = iterator(_tree, new_node);
                return (it);
            }
            template<class InputIt>
            void    insert(InputIt first, InputIt last)
            {
                while (first != last)
                {
                    _tree.insert(*(first)++);
                    while (_tree._iterator->parent)
                        _tree._iterator = _tree._iterator->parent;
                }

            }
            void    erase(iterator pos)
            {
                if (pos != this->end())
                {
                    _tree.deleteNode(pos->first);
                }
            }
            void    erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    _tree.deleteNode((first++)->first);
                }
            }
            size_type    erase(const Key& key)
            {
                return (_tree.deleteNode(key));
            }
            /* Lookup */
            size_type   count(const Key& key) const
            {
                return (_tree.count(key));
            }
            iterator    find(const Key& key)
            {
                typename    _RB_tree::node* search_node = NULL;

                search_node = _tree.search(key);
                while (_tree._iterator->parent)
                        _tree._iterator = _tree._iterator->parent;
                if (!search_node)
                    return (this->end());
                return (iterator(_tree, search_node));
            }
            const_iterator  find(const Key& key) const
            {
                return (const_iterator(_tree, _tree.find(key)));
            }

        private:
            typedef typename ft::RedBlackTree<value_type, map, key_type, mapped_type, key_compare, Allocator>   _RB_tree;
            _RB_tree    _tree; //need to use RD iterator nodes somewhere
            key_compare  _comp;
            allocator_type	_allocator;
			size_type		_capacity_allocator;
    };
}

#endif