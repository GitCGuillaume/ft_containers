#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# define RED 0
# define BLACK 1

#include <iostream>
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include "../library_headers/is_same.hpp"
#include "../library_headers/pair.hpp"
#include "../library_headers/integral_constant.hpp"
#include "../library_headers/utils.hpp"

/*
        The iterator receive a ft::pair<>, but alone it won't do anything
        So need to create nodes for rotation / whatever
*/

template<class T>
struct s_node
{
        T      pair;
        struct s_node*  parent;
        struct s_node*  left;
        struct s_node*  right;
        bool    colour;

        s_node(): pair(T()), parent(NULL), left(NULL), right(NULL), colour(RED){}
        s_node(const T & new_pair): pair(new_pair), parent(NULL), left(NULL), right(NULL), colour(RED){}
        s_node(const T & old_pair, s_node* node) : pair(T(old_pair.first, old_pair.second)), parent(node->parent), left(node->left)
                , right(node->right), colour(node->colour){}
        s_node & operator=(const T & rhs)
        {
                if (this != &rhs)
                {
                        parent = rhs.parent;
                        left = rhs.left;
                        right = rhs.right;
                        colour = rhs.colour;
                }
        }
        ~s_node(){}
};

namespace ft
{
        template<typename It, class Container, typename Node>
        struct   bidirectionnal_iterator
        {
                        /* FOR STD DISTANCE */
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::value_type    value_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::difference_type    difference_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::reference    reference;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::pointer    pointer;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::iterator_category    iterator_category;
                        typedef  Node       node;
 
                        bidirectionnal_iterator() : _ptr(NULL), _old(NULL), _root(NULL){}
                        bidirectionnal_iterator(node* ptr, node* iterator) : _ptr(ptr), _old(iterator), _root(iterator){}
                        template<typename U, typename V>
                        bidirectionnal_iterator(const bidirectionnal_iterator<U
                                , typename ft::enable_if<ft::is_same<U, typename Container::value_type>::value, Container>::type
                                , V>& rhs) : _ptr(rhs._ptr), _old(rhs._old), _root(rhs._root){}
                        template<typename U, typename V>
                        bidirectionnal_iterator &        operator=(const bidirectionnal_iterator& rhs)
                        {
                                if (this != &rhs)
                                {
                                        _ptr = rhs._ptr;
                                        _old = rhs._old;
                                        _root = rhs._root;
                                }
                                return (*this);
                        }
                        virtual ~bidirectionnal_iterator(){}
                        reference operator*() const
                        {
                                return (*(ft::addressof(_ptr->pair)));
                        }
                        pointer operator->() const
                        {
                        	return (ft::addressof(_ptr->pair));
			}
                        /* PREFIX */
                        /*
                                _old->right == _ptr will loop until parent root(NULL)
                                or until _ptr->right is not old anymore
                        */
                        bidirectionnal_iterator& operator++()
                        {
                                if (!_ptr)
                                {
                                        _ptr = _root;
                                        if (_ptr)
                                                while (_ptr->left) //Go to leftest key
                                                        _ptr = _ptr->left;
                                        return (*this);
                                }
                                if (_ptr->right) //check if struct on right
                                {
                                        _ptr = _ptr->right; //go to right
                                        while (_ptr->left) //then go to leftest key
                                                _ptr = _ptr->left;
                                }
                                else
                                {
                                        _old = _ptr->parent;
                                        while (_old && _old->right == _ptr)
                                        {
						_ptr = _old;
                                                _old = _ptr->parent;
                                        }
                                        _ptr = _old;
                                }
                                return (*this);
                        }
                        bidirectionnal_iterator& operator--()
                        {
                                if (!_ptr)
                                {
                                        _ptr = _root;
                                        if (_ptr)
                                        {
                                                while (_ptr->right)
                                                        _ptr = _ptr->right;
                                        }
                                        return (*this);
                                }
                                if (_ptr->left) //check if struct on left
                                {
                                        _ptr = _ptr->left; //go to left
                                        while (_ptr->right) //then go to rightest key
                                                _ptr = _ptr->right;
                                }
                                else
                                {
                                        _old = _ptr->parent;
                                        while (_old && _old->left == _ptr)
                                        {
                                                _ptr = _old;
                                                _old = _ptr->parent;
                                        }
                                        _ptr = _old;
                                }
                                return (*this);
                        }
                        /* POSTFIX*/
                        bidirectionnal_iterator operator++(int)
                        {
                                bidirectionnal_iterator tmp = *this;
                                this->operator++();
                                return (tmp);
                        }
                        bidirectionnal_iterator   operator--(int)
                        {
                                bidirectionnal_iterator tmp = *this;
                                this->operator--();
                                return (tmp);
                        }
                        
