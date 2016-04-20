#include "Light.h"
#include <iostream>

Light::Light() {
	//Default light values
	setPosition(1.0f,500.0f,1.0f);
	setRotation(1.0f,1.0f,1.0f);
	setLightColour(1.0f,1.0f,1.0f,1.0f);
	setNoLightColour(0.0f,0.0f,0.0f,1.0f);
	setLightModelAmbient(0.3f, 0.3f, 0.3f, 1.0);
	m_lightNumber = GL_LIGHT0;
}

void Light::setLightNum(GLenum lightNumber) {
	//Ensure enum is valid
	if (lightNumber == GL_LIGHT0 || lightNumber == GL_LIGHT1 || lightNumber == GL_LIGHT2 || lightNumber == GL_LIGHT3 || 
		lightNumber == GL_LIGHT4 || lightNumber == GL_LIGHT5 || lightNumber == GL_LIGHT6 || lightNumber == GL_LIGHT7) {
		m_lightNumber = lightNumber;
	} else {
		m_lightNumber = GL_LIGHT0;	//Default light
	}	
}

void Light::setPosition(float x, float y, float z) {
	m_position[0] = x;
	m_position[1] = y;
	m_position[2] = z;
	m_position[3] = 0.5;
}

void Light::setRotation(float x, float y, float z) {
	m_rotation[0] = x;
	m_rotation[1] = y;
	m_rotation[2] = z;
}

void Light::setLightColour(float R, float G, float B, float A) {
	lightColour[0] = R;
	lightColour[1] = G;
	lightColour[2] = B;
	lightColour[3] = A;
}
void Light::setNoLightColour(float R, float G, float B, float A) {
	noLight[0] = R;
	noLight[1] = G;
	noLight[2] = B;
	noLight[3] = A;
}
void Light::setLightModelAmbient(float R, float G, float B, float A) {
	lightModelAmbient[0] = R;
	lightModelAmbient[1] = G;
	lightModelAmbient[2] = B;
	lightModelAmbient[3] = A;
}

float Light::getPosX(){ return m_position[0]; }
float Light::getPosY(){ return m_position[1]; }
float Light::getPosZ(){ return m_position[2]; }

float Light::getRotX(){ return m_rotation[0]; }
float Light::getRotY(){ return m_rotation[1]; }
float Light::getRotZ(){ return m_rotation[2]; }

void Light::draw() {
	glEnable(GL_LIGHTING);
	glEnable(m_lightNumber);
	//Apply transformations
	glPushMatrix();
	glTranslatef(m_position[0], m_position[1], m_position[2]);		// Move to position
	glRotatef(m_rotation[0],1.0f, 0.0f,0.0f);							//Rotate around origin
	glRotatef(m_rotation[1],0.0f, 1.0f,0.0f);
	glRotatef(m_rotation[2],0.0f, 0.0f,1.0f);
	glTranslatef(-m_position[0], -m_position[1], -m_position[2]);	// Move to origin

	GLfloat spec[4] = {1.0,1.0,1.0, 1.0f};
	GLfloat diff[4] = {1.0,1.0,1.0, 1.0f};
	GLfloat ambient[4] = {1.0,1.0,1.0, 1.0f};
	//Set Light values
	glLightfv(m_lightNumber, GL_POSITION, m_position);
	glLightfv(m_lightNumber, GL_DIFFUSE, diff);
	glLightfv(m_lightNumber, GL_SPECULAR, spec);
	glLightfv(m_lightNumber, GL_AMBIENT, ambient);			// no ambient light from the source
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightModelAmbient);	// use global ambient instead

	glPopMatrix;
}