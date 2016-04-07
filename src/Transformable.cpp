#include "Transformable.h"

Transformable::Transformable() {
	//Initialize
	 m_vPosition = Vector3D();
	 m_vRotation = Vector3D();
	 m_vOrigin = Vector3D();
	 m_vScale = Vector3D(1.0f,1.0f,1.0f);
	 m_bUpdated = true;
}

void Transformable::move(Vector3D vector) { 
	m_vPosition += vector; 
	m_bUpdated = true;
}
void Transformable::rotate(Vector3D vector) { 
	m_vRotation += vector; 
	m_bUpdated = true;
}
void Transformable::scale(Vector3D vector){ 
	m_vScale += vector; 
	m_bUpdated = true;
}
void Transformable::rotateX(float x){ 
	m_vRotation.setX(m_vRotation.getX() + x); 
	m_bUpdated = true;
}
void Transformable::rotateY(float y){ 
	m_vRotation.setY(m_vRotation.getY() + y); 
	m_bUpdated = true;
}
void Transformable::rotateZ(float z){ 
	m_vRotation.setZ(m_vRotation.getZ() + z); 
	m_bUpdated = true;
}

void Transformable::setPosition(const Vector3D newPosition) {
	m_vPosition = newPosition;
	m_bUpdated = true;
}
void Transformable::setRotation(const Vector3D newRotation) {
	m_vRotation = newRotation;
	m_bUpdated = true;
}
void Transformable::setOrigin(const Vector3D newOrigin) {
	m_vOrigin = newOrigin;
	m_bUpdated = true;
}
void Transformable::setScale(const Vector3D newScale) {
	m_vScale = newScale;
	m_bUpdated = true;
}

void Transformable::setScale(const float newScale) {
	m_vScale.setX(newScale);
	m_vScale.setY(newScale);
	m_vScale.setZ(newScale);
	m_bUpdated = true;
}

void Transformable::setPosition(const float x, const float y, const float z) {
	m_vPosition.setX(x);
	m_vPosition.setY(y);
	m_vPosition.setZ(z);
	m_bUpdated = true;
}
void Transformable::setRotation(const float x, const float y, const float z) {
	m_vRotation.setX(x);
	m_vRotation.setY(y);
	m_vRotation.setZ(z);
	m_bUpdated = true;
}
void Transformable::setOrigin(const float x, const float y, const float z) {
	m_vOrigin.setX(x);
	m_vOrigin.setY(y);
	m_vOrigin.setZ(z);
	m_bUpdated = true;
}

void Transformable::setScale(const float x, const float y, const float z) {
	m_vScale.setX(x);
	m_vScale.setY(y);
	m_vScale.setZ(z);
	m_bUpdated = true;
}

Vector3D Transformable::getPosition() {
	return m_vPosition;
}
Vector3D Transformable::getRotation() {
	return m_vRotation;
}
Vector3D Transformable::getOrigin() {
	return m_vOrigin;
}