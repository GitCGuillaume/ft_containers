#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# define RED 1
# define BLACK 2

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
                        
                        node*    search(Key const &key)
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
                        node*    normalInsert(const ft::pair<U, X>& pair)
                        {
                                node    *new_node = NULL;
                                Key     firstSubRoot = _iterator->pair->first;
                                Key     firstNewNode = pair.first;
                                //ft::pair<U, X>  ret;

                                if (!_iterator->right && !_iterator->left
                                        && _iterator->colour == 0) //no root
                                {
                                        _allocator.destroy(_iterator->pair);
                                        _allocator.deallocate(_iterator->pair, 1);
                                        _iterator->pair = _allocator.allocate(1);
                                        _allocator.construct(_iterator->pair, pair);
                                        //black colour
                                        _iterator->colour = BLACK;
                                        return (_iterator);
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
                        /*node*    insertOperator(node *newNode)
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
                        }*/
                        
                        void    deleteNode(Key const & key)
                        {
                                node            *current = NULL;
                                node            *smallest_key = NULL;
                                node            *left_child = NULL;
                                node            *right_child = NULL;
                                int             memory_colour = 0;
                                short int       nb_child = 0;

                                current = search(key);
                                if (!current)
                                        return ;
                                memory_colour = current->colour;
                               /* if (!current->parent) //is root
                                {

                                }*/
                               // std::cout << "current addr : " << current << std::endl;

                                std::cout << "first :: " << current->pair->first << std::endl;
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
                                //std::cout << "nb_child : " << nb_child << std::endl;
                                std::cout << "COLOUR BEFORE ::: " << current->colour << std::endl;
                                if ( nb_child < 2)
                                {
                                        memory_colour = current->colour;
                                        _deleteOneChild(&current, &left_child, &right_child
                                                , memory_colour);
                                        //moved up is either left or right child just do if left / right
                                }
                                else if (nb_child == 2)
                                {
                                        //find smallest key of right (or left) subtree
                                        smallest_key = current;
                                        smallest_key = smallest_key->left;
                                        while (smallest_key->right)
                                                smallest_key = smallest_key->right;
                                        _destroyPair(current);
                                        //deleted node become smallest key node
                                        current->pair = _allocator.allocate(1);
                                        _allocator.construct(&current->pair, smallest_key->pair);
                                        //delete node from subtree
                                        memory_colour = smallest_key->colour;
                                        _deleteOneChild(&smallest_key, &smallest_key->left, &smallest_key->right
                                                , memory_colour);
                                        smallest_key = NULL;
                                        //moved up is smallest key
                                }
                                //REPEAR TREE
                                if (current)
                                        std::cout << "COLOUR AFTER ::: " << current->colour << std::endl;
                                /*if (nb_child == 2)
                                {
                                        _deleteTwoChild(&current, left_child, right_child);
                                }*/
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
                        node*   end() const
                        {
                                node    *start = _iterator;

                                while (start->parent)
                                        start = start->parent;
                                while (start->right)
                                        start = start->right;
                                return (start->right);
                        }

                        node*  _iterator; // struct stocked here, used to iterate

                        private:
                                /*
                                        0 =null
                                        1 = red
                                        >1 black
                                */
                                /*void    _caseOneColourRed(node **current, node **child)
                                {
                                        node*   parent = _getParent(*current);

                                        _destroyNode(*current);
                                        delete *current;
                                        *current = NULL;
                                        if (child && *child)
                                        {
                                                *current = *child;
                                                *current->parent = parent;
                                                *current->colour = BLACK;
                                        }
                                }*/
                                void    _deleteOneChild(node **current, node **left_child, node **right_child
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
                                                *current = new node();
                                }
                                void    _destroyPair(node *current)
                                {
                                        if (!current || !current->pair)
                                                return ;
                                        _allocator.destroy(current->pair);
                                        _allocator.deallocate(current->pair, 1);
                                }
                                void    _swapColour(int *colour)
                                {
                                        if (*colour == RED)
                                                *colour = BLACK;
                                        else
                                                *colour = RED;
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
                                                parent->colour = BLACK;
                                        if (uncle)
                                                uncle->colour = BLACK;
                                        if (gParentNode)
                                                gParentNode->colour = RED;
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
                                allocator_type	_allocator;
        };
}

#endif