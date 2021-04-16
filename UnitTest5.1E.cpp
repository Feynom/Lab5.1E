#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.1E/Vector3D.h"
#include "../Lab5.1E/Vector3D.cpp"
#include "../Lab5.1E/Object.h"
#include "../Lab5.1E/Object.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51E
{
	TEST_CLASS(UnitTest51E)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Vector3D A(1, 2, 3), B(4, 5, 6);
			//A * B	
			Assert::AreEqual(A * B, 32.);
		}
	};
}
