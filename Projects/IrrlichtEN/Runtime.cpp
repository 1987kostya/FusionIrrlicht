// ============================================================================
//
// This file contains routines that are handled during the Runtime.
//
// Including creating, display, and handling your object.
// 
// ============================================================================

// Common Include
#pragma once
#include	"common.h"
// DEBUGGER /////////////////////////////////////////////////////////////////

#if !defined(RUN_ONLY)
// Identifiers of items displayed in the debugger
enum
{
// Example
// -------
//	DB_CURRENTSTRING,
//	DB_CURRENTVALUE,
//	DB_CURRENTCHECK,
//	DB_CURRENTCOMBO
};

// Items displayed in the debugger
WORD DebugTree[]=
{
// Example
// -------
//	DB_CURRENTSTRING|DB_EDITABLE,
//	DB_CURRENTVALUE|DB_EDITABLE,
//	DB_CURRENTCHECK,
//	DB_CURRENTCOMBO,

	// End of table (required)
	DB_END
};

#endif // !defined(RUN_ONLY)


// --------------------
// GetRunObjectDataSize
// --------------------
// --------------------
// Returns the size of the runtime datazone of the object
// 
ushort WINAPI DLLExport GetRunObjectDataSize(fprh rhPtr, LPEDATA edPtr)
{
	return(sizeof(RUNDATA));
}


// ---------------
// CreateRunObject
// ---------------
// The routine where the object is actually created
// 
cSurface* retard;
cSurface* proto;
HWND hIrrlichtWindow;
video::SExposedVideoData videodata;
HWND hWnd;



