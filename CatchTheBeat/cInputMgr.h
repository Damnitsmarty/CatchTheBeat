/*
== == == == == == == == =
cInputMgr.h
- Header file for class definition - SPECIFICATION
- Header file for the InputMgr class
== == == == == == == == =
*/
#ifndef _CINPUTMGR_H
#define _CINPUTMGR_H
#include "GameConstants.h"

class cInputMgr
{
private:

	bool keysDownBuffer[256];     // true if specified key is down
	bool keysPressedBuffer[256];  // true if specified key was pressed
	glm::ivec2  mousePos;		  // mouse screen coordinates
	bool leftMouseBtn;            // true if left mouse button down
	bool middleMouseBtn;          // true if middle mouse button down
	bool rightMouseBtn;           // true if right mouse button down

	static cInputMgr* pInstance;

public:
	static cInputMgr* getInstance();

	// Values for clearing keysDown, KeysPressed and Mouse buffer
	const BYTE KEYS_DOWN_BUFFER = 1;
	const BYTE KEYS_PRESSED_BUFFER = 2;
	const BYTE MOUSE_BUFFER = 4;
	const BYTE KEYS_MOUSE_TEXT = KEYS_DOWN_BUFFER + KEYS_PRESSED_BUFFER + MOUSE_BUFFER;

	cInputMgr();								// Constructor
	void keyDown(WPARAM);						// Save key down state
	void keyUp(WPARAM);							// Save key up state
	bool isKeyDown(int vkey);					// Returns true if the specified VIRTUAL KEY is down, otherwise false.
	bool wasKeyPressed(int vkey);				// Return true if the specified VIRTUAL KEY has been pressed
	bool anyKeyPressed();						// Return true if any key was pressed
	void clearKeyPress(int vkey);				// Clear the specified key press
	void clearBuffers(BYTE bufferToClear);		// Clear buffers, single or combined
	void mouseXY(LPARAM);						// Reads mouse screen position into mouseX, mouseY
	void setLeftMouseBtn(bool b);				// Save state of mouse button
	void setMiddleMouseBtn(bool b);				// Save state of mouse button
	void setRightMouseBtn(bool b);				// Save state of mouse button
	int  getMouseXPos();						// Return mouse X position
	int  getMouseYPos();						// Return mouse Y position
	bool getLeftMouseBtn();						// Return state of left mouse button.
	bool getMiddleMouseBtn();					// Return state of middle mouse button.
	bool getRightMouseBtn();					// Return state of right mouse button.

};

#endif