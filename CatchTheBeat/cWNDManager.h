/*
==========================================================================
cWNDManager.h
==========================================================================
*/

#ifndef _WNDMANAGER_H
#define _WNDMANAGER_H

#include <windows.h>
#include "windowOGL.h"
#include "cInputMgr.h"


class cWNDManager
{
public:
	cWNDManager();
	~cWNDManager();

	bool createWND(int width, int height, int bpp);
	void destroyWND();
	void processWNDEvents();
	void attachOGLWnd(windowOGL* winOGL);
	void attachInputMgr(cInputMgr* inputMgr);

	bool isWNDRunning(); //Is the window running?

	HWND getWNDHandle(); // Return window handle.
	HDC getWNDDC(); // Return Device context

	void swapBuffers() { SwapBuffers(m_hdc); }

	static LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

	float getElapsedSeconds();
	static cWNDManager* getInstance();


private:
	static cWNDManager* pInstance;

	windowOGL* m_winOGL; //A link to the OGL window
	cInputMgr* m_InputMgr; //A link to the Input Manager

	bool m_isRunning; //Is the window still running?

	HGLRC m_hglrc; //Rendering context
	RECT m_windowRect; //Window bounds
	HINSTANCE m_hinstance; //Application instance
	WNDCLASSEX m_windowClass;

	void setupPixelFormat(void);
	windowOGL* getAttachedWND();

	float m_lastTime;

	HWND m_hwnd; //Window handle
	HDC m_hdc; //Device context

};
#endif