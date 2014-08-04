#include "blob.h"

namespace Myblob
{
	template<typename T>
	void testFriend(const Blob<T> &i)
	{
		cout << "test friend class "	 << endl;
		i.test;
	}
}
