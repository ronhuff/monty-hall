#include "stdafx.h"
#include "..\include\Door.h"


Door::Door()
{
	m_hasCar = false;
	m_hasGoat = false;
	m_isOpen = false;
}


Door::~Door()
{
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
