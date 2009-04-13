//
// AbstractPriorityDelegate.h
//
// $Id: //poco/1.3/Foundation/include/Poco/AbstractPriorityDelegate.h#1 $
//
// Library: Foundation
// Package: Events
// Module:  AbstractPriorityDelegate
//
// Implementation of the AbstractPriorityDelegate template.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef  Foundation_AbstractPriorityDelegate_INCLUDED
#define  Foundation_AbstractPriorityDelegate_INCLUDED


#include "Poco/Foundation.h"


namespace Poco {


template <class TArgs> 
class AbstractPriorityDelegate
	/// Interface for PriorityDelegate and PriorityExpire.
	/// Very similar to AbstractDelegate but having two separate files (no inheritance)
	/// allows to have compile-time checks when registering an observer
	/// instead of run-time checks.
{
public:
	AbstractPriorityDelegate(void* pTarget, int prio):
		_pTarget(pTarget),
		_priority(prio)
	{
	}

	AbstractPriorityDelegate(const AbstractPriorityDelegate& del):
		_pTarget(del._pTarget),
		_priority(del._priority)
	{
	}

	virtual ~AbstractPriorityDelegate() 
	{
	}

	virtual bool notify(const void* sender, TArgs & arguments) = 0;
		/// Returns false, if the Delegate is no longer valid, thus indicating an expire

	virtual AbstractPriorityDelegate* clone() const = 0;
		// Returns a deep-copy of the object.

	bool operator < (const AbstractPriorityDelegate<TArgs>& other) const
		/// Operator used for comparing AbstractPriorityDelegates in a collection.
	{
		if (_priority == other._priority)
		{
			return _pTarget < other._pTarget;
		}

		return (_priority < other._priority);
	}

	void* target() const
	{
		return _pTarget;
	}

	int priority() const
	{
		return _priority;
	}

protected:
	void* _pTarget;
	int   _priority;
};


} // namespace Poco


#endif
