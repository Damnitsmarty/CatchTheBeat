#ifndef _WINDOWOGL_H
#define _WINDOWOGL_H

#include <windows.h>
#include "GL/glut.h"

class windowOGL 
{
public:
    windowOGL();

	bool initOGL(int width, int height);
	void renderOGL(float rotAngle);
    void shutdown();

    void onResize(int width, int height);

};

#endif
