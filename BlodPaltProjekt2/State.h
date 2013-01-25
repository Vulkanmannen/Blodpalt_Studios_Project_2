#ifndef INCLUDED_STATE
#define INCLUDED_STATE

class Super;

class State
{
public:
	State(){ }
	~State();

	virtual void update(Super &r_super) = 0;
	virtual void draw(Super &r_super)  = 0;
};

#endif