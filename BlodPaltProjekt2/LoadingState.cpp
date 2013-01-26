#include "LoadingState.h"
#include "Super.h"
#include "EntityManager.h"
#include "ResourceHandler.h"

LoadingState::LoadingState(std::string filePath, EntityManager* manager) :
	mEntityManager( manager ),
	mLevelImage( ResourceHandler::getInstance()->loadImage(filePath) )
	{}

LoadingState::~LoadingState() {}

void LoadingState::update(Super &r_super){
		
	r_super.getStateManager().popState();
}

void LoadingState::draw(Super &r_super){}
