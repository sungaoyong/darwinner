#ifndef BUSINESSWINDOW_H
#define BUSINESSWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_BusinessWindow.h"
#include "DUIObserver.h"
#include "Business.h"
#include "BusinessType.h"
#include "common.h"
#include <list>
#include <map>
class SearchBox;
class BusinessDetailWidget;
class QByteArray;
class QEvent;
using namespace std;

typedef map<uint32, BusinessType> BusinessTypeArray;

class BusinessWindow : public QMainWindow, public DUIObserver
{
    Q_OBJECT
    Q_DISABLE_COPY(BusinessWindow)
public:
    explicit BusinessWindow(QWidget *parent = 0);
    virtual ~BusinessWindow();
	bool event(QEvent* ev);
	void OnEvent(Message& Msg);

protected:
    virtual void changeEvent(QEvent *e);
	virtual bool eventFilter(QObject* obj, QEvent* ev);

private:
	Ui::BusinessWindowClass ui;
	void addBusiness2View(list<Business>* data);
	void businessTypeSetting();
	void getAllBusiness();
	void getBusiness(uint32 id);
	void getBusinessType();
	void removeBusiness(uint32 id);
	void Exit();
	void Logoff();
	void Menu();
	void showSmallIcon(bool flag);
	void showTextLabel(bool flag);
	void showToolBar(bool flag);
	void typeSetting();

	SearchBox*  m_searchBox;
	BusinessDetailWidget* m_detailWidget;
	BusinessTypeArray m_businessTypeCache;
	bool m_started;
	ArrayUint32String* m_businessTypeNames;

private slots:
	void dealAction(QAction* action);
	void viewItemActivated(int row, int column, QVariant & data);
	void addBusiness(Business* business, QByteArray& image);
	void modifyBusiness(Business* business, QByteArray& image);
	void setBusinessType(list<BusinessType>* data);
};

#endif // BUSINESSWINDOW_H