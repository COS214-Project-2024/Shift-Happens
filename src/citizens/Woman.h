#ifndef WOMAN_H
#define WOMAN_H

namespace Building_State {
	class Woman : Building_State::Citizen {

	private:
		string Type;
		string Gender;
		boolean Employment;

	public:
		void setType(string type);

		void setGender(string gender);

		void setEmployment(boolean status);
	};
}

#endif
