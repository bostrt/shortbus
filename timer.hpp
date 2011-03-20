#ifndef TIMER_H
#define TIMER_H

class Timer{
private:
	int startTicks;
	int pausedTicks;
	bool paused;
	bool started;

public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();

	int getTicks();
	bool isStarted();
	bool isPaused();
};

#endif /* TIMER_H */
