#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"

/******************************************************************************/
/*!
\brief
Default constructor
*/
/******************************************************************************/
Camera3::Camera3()
{
}

/******************************************************************************/
/*!
\brief
Destructor
*/
/******************************************************************************/
Camera3::~Camera3()
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
void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
    this->position = pos;
    this->target = target;
    Vector3 view = (target - position).Normalized();
    Vector3 right = view.Cross(up);
    right.y = 0;
    right.Normalize();
    this->up = right.Cross(view).Normalized();

}

/******************************************************************************/
/*!
\brief
Reset the camera settings
*/
/******************************************************************************/
void Camera3::Reset()
{
}

/******************************************************************************/
/*!
\brief
To be called every frame. Camera will get user inputs and update its position and orientation

\param dt - frame time
*/
/******************************************************************************/
void Camera3::Update(double dt)
{
    static const float CAMERA_SPEED = 50.f;
    static const float CAMERA_SPEED2 = 10.f;
   // static const float ZOOM_SPEED = 20.F;
    Vector3 view = (target - position).Normalized();
    Vector3 moveDir = view;
    Vector3 rightDir = view.Cross(up).Normalized();
    moveDir.y = 0;
    rightDir.y = 0;
    rightDir.Normalize();
    moveDir.Normalize();



    /*if (Application::IsKeyPressed('W'))
    {
        Vector3 view = (target - position).Normalized();
        position += view * ZOOM_SPEED * static_cast<float>(dt);
        target = position + view;
    }
    */
    /*
    if (Application::IsKeyPressed('S'))
    {
        Vector3 view = (target - position).Normalized();
        position -= view * ZOOM_SPEED * static_cast<float>(dt);
        target = position + view;
    }*/
    
    
    if (Application::IsKeyPressed('A'))
    {
        /*Vector3 right = view.Cross(up).Normalized();
        right.y = 0;

        up = right.Cross(view).Normalized();*/

        position -= rightDir * dt * CAMERA_SPEED2;
        target -= rightDir * dt * CAMERA_SPEED2;

        if (position.x > 50 || position.x < -250 || position.z > 250 || position.z < -250)
        {
            position += rightDir * dt * CAMERA_SPEED2;
            target += rightDir * dt * CAMERA_SPEED2;
        }
    }
    if (Application::IsKeyPressed('D'))
    {
        /* Vector3 right = view.Cross(up).Normalized();
         right.y = 0;

         up = right.Cross(view).Normalized();*/

        position += rightDir * dt * CAMERA_SPEED2;
        target += rightDir * dt * CAMERA_SPEED2;

        if (position.x > 50 || position.x < -250 || position.z > 250 || position.z < -250)
        {
            position -= rightDir * dt * CAMERA_SPEED2;
            target -= rightDir * dt * CAMERA_SPEED2;
        }
    }
    if (Application::IsKeyPressed('W'))
    {
        //Vector3 right = view.Cross(up).Normalized();
        /*right.y = 0;
        up = right.Cross(view).Normalized();*/


        position += moveDir * dt * CAMERA_SPEED2;
        target += moveDir * dt * CAMERA_SPEED2;

        if (position.x > 50 || position.x < -250 || position.z > 250 || position.z < -250)
        {
            position -= moveDir * dt * CAMERA_SPEED2;
            target -= moveDir * dt * CAMERA_SPEED2;
        }
    }
    if (Application::IsKeyPressed('S'))
    {
        /*Vector3 right = view.Cross(up).Normalized();
        right.y = 0;

        up = right.Cross(view).Normalized();*/

        position -= moveDir * dt * CAMERA_SPEED2;
        target -= moveDir * dt * CAMERA_SPEED2;

        if (position.x > 50 || position.x < -250 || position.z > 250 || position.z < -250)
        {
            position += moveDir * dt * CAMERA_SPEED2;
            target += moveDir * dt * CAMERA_SPEED2;
        }
    }

    /*else if (Application::IsKeyPressed('Q'))
    {
        moveDir.y += 2;
        rightDir.y += 2;

        position -= moveDir * dt;
        target -= moveDir * dt;
    }
    else if (Application::IsKeyPressed('E'))
    {
        moveDir.y -= 2;
        rightDir.y -= 2;

        position -= moveDir * dt;
        target -= moveDir * dt;
    }*/

    if (Application::IsKeyPressed('E')) // Up to y+
    {
        position.y += CAMERA_SPEED2 * dt;
        target.y += CAMERA_SPEED2 * dt;
    }

    if (Application::IsKeyPressed('Q')) // Down to y-
    {
        if (position.y <= 1)
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

    if (Application::IsKeyPressed(VK_LEFT))
    {
        float yaw = CAMERA_SPEED * static_cast<float>(dt);
        Vector3 view = (target - position).Normalized();
        Mtx44 rotation;
        rotation.SetToRotation(yaw, 0, 1, 0);
        view = rotation * view;
        target = position + view;
        up = rotation * up;

    }
    if (Application::IsKeyPressed(VK_RIGHT))
    {
        float yaw = -CAMERA_SPEED * static_cast<float>(dt);
        Vector3 view = (target - position).Normalized();
        Mtx44 rotation;
        rotation.SetToRotation(yaw, 0, 1, 0);
        view = rotation * view;
        target = position + view;
        up = rotation * up;
    }
    if (Application::IsKeyPressed(VK_UP))
    {
        float pitch = CAMERA_SPEED * static_cast<float>(dt);
        Vector3 view = (target - position).Normalized();
        Vector3 right = view.Cross(up);
        right.y = 0;
        right.Normalize();
        up = right.Cross(view).Normalized();
        Mtx44 rotation;
        rotation.SetToRotation(pitch, right.x, right.y, right.z);
        view = rotation * view;
        target = position + view;

    }
    if (Application::IsKeyPressed(VK_DOWN))
    {
        float pitch = -CAMERA_SPEED * static_cast<float>(dt);
        Vector3 view = (target - position).Normalized();
        Vector3 right = view.Cross(up);
        right.y = 0;
        right.Normalize();
        up = right.Cross(view).Normalized();
        Mtx44 rotation;
        rotation.SetToRotation(pitch, right.x, right.y, right.z);
        view = rotation * view;
        target = position + view;
    }

}