#ifndef CAMERA_YX_H
#define CAMERA_YX_H

#include "Camera.h"

class CameraYX : public Camera
{
public:
	//Vector3 position;
	//Vector3 target;
	//Vector3 up;

	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;

	CameraYX();
	~CameraYX();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt, bool speed_boost, bool lift_boost, bool side_hover);
	virtual void Reset();
	bool fps;
};

#endif