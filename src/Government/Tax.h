#ifndef TAX_H
#define TAX_H

#include "Government.h"

#include <iostream>

	class Tax {
	private:
	
	protected:
		Government* government;

	public:
		virtual void higher() = 0;

		virtual void lower() = 0;
	};

#endif
