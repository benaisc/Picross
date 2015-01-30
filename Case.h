#ifndef __CASE_H__
#define __CASE_H__


class Case
{
private:
	enum ind {0, 1, -1};//0=0, 1=1, -1=2
public:
	Case();
	~Case();

	int valeur() const;
};
#endif