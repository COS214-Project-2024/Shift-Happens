#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

namespace Building_State {
	class IndustrialBuilding : Building_State::Building {

	private:
		int numberOfEmployees;
		int satisfactionScore;

	public:
		int getNumberOfEmployees();

		void setNumberOfEmployees(int numberOfEmployees);

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);
	};
}

#endif
