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
#include <iterator>
#include <cstdlib>
#include <limits>

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
        template<class It, class Container, class Key, class T, class Compare, class Allocator>
        class   RedBlackTree
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

                        RedBlackTree() : iterator(NULL){}
                        RedBlackTree(const RedBlackTree & rhs) : iterator(rhs.iterator)
                                        , _rebind_node(rhs._rebind_node), _comp(rhs._comp), _allocator(rhs._allocator){}
                        RedBlackTree & operator=(const RedBlackTree & rhs)
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
                        ~RedBlackTree(){}
                        RedBlackTree(node* iterator) : iterator(iterator){}
                        node*    search(Key const &key) const
                        {
                                node    *subRoot = iterator;
                                if (!subRoot)
                                        return (NULL);
                                Key     firstSubRoot = subRoot->pair.first;
                                Key     firstNewNode = key;
                                while (subRoot)
                                {
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                subRoot = subRoot->right;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair.first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                subRoot = subRoot->left;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair.first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return (subRoot);
                                }
                                return (NULL);
                        }
                        node*           find(Key const& key) const
                        {
                                node    *subRoot = iterator;
                                if (!subRoot)
                                        return (NULL);
                                Key     firstSubRoot = subRoot->pair.first;
                                Key     firstNewNode = key;

                                while (subRoot)
                                {
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                subRoot = subRoot->right;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair.first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                subRoot = subRoot->left;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair.first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return (subRoot);
                                }
                                return (this->end());
                        }
                        std::size_t     count(Key const &key) const
                        {
                                std::size_t n = 0;
                                node    *subRoot = iterator;
                                if (!subRoot)
                                        return (0);
                                Key     firstSubRoot = subRoot->pair.first;
                                Key     firstNewNode = key;

                                while (subRoot)
                                {
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                subRoot = subRoot->right;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair.first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                subRoot = subRoot->left;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair.first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                        {
                                                n++;
                                                subRoot = subRoot->left;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair.first;
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
                                        _newNode(iterator);
                                        iterator->colour = BLACK;
                                        return (iterator);
                                }
                                Key     firstSubRoot = iterator->pair.first;
                                Key     firstNewNode = pair.first;
                                new_node = _rebind_node.allocate(1);
                                _rebind_node.construct(new_node, node(pair));
                                _newNode(new_node);
                                //Search
                               while (iterator)
                                {
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                 if (!iterator->right)
                                                 {
                                                        new_node->parent = iterator;
                                                        iterator->right = new_node;
                                                        break ;
                                                 }
                                                iterator = iterator->right;
                                                firstSubRoot = iterator->pair.first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                if (!iterator->left)
                                                {
                                                        new_node->parent = iterator;
                                                        iterator->left = new_node;
                                                        break ;
                                                }
                                                iterator = iterator->left;
                                                firstSubRoot = iterator->pair.first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                        {
                                                _destroyNode(new_node);
                                                return (NULL);
                                        }
                                }
                                new_node->colour = RED;
                                _repearTreeInsert(new_node);
                                while (_getParent(iterator))
                                        iterator = iterator->parent;
                                return (new_node);
                        }
                        node*    normalInsert(const value_type& pair)
                        {
                                node    *new_node = NULL;

                                if (!iterator)
                                {
                                        iterator = _rebind_node.allocate(1);
                                        _rebind_node.construct(iterator, node(pair));
                                        _newNode(iterator);
                                        iterator->colour = BLACK;
                                        return (iterator);
                                }
                                Key     firstSubRoot = iterator->pair.first;
                                Key     firstNewNode = pair.first;
                                new_node = _rebind_node.allocate(1);
                                _rebind_node.construct(new_node, node(pair));
                                _newNode(new_node);
                                //Search
                               while (iterator)
                                {
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                 if (!iterator->right)
                                                 {
                                                        new_node->parent = iterator;
                                                        iterator->right = new_node;
                                                        break ;
                                                 }
                                                iterator = iterator->right;
                                                firstSubRoot = iterator->pair.first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                if (!iterator->left)
                                                {
                                                        new_node->parent = iterator;
                                                        iterator->left = new_node;
                                                        break ;
                                                }
                                                iterator = iterator->left;
                                                firstSubRoot = iterator->pair.first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                        {
                                                _destroyNode(new_node);
                                                return (iterator);
                                        }
                                }
                                new_node->colour = RED;
                                _repearTreeInsert(new_node);
                                while (_getParent(iterator))
                                        iterator = iterator->parent;
                                return (new_node);
                        }
                        std::size_t    deleteNode(Key const & key)
                        {
                                node            *current = NULL;
                                node            *smallest_key = NULL;
                                node            *left_child = NULL;
                                node            *right_child = NULL;
                                node            *null_node = NULL;
                                int             memory_colour = 0;
                                short int       nb_child = 0;

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
                                        null_node = _deleteOneChild(&current, &left_child, &right_child
                                                , memory_colour);
                                        if ((current && current->colour == RED) || (current && memory_colour == RED))
                                        {
                                                current->colour = BLACK;
                                                if (!current->parent)
                                                        iterator = current;
                                        }
                                        else if (current && current->colour == BLACK && memory_colour == BLACK)
                                                _repearDoubleBlack(current);
                                }
                                else if (nb_child == 2)
                                {
                                        //find smallest key of right (or left) subtree
                                        smallest_key = _getInorder(current);
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
                                        _destroyNode(current);
                                        //delete node from subtree
                                        memory_colour = smallest_key->colour;
                                        left_child = smallest_key->left;
                                        right_child = smallest_key->right;
                                        null_node = _deleteOneChild(&smallest_key, &left_child, &right_child
                                                , memory_colour);                                        
                                        if ((smallest_key && smallest_key->colour == RED) || (smallest_key && memory_colour == RED))
                                        {
                                                smallest_key->colour = BLACK;
                                                if (!smallest_key->parent)
                                                        iterator = smallest_key;
                                        }
                                        else if (smallest_key && smallest_key->colour == BLACK && memory_colour == BLACK)
                                                _repearDoubleBlack(smallest_key);
                                }
                                if (null_node == iterator)
                                        iterator = NULL;
                                if (null_node)
                                {
                                        _destroyNode(null_node->left);
                                        _destroyNode(null_node->right);
                                        _destroyNode(null_node);
                                }
                                return (1);
                        }
                        node*   getIterator() const
                        {
                                return (iterator);
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

                                if (!iterator)
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
                        node*  iterator;

                        private:
                                /* Seek previous value of current
                                        since this function is used into a double child, I just need to seek 
                                        previous value
                                */
                                node    *_getInorder(node *current)
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
                                
                                node*    _deleteOneChild(node **current, node **left_child, node **right_child
                                        , int memory_colour)
                                {
                                        node*   parent = _getParent(*current);

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
                                        _destroyNode(*current);
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
                                                _newNode(*current);
                                                (*current)->left = _rebind_node.allocate(1);
                                                _rebind_node.construct((*current)->left, node());
                                                _newNode((*current)->left);
                                                (*current)->right = _rebind_node.allocate(1);
                                                _rebind_node.construct((*current)->right, node());
                                                _newNode((*current)->right);
                                                (*current)->parent = parent;
                                                (*current)->colour = BLACK;
                                                (*current)->left->colour = BLACK;
                                                (*current)->right->colour = BLACK;
                                                return (*current);
                                        }
                                        return (NULL);
                                }
                                void    _repearDoubleBlack(node *current)
                                {
                                        node    *sibling = _getSibling(current);

                                        if (!current->parent)
                                        {
                                                iterator = current;
                                                current->colour = BLACK;
                                                return ;
                                        }
                                        if (!sibling)
                                                _repearDoubleBlack(current->parent);
                                        if (current && current->parent && sibling)
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
                                                                        _rotateRight(sibling->parent);
                                                                }
                                                                else if (sibling->right) //left right case
                                                                {
                                                                        sibling->right->colour = BLACK;
                                                                        _rotateLeft(sibling);
                                                                        _rotateRight(current->parent);
                                                                }
                                                        }
                                                        else
                                                        {
                                                                if (sibling->right && sibling->right->colour == RED) //right right case
                                                                {
                                                                        sibling->right->colour = BLACK;
                                                                        sibling->colour = sibling->parent->colour;
                                                                        _rotateLeft(sibling->parent);
                                                                }
                                                                else if (sibling->left)//right left case
                                                                {
                                                                        sibling->left->colour = BLACK;
                                                                        _rotateRight(sibling);
                                                                        _rotateLeft(current->parent);
                                                                }
                                                        }
                                                        if (!sibling->parent)
                                                                iterator = sibling;
                                                        else if (!sibling->parent->parent)
                                                                iterator = sibling->parent;
                                                        
                                                }
                                                else if (sibling->colour == RED)
                                                        _repearDoubleBlackTwo(current);
                                                else if (sibling->colour == BLACK
                                                        && (((sibling->left && sibling->left->colour == BLACK)
                                                        && (sibling && sibling->right->colour == BLACK))
                                                        || (sibling->colour == BLACK && !sibling->left && !sibling->right)))
                                                {
                                                        sibling->colour = RED;
                                                        if (current->parent && current->parent->colour == BLACK)
                                                                _repearDoubleBlack(current->parent);
                                                        else if (current->parent)
                                                                current->parent->colour = BLACK;
                                                }
                                        }
                                }
                                void    _repearDoubleBlackTwo(node *current)
                                {
                                        node*   sibling = _getSibling(current);

                                        if (!sibling)
                                                return ;
                                        sibling->colour = BLACK;
                                        current->parent->colour = RED;
                                        if (sibling == sibling->parent->left)
                                                _rotateRight(current->parent);
                                        else if (sibling == sibling->parent->right)
                                                _rotateLeft(current->parent);
                                        if (!_getGrandParent(current)->parent)
                                                iterator = _getGrandParent(current);
                                        _repearDoubleBlack(current);
                                }
                                void    _destroyNode(node *current)
                                {
                                        if (!current)
                                                return ;
                                        _rebind_node.destroy(current);
                                        _rebind_node.deallocate(current, 1);
                                }
                                void    _rotateRight(node *current)
                                {
                                        if (!current)
                                                return ;
                                        node    *parent = _getParent(current);
                                        node*    leftChild = current->left; //cpy left child of parent

                                        current->left = leftChild->right; //give to left child it's right child
                                        if (leftChild->right) //check if left child has a right child
                                                leftChild->right->parent = current; //give this child head the parent address
                                        leftChild->parent = parent;
                                        leftChild->right = current;
                                        if (parent && parent->left == current)
                                                parent->left = leftChild;
                                        else if (parent && parent->right == current)
                                                parent->right = leftChild;
                                        current->parent = leftChild;
                                }
                                void    _rotateLeft(node *current)
                                {
                                        if (!current)
                                                return ;
                                        node    *parent = _getParent(current);
                                        node*    rightChild = current->right; //cpy right child of current

                                        current->right = rightChild->left; //give to left child it's right child
                                        if (rightChild->left) //check if left child has a right child
                                                rightChild->left->parent = current; //give this child head the current address
                                        rightChild->parent = parent;
                                        rightChild->left = current;
                                        if (parent && parent->left == current)
                                                parent->left = rightChild;
                                        else if (parent && parent->right == current)
                                                parent->right = rightChild;
                                        current->parent = rightChild;
                                }
                                node    *_getGrandParent(node* current)
                                {
                                        node*    parent;

                                        if (!current)
                                                return (NULL);
                                        parent = current->parent;
                                        if (!parent)
                                                return (NULL);
                                        return (parent->parent);
                                }
                                node    *_getParent(node* current)
                                {
                                        if (!current)
                                                return (NULL);
                                        return (current->parent);
                                }
                                node    *_getUncle(node *current)
                                {
                                        node*   parent = _getParent(current);
                                        node*   gParentNode = _getGrandParent(current);
                                        if (!gParentNode || !parent)
                                                return (NULL);
                                        if (gParentNode->left != parent)
                                                return (gParentNode->left);
                                        else if (gParentNode->right != parent)
                                                return (gParentNode->right);
                                        return (NULL);
                                }
                                node    *_getSibling(node *current)
                                {
                                        node    *parent = _getParent(current);

                                        if (!parent)
                                                return (NULL);
                                        if (parent->left && parent->left != current)
                                                return (parent->left);
                                        else if (parent->right && parent->right != current)
                                                return (parent->right);
                                        return (NULL);
                                }
                                void    _repearCaseOne(node *current)
                                {
                                        node    *parent = _getParent(current);
                                        node    *uncle = _getUncle(current);
                                        node    *gParentNode = _getGrandParent(current);
                                        if (parent)
                                                parent->colour = BLACK;
                                        if (uncle)
                                                uncle->colour = BLACK;
                                        if (gParentNode)
                                                gParentNode->colour = RED;
                                        _repearTreeInsert(gParentNode);
                                }
                                void    _repearTreeInsert(node *current)
                                {
                                        node    *uncle = _getUncle(current);
                                        node    *parentNode = NULL;
                                        node    *gParentNode = NULL;
                                        parentNode = _getParent(current);
                                        gParentNode = _getGrandParent(current);

                                        if (!current->parent)
                                                current->colour = BLACK;
                                        else if (parentNode->colour == BLACK)
                                                return ;
                                        else if (uncle && uncle->colour == RED) //oncle and parent must be black
                                                _repearCaseOne(current);
                                        else
                                        {
                                                if (gParentNode->left && current == gParentNode->left->right)
                                                {
                                                        _rotateLeft(parentNode);
                                                        parentNode = current; //parent is now current
                                                        current = current->left; //current node is now it's old parent
                                                }
                                                else if (gParentNode->right && current == gParentNode->right->left)
                                                {
                                                        _rotateRight(parentNode);
                                                        parentNode = current;
                                                        current = current->right;
                                                }
                                                if (gParentNode && current == parentNode->left)
                                                        _rotateRight(gParentNode);
                                                else if (gParentNode && current == parentNode->right)
                                                        _rotateLeft(gParentNode);
                                                parentNode->colour = BLACK;
                                                gParentNode->colour = RED;
                                        }
                                }
                                void    _newNode(node* current)
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
        struct   BiDirectionnalIterator
        {
                        /* FOR STD DISTANCE */
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::value_type    value_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::difference_type    difference_type;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::reference    reference;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::pointer    pointer;
                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::iterator_category    iterator_category;
                        typedef  Node       node;

                        BiDirectionnalIterator() : _ptr(NULL), _old(NULL), _root(NULL){}
                        BiDirectionnalIterator(node* ptr, node* iterator) : _ptr(ptr), _old(iterator), _root(iterator){}
                        template<typename U, typename V>
                        BiDirectionnalIterator(const BiDirectionnalIterator<U
                                , typename ft::enable_if<ft::is_same<U, typename Container::value_type>::value, Container>::type
                                , V>& rhs) : _ptr(rhs._ptr), _old(rhs._old), _root(rhs._root){}
                        BiDirectionnalIterator &        operator=(const BiDirectionnalIterator& rhs)
                        {
                                if (this != &rhs)
                                {
                                        _ptr = rhs._ptr;
                                        _old = rhs._old;
                                        _root = rhs._root;
                                }
                                return (*this);
                        }
                        virtual ~BiDirectionnalIterator(){}
                        reference operator*() const
                        {
                                if (!_ptr)
                                {
                                        value_type      pair = value_type();
                                        pointer ptr = &pair;
                                        return (*ptr);
                                }
                                return (*(&_ptr->pair));
                        }
                        pointer operator->() const
                        {
                                if (_ptr)
                                        return (&_ptr->pair);
                                value_type      pair = value_type();
                                pointer ptr = &pair;
                                return (ptr);
                        }
                        /* PREFIX */
                        /*
                                _old->right == _ptr will loop until parent root(NULL)
                                or until _ptr->right is not old anymore
                        */
                        BiDirectionnalIterator& operator++()
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
                        BiDirectionnalIterator& operator--()
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
                        BiDirectionnalIterator operator++(int)
                        {
                                BiDirectionnalIterator tmp = *this;
                                this->operator++();
                                return (tmp);
                        }
                        BiDirectionnalIterator   operator--(int)
                        {
                                BiDirectionnalIterator tmp = *this;
                                this->operator--();
                                return (tmp);
                        }
                        bool    operator==(BiDirectionnalIterator const & rhs)
                        {
                                return (_ptr == rhs._ptr);
                        }
                        bool    operator!=(BiDirectionnalIterator const & rhs)
                        {
                                return (_ptr != rhs._ptr);
                        }
                        node*   _ptr;    //pointer of pair
                        node*   _old;
                        node*   _root; //look like we need to keep root in memory to keep begin and last value
        };
}

#endif