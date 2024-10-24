#ifndef MAN_H
#define MAN_H

namespace Building_State {
	class Man : Building_State::Citizen {

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
