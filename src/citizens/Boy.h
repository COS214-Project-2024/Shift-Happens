#ifndef BOY_H
#define BOY_H

	class Boy : public Citizen {

	private:
		std::string Type;
		std::string Gender;
		bool School;

	public:
		// functions from citizen class
		std::string getType();
		std::string getGender();
		bool getStatus();
		void setType(std::string type);
		void setGender(std::string gender);
		void setStatus(bool status);
		void setSchool(bool status);
	};

#endif
