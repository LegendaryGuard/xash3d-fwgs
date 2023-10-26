#ifndef EGLUTIL_H
#define EGLUTIL_H
#include "platform/platform.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>

extern struct eglstate_s
{
	qboolean valid, imported;
	EGLDisplay dpy;
	EGLSurface surface;
	EGLContext context;
	EGLConfig cfg;
	EGLint numCfg;

	const char *extensions;
	int gl_attribs[REF_GL_ATTRIBUTES_COUNT];
	qboolean gl_attribs_set[REF_GL_ATTRIBUTES_COUNT];
	EGLint gl_api;
	qboolean gles1;
	void *libgles1, *libgles2;
} eglstate;

extern struct eglapi_s
{
	EGLSurface (*GetCurrentSurface)( EGLint readdraw );
	EGLDisplay (*GetCurrentDisplay)( void );
	EGLint (*GetError)( void );
	EGLBoolean (*SwapBuffers)( EGLDisplay dpy, EGLSurface surface );
	EGLBoolean (*SwapInterval)( EGLDisplay dpy, EGLint interval );
	void *(*GetProcAddress)( const char *procname );
	EGLBoolean (*GetConfigAttrib)( EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value );
	EGLDisplay (*GetDisplay)( NativeDisplayType display );
	EGLBoolean (*Initialize)( EGLDisplay dpy, EGLint *major, EGLint *minor );
	EGLBoolean (*Terminate)( EGLDisplay dpy );
	const char *(*QueryString)( EGLDisplay dpy, EGLint name );
	EGLBoolean (*ChooseConfig)( EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config );
	EGLSurface (*CreateWindowSurface)( EGLDisplay dpy, EGLConfig config, NativeWindowType window, const EGLint *attrib_list );
	EGLContext (*CreateContext)( EGLDisplay dpy, EGLConfig config, EGLContext share_list, const EGLint *attrib_list );
	EGLBoolean (*DestroyContext)( EGLDisplay dpy, EGLContext ctx );
	EGLBoolean (*MakeCurrent)( EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx );
	EGLBoolean (*BindAPI)( EGLenum api );
	EGLBoolean (*DestroySurface)( EGLDisplay dpy, EGLSurface surface );

} egl;

void EGL_LoadLibrary( void );
void * EGL_GetProcAddress( const char *name );
void EGL_Terminate( void );
qboolean EGL_ImportContext( void );
qboolean EGL_CreateContext( void );
qboolean EGL_UpdateSurface( void *window );
int EGL_GetAttribute( int attr, int *val );
size_t EGL_GenerateContextConfig( EGLint *attribs, size_t size );
size_t EGL_GenerateConfig( EGLint *attribs, size_t size );
int EGL_SetAttribute( int attr, int val );

#endif // EGLUTIL_H
