#ifndef HIGHTAX_H
#define HIGHTAX_H

namespace Building_State {
	class HighTax : Building_State::Tax {


	public:
		void higher();

		void lower();
	};
}

#endif