                        node*   _ptr;    //pointer of pair
                        node*   _old;
                        node*   _root; //look like we need to keep root in memory to keep begin and last value
        };
        template<class It, class Container, class Key, class T, class Compare, class Allocator>
        class   red_black_tree
        {
                public:
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::value_type    value_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::difference_type    difference_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::reference    reference;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::pointer    pointer;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::iterator_category    iterator_category;
                        typedef Key key_type;
                        typedef T   mapped_type;
                        typedef Compare key_compare;
                        typedef Allocator   allocator_type;
                        typedef s_node<It>       node;
                        /* Allocate object of another type with new size than original template */
                        typedef typename Allocator::template rebind<s_node<It> >::other      rebind_node;
                        typedef ft::bidirectionnal_iterator<value_type, Container, node>      bi_iterator;
                        typedef ft::bidirectionnal_iterator<value_type const, Container, node>      const_bi_iterator;
                        typedef std::size_t size_type;
                        red_black_tree() : iterator(NULL), _size(0), _begin(NULL), _end(NULL){}
                        red_black_tree(const red_black_tree & rhs) : iterator(NULL)
                                        , _rebind_node(rhs._rebind_node), _comp(rhs._comp), _allocator(rhs._allocator)
                                        , _size(0), _begin(0), _end(0)
                        {
                                const_bi_iterator    it;
                                const_bi_iterator    ite = const_bi_iterator(rhs.end(), rhs.iterator);

                                if (!rhs.iterator)
                                        it = const_bi_iterator(rhs.end(), rhs.iterator);
                                else
                                        it = const_bi_iterator(rhs.begin(), rhs.iterator);
                                while (it != ite)
                                        insert(*(it)++);
                                if (iterator)
                                        while (iterator->parent)
                                                iterator = iterator->parent;
                        }
                        red_black_tree & operator=(const red_black_tree & rhs)
                        {
                                if (this != &rhs)
                                {
                                        const_bi_iterator    it;
                                        const_bi_iterator    ite = const_bi_iterator(end(), iterator);

                                        _rebind_node = rhs._rebind_node;
                                        _comp = rhs._comp;
                                        _allocator = rhs._allocator;
                                        if (!iterator)
                                                it = const_bi_iterator(end(), iterator);
                                        else
                                                it = const_bi_iterator(begin(), iterator);
                                        while (it != ite)
                                                this->delete_node((it++)->first);
                                        _size = 0;
                                        iterator = NULL;
                                        _begin = NULL;
                                        _end = NULL;
                                        if (!rhs.iterator)
                                                it = const_bi_iterator(rhs.end(), rhs.iterator);
                                        else
                                                it = const_bi_iterator(rhs.begin(), rhs.iterator);
                                        ite = const_bi_iterator(rhs.end(), rhs.iterator);
                                        while (it != ite)
                                                insert(*(it)++);
                                        if (iterator)
                                                while (iterator->parent)
                                                        iterator = iterator->parent;
                                }
                                return (*this);
                        }
                        virtual ~red_black_tree()
                        {
                                const_bi_iterator    it;
                                const_bi_iterator    ite = const_bi_iterator(end(), iterator);

                                if (!iterator)
                                        it = const_bi_iterator(end(), iterator);
                                else
                                        it = const_bi_iterator(begin(), iterator);
                                while (it != ite)
                                        this->delete_node((it++)->first);
                        }
                        node*    search(Key const &key) const
                        {
                                if (!iterator)
                                        return (NULL);
                                node    *sub_root = iterator;

                                while (sub_root)
                                {
                                        if (_comp(sub_root->pair.first, key))
                                                sub_root = sub_root->right;
                                        else if (_comp(key, sub_root->pair.first))
                                                sub_root = sub_root->left;
                                        else if (key == sub_root->pair.first)
                                                return (sub_root);
                                }
                                return (NULL);
                        }
                        node*           find(Key const& key) const
                        {
                                
                                if (!iterator)
                                        return (NULL);
                                node    *sub_root = iterator;

                                while (sub_root)
                                {
                                        if (_comp(sub_root->pair.first, key))
                                                sub_root = sub_root->right;
                                        else if (_comp(key, sub_root->pair.first))
                                                sub_root = sub_root->left;
                                        else if (key == sub_root->pair.first)
                                                return (sub_root);
                                }
                                return (this->end());
                        }
                        size_type     count(Key const &key) const
                        {
                                if (!iterator)
                                        return (0);
                                size_type n = 0;
                                node    *sub_root = iterator;

                                while (sub_root)
                                {
                                        if (_comp(sub_root->pair.first, key))
                                                sub_root = sub_root->right;
                                        else if (_comp(key, sub_root->pair.first))
                                                sub_root = sub_root->left;
                                        else if (key == sub_root->pair.first)
                                        {
                                                ++n;
                                                sub_root = sub_root->left;
                                        }
                                }
                                return (n);
                        }
			node*    insert(const value_type& pair)
                        {
                                node    *new_node = NULL;

                                if (!iterator)
                                {
                                        iterator = _rebind_node.allocate(1);
                                        _rebind_node.construct(iterator, node(pair));
                                        _new_node(iterator);
                                        iterator->colour = BLACK;
                                        ++_size;
                                        _begin = iterator;
                                        _end = iterator;
                                        return (iterator);
                                }
                                Key     first_sub_root = iterator->pair.first;
                                Key     first_new_node = pair.first;
                                new_node = _rebind_node.allocate(1);
                                _rebind_node.construct(new_node, node(pair));
                                _new_node(new_node);
                                //Search
                                while (iterator)
                                {
                                        if (_comp(first_sub_root, first_new_node))
                                        {
                                                 if (!iterator->right)
                                                 {
                                                        new_node->parent = iterator;
                                                        iterator->right = new_node;
                                                        break ;
                                                 }
                                                iterator = iterator->right;
                                                first_sub_root = iterator->pair.first;
                                        }
                                        else if (_comp(first_new_node, first_sub_root))
                                        {
                                                if (!iterator->left)
                                                {
                                                        new_node->parent = iterator;
                                                        iterator->left = new_node;
                                                        break ;
                                                }
                                                iterator = iterator->left;
                                                first_sub_root = iterator->pair.first;
                                        }
                                        else if (first_new_node == first_sub_root)
                                        {
                                                _destroy_node(new_node);
                                                return (NULL);
                                        }
                                }
                                ++_size;
                                new_node->colour = RED;
                                _repair_tree_insert(new_node);
                                _set_begin(new_node);
                                _set_end(new_node);
                                return (new_node);
                        }
			node*    insert_hint(node *hint,
                                const value_type& pair, const char side)
                        {
                                node    *new_node = 0;
                                node    *head = iterator;

                                if (!iterator)
                                {
                                        iterator = _rebind_node.allocate(1);
                                        _rebind_node.construct(iterator, node(pair));
                                        _new_node(iterator);
                                        iterator->colour = BLACK;
                                        ++_size;
                                        _begin = iterator;
                                        _end = iterator;
                                        return (iterator);
                                }
                                new_node = _rebind_node.allocate(1);
                                _rebind_node.construct(new_node, node(pair));
                                _new_node(new_node);
                                switch (side)
                                {
                                        case 1:
                                                new_node->parent = hint;
                                                if (hint->left)
                                                        hint->left->parent = new_node;
                                                hint->left = new_node;
                                                break ;
                                        case 2 :
                                                new_node->parent = hint;
                                                if (hint->right)
                                                        hint->right->parent = new_node;
                                                hint->right = new_node;
                                                break ;
                                        default:
                                                break ;
                                }
                                ++_size;
                                new_node->colour = RED;
                                _repair_tree_insert(new_node);
                                _set_begin(new_node);
                                _set_end(new_node);
                                iterator = head;
				while (iterator->parent)
                                        iterator = iterator->parent;
                                return (new_node);
                        }
                        size_type    delete_node(Key const & key)
                        {
                                node            *current = NULL;
                                node            *smallest_key = NULL;
                                node            *null_node = NULL;
                                int             memory_colour = 0;
                                short int       nb_child = 0;

                                if (!iterator)
                                        return (0);
                                current = search(key);
                                if (!current)
                                        return (0);
                                _repair_begin_end(current);
                                --_size;
                                memory_colour = current->colour;
                                if (current->left)
                                        ++nb_child;
                                if (current->right)
                                        ++nb_child;
                                if (nb_child < 2)
                                {
                                        memory_colour = current->colour;
                                        null_node = _delete_one_child(&current, current->left, current->right
                                                , memory_colour);
                                        if ((current && current->colour == RED)
                                                || (current && memory_colour == RED))
                                        {
                                                current->colour = BLACK;
                                                if (!current->parent)
                                                        iterator = current;
                                        }
                                        else if (current && current->colour == BLACK
                                                && memory_colour == BLACK)//double
                                                _repair_double_black(current);
                                }
                                else if (nb_child == 2)
                                {
                                        //find smallest key of subtree
                                        smallest_key = _get_inorder(current);
                                        if (!current)
                                                return (0);
                                        //copy content of smallest and take current place
                                        node*   cpy = _copy_node(smallest_key, current);
                                        if (cpy->pair.first == _begin->pair.first)
                                                _begin = cpy;
                                        _destroy_node(current);
					if (!cpy->parent)
						iterator = cpy;
                                        //delete node from subtree
                                        memory_colour = smallest_key->colour;
                                        null_node = _delete_one_child(&smallest_key, smallest_key->left, smallest_key->right
                                                , memory_colour); //delete then replace
                                        if ((smallest_key && smallest_key->colour == RED)
                                                || (smallest_key && memory_colour == RED))
                                        {
                                                smallest_key->colour = BLACK;
                                                if (!smallest_key->parent)
                                                        iterator = smallest_key;
                                        }
                                        else if (smallest_key && smallest_key->colour == BLACK
                                                && memory_colour == BLACK)//double
                                                _repair_double_black(smallest_key);
                                }
                                if (null_node == iterator)
                                        iterator = NULL;
                                if (null_node)
                                {
                                        _destroy_node(null_node->left);
                                        _destroy_node(null_node->right);
                                        _destroy_node(null_node);
                                }
                                return (1);
                        }
                        node*   begin() const
                        {
				return (_begin);
                        }
                        node*   end() const
                        {
				if (!_end)
                                        return (_end);
                                return (_end->right);
                        }
                        size_type   max_size() const
                        {
                                return (_rebind_node.max_size());
                        }
			/*
			 *	seek 4, first elem is 5
			 *	4 is not superior to 5 so go to left
			*/
			node*	lower_bound(Key const & key) const
			{
				node*	start = iterator;
				node*	ret = 0;

				while (start)
				{
					if (!_comp(start->pair.first, key))
					{
						ret = start;
						start = start->left;
					}
					else
						start = start->right;
				}
				return (ret);
			}
			node*	upper_bound(Key const & key) const
			{
				node*	start = iterator;
				node*	ret = 0;
				
				while (start)
				{
					if (_comp(key, start->pair.first))
					{
						ret = start;
						start = start->left;
					}
					else
						start = start->right;
				}
				return (ret);
			}
                        size_type     getSize() const
                        {
                                return (this->_size);
                        }
                        void    swap(red_black_tree & tree)
                        {
                                std::swap(_rebind_node, tree._rebind_node);
                                std::swap(_comp, tree._comp);
                                std::swap(_allocator, tree._allocator);
                                std::swap(_size, tree._size);
                                std::swap(iterator, tree.iterator);
                                std::swap(_begin, tree._begin);
                                std::swap(_end, tree._end);
                        }
                        node*  iterator;

