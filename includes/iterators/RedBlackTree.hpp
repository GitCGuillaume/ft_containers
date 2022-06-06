#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# define RED 1
# define BLACK 2
# define DOUBLE 3

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include "../library_headers/is_same.hpp"
#include "../library_headers/pair.hpp"
#include <iterator>
#include <cstdlib>
/*
        The iterator receive a ft::pair<>, but alone it won't do anything
        So need to create nodes for rotation + branches / leaves / whatever
*/

template<class T>
struct s_node
{
        struct s_node*  parent;
        struct s_node*  left;
        struct s_node*  right;
        T      pair;
        int    colour;
};

/*
        RB tree
        0 = none
        1 = red
        2 = 2 black
        3 = 3 black (delete part)
*/
namespace ft
{
        template<class It, class Container, class Key, class T, class Compare,class Allocator>
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
                        typedef  s_node<pointer>       node;
                        class   BiDirectionnalIterator //nested class
                        {
                                public:
                                        /* FOR STD DISTANCE */
                                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::value_type    value_type;
                                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::difference_type    difference_type;
                                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::reference    reference;
                                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::pointer    pointer;
                                        typedef typename ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, It> >::iterator_category    iterator_category;
                        
                                        BiDirectionnalIterator() : _ptr(NULL), _old(NULL){}
                                        
                                        //BiDirectionnalIterator(const BiDirectionnalIterator<U
                                        //        , typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value),
                                        //        Container>::type>& rhs) : _ptr(rhs.base()){}
                                        
