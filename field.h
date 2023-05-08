#ifndef FIELD_H_SENTRY
#define FIELD_H_SENTRY
#include "cell.h"
class Field{
	protected:
		int sizeX;
		int sizeY;
		Cell **cellField;
	public:
		Field();
		Field(int, int);
		virtual ~Field();
		void update();
		virtual void show() = 0;
	protected:
		bool defineNewState(int, int);
};
#endif
