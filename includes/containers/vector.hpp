#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../library_headers/is_integral.hpp"
#include "../library_headers/enable_if.hpp"
#include <iterator>
#include <exception>
#include <sstream>
#include <limits>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> > class	vector
	{
		public:
			/* MEMBERS TYPES */
			typedef T		value_type;
			typedef Allocator	allocator_type;
			typedef typename Allocator::reference	reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer	pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			//typedef typename ft::iterator<std::random_access_iterator_tag, ft::RandomAccessIterator<value_type> >	iterator;
			typedef ft::RandomAccessIterator<value_type>		iterator;
			typedef ft::RandomAccessIterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t	size_type;
			/* MEMBERS FUNCTIONS */
			vector() : _capacity_allocator(0), _size(0)
			{
				_vec = _allocator.allocate(0);
			}
			/* TESTER CAPACITY ALLOCATORS */
			explicit	vector(const Allocator& alloc) : _vec(NULL), _allocator(alloc), _capacity_allocator(0), _size(0){}
			explicit	vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) :
				_allocator(alloc), _capacity_allocator(count), _size(count)
			{
				_vec = _allocator.allocate(_capacity_allocator);
				for (size_type i = 0; i < this->size(); i++)
					_allocator.construct(_vec + i, value);
			}
			template<class InputIt>
			vector(InputIt first, InputIt last,
				const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) :
				_allocator(alloc)
			{
				size_type	count = 0;

				count = std::distance(last, first);
				_capacity_allocator = count;
				_vec = _allocator.allocate(_capacity_allocator);
				for (size_type i = 0; i < count; i++)
				{
					if (first != last)
					{
						_allocator.construct(_vec + i, *first);
						first++;
					}
				}
				_size = count;
			}
			vector(const vector& other)
			{
				_allocator = other.get_allocator();
				_vec = _allocator.allocate(other.capacity());
				_capacity_allocator = other.capacity();
				_size = other.size();
				for (size_type i = 0; i < other.size(); i++)
					_allocator.construct(_vec + i, other.at(i));
			}
			virtual	~vector()
			{
				if (_vec)
				{
					for (size_type i = 0; i < _size; i++)
						_allocator.destroy(_vec + i);
					_allocator.deallocate(_vec, _capacity_allocator);
				}
			}
			vector&	operator=(const vector& other)
			{
				if (this != &other)
				{
					if (_vec)
					{
						for (size_type i = 0; i < _size; i++)
							_allocator.destroy(_vec + i);
						_allocator.deallocate(_vec, _capacity_allocator);
						_allocator = other.get_allocator();
						_vec = _allocator.allocate(other.capacity());
					}
					_capacity_allocator = other.capacity();
					_size = other.size();
					for (size_type i = 0; i < other.size(); i++)
						_allocator.construct(_vec + i, other.at(i));
				}
				return (*this);
			}
			/* Oublie pas de mettre les fonctions dans le bon ordre */
			void	assign(size_type count, const T& value)
			{
				//TRY CATCH ?
				size_type i = 0;

				for (; i < _size; i++)
					_allocator.destroy(_vec + i);
				if (this->capacity() <= count)
				{
					if (_vec)
						_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = count;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				for (i = 0; i < count; i++)
					_allocator.construct(_vec + i, value);
				_size = count;
			}
			/* ::type* = 0 () */
			template<class InputIt>
			void	assign(InputIt first, InputIt last,
				typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				size_type	i = 0;
				difference_type	count = 0;

				count = std::distance(last, first);
				for (; i < _size; i++)
					_allocator.destroy(_vec + i);
				if (this->capacity() <= static_cast<unsigned>(count))
				{
					if (_vec)
						_allocator.deallocate(_vec, _capacity_allocator);
					_capacity_allocator = count;
					_vec = _allocator.allocate(_capacity_allocator);
				}
				i = 0;
				while (first != last)
				{
					_allocator.construct(_vec + i++, *first);
					first++;
				}
				_size = static_cast<size_type>(count);
			}
			allocator_type	get_allocator() const
			{
				return (_allocator);
			}
			/* ELEMENTS ACCESS */
			reference	at(size_type pos)
			{
				if (!(pos < this->size()))
				{
					std::stringstream	oss;
					std::string err_msg;
					std::string	concat_msg;

					err_msg = "vector::_M_check_range: __n (which is ";
					oss << pos;
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ") >= this->size() (which is ";
					concat_msg.clear();
					oss.clear();
					oss << this->size();
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ")";
					oss.clear();
					throw std::out_of_range(err_msg);
				}
				return (_vec[pos]);
			}
			/* ELEMENTS ACCESS */
			const_reference	at(size_type pos) const
			{
				if (!(pos < this->size()))
				{
					std::stringstream	oss;
					std::string err_msg;
					std::string	concat_msg;

					err_msg = "vector::_M_check_range: __n (which is ";
					oss << pos;
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ") >= this->size() (which is ";
					concat_msg.clear();
					oss.clear();
					oss << this->size();
					std::getline(oss, concat_msg);
					err_msg += concat_msg + ")";
					oss.clear();
					throw std::out_of_range(err_msg);
				}
				return (_vec[pos]);
			}
			reference	operator[](size_type pos)
			{
				return (_vec[pos]);
			}
			const_reference	operator[](size_type pos) const
			{
				return (_vec[pos]);
			}
			reference	front()
			{
				return (_vec[0]);
			}
			const_reference	front() const
			{
				return (_vec[0]);
			}
			reference	back()
			{
				return (_vec[_size - 1]);
			}
			const_reference	back() const
			{
				return (_vec[_size - 1]);
			}
			T*	data()
			{
				return (this->_vec);
			}
			const T*	data() const
			{
				return (this->_vec);
			}
			/* ITERATORS */
			iterator	begin()
			{
				return (this->_vec);
			}
			const_iterator	begin() const
			{
				return (this->_vec);
			}
			iterator	end()
			{
				if (_size == 0)
					return (this->_vec);
				return (this->_vec + _size);
			}
			const_iterator	end() const
			{
				if (_size == 0)
					return (this->_vec);
				return (this->_vec + _size);
			}
			/* CAPACITY */
			bool	empty() const
			{
				if (this->begin() == this->end())
					return (true);
				return (false);
			}
			size_type	size() const
			{
				return (_size);
			}
			/* Maximum number of items in a vector, it can still fail,
			because computer can run out of memory before 2^bits-1 2^(64-1 or 32-1) */
			size_type	max_size() const
			{
				return (std::numeric_limits<difference_type>::max()/2);
			}
			/* Reserve does provock iterator invalidity */
			void	reserve(size_type new_cap)
			{
				if (new_cap > this->max_size())
					throw std::length_error("vector::reserve");
				pointer	ptr = NULL;
				if (new_cap > this->capacity())
				{
					ptr = _allocator.allocate(new_cap);
					for (size_type i = 0; i < this->size(); i++)
					{
						_allocator.construct(ptr + i, *(_vec + i));
						_allocator.destroy(_vec + i);
					}
					_allocator.deallocate(_vec, this->capacity());
					_vec = ptr;
					_capacity_allocator = new_cap;
				}
			}
			size_type	capacity() const
			{
				return (_capacity_allocator);
			}
			/* MODIFIERS */
			void	clear()
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_vec + i);
				_size = 0;
			}
			/*
				Memory capacity is _capacity_allocator * 2 if new_size is greater than old capacity
				Put value at the iterator address
				Reserve does provock iterator invalidity
				To resolve this, can do std::distance or iterator - .begin();
				_allocator.construct(_vec + cpy_size, *(_vec + (cpy_size - 1)));
				_allocator.destroy(_vec + (cpy_size - 1));
			*/
			iterator	insert(iterator pos, const T& value)
			{
				iterator	new_it;
				iterator	it_end;
				size_type	offset = pos - this->begin();
				size_type	cpy_size = _size;

				if (_size + 1 > _capacity_allocator)
				{
					if (_capacity_allocator == 0)
						this->reserve(1);
					else
						this->reserve(_capacity_allocator << 1);
				}
				if (this->size() == 0)
					_allocator.construct(_vec, value);
				else
				{
					new_it = this->begin() - offset;
					it_end = this->end();
					while (it_end != new_it)
					{
						//_allocator.construct(_vec + cpy_size, *(_vec + (cpy_size - 1)));
						//_allocator.destroy(_vec + (cpy_size - 1));
						_vec[cpy_size] = _vec[cpy_size - 1];
						cpy_size--;
						it_end--;
					}
					_allocator.construct(_vec + cpy_size, value);
				}
				_size++;
				return (&_vec[cpy_size]);
			}

			/*
				00
				0111110 (2 - 1) + 5
				0122211110 (7 - 1) + 3
				Inserting element at a position other than end() cause element to relocate
				from pos to end
			*/
			//_vec[cpy + count] = _vec[cpy_size - 1];
			//_allocator.construct(_vec + (cpy + count), *(_vec + cpy));
			//_allocator.destroy(_vec + cpy);
			//est-il possible d'aller plus vite en déplacent d'un coup le nombre total d'élement à déplacer sans boucle, idée à penser samedi par ex
			void	insert(iterator pos, size_type count, const T& value)
			{
				size_type	offset = pos - this->begin();
				
				if (_size + count > _capacity_allocator)
				{
					if (_capacity_allocator == 0)
						this->reserve(_size + count);
					else if (_capacity_allocator + count > (_capacity_allocator << 1))
						this->reserve(_capacity_allocator + count);
					else
						this->reserve(_capacity_allocator << 1);
				}
				if (this->size() == 0)
				{
					for (size_type nb_count = 0; nb_count < count; nb_count++)
						_allocator.construct(_vec + nb_count, value);
				}
				else
				{
					size_type	cpy_size = _size;
					iterator	new_it = (this->begin() - offset) + count;
					iterator	it_end = this->end() + count;

					while (it_end != new_it)
					{
						size_type	cpy = cpy_size - 1;
						//_allocator.construct(_vec + (cpy + count), *(_vec + cpy));
						//_allocator.destroy(_vec + cpy);
						_vec[cpy + count] = _vec[cpy];
						cpy_size--;
						it_end--;
					}
					for (size_type nb_count = 0; nb_count < count; nb_count++)
						_allocator.construct(_vec + (cpy_size + nb_count), value);
				}
				_size += count;
			}
			template<class InputIt>
			void	insert(iterator pos, InputIt first, InputIt last)
			{
				difference_type	distance = std::distance(last, first);
				size_type	offset = pos - this->begin();
				size_type	nb_count = 0;

				if (_size + distance > _capacity_allocator)
				{
					if (_capacity_allocator == 0)
						this->reserve(_size + distance);
					else if (_capacity_allocator + distance > (_capacity_allocator << 1))
						this->reserve(_capacity_allocator + distance);
					else
						this->reserve(_capacity_allocator << 1);
				}
				if (this->size() == 0)
				{
					while (first != last)
						_allocator.construct(_vec + nb_count++, *(first)++);
				}
				else
				{
					size_type	cpy_size = _size;
					iterator	new_it = (this->begin() - offset) + distance;
					iterator	it_end = this->end() + distance;

					while (it_end != new_it)
					{
						size_type	cpy = cpy_size - 1;
						_vec[cpy + distance] = _vec[cpy];
						cpy_size--;
						it_end--;
					}
					while (first != last)
						_allocator.construct(_vec + (cpy_size + nb_count++), *(first)++);
				}
				_size += distance;
			}
			/* à tester dans l'exam05 */
			/* pointer ptr for last element because STL return an iterator with the deleted value */
			//_allocator.destroy(_vec + distance);
			//_allocator.construct(_vec + distance, *(_vec + (distance + 1)));
			iterator	erase(iterator pos)
			{
				size_type	offset = pos - this->begin();
				iterator	it(pos);
				iterator	it_end = this->end() - 1;
				difference_type	distance = std::distance(pos, this->begin());

				_vec[distance] = _vec[distance + 1];
				while (pos != it_end)
				{
					_allocator.destroy(_vec + distance);
					_vec[distance] = _vec[distance + 1];
					pos++;
					distance++;
				}
				_size--;
				if ((this->begin() - offset) == this->end())
					return (it);
				return(this->begin() - offset);
			}
			iterator	erase(iterator first, iterator last)
			{
				size_type	distance = 0;
				iterator	it(last);

				if (last == this->end())
					it = first;
				*first = *last;
				while (first != last)
				{
					_allocator.destroy(&*first);
					first++;
					distance++;
				}
				_size -= distance;
				return (it);
			}
			void	push_back(const T& value)
			{
				if (_capacity_allocator == 0)
					this->reserve(1);
				else if (_size + 1 > this->capacity())
					this->reserve(_capacity_allocator << 1);
				_vec[_size] = value;
				_size++;
			}
			void	pop_back()
			{
				_allocator.destroy(_vec + (_size - 1));
				_size--;
			}
			void	resize(size_type count)
			{
				if (_capacity_allocator < count)
				{
					if (_capacity_allocator == 0)
						this->reserve(count);
					else
						this->reserve(_capacity_allocator << 1);
				}
				while (_size < count)
				{
					_allocator.construct(_vec + _size, 0);
					_size++;
				}
				while (count < _size)
				{
					_allocator.destroy(_vec + _size);
					_size--;
				}
			}
			void	swap(vector& other)
			{
				vector	tmp(*this);

				*this = other;
				other = tmp;
			}
		private:
			pointer			_vec;
			allocator_type	_allocator;
			size_type		_capacity_allocator;
			size_type		_size;
	};

	template<class T, class Alloc>
	bool	operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs != rhs)
			return (true);
		return (false);
	}
	template<class T, class Alloc>
	void	swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
	{
		ft::vector<T>	tmp(rhs);

		rhs = lhs;
		lhs = tmp;
	}
}

#endif
