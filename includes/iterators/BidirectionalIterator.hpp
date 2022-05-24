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
                                while (subRoot)
                                {
                                        if (firstSubRoot < firstNewNode)
                                                subRoot = subRoot->right;
                                        else if (firstNewNode < firstSubRoot)
                                                subRoot = subRoot->right;
                                        else if (firstNewNode == firstSubRoot)
                                                return (subRoot);
                                        else
                                                return (NULL);
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
                                bool    newNodeSide = false;
                                bool    parentNodeSide = false;
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
                                                        newNodeSide = true; //detect if new node is left or right
                                                 }
                                                _iterator = _iterator->right;
                                               
                                        }
                                        else if (firstNewNode < firstSubRoot)
                                        {
                                                if (!_iterator->left)
                                                {
                                                        newNode->parent = _iterator;
                                                        newNodeSide = false; //detect if new node is left or right
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
                                if (_iterator->parent)
                                {
                                        if (_iterator == _iterator->parent->right)
                                                parentNodeSide = true;
                                        /*std::cout << "Gparent : " << _iterator->parent << std::endl;
                                        std::cout << "Gparent->left : " << _iterator->left << std::endl;
                                        std::cout << "Gparent->right : " << _iterator->right << std::endl;
                                        std::cout << "parentNodeSide : " << parentNodeSide << std::endl;*/
                                }
                                //detech wich type of violate
                                
                                _iterator = root;
                        }
                        //newNodeSide == 0 == newNode is left
                        //newNodeSide == 1 == newNode is right
                        //parentNode == 0 == parent is left
                        //parentNode == 1 == parent is right
                        char    _detectAndCorrectViolate(node** node, bool newNodeSide, bool parentNode)
                        {
                                //parentNode
                                //grandParentNode
                                //dois-je boucler le detectViolate (pour parent+oncle == rouge par ex)
                                //      pour que l'arbre sois validé
                                //si parent + uncle == rouge
                                        //lancer violationRepair1 (recolor racine sous arbre + parent et oncle)
                                /*
                                si parentNode == 0
                                        si newNodeSide == 0// && uncleSide == 1
                                                swap colour of parent and grand parent
                                                rotateRight
                                        sinon si newNodeSide == 1// && uncleSide == 1
                                                rotateLeft
                                                swap colour of parent and grand parent
                                                rotateRight
                                        sinon si 
                                finSi
                                si parentNode == 1
                                        si newNodeSide == 1// && uncleSide == 0
                                                swap colour of parent and grand parent
                                                rotateleft
                                        sinon si newNodeSide == 0// && uncleSide == 1
                                                rotateRight
                                                swap colour of parent and grand parent
                                                rotateLeft
                                        sinon si 
                                finSi
                                */
                        }
                        node*  _iterator; // struct stocked here, used to iterate
                        private:
                                allocator_type	_allocator;
                                
        };
}

#endif