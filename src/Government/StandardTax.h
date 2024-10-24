#ifndef STANDARDTAX_H
#define STANDARDTAX_H

namespace Building_State {
	class StandardTax : Building_State::Tax {


	public:
		void higher();

		void lower();
	};
}

#endif
