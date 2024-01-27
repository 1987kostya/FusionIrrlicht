// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
// You can manually enter these, or use CICK (recommended)
// See the Extension FAQ in this SDK for more info and where to download it
//
// ============================================================================

// Common Include
#include	"common.h"

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

// Definitions of parameters for each condition
short conditionsInfos[] =
{
	IDMN_CONDITION, M_CONDITION, CND_CONDITION, EVFLAGS_ALWAYS, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_CND_P1, M_CND_P2, M_CND_P3,
};

// Definitions of parameters for each action
short actionsInfos[] =
{
	ID_ADDTOIRRLICHT, M_AddToIrrlicht,	ACT_AddToIrrlicht,0,1, PARAM_EXPRESSION,0,
	ID_REMOVEFROMIRRLICHT, M_RemoveFromIrrlicht,	ACT_RemoveFromIrrlicht,0,0,

	ID_NODEPROPERTIES_SETPARENTNODE, M_SetParentNode,	ACT_SetParentNode,0,1,PARAM_EXPRESSION,0,
	ID_NODEPROPERTIES_ATTACHTOBONENODE, M_AttachToBoneNode,	ACT_AttachToBoneNode,0,1,PARAM_EXPRESSION,0, //TODO NO CLUE HOW THIS WORKS, FIGURE OUT
	ID_POSITION_SETXPOSITION, M_SetXPosition,	ACT_SetXPosition,0,1,PARAM_EXPRESSION,0,
	ID_POSITION_SETYPOSITION, M_SetYPosition,	ACT_SetYPosition,0,1,PARAM_EXPRESSION,0,
	ID_POSITION_SETZPOSITION, M_SetZPosition,	ACT_SetZPosition,0,1,PARAM_EXPRESSION,0,
	ID_POSITION_SETPOSITION, M_SetPosition,	ACT_SetPosition,0,3,PARAM_EXPRESSION,PARAM_EXPRESSION,PARAM_EXPRESSION,0,0,0,

	ID_ROTATION_SETXROTATION, M_SetXRotation,	ACT_SetXRotation,0,1,PARAM_EXPRESSION,0,
	ID_ROTATION_SETYROTATION, M_SetYRotation,	ACT_SetYRotation,0,1,PARAM_EXPRESSION,0,
	ID_ROTATION_SETZROTATION, M_SetZRotation,	ACT_SetZRotation,0,1,PARAM_EXPRESSION,0,
	ID_ROTATION_SETROTATION, M_SetRotation,	ACT_SetRotation,0,3,PARAM_EXPRESSION,PARAM_EXPRESSION,PARAM_EXPRESSION,0,0,0,

	ID_SCALE_SETXSCALE, M_SetXScale,	ACT_SetXScale,0,1,PARAM_EXPRESSION,0,
	ID_SCALE_SETYSCALE, M_SetYScale,	ACT_SetYScale,0,1,PARAM_EXPRESSION,0,
	ID_SCALE_SETZSCALE, M_SetZScale,	ACT_SetZScale,0,1,PARAM_EXPRESSION,0,
	ID_SCALE_SETSCALE, M_SetScale,	ACT_SetScale,0,3,PARAM_EXPRESSION,PARAM_EXPRESSION,PARAM_EXPRESSION,0,0,0,

	ID_VISIBILITY_SETVISIBILITY, M_SetVisibiliy,	ACT_SetVisibiliy,0,1,PARAM_EXPRESSION,0,

	ID_LOADMATERIAL, M_LoadMaterial, ACT_LoadMaterial,0,1,PARAM_EXPRESSION,0,
};