                private:
                        void    _set_begin(node *new_node)
                        {
                                if (_comp(new_node->pair.first, _begin->pair.first))
                                        _begin = new_node;
                        }
                        void    _set_end(node *new_node)
                        {
                                if (_comp(_end->pair.first, new_node->pair.first))
                                        _end = new_node;
                        }
                        void    _repair_begin_end(node *current)
                        {
                                if (current == _begin)
                                {
                                        if (_begin->right)
                                        {
                                                _begin = _begin->right;
                                                        while (_begin->left) //then go to leftest key
                                                        _begin = _begin->left;
                                        }
                                        else
                                                _begin = _begin->parent;
                                }
                                if (current == _end)
                                {
                                        if (_end->left)
                                        {
                                                _end = _end->left;
                                                while (_end->right) //then go to rightest key
                                                        _end = _end->right;
                                        }
                                        else
                                                _end = _end->parent;
                                }
                        }
                        node    *_copy_node(node *smallest_key, node *current)
                        {
                                node*   cpy = _rebind_node.allocate(1);
                                _rebind_node.construct(cpy, node(smallest_key->pair, current));
                                if (!cpy->parent)//parent part
                                        iterator = cpy;
                                else if (cpy->parent->left == current)
                                        cpy->parent->left = cpy;
                                else if (cpy->parent->right == current)
                                        cpy->parent->right = cpy;
                                if (cpy->left->parent == current)//child part
                                        cpy->left->parent = cpy;
                                if (cpy->right->parent == current)
                                        cpy->right->parent = cpy;
                                return (cpy);
                        }
                        /* Seek previous value of current
                                since this function is used into a double child, I just need to seek 
                                previous value
                        */
                        node    *_get_inorder(node *current)
                        {
                                if (!current)
                                        return (NULL);
                                if (current->left)
                                {
                                        current = current->left;
                                        while (current->right)
                                                current = current->right;
                                }
                                return (current);
                        }
                        /*
                                delete current node
                                then put next node at the deleted pos
                                if current node color was red, just transform it into black
                                memory_color == black create node 
                        */
                        node*    _delete_one_child(node **current, node *left_child, node *right_child
                                , int memory_colour)
                        {
                                node*   parent = _get_parent(*current);

                                if (parent && parent->left == *current)
                                {
                                        parent->left = NULL;
                                        if (left_child)
                                                parent->left = left_child;
                                        else if (right_child)
                                                parent->left = right_child;
                                }
                                else if (parent && parent->right == *current)
                                {
                                        parent->right = NULL;
                                        if (left_child)
                                                parent->right = left_child;
                                        else if (right_child)
                                                parent->right = right_child;
                                }
                                _destroy_node(*current);
                                *current = NULL;
                                if (left_child)
                                {
                                        (left_child)->parent = parent;
                                        *current = left_child;
                                }
                                else if (right_child)
                                {
                                        (right_child)->parent = parent;
                                        *current = right_child;
                                }
                                else if (memory_colour == BLACK)//need "null" node to repair tree
                                {
                                        *current = _rebind_node.allocate(1);
                                        _rebind_node.construct(*current, node());
                                        _new_node(*current);
                                        (*current)->left = _rebind_node.allocate(1);
                                        _rebind_node.construct((*current)->left, node());
                                        _new_node((*current)->left);
                                        (*current)->right = _rebind_node.allocate(1);
                                        _rebind_node.construct((*current)->right, node());
                                        _new_node((*current)->right);
                                        (*current)->parent = parent;
                                        (*current)->colour = BLACK;
                                        (*current)->left->colour = BLACK;
                                        (*current)->right->colour = BLACK;
                                        return (*current);
                                }
                                return (NULL);
                        }
                        
