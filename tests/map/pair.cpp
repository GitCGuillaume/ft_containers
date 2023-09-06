#include "pair.hpp"

void    pair_default()
{
    std::cout << "Default pair" << std::endl;
    NAMESPACE::pair<double, double>   pair;
    std::cout << "first : " << pair.first << std::endl;
    std::cout << "second : " << pair.second << std::endl;
}

void    pair_equal()
{
    std::cout << "pair equal" << std::endl;
    NAMESPACE::pair<double, double>   pair(0.005000, 0.005000);
    NAMESPACE::pair<double, double>   pair_2(0.005000, 0.005000);
    NAMESPACE::pair<double, double>   pair_3(0.005000, 0.000001);
    std::cout <<" pair is equal == " << (pair == pair) << std::endl;
    std::cout <<" pair is equal == " << (pair == pair_2) << std::endl;
    std::cout <<" pair is equal == " << (pair == pair_3) << std::endl;
}

void    pair_not_equal()
{
    std::cout << "pair not equal" << std::endl;
    NAMESPACE::pair<double, double>   pair(0.005000, 0.005000);
    NAMESPACE::pair<double, double>   pair_2(0.005000, 0.005000);
    NAMESPACE::pair<double, double>   pair_3(0.005000, 0.000001);
    std::cout <<" pair is equal != " << (pair != pair) << std::endl;
    std::cout <<" pair is equal != " << (pair != pair_2) << std::endl;
    std::cout <<" pair is equal != " << (pair != pair_3) << std::endl;
}

void    pair_left()
{
    std::cout << "pair left" << std::endl;
    NAMESPACE::pair<double, double>   pair(0.006000, 0.005000);
    NAMESPACE::pair<double, double>   pair_2(0.005000, 0.006000);
    NAMESPACE::pair<double, double>   pair_3(0.005000, 0.000001);
    NAMESPACE::pair<double, double>   pair_4(0.000001, 0.005000);
    std::cout << " pair is < " << (pair < pair) << std::endl;
    std::cout << " pair is < " << (pair < pair_2) << std::endl;
    std::cout << " pair is < " << (pair < pair_3) << std::endl;
    std::cout << " pair is < " << (pair_3 < pair_4) << std::endl;
    std::cout << " pair is < " << (pair_4 < pair_3) << std::endl;
    std::cout << " pair is < " << (pair_3 < pair_4) << std::endl;
    std::cout << " pair is < " << (pair_4 < pair) << std::endl;
    std::cout << " pair is < " << (pair < pair_4) << std::endl;
    std::cout << " pair is < " << (pair < pair_3) << std::endl;
    std::cout << " pair is < " << (pair_4 < pair_2) << std::endl;
    std::cout << " pair is < " << (pair_3 < pair_2) << std::endl;
}

void    pair_left_equal()
{
    std::cout << "pair left EQUAL" << std::endl;
    NAMESPACE::pair<double, double>   pair(0.006000, 0.005000);
    NAMESPACE::pair<double, double>   pair_2(0.005000, 0.006000);
    NAMESPACE::pair<double, double>   pair_3(0.005000, 0.000001);
    NAMESPACE::pair<double, double>   pair_4(0.000001, 0.005000);
    std::cout <<" pair is <= " << (pair <= pair) << std::endl;
    std::cout <<" pair is <= " << (pair <= pair_2) << std::endl;
    std::cout <<" pair is <= " << (pair <= pair_3) << std::endl;
    std::cout <<" pair is <= " << (pair_3 <= pair_4) << std::endl;
    std::cout <<" pair is <= " << (pair_4 <= pair_3) << std::endl;
    std::cout <<" pair is <= " << (pair_4 <= pair) << std::endl;
    std::cout <<" pair is <= " << (pair <= pair_4) << std::endl;
}

void    pair_right()
{
    std::cout << "pair right" << std::endl;
    NAMESPACE::pair<double, double>   pair(0.006000, 0.005000);
    NAMESPACE::pair<double, double>   pair_2(0.005000, 0.006000);
    NAMESPACE::pair<double, double>   pair_3(0.005000, 0.000001);
    NAMESPACE::pair<double, double>   pair_4(0.000001, 0.005000);
    std::cout <<" pair is > " << (pair > pair) << std::endl;
    std::cout <<" pair is > " << (pair > pair_2) << std::endl;
    std::cout <<" pair is > " << (pair > pair_3) << std::endl;
    std::cout <<" pair is > " << (pair_3 > pair_4) << std::endl;
    std::cout <<" pair is > " << (pair_4 > pair_3) << std::endl;
    std::cout <<" pair is > " << (pair_3 > pair_4) << std::endl;
    std::cout <<" pair is > " << (pair_4 > pair) << std::endl;
    std::cout <<" pair is > " << (pair > pair_4) << std::endl;
    std::cout <<" pair is > " << (pair > pair_3) << std::endl;
    std::cout <<" pair is > " << (pair_4 > pair_2) << std::endl;
    std::cout <<" pair is > " << (pair_3 > pair_2) << std::endl;
}

void    pair_right_equal()
{
    std::cout << "pair right EQUAL" << std::endl;
    NAMESPACE::pair<double, double>   pair(0.006000, 0.005000);
    NAMESPACE::pair<double, double>   pair_2(0.005000, 0.006000);
    NAMESPACE::pair<double, double>   pair_3(0.005000, 0.000001);
    NAMESPACE::pair<double, double>   pair_4(0.000001, 0.005000);
    std::cout << " pair is >= " << (pair >= pair) << std::endl;
    std::cout << " pair is >= " << (pair >= pair_2) << std::endl;
    std::cout << " pair is >= " << (pair >= pair_3) << std::endl;
    std::cout << " pair is >= " << (pair_3 >= pair_4) << std::endl;
    std::cout << " pair is >= " << (pair_4 >= pair_3) << std::endl;
    std::cout << " pair is >= " << (pair_4 >= pair) << std::endl;
    std::cout << " pair is >= " << (pair >= pair_4) << std::endl;
}

void    pair_copy()
{
    std::cout << "Pair copy" << std::endl;
    NAMESPACE::pair<double, double>   pair(1.006000, 2.005000);
    NAMESPACE::pair<double, double>   pair_2 = pair;
    pair_2 = NAMESPACE::make_pair(3, 3);
    std::cout << "first : " << pair_2.first << std::endl;
    std::cout << "second : " << pair_2.second << std::endl;
}