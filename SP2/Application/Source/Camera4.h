#ifndef CAMERA_4_H
#define CAMERA_4_H

#include "Camera.h"

class Camera4 : public Camera
{
public:
	//Vector3 position;
	//Vector3 target;
	//Vector3 up;

	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;

	Camera4();
	~Camera4();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt);
	//virtual void Reset();
	bool fps;
};

#endif