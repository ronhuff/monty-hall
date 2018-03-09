#include "stdafx.h"
#include "Door.h"


Door::Door()
	: m_hasCar(false), m_hasGoat(false), m_isOpen(false)
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

void Door::setIsOpen(bool newBool)
{
	m_isOpen = newBool;
}
void Door::setIsPicked(bool newBool)
{
	m_isPicked = newBool;
}

bool Door::getHasCar() const
{
	return (m_hasCar);
}

bool Door::getHasGoat() const
{
	return (m_hasGoat);
}

bool Door::getIsOpen() const
{
	return (m_isOpen);
}

bool Door::getIsPicked() const
{
	return(m_isPicked);
}