                                        //BiDirectionnalIterator(const RedBlackTree& src, node* ptr, typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value),
                                        //        Container>::type) : _ptr(ptr), _old(src._iterator){}
                                        template<typename U>
                                        BiDirectionnalIterator(const RedBlackTree<U, typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value), Container>::type
                                                , key_type, mapped_type, key_compare, Allocator>& src, node* ptr) : _ptr(ptr), _old(src._iterator){}
                                        template<typename U>
                                        BiDirectionnalIterator(const RedBlackTree<U, typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value), Container>::type
                                                , key_type, mapped_type, key_compare, Allocator>& rhs) : _ptr(rhs._ptr), _old(rhs._old){}
                                        BiDirectionnalIterator &        operator=(const BiDirectionnalIterator& rhs)
                                        {
                                                if (this != &rhs)
                                                {
                                                        _ptr = rhs._ptr;
                                                        _old = rhs._old;
                                                }
                                                return (*this);
                                        }
                                        ~BiDirectionnalIterator(){}
                                        reference operator*() const
                                        {
                                                if (!_ptr)
                                                {
                                                        value_type      pair = value_type();
                                                        pointer ptr = &pair;
                                                        return (*ptr);
                                                }
                                                return (*_ptr->pair);
                                        }
                                        pointer operator->() const
                                        {
                                                if (_ptr)
                                                        return (_ptr->pair);
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
                                                        return (*this);
                                                _old = _ptr->parent;
                                                if (_ptr->right) //check if struct on right
                                                {
                                                        _ptr = _ptr->right; //go ro right
                                                        while (_ptr->left) //then go to leftest key
                                                                _ptr = _ptr->left;
                                                }
                                                else if (_old && _old->right == _ptr)
                                                {
                                                        while (_old && _old->right == _ptr)
                                                        {
                                                                _ptr = _old;
                                                                _old = _ptr->parent;
                                                        }
                                                        _ptr = _old;
                                                }
                                                else
                                                        _ptr = _ptr->parent;
                                                return (*this);
                                        }
                                        BiDirectionnalIterator& operator--()
                                        {
                                                if (!_ptr)
                                                {
                                                        _ptr = _old;
                                                        while (_ptr->right)
                                                                _ptr = _ptr->right;
                                                        return (*this);
                                                }
                                                _old = _ptr->parent;
                                                if (_ptr->left) //check if struct on left
                                                {
                                                        _ptr = _ptr->left; //go ro left
                                                        while (_ptr->right) //then go to leftest key
                                                                _ptr = _ptr->right;
                                                }
                                                else if (_old && _old->left == _ptr)
                                                {
                                                        while (_old && _old->left == _ptr)
                                                        {
                                                                _ptr = _old;
                                                                _old = _ptr->parent;
                                                        }
                                                        _ptr = _old;
                                                }
                                                else
                                                        _ptr = _ptr->parent;
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
                                private:
                                        node*   _ptr;    //pointer of pair
                                        node*   _old;
                        };
                        RedBlackTree() : _iterator(NULL){}
                        ~RedBlackTree(){}
                        RedBlackTree(node* iterator) : _iterator(iterator){}
                        node*   find(Key const &key) const
                        {
                                
                        }
                        node*    search(Key const &key) const
                        {
                                node    *subRoot = _iterator;
                                if (!subRoot || !subRoot->pair)
                                        return (NULL);
                                Key     firstSubRoot = subRoot->pair->first;
                                Key     firstNewNode = key;

                                while (subRoot)
                                {
                                        //if (firstSubRoot < firstNewNode)
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                subRoot = subRoot->right;
                                                if (subRoot && subRoot->pair)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                subRoot = subRoot->left;
                                                if (subRoot && subRoot->pair)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return (subRoot);
                                }
                                return (NULL);
                        }
                        std::size_t       count(Key const &key) const
                        {
                                std::size_t n = 0;
                                node    *subRoot = _iterator;
                                if (!subRoot || !subRoot->pair)
                                        return (0);
                                Key     firstSubRoot = subRoot->pair->first;
                                Key     firstNewNode = key;

                                while (subRoot)
                                {
                                        //if (firstSubRoot < firstNewNode)
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                subRoot = subRoot->right;
                                                if (subRoot && subRoot->pair)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                subRoot = subRoot->left;
                                                if (subRoot && subRoot->pair)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                        {
                                                n++;
                                                subRoot = subRoot->left;
                                                if (subRoot && subRoot->pair)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                }
                                return (n);
                        }
                        template<typename U, typename X>
                        node*    insert(const ft::pair<U, X>& pair)
                        {
                                node    *new_node = NULL;

                                if (!_iterator || !_iterator->colour || !_iterator->pair) //no root
                                {
                                        if (!_iterator)
                                        {
                                                _iterator = new node();
                                                newNode(_iterator);
                                        }
                                        //if (_iterator->pair)
                                        //        _destroyPair(_iterator);
                                        _iterator->pair = _allocator.allocate(1);
                                        _allocator.construct(_iterator->pair, pair);
                                        //black colour
                                        _iterator->colour = BLACK;
                                        return (_iterator);
                                }
                                Key     firstSubRoot = _iterator->pair->first;
                                Key     firstNewNode = pair.first;
                                new_node = new node();
                                newNode(new_node);
                                //Search
                               while (_iterator)
                                {
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                 if (!_iterator->right)
                                                 {
                                                        new_node->parent = _iterator;
                                                        _iterator->right = new_node;
                                                        break ;
                                                 }
                                                _iterator = _iterator->right;
                                                firstSubRoot = _iterator->pair->first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                if (!_iterator->left)
                                                {
                                                        new_node->parent = _iterator;
                                                        _iterator->left = new_node;
                                                        break ;
                                                }
                                                _iterator = _iterator->left;
                                                firstSubRoot = _iterator->pair->first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                        {
                                                delete new_node;
                                                return (NULL);
                                        }
                                }
                                new_node->pair = _allocator.allocate(1);
                                _allocator.construct(new_node->pair, pair);
                                //red colour
                                new_node->colour = RED;
                                _repearTreeInsert(new_node);
                                while (_getParent(_iterator))
                                        _iterator = _iterator->parent;
                                return (new_node);
                        }
                        template<typename U, typename X>
                        node*    normalInsert(const ft::pair<U, X>& pair)
                        {
                                node    *new_node = NULL;

                                if (!_iterator || !_iterator->colour || !_iterator->pair) //no root
                                {
                                        if (!_iterator)
                                        {
                                                _iterator = new node();
                                                newNode(_iterator);
                                        }
                                        //if (_iterator->pair)
                                        //        _destroyPair(_iterator);
                                        _iterator->pair = _allocator.allocate(1);
                                        _allocator.construct(_iterator->pair, pair);
                                        //black colour
                                        _iterator->colour = BLACK;
                                        return (_iterator);
                                }
                                Key     firstSubRoot = _iterator->pair->first;
                                Key     firstNewNode = pair.first;
                                new_node = new node();
                                newNode(new_node);
                                //Search
                               while (_iterator)
                                {
                                        if (_comp(firstSubRoot, firstNewNode))
                                        {
                                                 if (!_iterator->right)
                                                 {
                                                        new_node->parent = _iterator;
                                                        _iterator->right = new_node;
                                                        break ;
                                                 }
                                                _iterator = _iterator->right;
                                                firstSubRoot = _iterator->pair->first;
                                        }
                                        else if (_comp(firstNewNode, firstSubRoot))
                                        {
                                                if (!_iterator->left)
                                                {
                                                        new_node->parent = _iterator;
                                                        _iterator->left = new_node;
                                                        break ;
                                                }
                                                _iterator = _iterator->left;
                                                firstSubRoot = _iterator->pair->first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                        {
                                                delete new_node;
                                                return (_iterator);
                                        }
                                }
                                new_node->pair = _allocator.allocate(1);
                                _allocator.construct(new_node->pair, pair);
                                //red colour
                                new_node->colour = RED;
                                _repearTreeInsert(new_node);
                                while (_getParent(_iterator))
                                        _iterator = _iterator->parent;
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
                                {
                                        return (0);
                                }
                                memory_colour = current->colour;
                                if (current->left)
                                {
                                        nb_child++;
                                        left_child = current->left;
                                }
                                if (current->right)
                                {
                                        nb_child++;
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
                                                        _iterator = current;
                                        }
                                        else if (current && current->colour == BLACK && memory_colour == BLACK)
                                                _repearDoubleBlack(current);
                                }
                                else if (nb_child == 2)
                                {
                                        //find smallest key of right (or left) subtree
                                        smallest_key = _getInorder(current);
                                        _destroyPair(current);
                                        //deleted node become smallest key node
                                        current->pair = _allocator.allocate(1);
                                        _allocator.construct(current->pair, *smallest_key->pair);
                                        //delete node from subtree
                                        memory_colour = smallest_key->colour;
                                        left_child = smallest_key->left;
                                        right_child = smallest_key->right;
                                       // std::cout << "smallest is : " << smallest_key->pair->first << std::endl;
                                        null_node = _deleteOneChild(&smallest_key, &left_child, &right_child
                                                , memory_colour);
                                        //moved up is smallest key
                                        /*if ((current && current->colour == RED) || (current && memory_colour == RED))
                                        {
                                                current->colour = BLACK;
                                                if (!current->parent)
                                                        _iterator = current;
                                        }
                                        else if (current && current->colour == BLACK && memory_colour == BLACK)
                                                _repearDoubleBlack(current);*/
                                        if ((smallest_key && smallest_key->colour == RED) || (smallest_key && memory_colour == RED))
                                        {
                                                smallest_key->colour = BLACK;
                                                if (!smallest_key->parent)
                                                        _iterator = smallest_key;
                                        }
                                        else if (smallest_key && smallest_key->colour == BLACK && memory_colour == BLACK)
                                                _repearDoubleBlack(smallest_key);
                                        //std::cout << "parent ::: " << current->parent << std::endl;
                                }
                                if (_iterator && !_iterator->pair)
                                        _iterator = NULL;
                                if (null_node && smallest_key)
                                {
                                        delete smallest_key->left;
                                        delete smallest_key->right;
                                        delete smallest_key;
                                }
                                else if (null_node)
                                {
                                        delete current->left;
                                        delete current->right;
                                        delete current;
                                }
                                return (1);
                        }
                        node*   getIterator() const
                        {
                                return (_iterator);
                        }
                        node*   begin() const
                        {
                                node    *start = _iterator;

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
                                node    *start = _iterator;

                                if (!_iterator)
                                        return (NULL);
                                while (start->parent)
                                        start = start->parent;
                                while (start->right)
                                        start = start->right;
                                return (start->right);
                        }

                        node*  _iterator; // struct stocked here, used to iterate

                        private:
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
                                        //if node is left side of it's parent, next node is it's parent
                                        else if (current->parent && current->parent->left)
                                                current = current->parent;
                                        //or current is max, go to parent until we find one if a left child
                                        else
                                        {
                                                while (current->parent && current->parent->right == current)
                                                        current = current->parent;
                                                current = current->parent;
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
                                                if (*right_child)
                                                        parent->left = *right_child;
                                        }
                                        else if (parent && parent->right == *current)
                                        {
                                                parent->right = NULL;
                                                if (*left_child)
                                                        parent->right = *left_child;
                                                if (*right_child)
                                                        parent->right = *right_child;
                                        }
                                        _destroyPair(*current);
                                        delete *current;
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
                                                *current = new node();
                                                newNode(*current);
                                                (*current)->left = new node();
                                                newNode((*current)->left);
                                                (*current)->right = new node();
                                                newNode((*current)->right);
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

                                        //current->colour = DOUBLE;
                                        if (!current->parent)
                                        {
                                                _iterator = current;
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
                                                                _iterator = sibling;
                                                        
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
                                                _iterator = _getGrandParent(current);
                                        _repearDoubleBlack(current);
                                }
                                void    _destroyPair(node *current)
                                {
                                        if (!current || !current->pair)
                                                return ;
                                        _allocator.destroy(current->pair);
                                        _allocator.deallocate(current->pair, 1);
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
                                                        //parentNode = _getParent(current); //get it's parent now
                                                }
                                                else if (gParentNode->right && current == gParentNode->right->left)
                                                {
                                                        _rotateRight(parentNode);
                                                        parentNode = current;
                                                        current = current->right;
                                                        //parentNode = _getParent(current);
                                                }
                                                if (gParentNode && current == parentNode->left)
                                                        _rotateRight(gParentNode);
                                                else if (gParentNode && current == parentNode->right)
                                                        _rotateLeft(gParentNode);
                                                parentNode->colour = BLACK;
                                                gParentNode->colour = RED;
                                        }
                                }
                                void    newNode(node* current)
                                {
                                        current->parent = NULL;
                                        current->left = NULL;
                                        current->right = NULL;
                                        current->pair = NULL;
                                        current->colour = 0;
                                }
                                key_compare     _comp;
                                allocator_type	_allocator;
        };
}

#endif