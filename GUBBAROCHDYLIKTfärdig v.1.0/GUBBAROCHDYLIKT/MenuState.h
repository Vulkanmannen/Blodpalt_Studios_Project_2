#ifndef INCLUDED_MENUSTATE
#define INCLUDED_MENUSTATE

#include "State.h"

class Super;

class MenuState : public State
{
public:
	MenuState(){ }
	~MenuState();

	virtual void update(Super &r_super) = 0;
	virtual void draw(Super &r_super)  = 0;
protected:
	bool mPressed;
};

#endif