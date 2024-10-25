#ifndef BOY_H
#define BOY_H

	class Boy : public Citizen {

	private:
		std::string Type;
		std::string Gender;
		bool School;

	public:
		void setType(std::string type);

		void setGender(std::string gender);

		void setSchool(bool status);
	};

#endif
