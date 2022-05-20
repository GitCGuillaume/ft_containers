#include "pair.hpp"

void    pair_default()
{
    std::cout << "Default pair" << std::endl;
    std::pair<double, double>   pair;
    std::cout << "first : " << pair.first << std::endl;
    std::cout << "second : " << pair.second << std::endl;
}

void    pair_equal()
{
    std::cout << "pair equal" << std::endl;
    std::pair<double, double>   pair(0.005000, 0.005000);
    std::pair<double, double>   pair2(0.005000, 0.005000);
    std::pair<double, double>   pair3(0.005000, 0.000001);
    std::cout <<" pair is equal == " << (pair == pair) << std::endl;
    std::cout <<" pair is equal == " << (pair == pair2) << std::endl;
    std::cout <<" pair is equal == " << (pair == pair3) << std::endl;
}

void    pair_not_equal()
{
    std::cout << "pair not equal" << std::endl;
    std::pair<double, double>   pair(0.005000, 0.005000);
    std::pair<double, double>   pair2(0.005000, 0.005000);
    std::pair<double, double>   pair3(0.005000, 0.000001);
    std::cout <<" pair is equal != " << (pair != pair) << std::endl;
    std::cout <<" pair is equal != " << (pair != pair2) << std::endl;
    std::cout <<" pair is equal != " << (pair != pair3) << std::endl;
}

void    pair_left()
{
    std::cout << "pair left" << std::endl;
    std::pair<double, double>   pair(0.006000, 0.005000);
    std::pair<double, double>   pair2(0.005000, 0.006000);
    std::pair<double, double>   pair3(0.005000, 0.000001);
    std::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is < " << (pair < pair) << std::endl;
    std::cout <<" pair is < " << (pair < pair2) << std::endl;
    std::cout <<" pair is < " << (pair < pair3) << std::endl;
    std::cout <<" pair is < " << (pair3 < pair4) << std::endl;
    std::cout <<" pair is < " << (pair4 < pair3) << std::endl;
    std::cout <<" pair is < " << (pair3 < pair4) << std::endl;
    std::cout <<" pair is < " << (pair4 < pair) << std::endl;
    std::cout <<" pair is < " << (pair < pair4) << std::endl;
    std::cout <<" pair is < " << (pair < pair3) << std::endl;
    std::cout <<" pair is < " << (pair4 < pair2) << std::endl;
    std::cout <<" pair is < " << (pair3 < pair2) << std::endl;
}

void    pair_left_equal()
{
    std::cout << "pair left EQUAL" << std::endl;
    std::pair<double, double>   pair(0.006000, 0.005000);
    std::pair<double, double>   pair2(0.005000, 0.006000);
    std::pair<double, double>   pair3(0.005000, 0.000001);
    std::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is <= " << (pair <= pair) << std::endl;
    std::cout <<" pair is <= " << (pair <= pair2) << std::endl;
    std::cout <<" pair is <= " << (pair <= pair3) << std::endl;
    std::cout <<" pair is <= " << (pair3 <= pair4) << std::endl;
    std::cout <<" pair is <= " << (pair4 <= pair3) << std::endl;
    std::cout <<" pair is <= " << (pair4 <= pair) << std::endl;
    std::cout <<" pair is <= " << (pair <= pair4) << std::endl;
}

void    pair_right()
{
    std::cout << "pair right" << std::endl;
    std::pair<double, double>   pair(0.006000, 0.005000);
    std::pair<double, double>   pair2(0.005000, 0.006000);
    std::pair<double, double>   pair3(0.005000, 0.000001);
    std::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is > " << (pair > pair) << std::endl;
    std::cout <<" pair is > " << (pair > pair2) << std::endl;
    std::cout <<" pair is > " << (pair > pair3) << std::endl;
    std::cout <<" pair is > " << (pair3 > pair4) << std::endl;
    std::cout <<" pair is > " << (pair4 > pair3) << std::endl;
    std::cout <<" pair is > " << (pair3 > pair4) << std::endl;
    std::cout <<" pair is > " << (pair4 > pair) << std::endl;
    std::cout <<" pair is > " << (pair > pair4) << std::endl;
    std::cout <<" pair is > " << (pair > pair3) << std::endl;
    std::cout <<" pair is > " << (pair4 > pair2) << std::endl;
    std::cout <<" pair is > " << (pair3 > pair2) << std::endl;
}

void    pair_right_equal()
{
    std::cout << "pair right EQUAL" << std::endl;
    std::pair<double, double>   pair(0.006000, 0.005000);
    std::pair<double, double>   pair2(0.005000, 0.006000);
    std::pair<double, double>   pair3(0.005000, 0.000001);
    std::pair<double, double>   pair4(0.000001, 0.005000);
    std::cout <<" pair is >= " << (pair >= pair) << std::endl;
    std::cout <<" pair is >= " << (pair >= pair2) << std::endl;
    std::cout <<" pair is >= " << (pair >= pair3) << std::endl;
    std::cout <<" pair is >= " << (pair3 >= pair4) << std::endl;
    std::cout <<" pair is >= " << (pair4 >= pair3) << std::endl;
    std::cout <<" pair is >= " << (pair4 >= pair) << std::endl;
    std::cout <<" pair is >= " << (pair >= pair4) << std::endl;
}