                        void    _repair_double_black(node *current)
                        {
                                node    *sibling = _get_sibling(current);
                                //if current is root, just put it black and stop
                                if (current && !current->parent)
                                {
                                        iterator = current;
                                        current->colour = BLACK;
                                        return ;
                                }
                                else if (!sibling)
                                        _repair_double_black(current->parent); //if no sibling, give parent then repair if red
                                else if (current && current->parent && sibling)
                                {
                                        if (sibling->colour == BLACK
                                                && ((sibling->left && sibling->left->colour == RED)
                                                || (sibling->right && sibling->right->colour == RED)))
                                        {
                                                _repair_double_black_two(current, sibling);
                                        }
                                        else if (sibling->colour == RED) //since parent will be moved, you need to recolor this parent otherwise
                                        {                                 //it will break tree (current is null node)
                                                sibling->colour = BLACK;
                                                sibling->parent->colour = RED;
                                                //now sibling is black, now it's left left or right right case
                                                //to repair tree
                                                if (sibling->parent && sibling == sibling->parent->left)
                                                        _rotate_right(sibling->parent);
                                                else if (sibling->parent && sibling == sibling->parent->right)
                                                        _rotate_left(sibling->parent);
                                                if (!_get_grand_parent(current)->parent)
                                                        iterator = _get_grand_parent(current);
                                        }
                                        else if (sibling->colour == BLACK) //all children are black
                                        {
                                                sibling->colour = RED;
                                                //now need to push black parent lvl
                                                if (sibling->parent->colour == BLACK)
                                                        _repair_double_black(sibling->parent); //already black, try recurse repair
                                                else
                                                        sibling->parent->colour = BLACK; //if parent is red
                                        }
                                }
                        }
                        void    _repair_double_black_two(node *current, node *sibling)
                        {
                                if (!current || !sibling)
                                        return ;
                                if (sibling->parent->left == sibling)
                                {
                                        if (sibling->left && sibling->left->colour == RED) //left left case                                        before:     3 (b)
                                        {                                                  //                                                              2(b)     4 (b+b)
                                                sibling->left->colour = BLACK;             //                                                           1(r) 2.5 (r)
                                                sibling->colour = sibling->parent->colour; //need to take back parent colour
                                                _rotate_right(sibling->parent);            //since it will be moved otherwise it will destroy tree  after:      2(b)
                                        }                                                  //                                                               1(b)     3(b)
                                        else if (sibling->right) //right child is 100% red no need to check (left right)                                           2.5(r) 4(b)
                                        {
                                                sibling->right->colour = BLACK; //it will be at sibling place
                                                _rotate_left(sibling);
                                                _rotate_right(current->parent); //need now to move parent otherwise it's a line
                                        }
                                }
                                else
                                {
                                        if (sibling->right && sibling->right->colour == RED) //right right case
                                        {
                                                sibling->right->colour = BLACK;
                                                sibling->colour = sibling->parent->colour; //need to take back parent colour
                                                _rotate_left(sibling->parent);             //since it will be moved otherwise it will destroy tree
                                        }
                                        else if (sibling->left)//left child 100% red
                                        {
                                                sibling->left->colour = BLACK; //it will be at sibling place
                                                _rotate_right(sibling);
                                                _rotate_left(current->parent);//need now to move parent otherwise it's a line
                                        }
                                }
                                if (!sibling->parent)
                                        iterator = sibling;
                                else if (!sibling->parent->parent)
                                        iterator = sibling->parent;
                        }
                        void    _destroy_node(node *current)
                        {
                                if (!current)
                                        return ;
                                _rebind_node.destroy(current);
                                _rebind_node.deallocate(current, 1);
                        }
                        void    _rotate_right(node *current)
                        {
                                if (!current)
                                        return ;
                                node *child = current->left;
                                node *parent = _get_parent(current);

                                if (parent && parent->left == current)
                                        parent->left = child;
                                else if (parent && parent->right == current)
                                        parent->right = child;
                                if (child)
                                {
                                        child->parent = parent;
                                        if (child->right)
                                                child->right->parent = current;
                                        current->left = child->right;
                                        child->right = current;
                                }
                                current->parent = child;
                        }
                        void    _rotate_left(node *current)
                        {
                                if (!current)
                                        return ;
                                node *child = current->right;
                                node *parent = _get_parent(current);

                                if (parent && parent->left == current)
                                        parent->left = child;
                                else if (parent && parent->right == current)
                                        parent->right = child;
                                if (child)
                                {
                                        child->parent = parent;
                                        if (child->left)
                                                child->left->parent = current;
                                        current->right = child->left;
                                        child->left = current;
                                }
                                current->parent = child;
                        }
                        node    *_get_grand_parent(node* current)
                        {
                                if (!current)
                                        return (NULL);
                                if (!current->parent)
                                        return (NULL);
                                return (current->parent->parent);
                        }
                        node    *_get_parent(node* current)
                        {
                                if (!current)
                                        return (NULL);
                                return (current->parent);
                        }
                        node    *_get_uncle(node *current)
                        {
                                node*   parent = _get_parent(current);
                                node*   g_parent_node = _get_grand_parent(current);
                                if (!g_parent_node || !parent)
                                        return (NULL);
                                if (g_parent_node->left != parent)
                                        return (g_parent_node->left);
                                else if (g_parent_node->right != parent)
                                        return (g_parent_node->right);
                                return (NULL);
                        }
                        node    *_get_sibling(node *current)
                        {
                                node    *parent = _get_parent(current);

                                if (!parent)
                                        return (NULL);
                                if (parent->left && parent->left != current)
                                        return (parent->left);
                                else if (parent->right && parent->right != current)
                                        return (parent->right);
                                return (NULL);
                        }
                        void    _repear_case_one(node *current)
                        {
                                node    *parent = _get_parent(current);
                                node    *uncle = _get_uncle(current);
                                node    *g_parent_node = _get_grand_parent(current);

                                while (g_parent_node && g_parent_node->colour == BLACK)
                                {
                                        parent = _get_parent(current);
                                        uncle = _get_uncle(current);
                                        g_parent_node = _get_grand_parent(current);
                                        if (parent)
                                                parent->colour = BLACK;
                                        if (uncle)
                                                uncle->colour = BLACK;
                                        if (g_parent_node)
                                                g_parent_node->colour = RED;
                                }
                                _repair_tree_insert(g_parent_node);
                        }
                        /* father and uncle node become black, grang_parent red*/
                        void    _case_one(node *current)
                        {
                                node    *uncle = _get_uncle(current);
                                node    *g_parent_node = _get_grand_parent(current);

                                while (g_parent_node && g_parent_node->colour == RED)
                                {
                                        uncle = _get_uncle(current);
                                        g_parent_node = _get_grand_parent(current);
                                        if (uncle)
                                                uncle->colour = BLACK;
                                        if (current->parent)
                                                current->parent->colour = BLACK;
                                        if (g_parent_node)
                                                g_parent_node->colour = RED;
                                        current = g_parent_node->parent;
                                }
                                _repair_tree_insert(g_parent_node);//repair colour if needed
                        }

