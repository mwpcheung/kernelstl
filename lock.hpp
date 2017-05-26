#pragma once
#include "common.h"
class CLock
{
public:
	CLock() {
		KeInitializeSpinLock(&m_lock);
	}
	~CLock() {
	}
public:
	void lock() {
		KeAcquireSpinLock(&m_lock, &irq);
	}
	void unlock() {
		KeReleaseSpinLock(&m_lock, irq);
	}
protected:
	KSPIN_LOCK m_lock;
	KIRQL irq;
};
