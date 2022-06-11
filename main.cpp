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
#include "tests/vector/reverse_iterator.hpp"
#include "tests/vector_custom/reverse_iterator.hpp"
#include "tests/vector/iterator.hpp"
#include "tests/vector_custom/iterator.hpp"
//#include <type_traits>
#include <stdint.h>
#include <ctime>
#include "sys/time.h"
#include <ios>
#include <iomanip>
#include "tests/map/constructor_summary_map.hpp"
#include "tests/map_custom/constructor_summary_map.hpp"
#include "includes/containers/map.hpp"

/*
 *	true == green == std
 *	false == cyan == ft
*/
void	execute_function(void (*ft)(void), bool colour_print)
{
	struct timeval	start, end;
	double		sum_time;
	long int	mem_seconds;
	long int	mem_micro_s;

	if (colour_print == false)
		std::cout << "\033[32m";
	else
		std::cout << "\033[36m";
	gettimeofday(&start, NULL);
	ft();
	gettimeofday(&end, NULL);
	mem_seconds = end.tv_sec - start.tv_sec;
	mem_micro_s = end.tv_usec - start.tv_usec;
	sum_time = mem_seconds + mem_micro_s * 1e-6;
	if (colour_print == false) // std
		std::cout << std::setprecision(17) << std::fixed << sum_time << std::endl;
	else // ft
		std::cout << std::setprecision(17) << std::fixed << sum_time << std::endl;
	std::cout << std::setprecision(0);
}

