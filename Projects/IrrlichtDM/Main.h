// Object identifier "SAM3"
#pragma once
#include <EnginePublic.h>
#pragma message ("************************ WARNING ****************************")
#pragma message ("***** Do not forget to change the IDENTIFIER in Main.h! *****")
#pragma message ("*************************************************************")

#define IDENTIFIER	MAKEID(I,R,D,M)		// REQUIRED: you MUST replace the letters in the MAKEID macro by others
										// and then remove the #pragma message above. If you do not do this, MMF2
										// could confuse your object with another in the event editor.

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_CONDITION				0
#define	CND_LAST					1

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define ACT_AddToIrrlicht        0
#define ACT_RemoveFromIrrlicht   1
#define ACT_SetParentNode        2
#define ACT_AttachToBoneNode     3
#define ACT_SetXPosition         4
#define ACT_SetYPosition         5
#define ACT_SetZPosition         6
#define ACT_SetPosition          7
#define ACT_SetXRotation         8
#define ACT_SetYRotation         9
#define ACT_SetZRotation         10
#define ACT_SetRotation          11
#define ACT_SetXScale            12
#define ACT_SetYScale            13
#define ACT_SetZScale            14
#define ACT_SetScale             15
#define ACT_SetVisibiliy         16
#define ACT_LAST 17
// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define EXP_GetParentNode 0
#define EXP_GetLocalPosX  1
#define EXP_GetLocalPosY  2
#define EXP_GetLocalPosZ  3
#define EXP_GetLocalRotX  4
#define EXP_GetLocalRotY  5
#define EXP_GetLocalRotZ  6
#define EXP_GetLocalSclX  7
#define EXP_GetLocalSclY  8
#define EXP_GetLocalSclZ  9
#define EXP_GetWorldPosX  10
#define EXP_GetWorldPosY  11
#define EXP_GetWorldPosZ  12
#define EXP_GetWorldRotX  13
#define EXP_GetWorldRotY  14
#define EXP_GetWorldRotZ  15
#define EXP_GetWorldSclX  16
#define EXP_GetWorldSclY  17
#define EXP_GetWorldSclZ  18
#define	EXP_LAST 19


class DummyFusionNode :public BaseFusionNode
{
public:
	void  SetXPosition(float value) { auto pos = node->getPosition(); node->setPosition(vector3df(value, pos.Y, pos.Z)); }
	void  SetYPosition(float value) { auto pos = node->getPosition(); node->setPosition(vector3df(pos.X, value, pos.Z)); }
	void  SetZPosition(float value) { auto pos = node->getPosition(); node->setPosition(vector3df(pos.Y, pos.Y, value)); }
	float GetXPosition() { return node->getPosition().X; }
	float GetYPosition() { return node->getPosition().Y; }
	float GetZPosition() { return node->getPosition().Z; }
	float GetAbsoluteXPosition() { return node->getAbsolutePosition().X; }
	float GetAbsoluteYPosition() { return node->getAbsolutePosition().Y; }
	float GetAbsoluteZPosition() { return node->getAbsolutePosition().Z; }
	void  SetXRotation(float value) { auto pos = node->getRotation(); node->setRotation(vector3df(value, pos.Y, pos.Z)); }
	void  SetYRotation(float value) { auto pos = node->getRotation(); node->setRotation(vector3df(pos.X, value, pos.Z)); }
	void  SetZRotation(float value) { auto pos = node->getRotation(); node->setRotation(vector3df(pos.Y, pos.Y, value)); }
	float GetXRotation() { return node->getRotation().X; }
	float GetYRotation() { return node->getRotation().Y; }
	float GetZRotation() { return node->getRotation().Z; }
	float GetAbsoluteXRotation() { return node->getAbsoluteTransformation().getRotationDegrees().X; }
	float GetAbsoluteYRotation() { return node->getAbsoluteTransformation().getRotationDegrees().Y; }
	float GetAbsoluteZRotation() { return node->getAbsoluteTransformation().getRotationDegrees().Z; }
	void  SetXScale(float value) {auto pos = node->getScale(); node->setScale(vector3df(value, pos.Y, pos.Z));}
	void  SetYScale(float value) {auto pos = node->getScale(); node->setScale(vector3df(pos.X, value, pos.Z));}
	void  SetZScale(float value) {auto pos = node->getScale(); node->setScale(vector3df(pos.Y, pos.Y, value));}
	float GetXScale() { return node->getScale().X; }
	float GetYScale() { return node->getScale().Y; }
	float GetZScale() { return node->getScale().Z; }
	float GetAbsoluteXScale() { return node->getAbsoluteTransformation().getScale().X; }
	float GetAbsoluteYScale() { return node->getAbsoluteTransformation().getScale().Y; }
	float GetAbsoluteZScale() { return node->getAbsoluteTransformation().getScale().Z; }
	BaseFusionNode* GetParentNode() { return parentNode; }
	void SetParentNode(BaseFusionNode* newParent) { parentNodeObject = newParent->owningObject;  parentNode = newParent; node->setParent(parentNode->node); }
};

// ---------------------
// OBJECT DATA STRUCTURE 
// ---------------------
// Used at edit time and saved in the MFA/CCN/EXE files
struct irrDefaultValues
{
	float posX;
	float posY;
	float posZ;
	float rotX;
	float rotY;
	float rotZ;
	float sclX;
	float sclY;
	float sclZ;
};
typedef struct tagEDATA_V1
{
	// Header - required
	extHeader		eHeader;

	// Object's data
	//short			swidth;
	//short			sheight;
	irrDefaultValues defaults;

} EDITDATA;
typedef EDITDATA* LPEDATA;

// Object versions
#define	KCX_CURRENT_VERSION			1

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// Used at runtime. Initialize it in the CreateRunObject function.
// Free any allocated memory or object in the DestroyRunObject function.
//
// Note: if you store C++ objects in this structure and do not store 
// them as pointers, you must call yourself their constructor in the
// CreateRunObject function and their destructor in the DestroyRunObject
// function. As the RUNDATA structure is a simple C structure and not a C++ object.

typedef struct tagRDATA
{
	// Main header - required
	headerObject	rHo;				
	// DON'T CHANGE THE ORDER. FUSION NODE SHOULD BE FIRST FOR ALL NODE-BASED OBJECTS
	DummyFusionNode* fusionNode;
	irrDefaultValues defaults;
	
	// Optional headers - depend on the OEFLAGS value, see documentation and examples for more info
//	rCom			rc;				// Common structure for movements & animations
//	rMvt			rm;				// Movements
//	rSpr			rs;				// Sprite (displayable objects)
//	rVal			rv;				// Alterable values

	// Object's runtime data

} RUNDATA;
typedef	RUNDATA* LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags - see documentation for more info
// -------------
#define	OEFLAGS      			0
#define	OEPREFS      			0


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100


