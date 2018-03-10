#include "stdafx.h"
#include "Door.h"


Door::Door()
	: m_hasCar(false)
{

}


Door::~Door()
{
}

void Door::setHasCar(bool newBool)
{
	m_hasCar = newBool;
}

bool Door::getHasCar() const
{
	return (m_hasCar);
}
