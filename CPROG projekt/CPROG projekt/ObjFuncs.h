#ifndef OBJFUNCS_H
#define OBJFUNCS_H

#include "Wrapper_ObjFuncs.h"
namespace cgame {
	template <typename OBJ>
	class ObjFuncs : public Wrapper_ObjFuncs
	{
	public:
		static ObjFuncs* getInstance(OBJ* o, void(OBJ::*f)()) {
			return new ObjFuncs(o, f);
		}
		void doFunc() {
			(object->*mpek)();
		}
		~ObjFuncs() {
			delete object;
			
			
		}
	protected:
		ObjFuncs(OBJ* o, void(OBJ::*f)()) : object(o), mpek(f) {}
	private:
		OBJ* object;
		void(OBJ::*mpek)();
	};

#endif



}