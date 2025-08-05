#include<stdio.h>
#include<X11/Xlib.h>
#include<stdlib.h>
#include<X11/cursorfont.h>

static Display *dis;
static int scr;
static Window root;

#define POSY 500
#define POSX 500
#define WIDTH 500
#define HEIGHT 500
#define BORDER 15

static Window create_win(int x,int y,int w,int h,int b){
	Window win;
	XSetWindowAttributes xwa;

	xwa.background_pixel = WhitePixel(dis,scr);
	xwa.border_pixel = BlackPixel(dis,scr);
	xwa.event_mask = ButtonPress;
	
	win = XCreateWindow(dis,root,x,y,w,h,b,DefaultDepth(dis,scr),InputOutput,DefaultVisual(dis,scr),
						CWBackPixel | CWBorderPixel | CWEventMask,&xwa);
	return win;
}

static void run(){
	XEvent ev;

	while(XNextEvent(dis,&ev) == 0){
		switch (ev.type){
		case ButtonPress:
			return;
		case KeyPress:
			return;
		}
	}
}

int main(){
	Window win;

	if((dis = XOpenDisplay(NULL)) == NULL){
		perror("XOpenDisplay");
	}
	scr = DefaultScreen(dis);
	root = RootWindow(dis,scr);

	win = create_win(POSX,POSY,WIDTH,HEIGHT,BORDER);
	XMapWindow(dis,win);
	
	run();
	
	XUnmapWindow(dis,win);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);
	return 0;
}
