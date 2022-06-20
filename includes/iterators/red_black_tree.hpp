#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# define RED 0
# define BLACK 1

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include "../library_headers/is_same.hpp"
#include "../library_headers/pair.hpp"

/*
        The iterator receive a ft::pair<>, but alone it won't do anything
        So need to create nodes for rotation / whatever
*/
#include <iostream>
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
                        typedef typename Allocator::template rebind<s_node<It> >::other      rebind_node;

                        red_black_tree() : iterator(NULL){}
                        red_black_tree(const red_black_tree & rhs) : iterator(rhs.iterator)
                                        , _rebind_node(rhs._rebind_node), _comp(rhs._comp), _allocator(rhs._allocator){}
                        red_black_tree & operator=(const red_black_tree & rhs)
                        {
                                if (this != &rhs)
                                {
                                        iterator = rhs.iterator;
                                        _rebind_node = rhs._rebind_node;
                                        _comp = rhs._comp;
                                        _allocator = rhs._allocator;
                                }
                                return (*this);
                        }
                        virtual ~red_black_tree(){}
                        red_black_tree(node* iterator) : iterator(iterator){}
                        node*    search(Key const &key) const
                        {
                                node    *sub_root = iterator;
                                if (!sub_root)
                                        return (NULL);
                                Key     first_sub_root = sub_root->pair.first;
                                Key     first_new_node = key;
                                while (sub_root)
                                {
                                        if (_comp(first_sub_root, first_new_node))
                                        {
                                                sub_root = sub_root->right;
                                                if (sub_root)
                                                        first_sub_root = sub_root->pair.first;
                                        }
                                        else if (_comp(first_new_node, first_sub_root))
                                        {
                                                sub_root = sub_root->left;
                                                if (sub_root)
                                                        first_sub_root = sub_root->pair.first;
                                        }
                                        else if (first_new_node == first_sub_root)
                                                return (sub_root);
                                }
                                return (NULL);
                        }
                        node*           find(Key const& key) const
                        {
                                node    *sub_root = iterator;
                                if (!sub_root)
                                        return (NULL);
                                Key     first_sub_root = sub_root->pair.first;
                                Key     first_new_node = key;

                                while (sub_root)
                                {
                                        if (_comp(first_sub_root, first_new_node))
                                        {
                                                sub_root = sub_root->right;
                                                if (sub_root)
                                                        first_sub_root = sub_root->pair.first;
                                        }
                                        else if (_comp(first_new_node, first_sub_root))
                                        {
                                                sub_root = sub_root->left;
                                                if (sub_root)
                                                        first_sub_root = sub_root->pair.first;
                                        }
                                        else if (first_new_node == first_sub_root)
                                                return (sub_root);
                                }
                                return (this->end());
                        }
                        std::size_t     count(Key const &key) const
                        {
                                std::size_t n = 0;
                                node    *sub_root = iterator;
                                if (!sub_root)
                                        return (0);
                                Key     first_sub_root = sub_root->pair.first;
                                Key     first_new_node = key;

                                while (sub_root)
                                {
                                        if (_comp(first_sub_root, first_new_node))
                                        {
                                                sub_root = sub_root->right;
                                                if (sub_root)
                                                        first_sub_root = sub_root->pair.first;
                                        }
                                        else if (_comp(first_new_node, first_sub_root))
                                        {
                                                sub_root = sub_root->left;
                                                if (sub_root)
                                                        first_sub_root = sub_root->pair.first;
                                        }
                                        else if (first_new_node == first_sub_root)
                                        {
                                                n++;
                                                sub_root = sub_root->left;
                                                if (sub_root)
                                                        first_sub_root = sub_root->pair.first;
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
                                new_node->colour = RED;
                                _repear_tree_insert(new_node);
                                while (_get_parent(iterator))
                                        iterator = iterator->parent;
                                return (new_node);
                        }
                        node*    normal_insert(const value_type& pair)
                        {
                                node    *new_node = NULL;

                                if (!iterator)
                                {
                                        iterator = _rebind_node.allocate(1);
                                        _rebind_node.construct(iterator, node(pair));
                                        _new_node(iterator);
                                        iterator->colour = BLACK;
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
                                                return (iterator);
                                        }
                                }
                                new_node->colour = RED;
                                _repear_tree_insert(new_node);
                                while (_get_parent(iterator))
                                        iterator = iterator->parent;
                                return (new_node);
                        }
                        std::size_t    delete_node(Key const & key)
                        {
                                node            *current = NULL;
                                node            *smallest_key = NULL;
                                node            *left_child = NULL;
                                node            *right_child = NULL;
                                node            *null_node = NULL;
                                int             memory_colour = 0;
                                short int       nb_child = 0;

                                if (!iterator)
                                        return (0);
                                current = search(key);
                                if (!current)
                                        return (0);
                                memory_colour = current->colour;
                                if (current->left)
                                {
                                        ++nb_child;
                                        left_child = current->left;
                                }
                                if (current->right)
                                {
                                        ++nb_child;
                                        right_child = current->right;
                                }
                                if (nb_child < 2)
                                {
                                        memory_colour = current->colour;
                                        null_node = _delete_one_child(&current, &left_child, &right_child
                                                , memory_colour);
                                        if ((current && current->colour == RED) || (current && memory_colour == RED))
                                        {
                                                current->colour = BLACK;
                                                if (!current->parent)
                                                        iterator = current;
                                        }
                                        else if (current && current->colour == BLACK && memory_colour == BLACK)
                                                _repear_double_black(current);
                                }
                                else if (nb_child == 2)
                                {
                                        //find smallest key of right (or left) subtree
                                        smallest_key = _get_inorder(current);
                                        if (!current)
                                                return (0);
                                        //deleted node become smallest key node
                                        node*   cpy = _rebind_node.allocate(1);
                                        _rebind_node.construct(cpy, node(smallest_key->pair, current));
                                        if (!cpy->parent)
                                                iterator = cpy;
                                        else if (cpy->parent->left == current)
                                                cpy->parent->left = cpy;
                                        else if (cpy->parent->right == current)
                                                cpy->parent->right = cpy;
                                        if (cpy->left->parent == current)
                                                cpy->left->parent = cpy;
                                        if (cpy->right->parent == current)
                                                cpy->right->parent = cpy;
                                        _destroy_node(current);
                                        //delete node from subtree
                                        memory_colour = smallest_key->colour;
                                        left_child = smallest_key->left;
                                        right_child = smallest_key->right;
                                        null_node = _delete_one_child(&smallest_key, &left_child, &right_child
                                                , memory_colour);                                        
                                        if ((smallest_key && smallest_key->colour == RED) || (smallest_key && memory_colour == RED))
                                        {
                                                smallest_key->colour = BLACK;
                                                if (!smallest_key->parent)
                                                        iterator = smallest_key;
                                        }
                                        else if (smallest_key && smallest_key->colour == BLACK && memory_colour == BLACK)
                                                _repear_double_black(smallest_key);
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
                                node    *start = iterator;

                                if (!start)
                                        return (NULL);
                                while (start->parent)
                                        start = start->parent;
                                while (start->left)
                                        start = start->left;
                                return (start);
                        }
                        node*   end() const
                        {
                                node    *start = iterator;

                                if (!start)
                                        return (NULL);
                                while (start->parent)
                                        start = start->parent;
                                while (start->right)
                                        start = start->right;
                                return (start->right);
                        }
                        std::size_t   max_size() const
                        {
                                return (_rebind_node.max_size());
                        }
			/*ft::pair<iterator, iterator>	equal_range(Key const & key)
			{

			}
			ft::pair<const_iterator, const_iterator>	equal_range(Key const & key) const
			{

			}*/
                        node*  iterator;

                        private:
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
                                
                                node*    _delete_one_child(node **current, node **left_child, node **right_child
                                        , int memory_colour)
                                {
                                        node*   parent = _get_parent(*current);

                                        if (parent && parent->left == *current)
                                        {
                                                parent->left = NULL;
                                                if (*left_child)
                                                        parent->left = *left_child;
                                                else if (*right_child)
                                                        parent->left = *right_child;
                                        }
                                        else if (parent && parent->right == *current)
                                        {
                                                parent->right = NULL;
                                                if (*left_child)
                                                        parent->right = *left_child;
                                                else if (*right_child)
                                                        parent->right = *right_child;
                                        }
                                        _destroy_node(*current);
                                        *current = NULL;
                                        if (*left_child)
                                        {
                                                (*left_child)->parent = parent;
                                                *current = *left_child;
                                        }
                                        else if (*right_child)
                                        {
                                                (*right_child)->parent = parent;
                                                *current = *right_child;
                                        }
                                        else if (memory_colour == BLACK)
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
                                void    _repear_double_black(node *current)
                                {
                                        //if (!iterator || !current)
                                          //      return ;
                                        node    *sibling = _get_sibling(current);

                                        if (!current->parent)
                                        {
                                                iterator = current;
                                                current->colour = BLACK;
                                                return ;
                                        }
                                        else if (!sibling)
                                                _repear_double_black(current->parent);
                                        else if (current && current->parent && sibling)
                                        {
                                                if (sibling->colour == BLACK
                                                        && ((sibling->left && sibling->left->colour == RED)
                                                        || (sibling->right && sibling->right->colour == RED)))
                                                {
                                                        if (sibling->parent->left == sibling)
                                                        {
                                                                if (sibling->left && sibling->left->colour == RED) //left left case
                                                                {
                                                                        sibling->left->colour = BLACK;
                                                                        sibling->colour = sibling->parent->colour;
                                                                        _rotate_right(sibling->parent);
                                                                }
                                                                else if (sibling->right) //left right case
                                                                {
                                                                        sibling->right->colour = BLACK;
                                                                        _rotate_left(sibling);
                                                                        _rotate_right(current->parent);
                                                                }
                                                        }
                                                        else
                                                        {
                                                                if (sibling->right && sibling->right->colour == RED) //right right case
                                                                {
                                                                        sibling->right->colour = BLACK;
                                                                        sibling->colour = sibling->parent->colour;
                                                                        _rotate_left(sibling->parent);
                                                                }
                                                                else if (sibling->left)//right left case
                                                                {
                                                                        sibling->left->colour = BLACK;
                                                                        _rotate_right(sibling);
                                                                        _rotate_left(current->parent);
                                                                }
                                                        }
                                                        if (!sibling->parent)
                                                                iterator = sibling;
                                                        else if (!sibling->parent->parent)
                                                                iterator = sibling->parent;
                                                        
                                                }
                                                else if (sibling->colour == RED)
                                                        _repear_double_blackTwo(current);
                                                else if (sibling->colour == BLACK)
                                                        //&& (((sibling->left && sibling->left->colour == BLACK)
                                                        //&& (sibling->right && sibling->right->colour == BLACK))
                                                        //|| (sibling && sibling->colour == BLACK && !sibling->left && !sibling->right)))
                                                {
                                                        sibling->colour = RED;
                                                        if (current->parent && current->parent->colour == BLACK)
                                                                _repear_double_black(current->parent);
                                                        else if (current->parent)
                                                                current->parent->colour = BLACK;
                                                }
                                        }
                                }
                                void    _repear_double_blackTwo(node *current)
                                {
                                        node*   sibling = _get_sibling(current);

                                        if (!sibling)
                                                return ;
                                        sibling->colour = BLACK;
                                        current->parent->colour = RED;
                                        if (sibling == sibling->parent->left)
                                                _rotate_right(current->parent);
                                        else if (sibling == sibling->parent->right)
                                                _rotate_left(current->parent);
                                        if (!_get_grand_parent(current)->parent)
                                                iterator = _get_grand_parent(current);
                                        _repear_double_black(current);
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
                                        node    *parent = _get_parent(current);
                                        node*    left_child = current->left; //cpy left child of parent

                                        current->left = left_child->right; //give to left child it's right child
                                        if (left_child->right) //check if left child has a right child
                                                left_child->right->parent = current; //give this child head the parent address
                                        left_child->parent = parent;
                                        left_child->right = current;
                                        if (parent && parent->left == current)
                                                parent->left = left_child;
                                        else if (parent && parent->right == current)
                                                parent->right = left_child;
                                        current->parent = left_child;
                                }
                                void    _rotate_left(node *current)
                                {
                                        if (!current)
                                                return ;
                                        node    *parent = _get_parent(current);
                                        node*    right_child = current->right; //cpy right child of current

                                        current->right = right_child->left; //give to left child it's right child
                                        if (right_child->left) //check if left child has a right child
                                                right_child->left->parent = current; //give this child head the current address
                                        right_child->parent = parent;
                                        right_child->left = current;
                                        if (parent && parent->left == current)
                                                parent->left = right_child;
                                        else if (parent && parent->right == current)
                                                parent->right = right_child;
                                        current->parent = right_child;
                                }
                                node    *_get_grand_parent(node* current)
                                {
                                        node*    parent;

                                        if (!current)
                                                return (NULL);
                                        parent = current->parent;
                                        if (!parent)
                                                return (NULL);
                                        return (parent->parent);
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
                                        if (parent)
                                                parent->colour = BLACK;
                                        if (uncle)
                                                uncle->colour = BLACK;
                                        if (g_parent_node)
                                                g_parent_node->colour = RED;
                                        _repear_tree_insert(g_parent_node);
                                }
                                void    _repear_tree_insert(node *current)
                                {
                                        node    *uncle = _get_uncle(current);
                                        node    *parent_node = NULL;
                                        node    *g_parent_node = NULL;
                                        parent_node = _get_parent(current);
                                        g_parent_node = _get_grand_parent(current);

					if (!current->parent)
					{
                                                current->colour = BLACK;
						iterator = current;
					}
					else if (parent_node->colour == BLACK)
                                                return ;
                                        else if (uncle && uncle->colour == RED) //oncle and parent must be black
                                                _repear_case_one(current);
                                        else
                                        {
                                                if (g_parent_node->left && current == g_parent_node->left->right)
                                                {
                                                        _rotate_left(parent_node);
                                                        parent_node = current; //parent is now current
                                                        current = current->left; //current node is now it's old parent
                                                }
                                                else if (g_parent_node->right && current == g_parent_node->right->left)
                                                {
                                                        _rotate_right(parent_node);
                                                        parent_node = current;
                                                        current = current->right;
                                                }
                                                if (g_parent_node && current == parent_node->left)
                                                        _rotate_right(g_parent_node);
                                                else if (g_parent_node && current == parent_node->right)
                                                        _rotate_left(g_parent_node);
                                                parent_node->colour = BLACK;
                                                g_parent_node->colour = RED;
						if (!parent_node->parent)
							iterator = parent_node;
					}
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
        };
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
                                /*if (!_ptr)
                                {
                                        value_type      pair = value_type();
                                        pointer ptr = &pair;
                                        return (*ptr);
                                }*/
                                return (*(&_ptr->pair));
                        }
                        pointer operator->() const
                        {
                                //if (_ptr)
                                        return (&_ptr->pair);
                                //value_type      pair = value_type();
                               // pointer ptr = &pair;
                               // return (ptr);
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
