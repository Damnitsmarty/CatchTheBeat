/*
=================
cSprite.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cSprite.h"
/*
=================
- Data constructor initializes the cSprite to the data passed to 
- the constructor from the paramater sPosition.
- Is always called, thus ensures all sprite objects are in a consistent state.
=================
*/
cSprite::cSprite() 			// Default constructor
{

	cSprite::spritePos2D.x = 0.0f;
	cSprite::spritePos2D.y = 0.0f;
	cSprite::setSpriteTexCoordData();
	cSprite::spriteTranslation = glm::vec2(0.0f, 0.0f);
	cSprite::spriteScaling = glm::vec2(1.0f, 1.0f);
	cSprite::spriteRotation = 0.0f;
	cSprite::spriteCentre = glm::vec2(0.0f, 0.0f);
	cSprite::setBoundingRect(&boundingRect);
}

/*
=================
- Destructor 
=================
*/
cSprite::~cSprite()			// Destructor
{
}
/*
=================
- Return the sprites current position.
=================
*/

glm::vec2 cSprite::getSpritePos()  // Return the sprites current position
{
	return cSprite::spritePos2D;
}

/*
=================
- set the position of the sprite.
=================
*/

void cSprite::setSpritePos(glm::vec2 sPosition)  // set the position of the sprite
{
	cSprite::spritePos2D = sPosition;
}

/*
=================
- Return the sprites current image.
=================
*/

GLuint cSprite::getTexture()  // Return the sprites current image
{
	return GLTextureID;
}

/*
=================
- set the image of the sprite.
=================
*/

void cSprite::setTexture(GLuint GLtexID)  // set the image of the sprite
{
	GLTextureID = GLtexID;
}

/*
=================================================================================
  set the amount of movement on the x & y axis
=================================================================================
*/
void cSprite::setSpriteTranslation(glm::vec2 translation)
{
	spriteTranslation = translation;
}

/*
=================================================================================
  get the amount of movement on the x & y axis
=================================================================================
*/
glm::vec2 cSprite::getSpriteTranslation()
{
	return spriteTranslation;
}
/*
=================================================================================
  Set the sprites centre point
=================================================================================
*/
void cSprite::setSpriteCentre()
{
	spriteCentre.x = textureWidth / 2;
	spriteCentre.y = textureHeight / 2;
}

/*
=================================================================================
  return the sprites centre point
=================================================================================
*/
glm::vec2 cSprite::getSpriteCentre()
{
	return spriteCentre;
}
/*
=================
- set the rotation for the sprite.
=================
*/

void cSprite::setSpriteRotation(float angle)      // set the rotation for the sprite
{
	cSprite::spriteRotation = angle;
}
/*
=================
- return the rotation for the sprite.
=================
*/

float cSprite::getSpriteRotation()      // return the rotation for the sprite
{
	return cSprite::spriteRotation;
}
/*
=================
- Set the sprite to active.
=================
*/
void cSprite::setActive(bool sActive) 			// Set the sprite to active.
{
	mActive = sActive;
}
/*
=================
- Determine if the sprite is active.
=================
*/
bool cSprite::isActive() 						// Determine if the sprite is active.
{
	return mActive;
}


/*
=================================================================================
Default render function
=================================================================================
*/
void cSprite::render()
{
	glPushMatrix();

	glTranslatef(spritePos2D.x, spritePos2D.y, 0.0f);
	glRotatef(spriteRotation, 0.0f, 0.0f,1.0f);
	glScalef(spriteScaling.x, spriteScaling.y, 1.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, GLTextureID); // Binding of GLtexture name 

	glBegin(GL_QUADS);
		glColor3f(255.0f, 255.0f, 255.0f);
		glTexCoord2f(spriteTexCoordData[0].x, spriteTexCoordData[0].y);
		glVertex2f(0, 0);
		glTexCoord2f(spriteTexCoordData[1].x, spriteTexCoordData[1].y);
		glVertex2f( textureWidth, 0);
		glTexCoord2f(spriteTexCoordData[2].x, spriteTexCoordData[2].y);
		glVertex2f(textureWidth, textureHeight);
		glTexCoord2f(spriteTexCoordData[3].x, spriteTexCoordData[3].y);
		glVertex2f(0, textureHeight);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}
void cSprite::setSpriteTexCoordData()
{
	spriteTexCoordData[0] = glm::vec2(0.0f, 0.0f);
	spriteTexCoordData[1] = glm::vec2(1.0f, 0.0f);
	spriteTexCoordData[2] = glm::vec2(1.0f, 1.0f);
	spriteTexCoordData[3] = glm::vec2(0.0f, 1.0f);
}

void cSprite::setTextureDimensions(int texWidth, int textHeight)
{
	textureWidth = texWidth;
	textureHeight = textHeight;
}
void cSprite::setMdlRadius()
{
	m_Radius = textureWidth / 2;
}

float cSprite::getMdlRadius()
{
	return m_Radius;
}
/* 
=================================================================
   Attach the input manager to the sprite
=================================================================
*/
void cSprite::attachInputMgr(cInputMgr* inputMgr)
{
	m_InputMgr = inputMgr;
}
/*
=================
- Determine the bounding rectangle for the sprite.
=================
*/

void cSprite::setBoundingRect(RECT* pRect)
{
	glm::vec2 sPos = getSpritePos();
	SetRect(pRect, (int)sPos.x, (int)sPos.y, (int)(textureWidth + sPos.x), (int)(textureHeight + sPos.y));
}
/*
=================
- Return the bounding rectangle for the sprite.
=================
*/
RECT cSprite::getBoundingRect()		// Return the bounding rectangle for the sprite
{
	return cSprite::boundingRect;
}
/*
=================
- Check for collisions.
=================
*/

bool cSprite::collidedWith(RECT thisSpriteRect, RECT otherSpriteRect)
{
	// declare rectangles for intersection test
	RECT tempRect;

	// perform the intersection test
	if (IntersectRect(&tempRect, &thisSpriteRect, &otherSpriteRect))
		return true;
	else
		return false;
}

bool cSprite::SphereSphereCollision(glm::vec2 spritePosition, float spriteRadius)
{
	const float distSq = lengthSQRD(spritePos2D - spritePosition);

	const float sumRadius = (m_Radius + spriteRadius);

	if (distSq < sumRadius * sumRadius)
	{
		return true; // Collision
	}
	return false; // No Collision
}

float cSprite::lengthSQRD(glm::vec2 theLength)
{
	return (theLength.x * theLength.x) + (theLength.y * theLength.y);
}
