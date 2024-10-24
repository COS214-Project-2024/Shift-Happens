#ifndef LOWTAX_H
#define LOWTAX_H

namespace Building_State {
	class LowTax : Building_State::Tax {


	public:
		void higher();

		void lower();
	};
}

#endif
