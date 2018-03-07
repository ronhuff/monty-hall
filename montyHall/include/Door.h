#pragma once
class Door
{
public:
	Door();
	~Door();


	void setHasCar(bool);
	void setHasGoat(bool);
	void setIsOpen(bool);

	bool getHasCar() const;
	bool getHasGoat() const;
	bool getIsOpen() const;

private:
	bool m_hasCar;
	bool m_hasGoat;
	bool m_isOpen;
};

