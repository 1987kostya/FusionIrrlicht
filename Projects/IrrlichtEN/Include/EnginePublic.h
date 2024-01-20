#pragma once

#include <irrlicht.h>
#ifdef IRRLICHTEN_EXPORTS
#define IRRLICHTEN_API __declspec(dllexport)
#else
#define IRRLICHTEN_API __declspec(dllimport)
#endif
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
struct engineCommon
{
	short			swidth;
	short			sheight;
};
struct engineRData
{
	// Main header - required
	headerObject	rHo;					// Header
	engineCommon common;
	IrrlichtDevice* device;
	
	// Optional headers - depend on the OEFLAGS value, see documentation and examples for more info
//	rCom			rc;				// Common structure for movements & animations
//	rMvt			rm;				// Movements
//	rSpr			rs;				// Sprite (displayable objects)
//	rVal			rv;				// Alterable values

	// Object's runtime data

};

struct engineEData
{
	// Header - required
	extHeader		eHeader;
	engineCommon common;
	// Object's data
	

};
class EmptyFusionNode
{
public:
	ISceneNode* node;
	virtual void SetXPosition(float pos)
	{
		printf("whatever\n");
	}

};
class CameraFusionNode:EmptyFusionNode
{
public:
	ISceneNode* node;
	void SetXPosition(float pos) override
	{
		printf("set x position for camera");
	}

};
class StaticMeshFusionNode:EmptyFusionNode
{
public:

};

//IRRLICHTEN_API extern engineEData* mainEngineEditor;
extern engineRData* mainEngineRuntime;

#define getMainEngine(x) ((engineRData*)x->rHo.hoAdRunHeader->rhFree6)



