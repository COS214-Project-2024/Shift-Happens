#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

namespace Building_State {
	class ResidentialBuilding : Building_State::Building {

	private:
		int capacity;
		int satisfactionScore;
		int incomePerHour;

	public:
		int getCapacity();

		void setCapacity(int capacity);

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);

		int getIncomePerHour();

		void setIncomePerHour(int incomePerHour);
	};
}

#endif
