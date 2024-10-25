#ifndef GIRL_H
#define GIRL_H

	class Girl : public Citizen {

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
