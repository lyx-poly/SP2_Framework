#ifndef SCENETAXI_H
#define SCENETAXI_H

#include "Scene.h"
#include "Mtx44.h"
#include "Camera.h"
#include "Camera2.h"
#include "Camera3.h"
#include "CameraYX.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"

class SceneYX : public Scene
{
	enum GEOMETRY_TYPE
	{
		GEO_AXES,
		GEO_FLOOR,
		GEO_QUAD,
		GEO_QUAD2,
		GEO_QUAD3,
		GEO_LIGHTBALL,

		// SatNav Spires
		GEO_NAV_SPIRE,
		GEO_NAV_TAXI, // Deport / Taxi Company

		// Skybox
		GEO_LEFT,
		GEO_RIGHT,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_FRONT,
		GEO_BACK,
		GEO_TORUS,

		// Hover Taxi
		GEO_TAXI,
		GEO_HOVER,

		// Taxi Comapny
		GEO_TAXI_COMPANY,
		GEO_TAXI_PAD,

		// Helper Bot
		GEO_ROBOT,

		// Passengers Pads and Spires (Pads to indicate location and pickup detection | Spires for use with SatNav)
		GEO_PASSENGERS_PAD_1,
		GEO_PASSENGERS_SPIRE_1,

		GEO_PASSENGERS_PAD_2,
		GEO_PASSENGERS_SPIRE_2,

		GEO_PASSENGERS_PAD_3,
		GEO_PASSENGERS_SPIRE_3,

		GEO_PASSENGERS_PAD_4,
		GEO_PASSENGERS_SPIRE_4,

		GEO_PASSENGERS_PAD_5,
		GEO_PASSENGERS_SPIRE_5,


		// Passenger models
		GEO_PASSENGERS_MALE_1,
		GEO_PASSENGERS_MALE_2,
		GEO_PASSENGERS_MALE_3,
		GEO_PASSENGERS_MALE_4,
		GEO_PASSENGERS_MALE_5,

		GEO_PASSENGERS_MALE_HAIR_1,
		GEO_PASSENGERS_MALE_HAIR_2,
		GEO_PASSENGERS_MALE_HAIR_3,
		GEO_PASSENGERS_MALE_HAIR_4,
		GEO_PASSENGERS_MALE_HAIR_5,

		GEO_PASSENGERS_FEMALE_1,
		GEO_PASSENGERS_FEMALE_2,
		GEO_PASSENGERS_FEMALE_3,
		GEO_PASSENGERS_FEMALE_4,
		GEO_PASSENGERS_FEMALE_5,

		GEO_PASSENGERS_FEMALE_HAIR_1,
		GEO_PASSENGERS_FEMALE_HAIR_2,
		GEO_PASSENGERS_FEMALE_HAIR_3,
		GEO_PASSENGERS_FEMALE_HAIR_4,
		GEO_PASSENGERS_FEMALE_HAIR_5,

		// Road
		GEO_ROAD,

		// Residential Buildings
		GEO_FLAT1,
		GEO_FLAT_PAD,

		// Futuristic Business District
		GEO_SCIFI_1,
		GEO_SCIFI_PLATFORM,
		GEO_SCIFI_2,
		GEO_SCIFI_3,
		GEO_SCIFI_4,
		GEO_SCIFI_5,
		GEO_SCIFI_6,
		GEO_SCIFI_7,

		// Hospital
		GEO_HOSPITAL,
		GEO_RED_CROSS,
		GEO_HOSPITAL_PAD,

		// Mall
		GEO_MALL,
		GEO_MALL_SIGN,
		GEO_MALL_PAD,

		// Park 
		GEO_TREE1,
		GEO_TREE2,
		GEO_TREE3,
		GEO_TREE4,

		GEO_PARK_PAD,

		GEO_TEXT,
		GEO_TEXT1,
		GEO_TEXT2,
		NUM_GEOMETRY,
	};

	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHTENABLED,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,
		//Second Light
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,
		//Third Light
		U_LIGHT2_POSITION,
		U_LIGHT2_COLOR,
		U_LIGHT2_POWER,
		U_LIGHT2_KC,
		U_LIGHT2_KL,
		U_LIGHT2_KQ,
		U_LIGHT2_TYPE,
		U_LIGHT2_SPOTDIRECTION,
		U_LIGHT2_COSCUTOFF,
		U_LIGHT2_COSINNER,
		U_LIGHT2_EXPONENT,
		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,
	};


private:
	MS modelStack, viewStack, projectionStack;

	Mtx44 translate, rotate, scale;
	Mtx44 model;
	Mtx44 view;
	Mtx44 projection;
	Mtx44 MVP;

	Light light[1];

	//float FPS;

	// Camera control (start camera control only after pressing start)
	bool cam_control;

	// Skybox translate
	float skybox_translateX, skybox_translateY, skybox_translateZ;

	// SatNav Spire translates and passive rotate
	float spire_x1, spire_y1, spire_z1;
	float spire_x2, spire_y2, spire_z2;
	float spire_x3, spire_y3, spire_z3;
	float spire_x4, spire_y4, spire_z4;
	float spire_x5, spire_y5, spire_z5;

	float spire_passive_rotate;

	// Passenger Interaction
	float hospital_spire_x1, hospital_spire_y1, hospital_spire_z1;
	float commercial_spire_x2, commercial_spire_y2, commercial_spire_z2;
	float residential1_spire_x3, residential1_spire_y3, residential1_spire_z3;
	float residential2_spire_x4, residential2_spire_y4, residential2_spire_z4;
	float mall_spire_x5, mall_spire_y5, mall_spire_z5;

	int passengerID;
	int cash;

	float tempxyz_position[3] = { };
	float tempxyz_target[3] = { }; // Temp storage for previous cam position
	float tempxyz_up[3] = { };
	bool value_store;

	bool pause, gamestart, upgrade; // game state bools

	bool speed_boost, lift_boost, side_hover; // Upgrade bools

	bool dialogue_1, dialogue_2, dialogue_3, dialogue_4, dialogue_5; // Dialogue upon pick up

	bool destination_1, destination_2, destination_3, destination_4, destination_5; // Output destination UI
	
	bool end_dialogue_1, end_dialogue_2, end_dialogue_3, end_dialogue_4, end_dialogue_5; // Dialogue upon drop off

	bool passenger_deliver_1, passenger_deliver_2, passenger_deliver_3, passenger_deliver_4, passenger_deliver_5; // Passenger delivered bool

	bool end_game;


	CameraYX camera;
	//Camera2 camera2;
	//Camera3 camera2;

	unsigned m_parameters[U_TOTAL];
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	//unsigned m_vertexBuffer[NUM_GEOMETRY];
	//unsigned m_colorBuffer[NUM_GEOMETRY];
	//unsigned m_indexBuffer[NUM_GEOMETRY];
	unsigned m_programID;

	float taxi_rise_transition;

	void RenderMesh(Mesh* mesh, bool enableLight);
	void RenderSkybox();

	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey);

public:
	SceneYX();
	~SceneYX();

	virtual void Init();
	virtual void Reset();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
};

#endif