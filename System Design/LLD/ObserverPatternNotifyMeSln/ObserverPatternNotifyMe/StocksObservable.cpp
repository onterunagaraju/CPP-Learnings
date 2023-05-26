#include<iostream>
#include<vector>

//class NotificationAlertObserver;

class StocksObservable;

int GetCount(StocksObservable* observable);

class NotificationAlertObserver
{
public:
	virtual void Update() = 0;
};

class EmailNotificationAlertObserver : public NotificationAlertObserver
{
	StocksObservable* observable;
	std::string email;
public:
	EmailNotificationAlertObserver(StocksObservable* observable, std::string email) : observable{ observable }, email{ email } {}

	void Update() override
	{
		std::cout << "Notified throgh email : " << email << " and the stock count is " << GetCount(observable) << std::endl;
	}
};

class MobileNotificationAlertObserver : public NotificationAlertObserver
{
	StocksObservable* observable;
	std::string mobileNo;
public:
	MobileNotificationAlertObserver(StocksObservable* observable, std::string mobileNo) : observable{ observable }, mobileNo{ mobileNo } {}

	void Update() override
	{
		std::cout << "Notified Through MobileNo : " << mobileNo << " and the stock count is " << GetCount(observable) << std::endl;
	}
};


class StocksObservable
{
public:
	virtual void Add(NotificationAlertObserver* obj) = 0;
	virtual void Remove(NotificationAlertObserver* obj) = 0;
	virtual void NotifySubscribers() = 0;
	virtual void SetStockCount(int stockCount) = 0;
	virtual int GetStockCount() = 0;
};

class IPhoneStockObservable : public StocksObservable
{
	std::vector<NotificationAlertObserver*> observersList;
	int stockCount = 0;
public:
	void Add(NotificationAlertObserver* observer) override
	{
		observersList.push_back(observer);
	}

	void Remove(NotificationAlertObserver* observer) override
	{
		observersList.erase(find(observersList.begin(), observersList.end(), observer));
	}

	void NotifySubscribers() override
	{
		for (auto* observer : observersList)
		{
			observer->Update();
		}
	}

	void SetStockCount(int count) override
	{
		if (stockCount == 0)
		{
			stockCount += count;
			NotifySubscribers();
			return;
		}
		stockCount += count;
	}

	int GetStockCount() override
	{
		return stockCount;
	}
};


int GetCount(StocksObservable* observable)
{
	return observable->GetStockCount();
}


int main()
{
	StocksObservable* observable = new IPhoneStockObservable();

	NotificationAlertObserver* observer1 = new EmailNotificationAlertObserver(observable, "naga@email.com");
	NotificationAlertObserver* observer2 = new EmailNotificationAlertObserver(observable, "raju@email.com");
	NotificationAlertObserver* observer3 = new MobileNotificationAlertObserver(observable, "91821747619");

	observable->Add(observer1);
	observable->Add(observer2);
	observable->Add(observer3);

	observable->SetStockCount(10);
	observable->SetStockCount(-10);
	observable->SetStockCount(20);
	return 0;
}