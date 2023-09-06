#ifndef MAP_HPP
# define MAP_HPP

#include "../iterators/red_black_tree.hpp"
#include "../library_headers/less.hpp"
#include "../library_headers/pair.hpp"
#include "../library_headers/equal.hpp"
#include "../library_headers/lexicographical_compare.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../library_headers/binary_function.hpp"
#include <stdexcept>

/*
    struct s_node* _node is a pointer because std::allocator allocate return pointer.
*/

namespace ft
{
    template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T   mapped_type;
            typedef ft::pair<const Key, T> value_type;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t  difference_type;
            typedef Compare key_compare;
            typedef Alloc   allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer  pointer;
            typedef typename allocator_type::const_pointer    const_pointer;
            typedef typename ft::bidirectionnal_iterator<value_type, map
                , typename ft::red_black_tree<value_type, map, key_type, mapped_type, key_compare, Alloc>::node > iterator;
            typedef typename ft::bidirectionnal_iterator<value_type const, map
                , typename ft::red_black_tree<value_type, map, key_type, mapped_type, key_compare, Alloc>::node > const_iterator;
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
            explicit    map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : _tree(), _comp(comp), _allocator(alloc)
            {
                _tree.iterator = NULL;
            }
            template <class InputIterator>
            map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()) : _tree(), _comp(comp), _allocator(alloc)
            {
                _tree.iterator = NULL;
                this->insert(first, last);
            }
            map(const map& x)
            {
                _comp = x._comp;
                _allocator = x._allocator;
                this->insert(x.begin(), x.end());
            }
            map&    operator=(const map& x)
            {
                if (this != &x)
                {
                    this->clear();
		            _comp = x._comp;
                    _allocator = x._allocator;
                    this->insert(x.begin(), x.end());
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
            mapped_type&  at(const key_type& k)
            {
                typename _RB_tree::node* new_node;
                new_node = _tree.search(k);
                if (!new_node)
                    throw std::out_of_range("map::at");
                return (new_node->pair.second);
            }
            const mapped_type&  at(const Key& k) const
            {
                typename _RB_tree::node* new_node;
                new_node = _tree.search(k);
                if (!new_node)
                    throw std::out_of_range("map::at");
                return (new_node->pair.second);
            }
            mapped_type&  operator[](const key_type& k)
            {
                typename _RB_tree::node*    head = _tree.iterator;
                ft::pair<key_type, mapped_type> new_pair(k, T());
                typename _RB_tree::node*   ret = _tree.insert(new_pair);
                if (!ret)
                    ret = _tree.iterator;
                if (head)
                    _tree.iterator = head;
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
                if (!_tree.iterator)
                    return (reverse_iterator(this->rend()));
				return (reverse_iterator(this->end()));
			}
			const_reverse_iterator	rbegin() const
			{
                if (!_tree.iterator)
                    return (const_reverse_iterator(this->rend()));
				return (const_reverse_iterator(this->end()));
			}
            iterator    end()
            {
                return (iterator(_tree.end(), _tree.iterator));
            }
            const_iterator    end() const
            {
                return (const_iterator(_tree.end(), _tree.iterator));
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
	        ft::pair<iterator, bool>   insert(const value_type& val)
            {
                iterator  it;
                typename _RB_tree::node*    head = _tree.iterator;
                typename _RB_tree::node*    new_node = _tree.insert(val);
                if (new_node)
                    it = iterator(new_node, _tree.iterator);
                else
                {
                    it = iterator(_tree.iterator, _tree.iterator);
                    if (head)
                        _tree.iterator = head;
                    while (_tree.iterator->parent)
                        _tree.iterator = _tree.iterator->parent;
                    return (ft::make_pair(it, 0));
                }
                if (head)
                    _tree.iterator = head;
                while (_tree.iterator->parent)
                    _tree.iterator = _tree.iterator->parent;
                return (ft::make_pair(it, 1));
            }
            iterator    insert(iterator position, const value_type& val)
            {
                typename _RB_tree::node*	new_node = NULL;
                iterator    prev = position;
                iterator    next = position;

                --prev;
                ++next;
                if (position._ptr && position->first == val.first)//ok
                    return (position);
                else if (prev._ptr && prev->first == val.first)
                    return (prev);
                else if (next._ptr && next->first == val.first)
                    return (next);
                if (position == this->end() && prev._ptr && _comp(prev->first, val.first))
                    new_node = _tree.insert_hint(prev._ptr, val, 2);
                else if (position._ptr && position == this->begin() && _comp(val.first, position->first))
                    new_node = _tree.insert_hint(position._ptr, val, 1);
                else if (!position._ptr || _comp(val.first, position->first))
                {
                    if (!prev._ptr || _comp(prev->first, val.first))
                    {
                        if (position._ptr && !position._ptr->left)
                                new_node = _tree.insert_hint(position._ptr, val, 1);
                        else
                                new_node = _tree.insert_hint(prev._ptr, val, 2); //--pos
                    }
                    else
                        return (insert(val).first);
                }
                else
                        return (insert(val).first);
                if (!new_node)
                    return (iterator(_tree.iterator, _tree.iterator));
                return (iterator(new_node, _tree.iterator));
            }
		    template<class InputIterator>
            void    insert(InputIterator first, InputIterator last)
            {
                iterator it = this->begin();

                while (first != last)
                {
                    it = insert(it, *first);
		            ++first;
                    while (_tree.iterator->parent)
                        _tree.iterator = _tree.iterator->parent;
                }
            }
            void    erase(iterator position)
            {
                if (position != this->end())
                    _tree.delete_node(position->first);
            }
            void    erase(iterator first, iterator last)
            {
                while (first != last)
                    _tree.delete_node((first++)->first);
            }
            size_type    erase(const key_type& key)
            {
                return (_tree.delete_node(key));
            }
            void    swap(map & x)
            {
                if (this != &x)
                {
                    std::swap(x._comp, _comp);
                    std::swap(x._allocator, _allocator);
                    _tree.swap(x._tree);
                }
            }
            /* Lookup */
            size_type   count(const key_type& k) const
            {
                return (_tree.count(k));
            }
            iterator    find(const key_type& k)
            {
                typename    _RB_tree::node* search_node = NULL;

                search_node = _tree.search(k);
                if (!search_node)
                    return (this->end());
                return (iterator(search_node, _tree.iterator));
            }
            const_iterator  find(const key_type& k) const
            {
                return (const_iterator(_tree.find(k), _tree.iterator));
            }
            ft::pair<iterator, iterator>   equal_range(const key_type& k)
            {
       	    	return (ft::make_pair(lower_bound(k), upper_bound(k)));	
		    }
            ft::pair<const_iterator, const_iterator>   equal_range(const key_type& k) const
            {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            iterator    lower_bound(const key_type& k)
            {
           	return (iterator(_tree.lower_bound(k), _tree.iterator));
            }
            const_iterator    lower_bound(const key_type& k) const
            {
   		        return (const_iterator(_tree.lower_bound(k), _tree.iterator));
            }
            iterator    upper_bound(const key_type& k)
            {
		        return (iterator(_tree.upper_bound(k), _tree.iterator));
            }
            const_iterator    upper_bound(const key_type& k) const
            {
		        return (const_iterator(_tree.upper_bound(k), _tree.iterator));
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
            typedef typename ft::red_black_tree<value_type, map, key_type, mapped_type, key_compare, Alloc>   _RB_tree;
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
    void    swap(ft::map<Key, T, Compare, Alloc>& x
        , ft::map<Key, T, Compare, Alloc>& y)
    {
        x.swap(y);
    }
}

#endif
