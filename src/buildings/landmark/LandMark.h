#ifndef LANDMARK_H
#define LANDMARK_H

namespace Building_State {
	class LandMark : Building_State::Building {

	public:
		int satisfactionScore;

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);
	};
}

#endif
