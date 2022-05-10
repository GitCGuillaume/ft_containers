#include "includes/iterators/iterator_traits.hpp"
#include "includes/iterators/RandomAccessIterator.hpp"
#include "includes/containers/vector.hpp"
#include <iostream>
#include "includes/iterators/reverse_iterator.hpp"
#include <vector>
#include "tests/vector_custom/iterator_forward.hpp"
#include "tests/vector_custom/iterator_backward.hpp"
#include "tests/vector/iterator_forward.hpp"
#include "tests/vector/iterator_backward.hpp"
#include "tests/vector/at.hpp"
#include "tests/vector_custom/at.hpp"
#include "includes/library_headers/is_integral.hpp"
#include "includes/library_headers/enable_if.hpp"
#include "tests/vector/front_back.hpp"
#include "tests/vector_custom/front_back.hpp"
#include "tests/vector/constructor.hpp"
#include "tests/vector_custom/constructor.hpp"
#include "tests/vector/data.hpp"
#include "tests/vector_custom/data.hpp"
#include "tests/vector/capacities.hpp"
#include "tests/vector_custom/capacities.hpp"
#include <iostream>
#include "tests/vector/modifiers.hpp"
#include "tests/vector_custom/modifiers.hpp"
#include "tests/vector/erase.hpp"
#include "tests/vector_custom/erase.hpp"
#include "tests/vector/operator.hpp"
#include "tests/vector_custom/operator.hpp"
//#include <type_traits>
#include <stdint.h>

int	main(void)
{
	test_std_assign1_forward();
	test_ft_assign1_forward();
	test_std_assign_it_forward();
	test_ft_assign_it_forward();
	test_std_assign1_backward();
	test_ft_assign1_backward();
	test_std_assign_it_backward();
	test_ft_assign_it_backward();
	at_ok();
	at_const_ok();
	at_out_of_range();
	at_custom_ok();
	at_custom_const_ok();
	at_custom_out_of_range();
	front();
	back();
	front_custom();
	back_custom();
	default_constructor();
	default_custom_constructor();
	allocator_constructor();
	allocator_custom_constructor();
	allocator_count_constructor();
	allocator_custom_count_constructor();
	allocator_iterator();
	allocator_custom_iterator();
	copy_constructor();
	copy_custom_constructor();
	operator_assignation_constructor();
	operator_custom_assignation_constructor();
	test_data();
	test_const_data();
	test_custom_data();
	test_custom_const_data();
	empty();
	empty_custom();
	max_size();
	max_size_custom();
	reserve_error();
	reserve_test();
	reserve_error_custom();
	reserve_test_custom();
	clear();
	clear_custom();
	insert();
	insert_100k();
	insert_reserve_100k();
	insert_return();
	insert_custom();
	insert_100k_custom();
	insert_reserve_100k_custom();
	insert_return_custom();
	//count_insert_100();
	//count_insert_100_custom();
	iterator_insert();
	iterator_insert_custom();
	erase();
	erase_30k();
	erase_custom();
	erase_30k_custom();
	erase_iterator();
	erase_iterator_custom();
	push_back_vector();
	push_back_vector_custom();
	pop_back_vector();
	pop_back_vector_custom();
	resize();
	resize_custom();
	swap_vector();
	swap_vector_custom();
	swap_vector_non_member();
	swap_vector_non_member_custom();
	equal_vector();
	equal_vector_custom();
	return (0);
}
