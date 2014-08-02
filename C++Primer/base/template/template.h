#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <iostream>

using namespace std;

namespace MyTemplateClass
{
	class normalClass;

//class friend template function step 1.
	template<typename> class testTemplate;
	template<typename T> void testCall(testTemplate<T>&t);
//end
	template<typename T>
	class testTemplate
	{
		public:

//class friend template function step 2.
			friend void testCall<T>(testTemplate<T> &t);
//end
			friend void testNormalCall();
			friend class normalClass;

			int value(){return testValue;}
		private:
			int testValue;
	};

	class normalClass
	{
		public:
			void justTest(){cout << "just test" << endl;}

		private:
			int testXXX;
	};

//class friend template function step 3.
	template<typename T> void testCall(testTemplate<T>& t)
	{
		cout << "test call the template by friend class" << endl;
		t.testValue = 10;
	}
//end
}

#endif
