#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall"){}
BrickWall::~BrickWall(){}
BrickWall*	BrickWall::clone() const
{
	BrickWall*	brickwall = new BrickWall();
	return (brickwall);
}
