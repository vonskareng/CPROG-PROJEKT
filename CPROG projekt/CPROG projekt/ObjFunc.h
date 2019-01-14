#ifndef OBJFUNC_H
#define OBJFUNC_H
#include <memory>

namespace cgame {
	template <typename OBJECT>
	struct ObjFunc {
		shared_ptr<OBJECT> o;
		
		void executeFunc() {
			cout << "asda" << endl;
		}

	};

}




#endif
