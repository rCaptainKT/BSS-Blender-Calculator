#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/spinctrl.h>
#include <string>
#include <vector>
#include <map>

#ifndef RECIPE_BOOK
	#include "recipebook.h"
#endif
#ifndef CALCULATOR
	#include "blendercalculator.h"
#endif

class MainFrame : public wxFrame {
	public:
		// Methods
		MainFrame(const wxString &title);
	private:
		// Members
		wxPanel *panel;
		wxBoxSizer *boxSizer;
		wxGridBagSizer *gridBagSizer;
		BlenderCalculator calculator;
		RecipeBook recipeBook;
		std::vector<wxSpinCtrl*> inputControls;
		std::vector<wxSpinCtrl*> inventoryControls;
		std::vector<wxTextCtrl*> outputControls;
		int rowCount;

		// Methods
		void addBaseItem(const std::string &itemName);
		void addBlenderItem(const std::string &itemName);
		void onInputChanged(wxCommandEvent &event);
		std::map<std::string, int> *getInput();
		void setOutput(std::map<std::string, long long> *output);
		void onExclusionChanged(wxCommandEvent &event);
		std::map<std::string, long long> *getInventory();
};

