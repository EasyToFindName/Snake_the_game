#pragma once
#include "Interfaces.h"

class BaseNotifiable : public Notifiable {
public:
	virtual void update() = 0;
	void subscribeOn(Notifier&);
	void unsubscribe();
private:
	Notifier* m_subscribedOn;
};

