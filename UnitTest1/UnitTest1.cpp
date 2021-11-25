#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 8.1.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char a = 'Q';
			char b = 'S';
			const char* str = "TestQQQ";
			bool R = Include(str, a, b,0);
			Assert::AreEqual(false, R);
		}
	};
}