// Definitions of parameters for each expression
short expressionsInfos[] =
{
	ID__GETPARENTNODE, M_GetParentNode, EXP_GetParentNode, 0,0,
	ID_LOCAL_POSITION_GETX, M_GetLocalPosX, EXP_GetLocalPosX, 0,0,
	ID_LOCAL_POSITION_GETY, M_GetLocalPosY, EXP_GetLocalPosY, 0,0,
	ID_LOCAL_POSITION_GETZ, M_GetLocalPosZ, EXP_GetLocalPosZ, 0,0,
	ID_LOCAL_ROTATION_GETX, M_GetLocalRotX, EXP_GetLocalRotX, 0,0,
	ID_LOCAL_ROTATION_GETY, M_GetLocalRotY, EXP_GetLocalRotY, 0,0,
	ID_LOCAL_ROTATION_GETZ, M_GetLocalRotZ, EXP_GetLocalRotZ, 0,0,
	ID_LOCAL_SCALE_GETX, M_GetLocalSclX, EXP_GetLocalSclX, 0,0,
	ID_LOCAL_SCALE_GETY, M_GetLocalSclY, EXP_GetLocalSclY, 0,0,
	ID_LOCAL_SCALE_GETZ, M_GetLocalSclZ, EXP_GetLocalSclZ, 0,0,
	ID_WORLD_POSITION_GETX, M_GetWorldPosX, EXP_GetWorldPosX, 0,0,
	ID_WORLD_POSITION_GETY, M_GetWorldPosY, EXP_GetWorldPosY, 0,0,
	ID_WORLD_POSITION_GETZ, M_GetWorldPosZ, EXP_GetWorldPosZ, 0,0,
	ID_WORLD_ROTATION_GETX, M_GetWorldRotX, EXP_GetWorldRotX, 0,0,
	ID_WORLD_ROTATION_GETY, M_GetWorldRotY, EXP_GetWorldRotY, 0,0,
	ID_WORLD_ROTATION_GETZ, M_GetWorldRotZ, EXP_GetWorldRotZ, 0,0,
	ID_WORLD_SCALE_GETX, M_GetWorldSclX, EXP_GetWorldSclX, 0,0,
	ID_WORLD_SCALE_GETY, M_GetWorldSclY, EXP_GetWorldSclY, 0,0,
	ID_WORLD_SCALE_GETZ, M_GetWorldSclZ, EXP_GetWorldSclZ, 0,0,
	ID_GETLOADEDMAT, M_GetLoadedMat, EXP_GetLoadedMat, 0,0,


//IDMN_EXPRESSION, M_EXPRESSION, EXP_EXPRESSION, 0, 3, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, 0, 0, 0,

//Note in the following.  If you are returning a string, you set the EXPFLAG_STRING.	
//IDMN_EXPRESSION2, M_EXPRESSION2, EXP_EXPRESSION2, EXPFLAG_STRING, 1, EXPPARAM_STRING, 0,

//Note in the following.  If you are returning a float, you set the EXPFLAG_DOUBLE
//IDMN_EXPRESSION3, M_EXPRESSION3, EXP_EXPRESSION3, EXPFLAG_DOUBLE, 1, EXPPARAM_LONG, 0,
};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

// -----------------
// Sample Condition
// -----------------
// Returns TRUE when the two values are equal!
// 

long WINAPI DLLExport Condition(LPRDATA rdPtr, long param1, long param2)
{

	//  **** Still use this method for 1 or 2 parameters ****	
	//	if (param1==param2)	
	//		return TRUE;

	long p1 = CNC_GetParameter(rdPtr);
	long p2 = CNC_GetParameter(rdPtr);
	long p3 = CNC_GetParameter(rdPtr);

	if ((p1 + p2) == p3)
		return TRUE;

	return FALSE;
}


// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

// -----------------
// Sample Action
// -----------------
// Does nothing!
// 
	//

short WINAPI DLLExport A_SetXPosition(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetXPosition(fp1);
	return 0;
}
short WINAPI DLLExport A_SetYPosition(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetYPosition(fp1);
	return 0;
}
short WINAPI DLLExport A_SetZPosition(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetZPosition(fp1);
	return 0;
}

short WINAPI DLLExport A_SetXRotation(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetXRotation(fp1);
	return 0;
}
short WINAPI DLLExport A_SetYRotation(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetYRotation(fp1);
	return 0;
}
short WINAPI DLLExport A_SetZRotation(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetZRotation(fp1);
	return 0;
}

short WINAPI DLLExport A_SetXScale(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetXScale(fp1);
	return 0;
}
short WINAPI DLLExport A_SetYScale(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetYScale(fp1);
	return 0;
}
short WINAPI DLLExport A_SetZScale(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetFloatParameter(rdPtr);
	float fp1 = *(float*)&p1;
	rdPtr->fusionNode->SetZScale(fp1);
	return 0;
}
short WINAPI DLLExport A_SetParentNode(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetParameter(rdPtr);
	LPHO obj;
	if (!p1)
		obj = NULL;
	else
		obj = GetObjectByFixedValue(rdPtr->rHo.hoAdRunHeader, p1);
	if (obj)
	{
		LPRDATA rData = (LPRDATA)obj->hoFree0;
		rdPtr->fusionNode->SetParentNode(rData->fusionNode); //It might have a different type, but the node position should always be the same, so let's hope it doesn't break :)
	}
	else
		rdPtr->fusionNode->SetParentNode(0);
	return 0;
}
// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

