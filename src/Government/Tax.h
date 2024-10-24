#ifndef TAX_H
#define TAX_H

namespace Building_State {
	class Tax {


	public:
		virtual void higher() = 0;

		virtual void lower() = 0;
	};
}

#endif
