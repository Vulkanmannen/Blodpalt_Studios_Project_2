#include "StateManager.h"
#include "Super.h"


StateManager::StateManager()
{
}

StateManager::~StateManager()
{
	internalClear();
}

void StateManager::update(Super &r_super)
{
	m_stateStack.top()->update(r_super);
}

void StateManager::draw(Super &r_super) const
{
	if(m_stateStack.top())
	{
		m_stateStack.top()->draw(r_super);
	}
}

void StateManager::pushState(State* p_state)
{
	m_stateStack.push(p_state);
}

void StateManager::popState()
{
	delete m_stateStack.top();
	m_stateStack.pop();
}

void StateManager::clear()
{
	internalClear();
}

void StateManager::internalClear()
{
	while(!m_stateStack.empty())
	{
		delete m_stateStack.top();
		m_stateStack.pop();
	}
}