void placeIrrlicht(LPRDATA rdPtr)
{
	video::E_DRIVER_TYPE driverType = EDT_OPENGL;

	char key='a';

	HINSTANCE hInstance = 0;
	
	hWnd = rdPtr->rHo.hoAdRunHeader->rhHEditWin;

	hIrrlichtWindow = CreateWindow("BUTTON", "",
		WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		0, 0, 640, 480, hWnd, NULL, hInstance, NULL);
	video::SExposedVideoData newVData((key == 'b') ? hIrrlichtWindow : 0);
	videodata = newVData;

	irr::SIrrlichtCreationParameters param;
	param.DriverType = driverType;
	param.Doublebuffer = true;
	if (key == 'a')
		param.WindowId = reinterpret_cast<void*>(hIrrlichtWindow);

	irr::IrrlichtDevice* device = irr::createDeviceEx(param);
	rdPtr->device = device;

	// setup a simple 3d scene

	irr::scene::ISceneManager* smgr = device->getSceneManager();
	video::IVideoDriver* driver = device->getVideoDriver();


	//TODO this causes a memory leak :)
	if (0)//driverType == video::EDT_OPENGL)
	{
		HDC HDc = GetDC(hIrrlichtWindow);
		PIXELFORMATDESCRIPTOR pfd = { 0 };
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		int pf = GetPixelFormat(HDc);
		DescribePixelFormat(HDc, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
		pfd.dwFlags |= PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
		pfd.cDepthBits = 16;
		pf = ChoosePixelFormat(HDc, &pfd);
		SetPixelFormat(HDc, pf, &pfd);
		videodata.OpenGLWin32.HDc = HDc;
		videodata.OpenGLWin32.HRc = wglCreateContext(HDc);
		wglShareLists((HGLRC)driver->getExposedVideoData().OpenGLWin32.HRc, (HGLRC)videodata.OpenGLWin32.HRc);
	}
	scene::ICameraSceneNode* cam = smgr->addCameraSceneNode();
	cam->setTarget(core::vector3df(0, 0, 0));
	cam->setPosition(core::vector3df(3, 3, 3));

	
	// show and execute dialog

	//ShowWindow(hWnd, SW_SHOW);
	//UpdateWindow(hWnd);

	// do message queue*/

	
	/*
	Now the only thing missing is the drawing loop using
	IrrlichtDevice::run(). We do this as usual. But instead of this, there
	is another possibility: You can also simply use your own message loop
	using GetMessage, DispatchMessage and whatever. Calling
	Device->run() will cause Irrlicht to dispatch messages internally too.
	You need not call Device->run() if you want to do your own message
	dispatching loop, but Irrlicht will not be able to fetch user input
	then and you have to do it on your own using the window messages,
	DirectInput, or whatever.
	*/

	
	

}
short WINAPI DLLExport CreateRunObject(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr)
{
	// XXX SOMEBODY PLEASE DO SOMETHING ABOUT IT AAAAAAAAAAAAAAAAAARGH
	rdPtr->rHo.hoAdRunHeader->rhFree6 = (long)rdPtr;
	memcpy(&rdPtr->common, &edPtr->common, sizeof(engineCommon));
	placeIrrlicht(rdPtr);


	return 0;
}


// ----------------
// DestroyRunObject
// ----------------
// Destroys the run-time object
// 
short WINAPI DLLExport DestroyRunObject(LPRDATA rdPtr, long fast)
{
	rdPtr->device->closeDevice();
	rdPtr->device->drop();

	//auto vData = rdPtr->device->getVideoDriver()->getExposedVideoData().OpenGLWin32;
	//ReleaseDC(hIrrlichtWindow, (HDC)vData.HDc);
	//wglDeleteContext((HGLRC)vData.HRc);

	DestroyWindow(hIrrlichtWindow);
/*
   When your object is destroyed (either with a Destroy action or at the end of
   the frame) this routine is called. You must free any resources you have allocated!
*/
	// No errors
	return 0;
}


// ----------------
// HandleRunObject
// ----------------
// Called (if you want) each loop, this routine makes the object live
// 
short WINAPI DLLExport HandleRunObject(LPRDATA rdPtr)
{
	
	
	return REFLAG_DISPLAY;
}

// ----------------
// DisplayRunObject
// ----------------
// Draw the object in the application screen.
// 

short WINAPI DLLExport DisplayRunObject(LPRDATA rdPtr)
{
	RECT* rect = &rdPtr->rHo.hoRect;
	rect->left = rdPtr->rHo.hoX;
	rect->top = rdPtr->rHo.hoY;
	rect->right = rdPtr->rHo.hoX + rdPtr->common.swidth;
	rect->bottom = rdPtr->rHo.hoY + rdPtr->common.sheight;
	auto device = rdPtr->device;
	if (!device->run())return 0;
	device->getVideoDriver()->beginScene(true, true, SColor(255, 255, 0, 255), videodata);
	device->getSceneManager()->drawAll();
	device->getVideoDriver()->endScene();
	

	return 0;
}

// -------------------
// GetRunObjectSurface
// -------------------
// Implement this function instead of DisplayRunObject if your extension
// supports ink effects and transitions. Note: you can support ink effects
// in DisplayRunObject too, but this is automatically done if you implement
// GetRunObjectSurface (MMF applies the ink effect to the surface).
//
// Note: do not forget to enable the function in the .def file 
// if you remove the comments below.

cSurface* WINAPI DLLExport GetRunObjectSurface(LPRDATA rdPtr)
{
	//ReleaseDC(hIrrlichtWindow, GetDC(hIrrlichtWindow));

	
	

	//HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); //create brush
	//SelectObject(hDC, brush); //select brush into DC
	//Rectangle(hDC, 0, 0, 640, 480); //draw rectangle over whole screen
	//BitBlt(retard->GetDC(), 0, 0, 640, 480, hDC, 0, 0, SRCCOPY);


	//retard->CaptureDC(hDC, retard->GetDC(), 0, 0, 0, 0, 640, 480, 640, 480, true, false);
	//retard->Fill(255, 0, 255);
	
	return retard;
}


// -------------------------
// GetRunObjectCollisionMask
// -------------------------
// Implement this function if your extension supports fine collision mode (OEPREFS_FINECOLLISIONS),
// Or if it's a background object and you want Obstacle properties for this object.
//
// Should return NULL if the object is not transparent.
//
// Note: do not forget to enable the function in the .def file 
// if you remove the comments below.
//
/*
LPSMASK WINAPI DLLExport GetRunObjectCollisionMask(LPRDATA rdPtr, LPARAM lParam)
{
	// Typical example for active objects
	// ----------------------------------
	// Opaque? collide with box
	if ( (rdPtr->rs.rsEffect & EFFECTFLAG_TRANSPARENT) == 0 )	// Note: only if your object has the OEPREFS_INKEFFECTS option
		return NULL;

	// Transparent? Create mask
	LPSMASK pMask = rdPtr->m_pColMask;
	if ( pMask == NULL )
	{
		if ( rdPtr->m_pSurface != NULL )
		{
			DWORD dwMaskSize = rdPtr->m_pSurface->CreateMask(NULL, lParam);
			if ( dwMaskSize != 0 )
			{
				pMask = (LPSMASK)calloc(dwMaskSize, 1);
				if ( pMask != NULL )
				{
					rdPtr->m_pSurface->CreateMask(pMask, lParam);
					rdPtr->m_pColMask = pMask;
				}
			}
		}
	}

	// Note: for active objects, lParam is always the same.
	// For background objects (OEFLAG_BACKGROUND), lParam maybe be different if the user uses your object
	// as obstacle and as platform. In this case, you should store 2 collision masks
	// in your data: one if lParam is 0 and another one if lParam is different from 0.

	return pMask;
}
*/

// ----------------
// PauseRunObject
// ----------------
// Enters the pause mode
// 
short WINAPI DLLExport PauseRunObject(LPRDATA rdPtr)
{
	// Ok
	return 0;
}


// -----------------
// ContinueRunObject
// -----------------
// Quits the pause mode
//
short WINAPI DLLExport ContinueRunObject(LPRDATA rdPtr)
{
	// Ok
	return 0;
}

// -----------------
// SaveRunObject
// -----------------
// Saves the object to disk
// 

BOOL WINAPI SaveRunObject(LPRDATA rdPtr, HANDLE hf)
{            
	BOOL bOK = FALSE;

#ifndef VITALIZE

	// Save the object's data here

	// OK
	bOK = TRUE;

#endif // VITALIZE

	return bOK;
}

// -----------------
// LoadRunObject
// -----------------
// Loads the object from disk
// 
BOOL WINAPI LoadRunObject(LPRDATA rdPtr, HANDLE hf)
{            
	BOOL bOK=FALSE;

	// Load the object's data here

	// OK
	bOK = TRUE;

	return bOK; 
}




// ============================================================================
//
// START APP / END APP / START FRAME / END FRAME routines
// 
// ============================================================================

// -------------------
// StartApp
// -------------------
// Called when the application starts or restarts.
// Useful for storing global data
// 
void WINAPI DLLExport StartApp(mv _far *mV, CRunApp* pApp)
{
	// Example
	// -------
	// Delete global data (if restarts application)
//	CMyData* pData = (CMyData*)mV->mvGetExtUserData(pApp, hInstLib);
//	if ( pData != NULL )
//	{
//		delete pData;
//		mV->mvSetExtUserData(pApp, hInstLib, NULL);
//	}
}

// -------------------
// EndApp
// -------------------
// Called when the application ends.
// 
void WINAPI DLLExport EndApp(mv _far *mV, CRunApp* pApp)
{
	// Example
	// -------
	// Delete global data
//	CMyData* pData = (CMyData*)mV->mvGetExtUserData(pApp, hInstLib);
//	if ( pData != NULL )
//	{
//		delete pData;
//		mV->mvSetExtUserData(pApp, hInstLib, NULL);
//	}
}

// -------------------
// StartFrame
// -------------------
// Called when the frame starts or restarts.
// 
void WINAPI DLLExport StartFrame(mv _far *mV, DWORD dwReserved, int nFrameIndex)
{
}

// -------------------
// EndFrame
// -------------------
// Called when the frame ends.
// 
void WINAPI DLLExport EndFrame(mv _far *mV, DWORD dwReserved, int nFrameIndex)
{
}

// ============================================================================
//
// TEXT ROUTINES (if OEFLAG_TEXT)
// 
// ============================================================================

// -------------------
// GetRunObjectFont
// -------------------
// Return the font used by the object.
// 
/*

  // Note: do not forget to enable the functions in the .def file 
  // if you remove the comments below.

void WINAPI GetRunObjectFont(LPRDATA rdPtr, LOGFONT* pLf)
{
	// Example
	// -------
	// GetObject(rdPtr->m_hFont, sizeof(LOGFONT), pLf);
}

// -------------------
// SetRunObjectFont
// -------------------
// Change the font used by the object.
// 
void WINAPI SetRunObjectFont(LPRDATA rdPtr, LOGFONT* pLf, RECT* pRc)
{
	// Example
	// -------
//	HFONT hFont = CreateFontIndirect(pLf);
//	if ( hFont != NULL )
//	{
//		if (rdPtr->m_hFont!=0)
//			DeleteObject(rdPtr->m_hFont);
//		rdPtr->m_hFont = hFont;
//		SendMessage(rdPtr->m_hWnd, WM_SETFONT, (WPARAM)rdPtr->m_hFont, FALSE);
//	}

}

// ---------------------
// GetRunObjectTextColor
// ---------------------
// Return the text color of the object.
// 
COLORREF WINAPI GetRunObjectTextColor(LPRDATA rdPtr)
{
	// Example
	// -------
	return 0;	// rdPtr->m_dwColor;
}

// ---------------------
// SetRunObjectTextColor
// ---------------------
// Change the text color of the object.
// 
void WINAPI SetRunObjectTextColor(LPRDATA rdPtr, COLORREF rgb)
{
	// Example
	// -------
	rdPtr->m_dwColor = rgb;
	InvalidateRect(rdPtr->m_hWnd, NULL, TRUE);
}
*/


// ============================================================================
//
// WINDOWPROC (interception of messages sent to hMainWin and hEditWin)
//
// Do not forget to enable the WindowProc function in the .def file if you implement it
// 
// ============================================================================

// Get the pointer to the object's data from its window handle
// Note: the object's window must have been subclassed with a
// callRunTimeFunction(rdPtr, RFUNCTION_SUBCLASSWINDOW, 0, 0);
// See the documentation and the Simple Control example for more info.
//
LPRDATA GetRdPtr(HWND hwnd, LPRH rhPtr)
{
	return (LPRDATA)GetProp(hwnd, (LPCSTR)rhPtr->rh4.rh4AtomRd);
}

// Called from the window proc of hMainWin and hEditWin.
// You can intercept the messages and/or tell the main proc to ignore them.
//
LRESULT CALLBACK DLLExport WindowProc(LPRH rhPtr, HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	LPRDATA rdPtr = NULL;
	printf("%X\n", nMsg);
	switch (nMsg) {

	// Example

	case WM_COMMAND:
		{
		
		
		//SwapBuffers(hDC);
			// Get the handle of the control
			HWND hWndControl = (HWND)lParam;

			// Get a pointer to the RUNDATA structure (see GetRdptr function above for more info)
			rdPtr = GetRdPtr(hWndControl, rhPtr);

			// Check if the rdPtr pointer is valid and points to an object created with this extension
			if ( rdPtr == NULL || rdPtr->rHo.hoIdentifier != IDENTIFIER )
				break;
			

			return REFLAG_MSGRETURNVALUE;
		}
		break;
	}

	return 0;
}


// ============================================================================
//
// DEBUGGER ROUTINES
// 
// ============================================================================

// -----------------
// GetDebugTree
// -----------------
// This routine returns the address of the debugger tree
//
LPWORD WINAPI DLLExport GetDebugTree(LPRDATA rdPtr)
{
#if !defined(RUN_ONLY)
	return DebugTree;
#else
	return NULL;
#endif // !defined(RUN_ONLY)
}

// -----------------
// GetDebugItem
// -----------------
// This routine returns the text of a given item.
//
void WINAPI DLLExport GetDebugItem(LPSTR pBuffer, LPRDATA rdPtr, int id)
{
#if !defined(RUN_ONLY)

	// Example
	// -------
/*
	char temp[DB_BUFFERSIZE];

	switch (id)
	{
	case DB_CURRENTSTRING:
		LoadString(hInstLib, IDS_CURRENTSTRING, temp, DB_BUFFERSIZE);
		wsprintf(pBuffer, temp, rdPtr->text);
		break;
	case DB_CURRENTVALUE:
		LoadString(hInstLib, IDS_CURRENTVALUE, temp, DB_BUFFERSIZE);
		wsprintf(pBuffer, temp, rdPtr->value);
		break;
	case DB_CURRENTCHECK:
		LoadString(hInstLib, IDS_CURRENTCHECK, temp, DB_BUFFERSIZE);
		if (rdPtr->check)
			wsprintf(pBuffer, temp, "TRUE");
		else
			wsprintf(pBuffer, temp, "FALSE");
		break;
	case DB_CURRENTCOMBO:
		LoadString(hInstLib, IDS_CURRENTCOMBO, temp, DB_BUFFERSIZE);
		wsprintf(pBuffer, temp, rdPtr->combo);
		break;
	}
*/

#endif // !defined(RUN_ONLY)
}

// -----------------
// EditDebugItem
// -----------------
// This routine allows to edit editable items.
//
void WINAPI DLLExport EditDebugItem(LPRDATA rdPtr, int id)
{
#if !defined(RUN_ONLY)

	// Example
	// -------
/*
	switch (id)
	{
	case DB_CURRENTSTRING:
		{
			EditDebugInfo dbi;
			char buffer[256];

			dbi.pText=buffer;
			dbi.lText=TEXT_MAX;
			dbi.pTitle=NULL;

			strcpy(buffer, rdPtr->text);
			long ret=callRunTimeFunction(rdPtr, RFUNCTION_EDITTEXT, 0, (LPARAM)&dbi);
			if (ret)
				strcpy(rdPtr->text, dbi.pText);
		}
		break;
	case DB_CURRENTVALUE:
		{
			EditDebugInfo dbi;

			dbi.value=rdPtr->value;
			dbi.pTitle=NULL;

			long ret=callRunTimeFunction(rdPtr, RFUNCTION_EDITINT, 0, (LPARAM)&dbi);
			if (ret)
				rdPtr->value=dbi.value;
		}
		break;
	}
*/
#endif // !defined(RUN_ONLY)
}


