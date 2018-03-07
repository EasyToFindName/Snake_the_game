#pragma once
class _ComponentCounter {
	static unsigned int m_count;
public:
	_ComponentCounter() {
		++m_count;
	}

	static unsigned int getCounter() { return m_count; }

};
