#include "pch.h"
#include "CppUnitTest.h"
#include "../COnly/LinkedList.h"
#include "../COnly/Usf.h"
#include "../COnly/RTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RTreeTests
{
	TEST_CLASS(RTreeTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			Assert::AreEqual("", "");
		}


		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(2, 2);
			float testArray[] = {3.3,1.1,0.1,2.2,};

			float minf = arrayMinf(&testArray[0],sizeof(testArray)/sizeof(float));
			Assert::AreEqual(0.1f, minf);
		}

		TEST_METHOD(indexFArray)
		{
			Assert::AreEqual(2, 2);
			float testArray[] = { 1.1,0.1,2.2,3.3 };
			int index = indexOfF(&testArray[0], 1.1, sizeof(testArray) / sizeof(float));
			
			Assert::AreEqual(index, 0);

			index = indexOfF(&testArray[0], 2.2, sizeof(testArray) / sizeof(float));

			Assert::AreEqual(index, 2);

			index = indexOfF(&testArray[0], 55.5, sizeof(testArray) / sizeof(float));
			Assert::AreEqual(index, -1);
		}


		TEST_METHOD(asdf)
		{
			int myValue = _determineTotalMinNumberOfNodesNeeded(6);
			Assert::AreEqual(myValue, 63);
		}
	};
}
