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
class BaseFusionNode
{
public:
	headerObject* owningObject;
	headerObject* parentNodeObject;
	ISceneNode* node;
	BaseFusionNode* parentNode;
	virtual void  SetXPosition(float pos) {}
	virtual void  SetYPosition(float pos) {}
	virtual void  SetZPosition(float pos) {}
	virtual float GetXPosition() { return 0; }
	virtual float GetYPosition() { return 0; }
	virtual float GetZPosition() { return 0; }
	virtual float GetAbsoluteXPosition() { return 0; }
	virtual float GetAbsoluteYPosition() { return 0; }
	virtual float GetAbsoluteZPosition() { return 0; }
	virtual void  SetXRotation(float pos) {}
	virtual void  SetYRotation(float pos) {}
	virtual void  SetZRotation(float pos) {}
	virtual float GetXRotation() { return 0; }
	virtual float GetYRotation() { return 0; }
	virtual float GetZRotation() { return 0; }
	virtual float GetAbsoluteXRotation() { return 0; }
	virtual float GetAbsoluteYRotation() { return 0; }
	virtual float GetAbsoluteZRotation() { return 0; }
	virtual void  SetXScale(float pos) {}
	virtual void  SetYScale(float pos) {}
	virtual void  SetZScale(float pos) {}
	virtual float GetXScale() { return 0; }
	virtual float GetYScale() { return 0; }
	virtual float GetZScale() { return 0; }
	virtual float GetAbsoluteXScale() { return 0; }
	virtual float GetAbsoluteYScale() { return 0; }
	virtual float GetAbsoluteZScale() { return 0; }
	virtual BaseFusionNode* GetParentNode() { return NULL; }
	virtual void SetParentNode(BaseFusionNode* newParent) { }

};



#define getMainEngine(x) ((engineRData*)(x->rHo.hoAdRunHeader->rhFree6))
#define getFixedValue(rHo) ((rHo.hoCreationId << 16)| (rHo.hoHFII))

// XXX CALLING THIS BEFORE ALL OBJECTS ARE CREATED WILL RESULT IN A CRASH
static LPHO GetObjectByFixedValue(LPRH hdr,int fixed)
{
	auto objectList = hdr->rhObjectList;
	auto objectCount = hdr->rhNObjects;
	objectsList* ptr = objectList;
	for (int i = 0; i < objectCount; i++)
	{
		if (fixed == getFixedValue((*ptr->oblOffset)))
		{
			return ptr->oblOffset;
		}
		ptr++;
	}
	return 0;
}

