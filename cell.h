#ifndef CELL_H_SENTRY
#define CELL_H_SENTRY
class Cell{
	private:
		bool currentState;
		bool futureState;
	public:
		Cell();
		Cell(bool);
		~Cell();
		void setCurrentState(bool);
		void setFutureState(bool);
		void updateState();
		bool isAlive();
};
#endif
