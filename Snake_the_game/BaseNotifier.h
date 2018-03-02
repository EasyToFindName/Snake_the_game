#pragma once

#include "Interfaces.h"
#include <set>
class BaseNotifier : public Notifier {
public:
	virtual void detach(Notifiable*) override;
	virtual void attach(Notifiable*) override;
	virtual void notify() override;
protected:
	std::set<Notifiable*> m_subscribers;
};