                        /*
                                ex :
                                        3 black              2 black (p)
                                        2 red        ->   1 red        3 red (gp)
                                        1 red (is new)
                        */
                        void    _case_two(node *current)
                        {
                                if (!current)
                                        return ;
                                node    *g_parent_node = _get_grand_parent(current);
                                node    *parent_node = _get_parent(current);

                                if (!g_parent_node || !parent_node)
                                        return ;
                                if (g_parent_node->left == parent_node)
                                {
                                        if (current == parent_node->left)
                                        {
                                                _rotate_right(g_parent_node);
                                                parent_node->colour = BLACK;
                                                g_parent_node->colour = RED;
                                        }
                                        else if (current == parent_node->right)
                                        {
                                                _rotate_left(parent_node);
                                                _rotate_right(g_parent_node); // still form a red line so need to repair it with
                                                current->colour = BLACK;        // rotate right
                                                g_parent_node->colour = RED;
                                        }
                                }
                                else if (g_parent_node->right == parent_node)
                                {
                                        if (current == parent_node->right)
                                        {
                                                _rotate_left(g_parent_node);
                                                parent_node->colour = BLACK;
                                                g_parent_node->colour = RED;
                                        }
                                        else if (current == parent_node->left)
                                        {
                                                _rotate_right(parent_node);
                                                _rotate_left(g_parent_node);
                                                current->colour = BLACK;
                                                g_parent_node->colour = RED;
                                        }
                                }
                        }
                        void    _repair_tree_insert(node *current)
                        {
                                node    *uncle = _get_uncle(current);
                                node    *parent_node = _get_parent(current);

                                if (!current)
                                        return ;
                                if (!parent_node)
                                {
                                        current->colour = BLACK;
                                        return ;
                                }
                                else if (parent_node->colour == BLACK)
                                        return ;
                                else if (uncle && uncle->colour == RED)
                                {
                                        _repear_case_one(current);
                                        return ;
                                }
                                _case_two(current); //uncle black
                        }
                        void    _new_node(node* current)
                        {
                                current->parent = NULL;
                                current->left = NULL;
                                current->right = NULL;
                                current->colour = 0;
                        }
                        rebind_node     _rebind_node;
                        key_compare     _comp;
                        allocator_type	_allocator;
                        size_type     _size;
                        node*  _begin;
                        node*  _end;
        };
        
