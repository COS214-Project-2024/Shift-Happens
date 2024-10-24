#ifndef GIRL_H
#define GIRL_H

namespace Building_State {
	class Girl : Building_State::Citizen {

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
