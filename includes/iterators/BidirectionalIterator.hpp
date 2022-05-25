#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

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
        0 = red
        1 = black
        2+ = 2+ black (delete part)
*/
namespace ft
{
        template<class It, class Container, class Key, class T, class Allocator>
        class   BidirectionalIterator
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
                        BidirectionalIterator(){}
                        ~BidirectionalIterator(){}
                        BidirectionalIterator(node* iterator) : _iterator(iterator){}
                        reference operator*() const
                        {
                                return (*_iterator->pair);
                        }
                        pointer operator->()
                        {
                                return (_iterator->pair);
                        }
                        node*    _search(node *newNode)
                        {
                                node    *subRoot = _iterator;

                                Key     firstSubRoot = subRoot->pair->first;
                                Key     firstNewNode = newNode->pair->first;
                                std::cout << "SEARCH" << std::endl;
                                while (subRoot)
                                {
                                        std::cout << "first : " << firstSubRoot
                                                << " colour : " << subRoot->colour << std::endl;
                                        if (firstSubRoot < firstNewNode)
                                        {
                                                subRoot = subRoot->right;
                                                firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (firstNewNode < firstSubRoot)
                                        {
                                                subRoot = subRoot->left;
                                                firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return (subRoot);
                                }
                                return (NULL);
                        }
                        void    _insert(node *newNode)
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
                                        return ;
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
                                                return ;
                                }
                                newNode->colour = 1;
                                //detech wich type of violate
                                _repearTree(newNode);
                                //find new root
                                while (getParent(_iterator))
                                        _iterator = _iterator->parent;
                        }
                        node    *getGrandParent(node* current)
                        {
                                node*    parent;

                                if (!current)
                                        return (NULL);
                                parent = current->parent;
                                if (!parent)
                                        return (NULL);
                                return (parent->parent);
                        }
                        node    *getParent(node* current)
                        {
                                if (!current)
                                        return (NULL);
                                return (current->parent);
                        }
                        node    *getUncle(node *current)
                        {
                                node*   parent = getParent(current);
                                node*   gParentNode = getGrandParent(current);
                                if (!gParentNode || !parent)
                                        return (NULL);
                                if (gParentNode->left != parent)
                                        return (gParentNode->left);
                                else if (gParentNode->right != parent)
                                        return (gParentNode->right);
                                return (NULL);
                        }
                        void    repearCaseOne(node *current)
                        {
                                node    *parent = getParent(current);
                                node    *uncle = getUncle(current);
                                node    *gParentNode = getGrandParent(current);
                                if (parent)
                                        parent->colour = 2;
                                if (uncle)
                                        uncle->colour = 2;
                                if (gParentNode)
                                        gParentNode->colour = 1;
                                //return (gParentNode);
                                _repearTree(gParentNode);
                        }
                        /*
                         0 =null
                         1 = red
                         >1 black
                        */
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
                                node    *parent = getParent(current);
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
                                node    *parent = getParent(current);
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
                        void    _repearTree(node *current)
                        {
                                node    *uncle = getUncle(current);
                                node    *parentNode = NULL;
                                node    *gParentNode = NULL;
                                parentNode = getParent(current);
                                gParentNode = getGrandParent(current);
                                if (!current->parent)
                                        current->colour = 2;
                                else if (parentNode->colour == 2)
                                        return ;
                                else if (uncle && uncle->colour == 1) //oncle and parent must be black
                                        repearCaseOne(current);
                                else
                                {
                                        if (gParentNode->left && current == gParentNode->left->right)
                                        {
                                                _rotateLeft(parentNode);
                                                parentNode = current; //parent is now current
                                                current = current->left; //current node is now it's old parent
                                                //parentNode = getParent(current); //get it's parent now
                                        }
                                        else if (gParentNode->right && current == gParentNode->right->left)
                                        {
                                                _rotateRight(parentNode);
                                                parentNode = current;
                                                current = current->right;
                                                //parentNode = getParent(current);
                                        }
                                        if (gParentNode && current == parentNode->left)
                                                _rotateRight(gParentNode);
                                        else if (gParentNode && current == parentNode->right)
                                                _rotateLeft(gParentNode);
                                        parentNode->colour = 2;
                                        gParentNode->colour = 1;
                                }
                        }
                        node*  _iterator; // struct stocked here, used to iterate
                        private:
                                allocator_type	_allocator;
        };
}

#endif