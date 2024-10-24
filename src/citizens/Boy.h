#ifndef BOY_H
#define BOY_H

namespace Building_State {
	class Boy : Building_State::Citizen {

	private:
		string Type;
		string Gender;
		boolean School;

	public:
		void setType(string type);

		void setGender(string gender);

		void setSchool(boolean status);
	};
}

#endif
