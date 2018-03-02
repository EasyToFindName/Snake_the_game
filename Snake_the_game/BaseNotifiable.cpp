#include "BaseNotifiable.h"


void BaseNotifiable::subscribeOn(Notifier& n) {
	unsubscribe();
	m_subscribedOn = &n;
	n.attach(this);
}

void BaseNotifiable::unsubscribe() {
	if(m_subscribedOn != nullptr)
		m_subscribedOn->detach(this);

	m_subscribedOn = nullptr;
}
