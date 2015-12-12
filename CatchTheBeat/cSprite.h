/*
=================
cSprite.h
- Header file for class definition - SPECIFICATION
- Header file for the Sprite class
=================
*/
#ifndef _CSPRITE_H
#define _CSPRITE_H
#include "cInputMgr.h"
#include "GameConstants.h"

class cSprite
{
protected:
	// position, rotation, scalling
	glm::vec2 spritePos2D;
	glm::vec2 spriteTranslation;
	glm::vec2 spriteCentre;
	glm::vec2 spriteScaling;
	float spriteScalingRotation;
	float spriteRotation;
	glm::mat4x4 spriteTransformMatrix;
	RECT boundingRect;
	float m_Radius;
	bool mActive;

	//texturing
	glm::vec2 spriteVertexData[4];
	glm::vec2 spriteTexCoordData[4];

	// Texture width & Height
	int textureWidth;
	int textureHeight;
	GLuint GLTextureID;
	cInputMgr* m_InputMgr;

	float lengthSQRD(glm::vec2 theLength);

public:
	cSprite();			// Default constructor
	~cSprite();			// Destructor
	virtual void render();		// Default render function
	void setSpriteTexCoordData();
	glm::vec2 getSpritePos();  // Return the sprites current position
	void setSpritePos(glm::vec2 sPosition); // set the position of the sprite
	GLuint getTexture();  // Return the sprites current image
	void setTexture(GLuint GLtexID);  // set the image of the sprite
	void setTextureDimensions(int texWidth, int textHeight);
	void setSpriteTranslation(glm::vec2 translation); // Set the amount of movement on the x & y axis
	glm::vec2 getSpriteTranslation();  // return the amount of movement on the x & y axis
	void setSpriteCentre(); // Set the sprites centre point
	glm::vec2 getSpriteCentre();  // return the sprites centre point
	void setSpriteRotation(float angle);      // set the rotation for the sprite
	float getSpriteRotation();      // return the rotation for the sprite
	void setActive(bool sActive);			// Set the sprite to active.
	bool isActive();						// Determine if the sprite is active.
	void setMdlRadius();
	float getMdlRadius();
	void attachInputMgr(cInputMgr* inputMgr);  // Attach the Input Manager
	virtual void update(float deltaTime) = 0;
	void setBoundingRect(RECT* pRect);		// Determine the bounding rectangle for the sprite
	RECT getBoundingRect();		// Determine the bounding rectangle for the sprite
	bool collidedWith(RECT thisSprite, RECT otherSpritePos);	// Check for collisions
	bool SphereSphereCollision(glm::vec2 spritePosition, float spriteRadius);
};
#endif