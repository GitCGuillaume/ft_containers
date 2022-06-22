#ifndef MAP_HPP
# define MAP_HPP

#include "../iterators/red_black_tree.hpp"
#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"
#include "../library_headers/equal.hpp"
#include "../library_headers/lexicographical_compare.hpp"
#include "../iterators/reverse_iterator.hpp"
#include <stdexcept>

/*
    struct s_node* _node is a pointer because std::allocator allocate return pointer.
*/

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
            typedef typename ft::bidirectionnal_iterator<value_type, map
                , typename ft::red_black_tree<value_type, map, key_type, mapped_type, key_compare, Allocator>::node > iterator;
            typedef typename ft::bidirectionnal_iterator<value_type const, map
                , const typename ft::red_black_tree<value_type, map, key_type, mapped_type, key_compare, Allocator>::node > const_iterator;
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
                : _tree(), _comp(comp), _allocator(alloc)
            {
                _tree.iterator = NULL;
            }
            template<class InputIt>
            map(InputIt first, InputIt second, const Compare& comp = Compare(),
                const Allocator& alloc = Allocator()) : _tree(), _comp(comp), _allocator(alloc)
            {
                _tree.iterator = NULL;
                this->insert(first, second);
            }
            map(const map& other)
            {
                _comp = other._comp;
                _allocator = other._allocator;
                this->insert(other.begin(), other.end());
            }
            map&    operator=(const map& other)
            {
                if (this != &other)
                {
                    this->clear();
		            _comp = other._comp;
                    _allocator = other._allocator;
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

                while (it != ite)
                    _tree.delete_node((it++)->first);
            }
            bool    empty() const
            {
                if (this->begin() == this->end())
                    return (true);
                return (false);
            }
            size_type   size() const
            {
                return (_tree.getSize());
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
                return (new_node->pair.second);
            }
            const T&  at(const Key& key) const
            {
                typename _RB_tree::node* new_node;
                new_node = _tree.search(key);
                if (!new_node)
                    throw std::out_of_range("map::at");
                return (new_node->pair.second);
            }
            T&  operator[](const Key& key)
            {
                ft::pair<key_type, mapped_type> new_pair(key, T());
                typename _RB_tree::node*   ret = _tree.normal_insert(new_pair);
                while (_tree.iterator->parent)
                        _tree.iterator = _tree.iterator->parent;
                return (ret->pair.second);
            }
            iterator    begin()
            {
                if (!_tree.iterator)
                    return (iterator(_tree.end(), _tree.iterator));
                return (iterator(_tree.begin(), _tree.iterator));
            }
            const_iterator    begin() const
            {
                if (!_tree.iterator)
                    return (const_iterator(_tree.end(), _tree.iterator));
                return (const_iterator(_tree.begin(), _tree.iterator));
            }
            reverse_iterator	rbegin()
			{
				return (reverse_iterator(this->end()));
			}
			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}
            iterator    end()
            {
                return (iterator(_tree.end(), _tree.iterator));
            }
            const_iterator    end() const
            {
                return (std map insert hint souce code);
            }
            reverse_iterator	rend()
			{
				return (reverse_iterator(this->begin()));
			}
			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}
            /* MODIFIERS */
            void    clear()
            {
                const_iterator    it = this->begin();
                const_iterator    ite = this->end();

                while (it != ite)
                    _tree.delete_node((it++)->first);
            }
	        ft::pair<iterator, bool>   insert(const value_type& value)
            {
                iterator  it;
                typename _RB_tree::node*    new_node = _tree.insert(value);

                if (new_node)
                    it = iterator(new_node, _tree.iterator);
                else
                {
                    it = iterator(_tree.iterator, _tree.iterator);
                    while (_tree.iterator->parent)
                        _tree.iterator = _tree.iterator->parent;
                    return (ft::make_pair(it, 0));
                }
                return (ft::make_pair(it, 1));
            }
		    /* hint is suggestion as to where to start the search */
            iterator    insert(iterator hint, const value_type& value)
            {
                iterator	it;
                typename _RB_tree::node*	new_node = NULL;

                if (hint == end())
                    new_node = _tree.insert(value);
                else
                    new_node = _tree.insert_hint(value, hint->first);
                if (!new_node)
                {
                    it = iterator(_tree.iterator, _tree.iterator);
                    while (_tree.iterator->parent)
                        _tree.iterator = _tree.iterator->parent;
                    return (it);
                }
                it = iterator(new_node, _tree.iterator);
                return (it);
            }
		    template<class InputIt>
            void    insert(InputIt first, InputIt last)
            {
                while (first != last)
                {
                    _tree.insert(*(first)++);
                    while (_tree.iterator->parent)
                        _tree.iterator = _tree.iterator->parent;
                }
            }
            void    erase(iterator pos)
            {
                if (pos != this->end())
                    _tree.delete_node(pos->first);
            }
            void    erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    _tree.delete_node((first++)->first);
                }
            }
            size_type    erase(const Key& key)
            {
                return (_tree.delete_node(key));
            }
            void    swap(map & other)
            {
                _RB_tree    tmp_tree = other._tree;
                key_compare tmp_comp = other._comp;
				allocator_type	tmp_alc = other._allocator;

                other._tree = _tree;
                other._comp = _comp;
				other._allocator = _allocator;
                _tree = tmp_tree;
                _comp = tmp_comp;
				_allocator = tmp_alc;
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
                if (!search_node)
                    return (this->end());
                return (iterator(search_node, _tree.iterator));
            }
            const_iterator  find(const Key& key) const
            {
                return (const_iterator(_tree.find(key), _tree.iterator));
            }
            ft::pair<iterator, iterator>   equal_range(const Key& key)
            {
       	    	return (ft::make_pair(lower_bound(key), upper_bound(key)));	
		    }
            ft::pair<const_iterator, const_iterator>   equal_range(const Key& key) const
            {
                return (ft::make_pair(lower_bound(key), upper_bound(key)));
            }
            iterator    lower_bound(const Key& key)
            {
           	return (iterator(_tree.lower_bound(key), _tree.iterator));
            }
            const_iterator    lower_bound(const Key& key) const
            {
   		        return (const_iterator(_tree.lower_bound(key), _tree.iterator));
            }
            iterator    upper_bound(const Key& key)
            {
		        return (iterator(_tree.upper_bound(key), _tree.iterator));
            }
            const_iterator    upper_bound(const Key& key) const
            {
		        return (const_iterator(_tree.upper_bound(key), _tree.iterator));
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
            typedef typename ft::red_black_tree<value_type, map, key_type, mapped_type, key_compare, Allocator>   _RB_tree;
            _RB_tree    _tree;
            key_compare  _comp;
            allocator_type	_allocator;
    };
    template<class Key, class T, class Compare, class Alloc>
    bool    operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
        const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
			return (false);
		bool	is_equal = ft::equal(lhs.begin(), lhs.end(), rhs.begin());

		return (is_equal);
    }
    template<class Key, class T, class Compare, class Alloc>
    bool    operator!=(const ft::map<Key, T, Compare, Alloc>& lhs,
        const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size()) // Quicker
			return (true);
		bool	is_equal = ft::equal(lhs.begin(), lhs.end(), rhs.begin());

		return (!is_equal);
    }
    template<class Key, class T, class Compare, class Alloc>
    bool    operator<(const ft::map<Key, T, Compare, Alloc>& lhs,
        const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        bool	is_left = ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	
		return (is_left);
    }
    template<class Key, class T, class Compare, class Alloc>
    bool    operator<=(const ft::map<Key, T, Compare, Alloc>& lhs,
        const ft::map<Key, T, Compare, Alloc>& rhs)
    {
		return (!(lhs > rhs));
	}
    template<class Key, class T, class Compare, class Alloc>
    bool    operator>(const ft::map<Key, T, Compare, Alloc>& lhs,
        const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        return (rhs < lhs);
    }
    template<class Key, class T, class Compare, class Alloc>
    bool    operator>=(const ft::map<Key, T, Compare, Alloc>& lhs,
        const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }
    template<class Key, class T, class Compare, class Alloc>
    void    swap(ft::map<Key, T, Compare, Alloc>& lhs
        , ft::map<Key, T, Compare, Alloc>& rhs)
    {
        lhs.swap(rhs);
    }
}

#endif
