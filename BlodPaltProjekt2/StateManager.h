#ifndef INCLUDED_STATEMANAGER
#define INCLUDED_STATEMANAGER

#include "State.h"
#include <stack>

class Super;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void update(Super &r_super);
	void draw(Super &r_super) const;

	void pushState(State* p_state);
	void popState();
	void clear();

private:
	void internalClear();
	std::stack<State*> m_stateStack;


};

#endif