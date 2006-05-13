/*
        Psychtoolbox2/Source/Common/PsychConstants.h            
  
        AUTHORS:
        Allen.Ingling@nyu.edu           awi 
  
        PLATFORMS:      Mac OS 9   

        HISTORY:
        7/16/02         awi     Split off from PsychProject.h
  
        PROJECTS
        7/16/02         awi     MacOS9 Screen.  

        DESCRIPTION:
        PsychConstants.h defines constants which abstract out platform-specific types.  Note
        That all such abstract types are prefixed with "psych_" as in "psych_uint32".   

        This file also includes platform-specific macros
        
        
         
 

*/

//begin include once 
#ifndef PSYCH_IS_INCLUDED_PsychConstants
#define PSYCH_IS_INCLUDED_PsychConstants

#if !defined(__cplusplus)
#if PSYCH_LANGUAGE != PSYCH_MATLAB
typedef unsigned char bool;
#endif
#endif


//bring in the standard c and system headers 
#include "PsychIncludes.h"

#if PSYCH_LANGUAGE == PSYCH_OCTAVE

// Definitions for constants:
#define mxUINT8_CLASS 0
#define mxDOUBLE_CLASS 1
#define mxLOGICAL_CLASS 2

#endif

#if PSYCH_LANGUAGE == PSYCH_MATLAB | PSYCH_LANGUAGE == PSYCH_OCTAVE
	#undef printf
	#define printf mexPrintf
#endif

//platform dependent macro defines 
#if PSYCH_SYSTEM == PSYCH_WINDOWS

#elif PSYCH_SYSTEM == PSYCH_OS9
        #define FALSE   0
        #define TRUE    1
#elif PSYCH_SYSTEM == PSYCH_OSX
        #define FALSE   0
        #define TRUE    1
#elif PSYCH_SYSTEM == PSYCH_LINUX
        #define FALSE   0
        #define TRUE    1
#endif 

#ifndef false
#define false FALSE
#endif

#ifndef true
#define true TRUE
#endif

#ifndef GL_TABLE_TOO_LARGE
#define GL_TABLE_TOO_LARGE   0x8031  
#endif
#ifndef GL_TEXTURE_RECTANGLE_EXT
#define GL_TEXTURE_RECTANGLE_EXT 0x84F5
#endif
#ifndef GL_TEXTURE_RECTANGLE_NV
#define GL_TEXTURE_RECTANGLE_NV  0x84F5
#endif
#ifndef GL_UNSIGNED_INT_8_8_8_8
#define GL_UNSIGNED_INT_8_8_8_8  0x8035
#endif
// Define GL_BGRA as GL_BGRA_EXT aka 0x80E1 if it isn''t defined already
#ifndef GL_BGRA
#define GL_BGRA              0x80E1
#endif
#ifndef GL_UNSIGNED_INT_8_8_8_8_REV
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#endif
#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif

#ifndef GL_TEXTURE_DEPTH
#define GL_TEXTURE_DEPTH 0x8071
#endif

//abstract up simple data types. 
#if PSYCH_SYSTEM == PSYCH_LINUX
        typedef bool                            boolean;
        typedef unsigned long long              psych_uint64;
        typedef unsigned int                    psych_uint32;
        typedef unsigned char                   psych_uint8;
        typedef unsigned short                  psych_uint16;
        typedef GLubyte                         ubyte;          
        typedef boolean                         mxLogical;
        typedef boolean                         Boolean;
        typedef char                            Str255[255];
        #if PSYCH_LANGUAGE == PSYCH_MATLAB
        // Matlab 5 doesn't know about mxLOGICAL_CLASS :(
        #ifndef mxLOGICAL_CLASS
        #define mxLOGICAL_CLASS mxUINT8_CLASS
        #endif
        #define mxGetLogicals(p) ((PsychNativeBooleanType*)mxGetData((p)))
        mxArray* mxCreateNativeBooleanMatrix3D(int m, int n, int p);

        #define mxCreateLogicalMatrix(m,n) mxCreateNativeBooleanMatrix3D((m), (n), 1)

        #endif

        // We don't have Quicktime for Linux, so we provide a little hack to
        // make the compiler happy:
        typedef void*                           CVOpenGLTextureRef;
        typedef int CGDisplayCount;
        // CGDirectDisplayID is typedef'd to a X11 display connection handle:
        typedef Display* CGDirectDisplayID;
        typedef int CGDisplayErr;
        typedef unsigned int CFDictionaryRef;
#endif

#if PSYCH_SYSTEM == PSYCH_WINDOWS
// typedef BOOL                            boolean;  //Windows already defines this.  
        typedef LONG                            psych_uint64;
        typedef DWORD                           psych_uint32;
        typedef BYTE                            psych_uint8;
        typedef WORD                            psych_uint16;
        typedef GLubyte                         psych_uint8;
        typedef GLubyte                         ubyte;          
        typedef boolean                         mxLogical;
        typedef boolean                         Boolean;
//        typedef char                            Str255[255];
        // The Visual C 6 compiler doesn't know about the __func__ keyword :(
        #define __func__ "UNKNOWN"
        // Matlab 5 doesn't know about mxLOGICAL_CLASS :(
        #define mxLOGICAL_CLASS mxUINT8_CLASS
        #define mxGetLogicals(p) ((PsychNativeBooleanType*)mxGetData((p)))
        mxArray* mxCreateNativeBooleanMatrix3D(int m, int n, int p);

        #if PSYCH_LANGUAGE == PSYCH_MATLAB
        #define mxCreateLogicalMatrix(m,n) mxCreateNativeBooleanMatrix3D((m), (n), 1)
        #endif

        // Hack to make compiler happy until QT7 Windows supports this:
        typedef void*                           CVOpenGLTextureRef;
        typedef int CGDisplayCount;
        typedef HDC CGDirectDisplayID;
        typedef int CGDisplayErr;
        //typedef unsigned int CFDictionaryRef;

#elif PSYCH_SYSTEM == PSYCH_OS9
	typedef Boolean				boolean;
	typedef unsigned long 			psych_uint32;
	typedef Byte				psych_uint8;
	typedef unsigned short 			psych_uint16;
        typedef GLubyte				psych_uint8;
        typedef GLubyte				ubyte;		

#elif PSYCH_SYSTEM == PSYCH_OSX
        typedef Boolean				boolean;
        typedef GLubyte				psych_uint8;
        typedef GLubyte				ubyte;
        typedef UInt32				psych_uint32;
        typedef unsigned long long		psych_uint64;		
#endif
 

#if PSYCH_LANGUAGE == PSYCH_MATLAB | PSYCH_LANGUAGE == PSYCH_OCTAVE
	typedef const mxArray CONSTmxArray;
        #define PsychGenericScriptType mxArray
        typedef mxLogical PsychNativeBooleanType; 
#endif

//macros
#if PSYCH_SYSTEM == PSYCH_WINDOWS
        #define EXP  //nothing
// This didn't work with Matlab5:	#define EXP __declspec(dllexport)
#else
	#define EXP  //nothing
#endif
	
#ifndef APIENTRY
#define APIENTRY
#endif

//end include once
#endif

