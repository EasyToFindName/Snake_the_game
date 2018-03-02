#include "BaseNotifier.h"


void BaseNotifier::attach(Notifiable* obj) {
	m_subscribers.insert(obj);
}

void BaseNotifier::detach(Notifiable* obj) {
	m_subscribers.erase(obj);
}

void BaseNotifier::notify() {
	for(auto& obj : m_subscribers) {
		obj->update();
	}
}