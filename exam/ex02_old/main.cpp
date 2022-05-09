#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"

int	main(void)
{
	Warlock const richard("Richard", "Mistress of magma");
	Dummy	bob;
	Dummy	test(bob);
	Fwoosh*	fwoosh = new Fwoosh();
	BrickWall	model1;
	Polymorph*	polymorph = new Polymorph();
	Fireball*	fireball = new Fireball();
	TargetGenerator	tarGen;

	tarGen.learnTargetType(&model1);
	richard.introduce();
	std::cout << "name : " << richard.getName() << " title : " << richard.getTitle() << std::endl;
	Warlock*	jack = new Warlock("Jack", "The long");
	ATarget*	wall = tarGen.createTarget("Inconspicuous Red-brick Wall");
	ATarget*	wall2 = tarGen.createTarget("Inconcuous Red-brick Wall");
	jack->learnSpell(polymorph);
	jack->learnSpell(fireball);
	jack->introduce();
	jack->setTitle("test");
	jack->introduce();
	jack->learnSpell(fwoosh);
	jack->learnSpell(fwoosh);
	jack->introduce();
	jack->launchSpell("Fwoosh", test);
	jack->launchSpell("Polymorph", *wall);
	jack->launchSpell("Fireball", *wall);
	jack->launchSpell("Fireball", *wall2);
	jack->forgetSpell("Fwoosh");
	jack->forgetSpell("Polymorph");
	jack->forgetSpell("Fireball");
	jack->launchSpell("Fwoosh", bob);
	delete fwoosh;
	delete jack;
	delete polymorph;
	delete fireball;
	return (0);
}
