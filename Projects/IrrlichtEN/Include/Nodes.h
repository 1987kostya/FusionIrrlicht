#pragma once
#include "EnginePublic.h"

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

class DummyFusionNode :public BaseFusionNode
{
public:
	void  SetXPosition(float value) { auto pos = node->getPosition(); node->setPosition(vector3df(value, pos.Y, pos.Z)); }
	void  SetYPosition(float value) { auto pos = node->getPosition(); node->setPosition(vector3df(pos.X, value, pos.Z)); }
	void  SetZPosition(float value) { auto pos = node->getPosition(); node->setPosition(vector3df(pos.X, pos.Y, value)); }
	float GetXPosition() { return node->getPosition().X; }
	float GetYPosition() { return node->getPosition().Y; }
	float GetZPosition() { return node->getPosition().Z; }
	float GetAbsoluteXPosition() { return node->getAbsolutePosition().X; }
	float GetAbsoluteYPosition() { return node->getAbsolutePosition().Y; }
	float GetAbsoluteZPosition() { return node->getAbsolutePosition().Z; }
	void  SetXRotation(float value) { auto pos = node->getRotation(); node->setRotation(vector3df(value, pos.Y, pos.Z)); }
	void  SetYRotation(float value) { auto pos = node->getRotation(); node->setRotation(vector3df(pos.X, value, pos.Z)); }
	void  SetZRotation(float value) { auto pos = node->getRotation(); node->setRotation(vector3df(pos.X, pos.Y, value)); }
	float GetXRotation() { return node->getRotation().X; }
	float GetYRotation() { return node->getRotation().Y; }
	float GetZRotation() { return node->getRotation().Z; }
	float GetAbsoluteXRotation() { return node->getAbsoluteTransformation().getRotationDegrees().X; }
	float GetAbsoluteYRotation() { return node->getAbsoluteTransformation().getRotationDegrees().Y; }
	float GetAbsoluteZRotation() { return node->getAbsoluteTransformation().getRotationDegrees().Z; }
	void  SetXScale(float value) { auto pos = node->getScale(); node->setScale(vector3df(value, pos.Y, pos.Z)); }
	void  SetYScale(float value) { auto pos = node->getScale(); node->setScale(vector3df(pos.X, value, pos.Z)); }
	void  SetZScale(float value) { auto pos = node->getScale(); node->setScale(vector3df(pos.X, pos.Y, value)); }
	float GetXScale() { return node->getScale().X; }
	float GetYScale() { return node->getScale().Y; }
	float GetZScale() { return node->getScale().Z; }
	float GetAbsoluteXScale() { return node->getAbsoluteTransformation().getScale().X; }
	float GetAbsoluteYScale() { return node->getAbsoluteTransformation().getScale().Y; }
	float GetAbsoluteZScale() { return node->getAbsoluteTransformation().getScale().Z; }
	BaseFusionNode* GetParentNode() { return parentNode; }
	void SetParentNode(BaseFusionNode* newParent) {
		if (!newParent) {
			parentNodeObject = NULL;
			parentNode = NULL;
			auto scene = ((engineRData*)owningObject->hoAdRunHeader->rhFree6)->device->getSceneManager();
			node->setParent(scene->getRootSceneNode()); return;
		} 
		parentNodeObject = newParent->owningObject;  parentNode = newParent; node->setParent(parentNode->node);
	}
};

class CameraFusionNode :public DummyFusionNode
{
public:

};