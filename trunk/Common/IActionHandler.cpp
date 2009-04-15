///////////////////////////////////////////////////////////
//  IActionHandler.cpp
//  Implementation of the Class IActionHandler
//  Created on:      02-Apr-2009 18:09:50
//  Original author: Tim Kuo
///////////////////////////////////////////////////////////
#include "IActionHandler.h"
#include "IEventObserver.h"
#include "Message.h"

void IActionHandler::SetObserver(IEventObserver* observer){
	list<IEventObserver*>::iterator it = m_listObserver.begin();

	while(m_listObserver.end() != it) {
		if(*it == observer) return;
		it++;
	}
	
	m_listObserver.push_back(observer);
	DBINFO("one observer inserted:", (int*)observer);
}

void IActionHandler::BroadcastEvent(Message& ev){
	list<IEventObserver*>::const_iterator it = m_listObserver.begin();
	while(m_listObserver.end() != it) {
		if(NULL != *it) {
			(*it)->OnEvent(ev);
			DBINFO("one message broadcasted to:", (int*)(*it));
		}
		it++;
	}
}

void IActionHandler::DeregisterObserver(IEventObserver* observer){
	m_listObserver.remove(observer);
}