#ifndef INCLUDED_MOVINGBLOCK
#define INCLUDED_MOVINGBLOCK
#include "Block.h"
#include <SFML\System\Vector2.hpp>
///////////////////////////////////////////////////////
// /No copies
///////////////////////////////////////////////////////
enum MovementMode{
	HORIZONTAL, VERTICAL
};
class MovingBlock : public Block {
public:
	///////////////////////////////////////////////////////
	// /Assign position of the block and if it moves
	// /horizontal or vertical. Defaults to horizontal
	///////////////////////////////////////////////////////
	MovingBlock(sf::Vector2f position, MovementMode  movement = HORIZONTAL){};
	///////////////////////////////////////////////////////
	// /No dynamic members.
	///////////////////////////////////////////////////////
	~MovingBlock(){};
	///////////////////////////////////////////////////////
	// /Updateing a moveing block moves it in it's direction
	///////////////////////////////////////////////////////
	void update(){};
	///////////////////////////////////////////////////////
	// /Draws the block
	///////////////////////////////////////////////////////
	void render(sf::RenderWindow &window){};
	///////////////////////////////////////////////////////
	// /If the moving block collides with another block, it
	// /ends it movement in it's current direction and 
	// /reverses it's movement path.
	// /If it collides with Arvid, Arvid is pushed by the block.
	///////////////////////////////////////////////////////
	void onCollision(Entity* e){};

private:
	bool mMoveDir;

};

#endif