// -----------------
// Sample expression
// -----------------
// Add three values
// 
long WINAPI DLLExport E_GetParentNode(LPRDATA rdPtr, long param1) { if (rdPtr->fusionNode->parentNode == NULL) return NULL; return getFixedValue((*rdPtr->fusionNode->parentNodeObject)); }

long WINAPI DLLExport E_GetLocalXPos(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetXPosition();return *((int*)&f);}
long WINAPI DLLExport E_GetLocalYPos(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetYPosition();return *((int*)&f);}
long WINAPI DLLExport E_GetLocalZPos(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetZPosition();return *((int*)&f);}

long WINAPI DLLExport E_GetLocalXRot(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetXRotation(); return *((int*)&f); }
long WINAPI DLLExport E_GetLocalYRot(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetYRotation(); return *((int*)&f); }
long WINAPI DLLExport E_GetLocalZRot(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetZRotation(); return *((int*)&f); }

long WINAPI DLLExport E_GetLocalXScl(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetXScale(); return *((int*)&f); }
long WINAPI DLLExport E_GetLocalYScl(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetYScale(); return *((int*)&f); }
long WINAPI DLLExport E_GetLocalZScl(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetZScale(); return *((int*)&f); }

long WINAPI DLLExport E_GetWorldXPos(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteXPosition(); return *((int*)&f); }
long WINAPI DLLExport E_GetWorldYPos(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteYPosition(); return *((int*)&f); }
long WINAPI DLLExport E_GetWorldZPos(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteZPosition(); return *((int*)&f); }
						   																											
long WINAPI DLLExport E_GetWorldXRot(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteXRotation(); return *((int*)&f); }
long WINAPI DLLExport E_GetWorldYRot(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteYRotation(); return *((int*)&f); }
long WINAPI DLLExport E_GetWorldZRot(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteZRotation(); return *((int*)&f); }
						   																											
long WINAPI DLLExport E_GetWorldXScl(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteXScale(); return *((int*)&f); }
long WINAPI DLLExport E_GetWorldYScl(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteYScale(); return *((int*)&f); }
long WINAPI DLLExport E_GetWorldZScl(LPRDATA rdPtr, long param1) { rdPtr->rHo.hoFlags |= HOF_FLOAT; float f = rdPtr->fusionNode->GetAbsoluteZScale(); return *((int*)&f); }


//Reverse the string passed in.
long WINAPI DLLExport Expression2(LPRDATA rdPtr, long param1)
{
	char* temp;

	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	//I'm storing the string pointer returned into a char *
	temp = (LPSTR)p1;

	//Reversing the string.
	_strrev(temp);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)temp;
}

//Divide the float by 2.
long WINAPI DLLExport Expression3(LPRDATA rdPtr, long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_FLOAT);

	//Floats are tricky.  If you want to pass in a float, you must do the
	//following to convert the long to a true float, but only when you use
	//TYPE_FLOAT.
	float fp1 = *(float*)&p1;

	//Just doing simple math now.
	fp1 /= 2;

	//Setting the HOF_FLOAT flag lets MMF know that you are returning a float.
	rdPtr->rHo.hoFlags |= HOF_FLOAT;

	//Return the float without conversion
	return *((int*)&fp1);
}



// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
long (WINAPI* ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) =
{
	Condition,
	0, // Last
};

short (WINAPI* ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
{
	0, // Add to Irrlicht
	0, // Remove from Irrlicht
	A_SetParentNode,
	0, // Attack to Bone Node
	A_SetXPosition,
	A_SetYPosition,
	A_SetZPosition,
	0, // Set Position
	A_SetXRotation,
	A_SetYRotation,
	A_SetZRotation,
	0, // Set Rotation
	A_SetXScale,
	A_SetYScale,
	A_SetZScale,
	0, // Set Scale
	0, // Set Visibility
	0, // Load Material
	0, // Last
};

long (WINAPI* ExpressionJumps[])(LPRDATA rdPtr, long param) =
{
	E_GetParentNode,
	E_GetLocalXPos,
	E_GetLocalYPos,
	E_GetLocalZPos,
	E_GetLocalXRot,
	E_GetLocalYRot,
	E_GetLocalZRot,
	E_GetLocalXScl,
	E_GetLocalYScl,
	E_GetLocalZScl,
	E_GetWorldXPos,
	E_GetWorldYPos,
	E_GetWorldZPos,
	E_GetWorldXRot,
	E_GetWorldYRot,
	E_GetWorldZRot,
	E_GetWorldXScl,
	E_GetWorldYScl,
	E_GetWorldZScl,
	0, // Get Loaded Material
	0, // Last
};