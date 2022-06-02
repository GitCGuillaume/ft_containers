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
                //std::cout << "_iterator addr : " << _iterator << std::endl;
                                if (!subRoot || !subRoot->pair)
                                        return (NULL);
                                Key     firstSubRoot = subRoot->pair->first;
                                Key     firstNewNode = key;
                        std::cout << "sub key : " << firstSubRoot << std::endl;
                        std::cout << "key : " << firstNewNode << std::endl;
                                while (subRoot)
                                {
                                        if (firstSubRoot < firstNewNode)
                                        {
                                                subRoot = subRoot->right;
                                                if (subRoot && subRoot->pair)
                                                        firstSubRoot = subRoot->pair->first;
                                        }
                                        else if (firstNewNode < firstSubRoot)
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
                        template<typename U, typename X>
                        node*    normalInsert(const ft::pair<U, X>& pair)
                        {
                                node    *new_node = NULL;

                                if (!_iterator->colour || !_iterator->pair) //no root
                                {
                                        //_allocator.destroy(_iterator->pair);
                                        //_allocator.deallocate(_iterator->pair, 1);
                                        _iterator->pair = _allocator.allocate(1);
                                        _allocator.construct(_iterator->pair, pair);
                                        //black colour
                                        _iterator->colour = BLACK;
                                        return (_iterator);
                                }
                                Key     firstSubRoot = _iterator->pair->first;
                                Key     firstNewNode = pair.first;
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
                        node    *getInorder(node *current)
                        {
                                if (!current)
                                        return (NULL);
                                if (current->right)
                                {
                                        current = current->right;
                                        while (current->left)
                                                current = current->left;
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
                        void    deleteNode(Key const & key)
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
                                        return ;
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
                                        //std::cout << "aaabb" << std::endl;
                                        memory_colour = current->colour;
                                        null_node = _deleteOneChild(&current, &left_child, &right_child
                                                , memory_colour);
                                        //U = current
                                        //V = old
                                        if ((current && current->colour == RED) || (current && memory_colour == RED))
                                        {
                                                current->colour = BLACK;
                                                if (!current->parent)
                                                        _iterator = current;
                                        }
                                        else if (current->colour == BLACK && memory_colour == BLACK)
                                                _repearDoubleBlack(current);
                                        //if (memory_colour == BLACK)
                                        //        _repearTreeDelete(current);
                                }
                                else if (nb_child == 2)
                                {
                                        //find smallest key of right (or left) subtree
                                        smallest_key = getInorder(current);
                                        //std::cout << "inorder is : " << smallest_key->pair->first << std::endl;
                                        _destroyPair(current);
                                        //deleted node become smallest key node
                                        current->pair = _allocator.allocate(1);
                                        _allocator.construct(&current->pair, smallest_key->pair);
                                        //delete node from subtree
                                        memory_colour = smallest_key->colour;
                                        null_node = _deleteOneChild(&smallest_key, &smallest_key->left, &smallest_key->right
                                                , memory_colour);
                                        //moved up is smallest key
                                        if (smallest_key->colour == RED || memory_colour == RED)
                                                smallest_key->colour = BLACK;
                                        else if (smallest_key->colour == BLACK && memory_colour == BLACK)
                                                _repearDoubleBlack(smallest_key);
                                        /*else */
                                        //if (memory_colour == BLACK)
                                        //        _repearTreeDelete(smallest_key);
                                }
                                std::cout << "lefttt" << std::endl;
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
                        }
                        void    _repearDoubleBlack(node *current)
                        {
                                std::cout << "reparation !" << std::endl;
                                if (current->pair)
                                        std::cout << "CURRENT IS : " << current->pair->first << std::endl;
                                node    *sibling = _getSibling(current);
                               // std::cout << "reparation2 !" << std::endl;
//std::cout << "addr current pair : " << current->pair << std::endl;
//std::cout << "addr parent : " << current->parent << std::endl;
                                current->colour = DOUBLE;
                                if (!current->parent)
                                {
                                        std::cout << "!current->parent" << std::endl;
                                      //  std::cout << "current :: " << current->pair->first << std::endl; 
                                        _iterator = current;
                                        current->colour = BLACK;
                                        return ;
                                }
                                if (!sibling)
                                {
                                        std::cout << "no sibling" << std::endl;
                                        _repearDoubleBlack(current->parent);
                                }
                                //std::cout << "allo" << std::endl;
                                if (current && current->parent && sibling)
                                {
                                        std::cout << "current par all that" << std::endl;
                                        std::cout << "sibli col : " << sibling->colour << " sib le col : "
                                                << sibling->left << "si : " << sibling->right << std::endl;
                                        if (sibling->colour == BLACK
                                                && ((sibling->left && sibling->left->colour == RED)
                                                || (sibling->right && sibling->right->colour == RED)))
                                        {
                                                //left left case
                                                if (sibling->parent && sibling == sibling->parent->left
                                                        && (sibling->left->colour == RED
                                                        || (sibling->left->colour == RED && sibling->right->colour == RED)))
                                                {
                                                        sibling->left->colour = BLACK;
                                                        sibling->colour = sibling->parent->colour;
                                                        _rotateRight(sibling->parent);
                                                        std::cout << "LEFT LEFT CASE" << std::endl;
                                                }
                                                //left right case
                                                else if (sibling->parent && sibling->parent->left == current
                                                        && sibling->right->colour == RED)
                                                {
                                                        _rotateLeft(sibling);
                                                        _rotateRight(current->parent);
                                                        //sibling = _getSibling(current);
                                                      //   std::cout << "sib left" << std::endl;
                                                        std::cout << "LEFT RIGHT CASE " << std::endl;
                                                }
                                                //right right case
                                                else if (sibling->parent && sibling == sibling->parent->right
                                                        && (sibling->right->colour == RED
                                                        || (sibling->left->colour == RED && sibling->right->colour == RED)))
                                                {
                                                        sibling->right->colour = BLACK;
                                                        sibling->colour = sibling->parent->colour;
                                                        _rotateLeft(sibling->parent);
                                                        std::cout << "RIGHT RIGHT CASE" << std::endl;
                                                }
                                                else if (sibling->parent && sibling->parent->right == current
                                                        && sibling->left->colour == RED) // Right left case
                                                {
                                                        _rotateRight(sibling);
                                                        _rotateLeft(current->parent);
                                                        //sibling = _getSibling(current);
                                                     //   std::cout << "sib right " << std::endl;
                                                        std::cout << "RIGHT LEFT CASE" << std::endl;
                                                }
                                               // std::cout << "sib val : " << sibling->pair->first << std::endl;
                                                std::cout << "ikkk" << std::endl;
                                                if (!sibling->parent)
                                                        _iterator = sibling;
                                               // std::cout << "zzzkkk" << std::endl;
                                                
                                        }
                                        else if (sibling->colour == RED)
                                                _repearDoubleBlackTwo(current);
                                        else if (sibling->colour == BLACK
                                                && ((sibling->left && sibling->left->colour == BLACK)
                                                && (sibling && sibling->right->colour == BLACK))
                                                || (sibling->colour == BLACK && !sibling->left && !sibling->right))
                                        {
                                                std::cout << "àkkk" << std::endl;
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
                                //node*   save = current;
                                node*   sibling = _getSibling(current);

                                if (!sibling)
                                        return ;
                                sibling->colour = BLACK;
                                current->parent->colour = RED;
                                std::cout << "kmdqsfqd" << std::endl;
                                //std::cout << "aaaaaaaaaaa : " << current->pair->first << std::endl;
                                if (sibling == sibling->parent->left)
                                {
                                      //  std::cout << "right rota ! " << std::endl;
                                        _rotateRight(current->parent);
                                        //current = current->right;
                                }
                                else if (sibling == sibling->parent->right)
                                {
                                      //  std::cout << "current --- : " << current->parent->pair->first << std::endl; 
                                      //  std::cout << "left rota ! " << std::endl;
                                        _rotateLeft(current->parent);
                                        //current = current->left;
                                }
                                if (!_getGrandParent(current)->parent)
                                        _iterator = _getGrandParent(current);
                                //std::cout << "pair : " << current->pair << std::endl;
                                //std::cout << "current --- : " << current->parent->parent->parent->pair->first << std::endl; 
                                //std::cout << "current->f : " << current->pair->first << std::endl;
                                //std::cout << "save : " << save->pair->first << std::endl;
                                //if (!save->parent)
                                //        _iterator = save;
                                //if (current->parent && current->parent->pair)
                                //        std::cout << "bbbbbbbb : " << current->parent->pair->first << std::endl;
                                _repearDoubleBlack(current);
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
                                      //  std::cout << "*current addr : " << *current << std::endl;
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
                                                (*current)->left = new node();
                                                (*current)->right = new node();
                                                (*current)->parent = parent;
                                                (*current)->colour = BLACK;
                                                (*current)->left->colour = BLACK;
                                                (*current)->right->colour = BLACK;
                                                return (*current);
                                        }
                                        return (NULL);
                                       // std::cout << "left addr : " << left_child << std::endl;
                                       // std::cout << "*current addr : " << *current << std::endl;
                                       // std::cout << "right addr : " << right_child << std::endl;
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
/*std::cout << "parent : " << parent->pair->first << std::endl;
if (parent->left)
        std::cout << "gauche : " << parent->left->pair->first << std::endl;
if (parent->right)
        std::cout << "droite : " << parent->right->pair->first << std::endl;*/
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
                                /*void    _repearTreeDelete(node *current)
                                {
                                        node*   sibling = NULL;

                                        if (!current)
                                                return ;
                                        if (!current->parent) //is_root
                                        {
                                                current->colour = BLACK;
                                                _iterator = current;
                                                return ;
                                        }
                                        sibling = _getSibling(current);
                                        
                                        */
                                        /*if (current)
                                                std::cout << "current is : " << current->pair << std::endl;
                                        if (current && current->pair)
                                                std::cout << "current first is : " << current->pair->first << std::endl;
                                        std::cout << "sibling colour : " << sibling->colour << std::endl;
                                        std::cout << "sibling is : " << sibling->pair->first << std::endl;
                                        */
                                        /*if (!sibling)
                                                return ;
                                        if (sibling->colour == RED) //sibling is red
                                        {
                                                sibling->colour = BLACK;
                                                current->parent->colour = RED;
                                                if (current->parent->left == current)
                                                {
                                                        std::cout << "left rotate" << std::endl;
                                                        _rotateLeft(current->parent);
                                                }
                                                else if (current->parent->right == current)
                                                        _rotateRight(current->parent);
                                                sibling = _getSibling(current);
                                                std::cout << "sib par->par : " << sibling->parent->parent->pair->first << std::endl;
                                                std::cout << "case 2 mes couilles" << std::endl;
                                                //now we need to have correct black height node
                                                //parent can't be red if it's sibling is black
                                                //sibling->colour = RED;
                                                //sibling->parent->colour = BLACK;
                                        }
                                        //check right number of case current and sibling black
                                        if (sibling->colour == BLACK
                                                && ((sibling->left && sibling->left->colour == BLACK)
                                                && (sibling->right && sibling->right->colour == BLACK)
                                                || (!sibling->left && !sibling->right)))
                                        {
                                                std::cout << "case 3" << std::endl;
                                                sibling->colour = RED; //need to correct height black
                                                if (sibling->parent->colour == RED) //if parent is red
                                                        sibling->parent->colour = BLACK;
                                                else if (sibling->parent->colour == BLACK) //if parent is black throw case sibling is red
                                                        _repearTreeDelete(current->parent);
                                        }
                                        //else if (sibling->colour == BLACK
                                        //        && ((sibling->left && sibling->left->colour == RED)
                                        //        || (sibling->right && sibling->right->colour == RED)))
                                        else
                                        {
                                                //current is on left
                                                if (current->parent->left == current
                                                        && sibling->right->colour == BLACK)
                                                {
                                                        sibling->left->colour = RED;
                                                        sibling->colour = RED;
                                                        _rotateRight(sibling);
                                                        sibling = current->parent->right;
                                                        */
                                                        /*std::cout << "case 5 current left" << std::endl;
                                                        //neveux est tout à droite
                                                        //recolour inner nephew
                                                        if (sibling->left)
                                                                sibling->left->colour = BLACK;
                                                        sibling->colour = RED;
                                                        _rotateRight(sibling);
                                                        sibling = current->parent->right;
                                                        //sibling = _getSibling(current);
                                                        sibling->colour = sibling->parent->colour;
                                                        sibling->parent->colour = BLACK;
                                                        if (sibling->right)
                                                                sibling->right->colour = BLACK;
                                                        _rotateLeft(sibling->parent);
                                                        sibling = _getSibling(current);
                                                        return ;*/
                                                /*}
                                                else if (current->parent->right == current
                                                        && sibling->left->colour == BLACK)
                                                {
                                                        std::cout << "case 5 current right" << std::endl;
                                                        sibling->right->colour = BLACK;
                                                        sibling->colour = RED;
                                                        _rotateLeft(sibling);
                                                        sibling = current->parent->left;
                                                        //neveux est tout à gauche
                                                        */
                                                        /*if (sibling->right)
                                                                sibling->right->colour = BLACK;
                                                        sibling->colour = RED;
                                                        _rotateLeft(sibling);
                                                        sibling = current->parent->left;
                                                        //sibling = _getSibling(current);
                                                        sibling->colour = sibling->parent->colour;
                                                        sibling->parent->colour = BLACK;
                                                        if (sibling->left)
                                                                sibling->left->colour = BLACK;
                                                        _rotateRight(sibling->parent);
                                                        sibling = _getSibling(current);
                                                        return ;*/
                                                /*}
                                                std::cout << "case 6" << std::endl;
                                                sibling->colour = current->parent->colour;
                                                current->parent->colour = BLACK;
                                                if (current->parent->left == current)
                                                {
                                                        sibling->right->colour = BLACK;
                                                        _rotateLeft(current->parent);
                                                }
                                                else
                                                {
                                                        sibling->left->colour = BLACK;
                                                        _rotateRight(current->parent);
                                                }
                                                */
                                                /*if (current->parent->left == current
                                                        && sibling->right->colour == RED)
                                                {
                                                        std::cout << "case 6 current left" << std::endl;
                                                        sibling->colour = sibling->parent->colour;
                                                        sibling->parent->colour = BLACK;
                                                        sibling->right->colour = BLACK;
                                                        std::cout << "SIBLING PARENT :: " << sibling->parent->pair->first << std::endl;
                                                        if (_getGrandParent(sibling))
                                                                std::cout << "SIBLING GR PARENT :: " << _getGrandParent(sibling)->pair->first << std::endl;
                                                        std::cout << "PARENT :: " << current->parent->pair->first << std::endl;
                                                        if (_getGrandParent(current))
                                                                std::cout << "GR PARENT :: " << _getGrandParent(current)->pair->first << std::endl;
                                                        _rotateLeft(current->parent);
                                                        if (current && current->pair)
                                                                std::cout << "current pair first : " << current->pair->first << std::endl;
                                                        if (sibling && sibling->pair)
                                                                std::cout << "sibling pair first : " << sibling->pair->first << std::endl;
                                                        sibling->parent = current->parent;
                                                        _iterator = current->parent;
                                                        std::cout << "CURRENT PARENT PARENT ADDR :: " << current->parent->parent->parent->parent->pair->first << std::endl;
                                                        std::cout << "CURRENT PARENT :: " << current->parent->pair->first << std::endl;
                                                        std::cout << "SIBLING PARENT ADDR :: " << sibling->parent << std::endl;
                                                        std::cout << "SIBLING PARENT :: " << sibling->parent->pair->first << std::endl;
                                                        //exit(0);
                                                        //current = current->parent;
                                                        //sibling = _getSibling(current);
                                                        //if (!current->parent)
                                                        //        _iterator = current;
                                                        //std::cout << "sibling right now : " << current->pair->first << std::endl;
                                                        //std::cout << "_it first : " << _iterator->pair->first << std::endl;
                                                        //exit(0);
                                                }
                                                else if (current->parent->right == current
                                                        && sibling->left->colour == RED)
                                                {
                                                        std::cout << "case 6 current right" << std::endl;
                                                        sibling->colour = sibling->parent->colour;
                                                        sibling->parent->colour = BLACK;
                                                        if (sibling->left)
                                                                sibling->left->colour = BLACK;
                                                        _rotateRight(current->parent);
                                                        std::cout << "CURRENT PARENT ADDR :: " << current->parent << std::endl;
                                                        std::cout << "CURRENT PARENT :: " << current->parent->pair->first << std::endl;
                                                        std::cout << "SIBLING PARENT ADDR :: " << sibling->parent << std::endl;
                                                        std::cout << "SIBLING PARENT :: " << sibling->parent->pair->first << std::endl;
                                                        exit(0);
                                                }*/
                                        //}
                                //}
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