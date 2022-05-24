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
        char    colour;
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
                                        std::cout << "first : " << firstSubRoot << std::endl;
                                        if (firstSubRoot < firstNewNode)
                                        {
                                                subRoot = subRoot->right;
                                        }
                                        else if (firstNewNode < firstSubRoot)
                                        {
                                                subRoot = subRoot->right;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return (subRoot);
                                        else
                                                return (NULL);
                                        if (_iterator && _iterator->pair)
                                                firstSubRoot = _iterator->pair->first;
                                }
                                return (NULL);
                        }
                        void    _insert(node *newNode)
                        {
                                std::cout << "newNode : " << newNode << std::endl;
                                node*   root = _iterator;
                                node*   nodeMemory = _iterator;
                                Key     firstSubRoot = _iterator->pair->first;
                                Key     firstNewNode = newNode->pair->first;
                                //bool    newNodeSide = false;
                                //bool    parentNodeSide = false;
                                //Search
                                if (!_iterator->right && !_iterator->left
                                        && _iterator->colour == 0) //no root
                                {
                                        _allocator.destroy(_iterator->pair);
                                        _allocator.deallocate(_iterator->pair, 1);
                                        _iterator->pair = newNode->pair;
                                        _iterator->colour = 1;
                                        return ;
                                }
                                while (_iterator)
                                {
                                        nodeMemory = _iterator;
                                        if (firstSubRoot < firstNewNode)
                                        {
                                                 if (!_iterator->right)
                                                 {
                                                        newNode->parent = _iterator;
                                                        //newNodeSide = true; //detect if new node is left or right
                                                 }
                                                _iterator = _iterator->right;
                                               
                                        }
                                        else if (firstNewNode < firstSubRoot)
                                        {
                                                if (!_iterator->left)
                                                {
                                                        newNode->parent = _iterator;
                                                        //newNodeSide = false; //detect if new node is left or right
                                                }
                                                _iterator = _iterator->left;
                                        }
                                        else if (firstNewNode == firstSubRoot)
                                                return ;
                                        if (_iterator && _iterator->pair)
                                                firstSubRoot = _iterator->pair->first;
                                }
                                //nodeMemory is sub root
                                _iterator = nodeMemory;
                                //insert new node as left or right
                                if (firstSubRoot < firstNewNode)
                                        _iterator->right = newNode;
                                else
                                        _iterator->left = newNode;
                                /*std::cout << "newNode : " << newNode << std::endl;
                                std::cout << "subroot : " << _iterator << std::endl;
                                std::cout << "parent : " << newNode->parent << std::endl;
                                std::cout << "newNode->parent->left : " << newNode->parent->left << std::endl;
                                std::cout << "newNode->parent->right : " << newNode->parent->right << std::endl;
                                std::cout << "newNodeSide : " << newNodeSide << std::endl;*/
                                //put it as red colour
                                newNode->colour = 0;
                                //detect if parent node is left or right
                                //if (_iterator->parent)
                               // {
                                 //       if (_iterator == _iterator->parent->right)
                                   //             parentNodeSide = true;
                                        /*std::cout << "Gparent : " << _iterator->parent << std::endl;
                                        std::cout << "Gparent->left : " << _iterator->left << std::endl;
                                        std::cout << "Gparent->right : " << _iterator->right << std::endl;
                                        std::cout << "parentNodeSide : " << parentNodeSide << std::endl;*/
                               // }
                                //detech wich type of violate
                                _repearTree(newNode);
                                //find new root
                                while (getParent(newNode))
                                        newNode = newNode->parent;
                                _iterator = newNode;
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
                        node    *getUncle(node* gParentNode, node* parent)
                        {

                                if (!gParentNode || !parent)
                                        return (NULL);
                                if (gParentNode->left != parent)
                                        return (gParentNode->left);
                                else
                                        return (gParentNode->right);
                                return (NULL);
                        }
                        node    *getParent(node* current)
                        {
                                if (!current)
                                        return (NULL);
                                return (current->parent);
                        }
                        node*    repearCaseOne(node* parent, node* uncle, node* gParentNode)
                        {
                                parent->colour = 0;
                                uncle->colour = 0;
                                gParentNode->colour = 1;
                                return (gParentNode);
                        }
                        void    _swapColour(char *colour)
                        {
                                if (*colour == 0)
                                        *colour = 1;
                                else
                                        *colour = 0;
                        }
                        void    _rotateRight(node *parent, node *grandParent)
                        {
                                node*    leftChild = parent->left; //cpy left child of parent

                                parent->left = leftChild->right; //give to left child it's right child
                                if (leftChild->right) //check if left child has a right child
                                        leftChild->right->parent = parent; //give this child head the parent address
                                leftChild->parent = grandParent;
                                leftChild->right = parent;
                                if (grandParent && parent == grandParent->left) //give grand parent the right branch
                                        grandParent->left = leftChild;
                                else if (grandParent && parent == grandParent->right)
                                        grandParent->right = leftChild;
                                parent->parent = leftChild; //current node need an update parent so the left child
                        }
                        void    _rotateLeft(node *parent, node *grandParent)
                        {
                                node*    rightChild = parent->right; //cpy right child of parent

                                parent->right = rightChild->left; //give to right child it's right child
                                if (rightChild->left) //check if right child has a left child
                                        rightChild->left->parent = parent; //give this child head the parent address
                                rightChild->parent = grandParent;
                                rightChild->left = parent;
                                if (grandParent && parent == grandParent->left) //give grand parent the right branch
                                        grandParent->left = rightChild;
                                else if (grandParent && parent == grandParent->right)
                                        grandParent->right = rightChild;
                                parent->parent = rightChild; //current node need an update parent so the right child
                        }
                        void    _repearTree(node *current)
                        {
                                node   *gParentNode, *parentNode, *uncle;

                                gParentNode = getGrandParent(current);
                                parentNode = getParent(current);
                                //if (!parentNode || !gParentNode)
                                //        return ;
                                uncle = getUncle(gParentNode, parentNode);
                                while (uncle && uncle->colour > 0)
                                {
                                        current = repearCaseOne(parentNode, uncle, gParentNode);
                                        gParentNode = getGrandParent(current);
                                        parentNode = getParent(current);
                                        uncle = getUncle(gParentNode, parentNode);
                                }
                                //if (gparentNode == gParentNode->left) //parent is left
                                //{
                                        if (parentNode->left == current) //node is left
                                        {
                                                //swap colour of parent and grand parent
                                                _swapColour(&parentNode->colour);
                                                _swapColour(&gParentNode->colour);
                                                //rotateRight
                                                _rotateRight(parentNode, gParentNode);
                                        }
                                        else if (parentNode->right == current)
                                        {
                                                //rotateLeft
                                                _rotateLeft(parentNode, gParentNode);
                                                //swap colour of parent and grand parent
                                                _swapColour(&parentNode->colour);
                                                _swapColour(&gParentNode->colour);
                                                //rotateRight
                                                _rotateRight(parentNode, gParentNode);
                                        }
                                /*}
                                else if (parentNode == gParentNode->right) // parent is right
                                {*/
                                        if (parentNode->right == current) //node is right
                                        {
                                                //swap colour of parent and grand parent
                                                _swapColour(&parentNode->colour);
                                                _swapColour(&gParentNode->colour);
                                                //rotateleft
                                                 _rotateLeft(parentNode, gParentNode);
                                        }
                                        else if (parentNode->left == current)
                                        {
                                                //rotateRight
                                                _rotateRight(parentNode, gParentNode);
                                                //swap colour of parent and grand parent
                                                _swapColour(&parentNode->colour);
                                                _swapColour(&gParentNode->colour);
                                                //rotateLeft
                                                _rotateLeft(parentNode, gParentNode);
                                        }
                                //}
                        }
                        node*  _iterator; // struct stocked here, used to iterate
                        private:
                                allocator_type	_allocator;
                                
        };
}

#endif