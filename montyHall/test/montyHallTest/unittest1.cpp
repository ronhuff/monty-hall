#include "stdafx.h"
#include "CppUnitTest.h"
#include "Door.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace montyHallTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDoorInit)
		{
			Door d1;
			Assert::AreEqual(false, d1.getIsOpen());
			Assert::AreEqual(false, d1.getHasGoat());
			Assert::AreEqual(false, d1.getHasCar());
		}

	};
}