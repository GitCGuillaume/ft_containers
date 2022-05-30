#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

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
        struct s_node*  parent = NULL;
        struct s_node*  left = NULL;
        struct s_node*  right = NULL;
        T      pair = NULL;
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
        template<class It, class Container, class Key, class T, class Allocator>
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
                        
                                        BiDirectionnalIterator() : _ptr(), _old(){}
                                        
                                        //BiDirectionnalIterator(const BiDirectionnalIterator<U
                                        //        , typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value),
                                        //        Container>::type>& rhs) : _ptr(rhs.base()){}
                                        
                                        //BiDirectionnalIterator(const RedBlackTree& src, node* ptr, typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value),
                                        //        Container>::type) : _ptr(ptr), _old(src._iterator){}
                                        template<typename U>
                                        BiDirectionnalIterator(const RedBlackTree<U, typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value), Container>::type
                                                , key_type, mapped_type, Allocator>& src, node* ptr) : _ptr(ptr), _old(src._iterator){}
                                        template<typename U>
                                        BiDirectionnalIterator(const RedBlackTree<U, typename ft::enable_if<(ft::is_same<U, typename Container::value_type>::value), Container>::type
                                                , key_type, mapped_type, Allocator>& rhs) : _ptr(rhs._ptr), _old(rhs._old){}
                                        BiDirectionnalIterator &        operator=(const BiDirectionnalIterator& rhs)
                                        {
                                                if (this != &rhs)
                                                {
                                                        _ptr = rhs._ptr;
                                                        _old = rhs._old;
                                                }
                                                return (*this);
                                        }
                                        reference operator*() const
                                        {
                                                return (*_ptr->pair);
                                        }
                                        pointer operator->() const
                                        {
                                                return (_ptr->pair);
                                        }
                                        /* PREFIX */
                                        /*
                                                _old->right == _ptr will loop until parent root(NULL)
                                                or until _ptr->right is not old anymore
                                        */
                                        BiDirectionnalIterator& operator++()
                                        {
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
                        
                        node*    _search(Key const &key)
                        {
                                node    *subRoot = _iterator;

                                Key     firstSubRoot = subRoot->pair->first;
                                Key     firstNewNode = key;
                                //std::cout << "SEARCH" << std::endl;
                                while (subRoot)
                                {
                                        //std::cout << "first : " << firstSubRoot
                                          //      << " colour : " << subRoot->colour << std::endl;
                                        if (firstSubRoot < firstNewNode)
                                        {
                                                subRoot = subRoot->right;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (firstNewNode < firstSubRoot)
                                        {
                                                subRoot = subRoot->left;
                                                if (subRoot)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return (subRoot);
                                }
                                return (NULL);
                        }
                        template<typename U, typename X>
                        ft::pair<U, X>&    normalInsert(const ft::pair<U, X>& pair)
                        {
                                node    *new_node = NULL;
                                Key     firstSubRoot = _iterator->pair->first;
                                Key     firstNewNode = pair.first;
                                ft::pair<U, X>  ret;

                                if (!_iterator->right && !_iterator->left
                                        && _iterator->colour == 0) //no root
                                {
                                        _allocator.destroy(_iterator->pair);
                                        _allocator.deallocate(_iterator->pair, 1);
                                        _iterator->pair = _allocator.allocate(1);
                                        _allocator.construct(_iterator->pair, pair);
                                        //black colour
                                        _iterator->colour = 2;
                                        return (*_iterator->pair);
                                }
                                new_node = new node();
                                //Search
                               while (_iterator)
                                {
                                        if (firstSubRoot < firstNewNode)
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
                                        else if (firstNewNode < firstSubRoot)
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
                                                return (*_iterator->pair);
                                        }
                                }
                                new_node->pair = _allocator.allocate(1);
                                _allocator.construct(new_node->pair, pair);
                                //red colour
                                new_node->colour = 1;
                                _repearTreeInsert(new_node);
                                while (_getParent(_iterator))
                                        _iterator = _iterator->parent;
                                return (*new_node->pair);
                        }
                        node*    insertOperator(node *newNode)
                        {
                                Key     firstSubRoot = _iterator->pair->first;
                                Key     firstNewNode = newNode->pair->first;

                                if (!_iterator->right && !_iterator->left
                                        && _iterator->colour == 0) //no root
                                {
                                        _allocator.destroy(_iterator->pair);
                                        _allocator.deallocate(_iterator->pair, 1);
                                        _iterator->pair = newNode->pair;
                                        _iterator->colour = 2;
                                        return (NULL);
                                }
                                //Search
                                while (_iterator)
                                {
                                        if (firstSubRoot < firstNewNode)
                                        {
                                                 if (!_iterator->right)
                                                 {
                                                        newNode->parent = _iterator;
                                                        _iterator->right = newNode;
                                                        break ;
                                                 }
                                                _iterator = _iterator->right;
                                                firstSubRoot = _iterator->pair->first;
                                               
                                        }
                                        else if (firstNewNode < firstSubRoot)
                                        {
                                                if (!_iterator->left)
                                                {
                                                        newNode->parent = _iterator;
                                                        _iterator->left = newNode;
                                                        break ;
                                                }
                                                _iterator = _iterator->left;
                                                firstSubRoot = _iterator->pair->first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return (_iterator);
                                }
                                newNode->colour = 1;
                                //detech wich type of violate
                                _repearTreeInsert(newNode);
                                //_iterator = newNode;
                                //find new root
                                while (_getParent(_iterator))
                                        _iterator = _iterator->parent;
                                return (NULL);
                        }
                        
                        void    directDeleteNode(node *current)
                        {
                                node            *left_child = NULL;
                                node            *right_child = NULL;
                                short int       nb_child = 0;

                                if (!current)
                                        return ;
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
                                //if ( nb_child < 2)
                                  //      _deleteOneChild(&current, &left_child, &right_child);
                                /*if (nb_child == 2)
                                {
                                        _deleteTwoChild(&current, left_child, right_child);
                                }*/
                        }
                        void    deleteNode(Key const &key)
                        {
                                //node*    search_node = _search(key);

                                //if (search_node)
                                //{
                                //        if (search)
                                //}
                        }
                        node*   getIterator() const
                        {
                                return (_iterator);
                        }
                        node*   begin() const
                        {
                                node    *start = _iterator;

                                while (start->parent)
                                        start = start->parent;
                                while (start->left)
                                        start = start->left;
                                return (start);
                        }
                        node*  _iterator; // struct stocked here, used to iterate

                        private:
                                /*
                                0 =null
                                1 = red
                                >1 black
                                */
                                void    _caseOneColourRed(node **current, node **child)
                                {
                                        node*   parent = _getParent(*current);

                                        _destroyNode(*current);
                                        delete *current;
                                        *current = NULL;
                                        if (child && *child)
                                        {
                                                *current = *child;
                                                *current->parent = parent;
                                                *current->colour = 2;
                                        }
                                }
                                /* in case current or child is red */
                                bool    _caseTwoDelete(node **current, node **left_child, node **right_child)
                                {
                                        if (left_child && left_child->colour == 1)
                                        {
                                                _caseOneColourRed(current, left_child);
                                                return (true);
                                        }
                                        else if (right_child && right_child->colour == 1)
                                        {
                                                _caseOneColourRed(current, right_child);
                                                return (true);
                                        }
                                        else if (*current->colour == 1)
                                        {
                                                //if (left_child)
                                                _caseOneColourRed(current, left_child);
                                                //if (right_child)
                                                //        _caseOneColourRed(current, right_child);
                                                return (true);
                                        }
                                        return (false);
                                }
                                /*
                                        Case left left delete
                                                or left right
                                */
                                /*void    _caseThreeLeftDelete(node *current, current *child)
                                {
                                        node    *sibling = _getSibling(current);
                                        //left left

                                }*/
                                /*
                                        Case right right delete
                                                or right right
                                        child is left child (current will become left child)
                                */
                                void    _caseThreeRightDelete(node *current, node* sibling, node *child)
                                {
                                        //current->colour = 3;
                                        //_destroyNode(current);
                                }
                                /* if both current and child are black
                                        or one is red */
                                /*void    _deleteTwoChild(node **current, node *left_child, node *right_child)
                                {
                                        node*   parent = _getParent(*current);

                                        if (_caseTwoDelete(current, left_child, right_child))
                                                return ;
                                        if (parent && parent->left == current)
                                        {
                                                //call right correction
                                                _caseThreeRightDelete(current, _getSibling(current), left_child);
                                        }
                                        
                                }*/
                                void    _deleteOneChild(node **current, node **left_child, node **right_child)
                                {
                                        node*   parent = _getParent(*current);

                                        _destroyNode(*current);
                                        delete *current;
                                        if (*left_child)
                                                *current = *left_child;
                                        if (*right_child)
                                                *current = *right_child;
                                        if (*current)
                                                (*current)->colour = 2;
                                        (*current)->parent = parent;
                                }
                                void    _destroyNode(node *current)
                                {
                                        if (!current || !current->pair)
                                                return ;
                                        _allocator.destroy(current->pair);
                                        _allocator.deallocate(current->pair, 1);
                                }
                                void    _swapColour(int *colour)
                                {
                                        if (*colour == 1)
                                                *colour = 2;
                                        else
                                                *colour = 1;
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
                                        node    *parent = getParent(current);

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
                                                parent->colour = 2;
                                        if (uncle)
                                                uncle->colour = 2;
                                        if (gParentNode)
                                                gParentNode->colour = 1;
                                        //return (gParentNode);
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
                                                current->colour = 2;
                                        else if (parentNode->colour == 2)
                                                return ;
                                        else if (uncle && uncle->colour == 1) //oncle and parent must be black
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
                                                parentNode->colour = 2;
                                                gParentNode->colour = 1;
                                        }
                                }
                                allocator_type	_allocator;
        };
}

#endif