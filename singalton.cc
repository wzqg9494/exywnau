#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

class Singalton
{
private:
	class Aotu
	{
	public:
		Aotu()
		{
			cout << "Auto" << endl;
		}
		~Aotu()
		{
			cout << "~Auto" << endl;
			if(_pinstance)
				delete _pinstance;
		}
	};
private:

	Singalton()
	{
		cout << "Singalton()" << endl;
	}

	~Singalton()
	{
		cout << "~Singalton()" << endl;
	}

public:
	static Singalton * getInstance()
	{
		if(_pinstance == NULL)
		{
			_pinstance = new Singalton;
		}
		return _pinstance;
	}
private:
	static Singalton * _pinstance;
	static Aotu _auto;
};

Singalton* Singalton::_pinstance = new Singalton;
Singalton::Aotu Singalton::_auto;
int main()
{
	Singalton * p1 = Singalton::getInstance();
	Singalton * p2 = Singalton::getInstance();
	Singalton * p3 = Singalton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);
	return 0;
}
