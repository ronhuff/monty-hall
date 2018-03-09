#pragma once
class Door
{
public:
	Door();
	~Door();


	void setHasCar(bool);
	void setHasGoat(bool);


	bool getHasCar() const;
	bool getHasGoat() const;
	

private:
	bool m_hasCar;
	bool m_hasGoat;
};

