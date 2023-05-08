#ifndef TEXTFIELD_H_SENTRY
#define TEXTFIELD_H_SENTRY
#include "field.h"

class TextField : public Field{
	public:
		TextField();
		TextField(int, int);
		TextField(int, int, const char*); 
			~TextField();
		void show();
		void infPlay(int);
};
#endif
