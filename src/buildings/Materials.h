#ifndef MATERIALS_H
#define MATERIALS_H

namespace Building_State {
	class Materials {

	private:
		string description;
		double cost;
		int quantity;
		vector<Building_State::Materials*> components[];

	public:
		void getAvailableMaterials();

		void getMaterialSaleRecords();
	};
}

#endif
