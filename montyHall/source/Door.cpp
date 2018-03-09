#include "stdafx.h"
#include "Door.h"


Door::Door()
	: m_hasCar(false), m_hasGoat(false)
{

}


Door::~Door()
{
}

void Door::setHasCar(bool newBool)
{
	m_hasCar = newBool;
}

void Door::setHasGoat(bool newBool)
{
	m_hasGoat = newBool;
}

bool Door::getHasCar() const
{
	return (m_hasCar);
}

bool Door::getHasGoat() const
{
	return (m_hasGoat);
}
