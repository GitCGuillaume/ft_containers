#ifndef MAP_HPP
# define MAP_HPP

#include "../iterators/RedBlackTree.hpp"
#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"
#include "../iterators/reverse_iterator.hpp"
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
            typedef typename ft::BiDirectionnalIterator<value_type, map
                , typename ft::RedBlackTree<value_type, map, key_type, mapped_type, key_compare, Allocator>::node > iterator;
            typedef typename ft::BiDirectionnalIterator<value_type const, map
                , const typename ft::RedBlackTree<value_type, map, key_type, mapped_type, key_compare, Allocator>::node > const_iterator;
            typedef ft::reverse_iterator<iterator>  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
            class   value_compare : public ft::binary_function<value_type, value_type, bool>
            {
                protected:
                    Compare comp;
                public :
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
                const_iterator    it = this->begin();
                const_iterator    ite = this->end();

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
                return (_tree.max_size());
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
                    return (iterator(_tree.end(), _tree._iterator));
                return (iterator(_tree.begin(), _tree._iterator));
            }
            const_iterator    begin() const
            {
                if (!_tree._iterator || !_tree._iterator->pair)
                    return (const_iterator(_tree.end(), _tree._iterator));
                return (const_iterator(_tree.begin(), _tree._iterator));
            }
            iterator    end()
            {
                return (iterator(_tree.end(), _tree._iterator));
            }
            const_iterator    end() const
            {
                return (const_iterator(_tree.end(), _tree._iterator));
            }
            /* MODIFIERS */
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
                    it = iterator(new_node, _tree._iterator);
                else
                {
                    it = iterator(_tree._iterator, _tree._iterator);
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
                    it = iterator(_tree._iterator, _tree._iterator);
                    while (_tree._iterator->parent)
                        _tree._iterator = _tree._iterator->parent;
                    return (it);
                }
                it = iterator(new_node, _tree._iterator);
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
            void    swap(map & other)
            {
                _RB_tree    tmp_tree = other._tree;
                key_compare tmp_comp = other._comp;
				allocator_type	tmp_alc = other._allocator;
				size_type	tmp_cap = other._capacity_allocator;

                other._tree = _tree;
                other._comp = _comp;
				other._allocator = _allocator;
				other._capacity_allocator = _capacity_allocator;
                _tree = tmp_tree;
                _comp = tmp_comp;
				_allocator = tmp_alc;
				_capacity_allocator = tmp_cap;
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
                return (iterator(search_node, _tree._iterator));
            }
            const_iterator  find(const Key& key) const
            {
                return (const_iterator(_tree.find(key), _tree._iterator));
            }
            ft::pair<iterator, iterator>   equal_range(const Key& key)
            {
                iterator    it = this->begin();
                iterator    ite = this->end();
                iterator    first;
                bool        first_found = false;

                if (key < it->first)
                    return (ft::make_pair(it, it));
                while (it != ite)
                {
                    if (!(_comp(it->first, key)) && first_found == false)
                    {
                        first = it;
                        first_found = true;
                        if (it->first != key)
                            return (ft::make_pair(it, it));
                    }
                    else if (_comp(key, it->first))// && first_found == true)
                        return (ft::make_pair(first, it));
                    it++;
                }
                if (it == ite && first_found == true)
                    return (ft::make_pair(first, ite));
                return (ft::make_pair(ite, ite));
            }
            ft::pair<const_iterator, const_iterator>   equal_range(const Key& key) const
            {
                const_iterator    it = this->begin();
                const_iterator    ite = this->end();
                const_iterator    first;
                bool        first_found = false;

                if (key < it->first)
                    return (ft::make_pair(it, it));
                while (it != ite)
                {
                    if (!(_comp(it->first, key)) && first_found == false)
                    {
                        first = it;
                        first_found = true;
                        if (it->first != key)
                            return (ft::make_pair(it, it));
                    }
                    else if (_comp(key, it->first))
                        return (ft::make_pair(first, it));
                    it++;
                }
                if (it == ite && first_found == true)
                    return (ft::make_pair(first, ite));
                return (ft::make_pair(ite, ite));
            }
            iterator    lower_bound(const Key& key)
            {
                iterator    it = this->begin();
                iterator    ite = this->end();

                while (it != ite)
                {
                    if (!(_comp(it->first, key)))
                        return (it);
                    it++;
                }
                return (ite);
            }
            const_iterator    lower_bound(const Key& key) const
            {
                const_iterator    it = this->begin();
                const_iterator    ite = this->end();

    
                while (it != ite)
                {
                    if (!(_comp(it->first, key)))
                        return (it);
                    it++;
                }
                return (ite);
            }
            iterator    upper_bound(const Key& key)
            {
                iterator    it = this->begin();
                iterator    ite = this->end();

                while (it != ite)
                {
                    if (_comp(key, it->first))
                        return (it);
                    it++;
                }
                return (ite);
            }
            const_iterator    upper_bound(const Key& key) const
            {
                const_iterator    it = this->begin();
                const_iterator    ite = this->end();

    
                while (it != ite)
                {
                    if (_comp(key, it->first))
                        return (it);
                    it++;
                }
                return (ite);
            }
            key_compare key_comp()  const
            {
                return (_comp);
            }
            value_compare  value_comp()    const
            {
                return (value_compare(_comp));
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