        /* NON CONST */
        template<typename It, class Container, typename Node>
        bool    operator==(const ft::bidirectionnal_iterator<It, Container, Node>& lhs, const ft::bidirectionnal_iterator<It, Container, Node>& rhs)
        {
                if (lhs.operator->() == rhs.operator->())
                        return true;
                return (false);
        }
        template<typename It, class Container, typename Node>
        bool    operator!=(const ft::bidirectionnal_iterator<It, Container, Node>& lhs, const ft::bidirectionnal_iterator<It, Container, Node>& rhs)
        {
                if (lhs.operator->() != rhs.operator->())
                        return true;
                return (false);
        }
        /* CONST */
        template<typename It, typename It2, class Container, typename Node, typename Node2>
        bool    operator==(const ft::bidirectionnal_iterator<It, Container, Node>& lhs, const ft::bidirectionnal_iterator<It2, Container, Node2>& rhs)
        {
                if (lhs.operator->() == rhs.operator->())
                        return true;
                return (false);
        }
        template<typename It, typename It2, class Container, typename Node, typename Node2>
        bool    operator!=(const ft::bidirectionnal_iterator<It, Container, Node>& lhs, const ft::bidirectionnal_iterator<It2, Container, Node2>& rhs)
        {
                if (lhs.operator->() != rhs.operator->())
                        return true;
                return (false);
        }
}

#endif
