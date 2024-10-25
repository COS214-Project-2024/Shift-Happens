#ifndef BOY_H
#define BOY_H

namespace Building_State {
	class Boy : public Building_State::Citizen {

	private:
		std::string Type;
		std::string Gender;
		bool School;

	public:
		void setType(std::string type);

		void setGender(std::string gender);

		void setSchool(bool status);
	};
}

#endif
