/*
 * ofAppEmscriptenWindow.h
 *
 *  Created on: May 8, 2014
 *      Author: arturo
 */

#ifndef OFAPPEMSCRIPTENWINDOW_H_
#define OFAPPEMSCRIPTENWINDOW_H_

#include "ofAppBaseWindow.h"
#include "EGL/egl.h"
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>

class ofxAppEmscriptenWindow: public ofAppBaseGLESWindow {
public:
	ofxAppEmscriptenWindow();
	~ofxAppEmscriptenWindow();

	void setupOpenGL(int w, int h, int screenMode);
	void initializeWindow();
	void runAppViaInfiniteLoop(ofBaseApp * appPtr);

	void hideCursor();
	void showCursor();

	void	setWindowPosition(int x, int y);
	void	setWindowShape(int w, int h);

	ofPoint	getWindowPosition();
	ofPoint	getWindowSize();
	ofPoint	getScreenSize();

	void			setOrientation(ofOrientation orientation);
	ofOrientation	getOrientation();
	bool	doesHWOrientation();

	//this is used by ofGetWidth and now determines the window width based on orientation
	int		getWidth();
	int		getHeight();

	void	setWindowTitle(string title);

	int		getWindowMode();

	void	setFullscreen(bool fullscreen);
	void	toggleFullscreen();

	void	enableSetupScreen();
	void	disableSetupScreen();

	void	setVerticalSync(bool enabled);

	EGLDisplay getEGLDisplay();
	EGLContext getEGLContext();
	EGLSurface getEGLSurface();

private:
	static void display_cb();
	static int keydown_cb(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData);
	static int keyup_cb(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData);
	static int mousedown_cb(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
	static int mouseup_cb(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
	static int mousemoved_cb(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
	void update();
	void draw();
	EGLDisplay display;
	EGLContext context;
	EGLSurface surface;
    static ofxAppEmscriptenWindow * instance;
    bool bEnableSetupScreen;
};

#endif /* OFAPPEMSCRIPTENWINDOW_H_ */
