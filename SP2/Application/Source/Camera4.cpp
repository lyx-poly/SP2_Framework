#include "Camera4.h"
#include "Application.h"
#include "Vertex.h"
#include "Mtx44.h"

/******************************************************************************/
/*!
\brief
Default constructor
*/
/******************************************************************************/
Camera4::Camera4()
{
}

/******************************************************************************/
/*!
\brief
Destructor
*/
/******************************************************************************/
Camera4::~Camera4()
{
}

/******************************************************************************/
/*!
\brief
Initialize camera

\param pos - position of camera
\param target - where the camera is looking at
\param up - up vector of camera
*/
/******************************************************************************/
void Camera4::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = pos;
	this->target = target;
	this->up = up;
}

/******************************************************************************/
/*!
\brief
Reset the camera settings
*/
/******************************************************************************/
/*void Camera4::Reset(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	if (Application::IsKeyPressed('R'))
	{
		this->position = pos;
		this->target = target;
		this->up = up;
	}
}*/

/******************************************************************************/
/*!
\brief
To be called every frame. Camera will get user inputs and update its position and orientation

\param dt - frame time
*/
/******************************************************************************/
void Camera4::Update(double dt)
{

	/*
	if (Application::IsKeyPressed('A'))
		this->position.x -= CAMERA_SPEED * dt; //move camera left
	if (Application::IsKeyPressed('D'))
		this->position.x += CAMERA_SPEED * dt; //move camera right
	if (Application::IsKeyPressed('W'))
		this->position.y += CAMERA_SPEED * dt; //move camera up
	if (Application::IsKeyPressed('S'))
		this->position.y -= CAMERA_SPEED * dt; //move camera down
	if (Application::IsKeyPressed('M'))
		this->position.z += CAMERA_SPEED * dt; //move camera forward
	if (Application::IsKeyPressed('N'))
		this->position.z -= CAMERA_SPEED * dt; //move camera backwards
		*/

		/*float zx_hyp; // Hypothenuse
		float yx_hyp;
		float zx_tan; // Angle
		float yx_tan;
		float x;
		float y;
		float z;*/

		/*x = this->position.x;
		y = this->position.y;
		z = this->position.z;

		zx_hyp = sqrt((x * x) + (z * z));
		yx_hyp = sqrt((x * x) + (y * y));

		//zx_tan = this->position.z / this->position.x;// zx plane | zx_tan = opp/adj ; opp = position.z, adj = position.x*/
	static const float CAMERA_SPEED = 50.f;
	static const float CAMERA_SPEED2 = CAMERA_SPEED / 2;

	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	if (Application::IsKeyPressed(VK_UP))
	{
		// Rotation matrix
		//Vector3 view = (target - position).Normalized();
		//Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalized();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(CAMERA_SPEED * dt, right.x, right.y, right.z);

		// Apply Rotation
		//position = rotation * position;
		//up = right.Cross(view).Normalized();

		// Apply Rotation FPS
		view = rotation * view;
		target = position + view;
	}
	if (Application::IsKeyPressed(VK_LEFT))
	{
		Mtx44 rotation;
		rotation.SetToRotation(CAMERA_SPEED * dt, 0, 1, 0);
		// Apply Rotation
		//position = rotation * position;
		//up = rotation * up;

		view = rotation * view;
		target = position + view;
		up = rotation * up;
	}

	if (Application::IsKeyPressed(VK_DOWN))
	{
		// Rotation matrix
		//Vector3 view = (target - position).Normalized();
		//Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalized();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(-CAMERA_SPEED * dt, right.x, right.y, right.z);
		// Apply Rotation
		//position = rotation * position;
		//up = right.Cross(view).Normalized();

		// Apply Rotation FPS
		view = rotation * view;
		target = position + view;
	}

	if (Application::IsKeyPressed(VK_RIGHT))
	{
		Mtx44 rotation;
		rotation.SetToRotation(-CAMERA_SPEED * dt, 0, 1, 0);
		// Apply Rotation
		//position = rotation * position;
		//up = rotation * up;

		view = rotation * view;
		target = position + view;
		up = rotation * up;
	}





	if (Application::IsKeyPressed('S')) // Backward to z+
	{
		if (position.z >= 250)
		{
			position.z -= CAMERA_SPEED2 * dt;
			target.z -= CAMERA_SPEED2 * dt;
		}

		else
		{
			position.z += CAMERA_SPEED2 * dt;
			target.z += CAMERA_SPEED2 * dt;
		}
	}

	if (Application::IsKeyPressed('A')) // Right to x-
	{
		if (position.x <= -250)
		{
			position.x += CAMERA_SPEED2 * dt;
			target.x += CAMERA_SPEED2 * dt;
		}

		else
		{
			position.x -= CAMERA_SPEED2 * dt;
			target.x -= CAMERA_SPEED2 * dt;
		}
	}

	if (Application::IsKeyPressed('D')) // Left to x+
	{
		if (position.x >= 250)
		{
			position.x -= CAMERA_SPEED2 * dt;
			target.x -= CAMERA_SPEED2 * dt;
		}

		else
		{
			position.x += CAMERA_SPEED2 * dt;
			target.x += CAMERA_SPEED2 * dt;
		}
	}

	if (Application::IsKeyPressed('W')) // Forward to z-
	{
		if (position.z <= -250)
		{
			position.z += CAMERA_SPEED2 * dt;
			target.z += CAMERA_SPEED2 * dt;
		}

		else
		{
			position.z -= CAMERA_SPEED2 * dt;
			target.z -= CAMERA_SPEED2 * dt;
		}
	}

	if (Application::IsKeyPressed('E')) // Up to y+
	{
		position.y += CAMERA_SPEED2 * dt;
		target.y += CAMERA_SPEED2 * dt;
	}

	if (Application::IsKeyPressed('Q')) // Down to y-
	{
		if (position.y <= 0)
		{
			position.y += CAMERA_SPEED2 * dt;
			target.y += CAMERA_SPEED2 * dt;
		}

		else
		{
			position.y -= CAMERA_SPEED2 * dt;
			target.y -= CAMERA_SPEED2 * dt;
		}
	}



	/*
	// Camera Position Movement

	if (Application::IsKeyPressed('I')) //Forward
	{
		target.z += CAMERA_SPEED * dt / 10;
		position.z += CAMERA_SPEED * dt / 10;
	}

	if (Application::IsKeyPressed('K')) //Backward
	{
		//Mtx44 rotation;
		//rotation.SetToRotation(-CAMERA_SPEED * dt, 0, 1, 0);
		// Apply Rotation
		//target = rotation * target;
		//up = rotation * up;

		target.z -= CAMERA_SPEED * dt / 10;
		position.z -= CAMERA_SPEED * dt / 10;
	}

	if (Application::IsKeyPressed('J')) //Left
	{
		target.x -= CAMERA_SPEED * dt / 10;
		position.x -= CAMERA_SPEED * dt / 10;
	}

	if (Application::IsKeyPressed('L')) //Right
	{
		target.x += CAMERA_SPEED * dt / 10;
		position.x += CAMERA_SPEED * dt / 10;

	}*/
}