int	main(void)
{
	execute_function(&test_std_assign1_forward, 0);
	execute_function(&test_ft_assign1_forward, 1);
	execute_function(&test_std_assign_it_forward, 0);
	execute_function(&test_ft_assign_it_forward, 1);
	execute_function(&test_std_assign1_backward, 0);
	execute_function(&test_ft_assign1_backward, 1);
	execute_function(&test_std_assign_it_backward, 0);
	execute_function(&test_ft_assign_it_backward, 1);
	execute_function(&at_ok, 0);
	execute_function(&at_custom_ok, 1);
	execute_function(&at_const_ok, 0);
	execute_function(&at_custom_const_ok, 1);
	execute_function(&at_out_of_range, 0);
	execute_function(&at_custom_out_of_range, 1);
	execute_function(&front, 0);
	execute_function(&front_custom, 1);
	execute_function(&back, 0);
	execute_function(&back_custom, 1);
	
	execute_function(&default_constructor, 0);
	execute_function(&default_custom_constructor, 1);
	execute_function(&allocator_constructor, 0);
	execute_function(&allocator_custom_constructor, 1);
	execute_function(&allocator_count_constructor, 0);
	execute_function(&allocator_custom_count_constructor, 1);
	execute_function(&allocator_iterator, 0);
	execute_function(&allocator_custom_iterator, 1);
	execute_function(&copy_constructor, 0);
	execute_function(&copy_custom_constructor, 1);
	execute_function(&fill_constructor, 0);
	execute_function(&fill_constructor_custom, 1);
	execute_function(&operator_assignation_constructor, 0);
	execute_function(&operator_custom_assignation_constructor, 1);
	execute_function(&test_data, 0);
	execute_function(&test_custom_data, 1);
	execute_function(&test_const_data, 0);
	execute_function(&test_custom_const_data, 1);
	execute_function(&empty, 0);
	execute_function(&empty_custom, 1);
	execute_function(&max_size, 0);
	execute_function(&max_size_custom, 1);
	execute_function(&reserve_error, 0);
	execute_function(&reserve_error_custom, 1);
	execute_function(&reserve_test, 0);
	execute_function(&reserve_test_custom, 1);
	execute_function(&clear, 0);
	execute_function(&clear_custom, 1);
	execute_function(&insert, 0);
	execute_function(&insert_custom, 1);
	execute_function(&insert_100k, 0);
	execute_function(&insert_100k_custom, 1);
	execute_function(&insert_reserve_100k, 0);
	execute_function(&insert_reserve_100k_custom, 1);
	execute_function(&insert_return, 0);
	execute_function(&insert_return_custom, 0);
	execute_function(&count_insert_100, 0);
	execute_function(&count_insert_100_custom, 1);
	execute_function(&iterator_insert, 0);
	execute_function(&iterator_insert_custom, 1);

	execute_function(&erase, 0);
	execute_function(&erase_custom, 1);
	execute_function(&erase_30k, 0);
	execute_function(&erase_30k_custom, 1);
	execute_function(&erase_iterator, 0);
	execute_function(&erase_iterator_custom, 1);
	execute_function(&push_back_vector, 0);
	execute_function(&push_back_vector_custom, 1);
	execute_function(&pop_back_vector, 0);
	execute_function(&pop_back_vector_custom, 1);
	execute_function(&resize, 0);
	execute_function(&resize_custom, 1);
	execute_function(&swap_vector, 0);
	execute_function(&swap_vector_custom, 1);
	execute_function(&swap_vector_non_member, 0);
	execute_function(&swap_vector_non_member_custom, 1);
	execute_function(&equal_vector, 0);
	execute_function(&equal_vector_custom, 1);
	execute_function(&reverse_iterator, 0);
	execute_function(&reverse_iterator_custom, 1);
	execute_function(&reverse_iterator_empty, 0);
	execute_function(&reverse_iterator_empty_custom, 1);
	execute_function(&iterator_test, 0);
	execute_function(&iterator_test_custom, 1);
	execute_function(&iterator_empty, 0);
	execute_function(&iterator_empty_custom, 1);
	//MAP PART

	execute_function(default_constructor_map, 0);
	execute_function(default_constructor_map_custom, 1);
	execute_function(constructor_range_map, 0);
	execute_function(constructor_range_map_custom, 1);
	execute_function(copy_constructor_map, 0);
	execute_function(copy_constructor_map_custom, 1);
	execute_function(operator_assignation_map, 0);
	execute_function(operator_assignation_map_custom, 1);
	execute_function(constructor_range_speed, 0);
	execute_function(constructor_range_speed_custom, 1);
	execute_function(constructor_copy_speed, 0);
	execute_function(constructor_copy_speed, 1);
	execute_function(assignation_speed, 0);
	execute_function(assignation_speed_custom, 1);

	execute_function(pair_default, 0);
	execute_function(pair_default_custom, 1);
	execute_function(pair_equal, 0);
	execute_function(pair_equal_custom, 1);
	execute_function(pair_not_equal, 0);
	execute_function(pair_not_equal_custom, 1);
	execute_function(pair_left, 0);
	execute_function(pair_left_custom, 1);
	execute_function(pair_left_equal, 0);
	execute_function(pair_left_equal_custom, 1);
	execute_function(pair_right, 0);
	execute_function(pair_right_custom, 1);
	execute_function(pair_right_equal, 0);
	execute_function(pair_right_equal_custom, 1);
	execute_function(pair_copy, 0);
	execute_function(pair_copy_custom, 1);
	execute_function(iterator_map_default, 0);
	execute_function(iterator_map_default_custom, 1);
	execute_function(empty_bracket, 0);
	execute_function(empty_bracket_custom, 1);
	execute_function(bracket_map, 0);
	execute_function(bracket_map_custom, 1);
	execute_function(at_map, 0);
	execute_function(at_map_custom, 1);
	
	execute_function(iterator_assignation_map, 0);
	execute_function(iterator_assignation_map_custom, 1);
	execute_function(iterator_forward_map, 0);
	execute_function(iterator_forward_map_custom, 1);
	
	execute_function(iterator_backward_map, 0);
	execute_function(iterator_backward_map_custom, 1);
	execute_function(reverse_iterator_map, 0);
	execute_function(reverse_iterator_empty_map, 0);
	execute_function(reverse_iterator_map, 1);
	execute_function(reverse_iterator_empty_map, 1);
	execute_function(equal_map, 0);
	execute_function(equal_map_custom, 1);
	execute_function(simple_clear, 0);
	execute_function(simple_clear_custom, 1);   
	execute_function(simple_erase, 0);
	execute_function(simple_erase_custom, 1);
	execute_function(range_erase, 0);
	execute_function(range_erase_custom, 1);
	execute_function(erase_key, 0);
	execute_function(erase_key_custom, 1);
	execute_function(insert_value_type, 0);
	execute_function(insert_value_type_custom, 1);
	execute_function(insert_hint, 0);
	execute_function(insert_hint_custom, 1);
	execute_function(insert_range, 0);
	execute_function(insert_range_custom, 1);
	execute_function(lookup_find, 0);
	execute_function(lookup_find_custom, 1);
	execute_function(map_count, 0);
	execute_function(map_count_custom, 1);
	execute_function(map_swap, 0);
	execute_function(map_swap_custom, 1);
	execute_function(map_swap_non_member, 0);
	execute_function(map_swap_non_member_custom, 1);
	execute_function(map_equal_range, 0);
	execute_function(map_equal_range_custom, 1);
	execute_function(map_equal_range_const, 0);
	execute_function(map_equal_range_const_custom, 1);
	execute_function(lower_bound_map, 0);
	execute_function(lower_bound_map_custom, 1);
	execute_function(upper_bound_map, 0);
	execute_function(upper_bound_map_custom, 1);
	execute_function(test_keycomp, 0);
	execute_function(test_keycomp_custom, 1);
	execute_function(test_value_comp, 0);
	execute_function(test_value_comp_custom, 1);
	execute_function(non_member_operator_map, 0);
	execute_function(non_member_operator_map_custom, 1);
	return (0);
}
