#pragma once
class Door
{
public:
	Door();
	~Door();


	void setHasCar(bool);


	bool getHasCar() const;
	

private:
	bool m_hasCar;
};

