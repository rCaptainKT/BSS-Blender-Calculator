#include <wx/wx.h>
#include <wx/gbsizer.h>
#include <wx/spinctrl.h>
#include <vector>
#include <string>

#include "mainframe.h"
#ifndef CALCULATOR
	#include "blendercalculator.h"
#endif

#ifndef MAINFRAME
	#define MAINFRAME
#endif

MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title) {
	panel = new wxPanel(this);
	boxSizer = new wxBoxSizer(wxVERTICAL);
	gridBagSizer = new wxGridBagSizer(3, 5);

	// Add Headers (Base Items)
	wxStaticText *inventoryHeader = new wxStaticText(panel, wxID_ANY, "INVENTORY");
	wxStaticText *neededHeader = new wxStaticText(panel, wxID_ANY, "NEEDED");
	gridBagSizer->Add(inventoryHeader, wxGBPosition(rowCount, 2), wxGBSpan(1, 1), wxEXPAND | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL);
	gridBagSizer->Add(neededHeader, wxGBPosition(rowCount, 4), wxGBSpan(1, 1), wxEXPAND | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL);
	rowCount++;

	// Add Base Items
	for (std::vector<std::string>::iterator itr = recipeBook.getBaseItems()->begin(); itr != recipeBook.getBaseItems()->end(); itr++) {
		addBaseItem(*itr);
	}

	// Gap
	rowCount++;

	// Add Headers (Blender Items)
	wxStaticText *exclusionHeader = new wxStaticText(panel, wxID_ANY, "EXCLUDE");
	wxStaticText *quantityHeader2 = new wxStaticText(panel, wxID_ANY, "QUANTITY");
	wxStaticText *inventoryHeader2 = new wxStaticText(panel, wxID_ANY, "INVENTORY");
	wxStaticText *neededHeader2 = new wxStaticText(panel, wxID_ANY, "NEEDED");
	gridBagSizer->Add(exclusionHeader, wxGBPosition(rowCount, 0), wxGBSpan(1, 1), wxEXPAND | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL);
	gridBagSizer->Add(quantityHeader2, wxGBPosition(rowCount, 1), wxGBSpan(1, 1), wxEXPAND | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL);
	gridBagSizer->Add(inventoryHeader2, wxGBPosition(rowCount, 2), wxGBSpan(1, 1), wxEXPAND | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL);
	gridBagSizer->Add(neededHeader2, wxGBPosition(rowCount, 4), wxGBSpan(1, 1), wxEXPAND | wxALIGN_BOTTOM | wxALIGN_CENTER_HORIZONTAL);
	rowCount++;;

	// Add Blender Items
	for (std::vector<std::string>::iterator itr = recipeBook.getBlenderItems()->begin(); itr != recipeBook.getBlenderItems()->end(); itr++) {
		addBlenderItem(*itr);
	}

	// Add Sizers
	boxSizer->Add(gridBagSizer, wxSizerFlags().Expand().Border(wxALL, 10));
	panel->SetSizer(boxSizer);
	boxSizer->SetSizeHints(this);

	// Set Frame
	SetClientSize(800, 600);
	Center();
}

void MainFrame::addBaseItem(const std::string &itemName) {
	wxSize defaultSize = wxSize(75, 20);
	wxSize labelSize = defaultSize + wxSize(25, 0);

	// Inventory Control
	wxSpinCtrl *input = new wxSpinCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, defaultSize, wxSP_ARROW_KEYS | wxALIGN_RIGHT, 0, 999999999);
	input->SetName(wxString(itemName).Lower());
	input->Bind(wxEVT_SPINCTRL, &MainFrame::onInputChanged, this);
	gridBagSizer->Add(input, wxGBPosition(rowCount, 2), wxGBSpan(1, 1), wxEXPAND);
	inventoryControls.insert(inventoryControls.end(), input);

	// Label
	wxStaticText *label = new wxStaticText(panel, wxID_ANY, itemName, wxDefaultPosition, labelSize, wxALIGN_LEFT);
	gridBagSizer->Add(label, wxGBPosition(rowCount, 3), wxGBSpan(1, 1), wxEXPAND);

	// Output Control
	wxTextCtrl *output = new wxTextCtrl(panel, wxID_ANY, std::to_string(0), wxDefaultPosition, defaultSize, wxTE_READONLY | wxALIGN_RIGHT);
	output->SetBackgroundColour(*wxWHITE);
	output->SetName(wxString(itemName).Lower());
	output->Disable();
	gridBagSizer->Add(output, wxGBPosition(rowCount++, 4), wxGBSpan(1, 1), wxEXPAND);
	outputControls.insert(outputControls.end(), output);
}

void MainFrame::addBlenderItem(const std::string &itemName) {
	wxSize defaultSize = wxSize(75, 20);
	wxSize labelSize = defaultSize + wxSize(25, 0);
	
	// Exclusion Control
	wxCheckBox *exclusion = new wxCheckBox(panel, wxID_ANY, wxEmptyString);
	exclusion->SetName(wxString(itemName).Lower());
	exclusion->Bind(wxEVT_CHECKBOX, &MainFrame::onExclusionChanged, this);
	gridBagSizer->Add(exclusion, wxGBPosition(rowCount, 0), wxGBSpan(1, 1), wxEXPAND | wxALIGN_CENTER_HORIZONTAL);

	// Input Control
	wxSpinCtrl *input1 = new wxSpinCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, defaultSize,
		wxSP_ARROW_KEYS | wxALIGN_RIGHT, 0, 999999999);
	input1->SetName(wxString(itemName).Lower());
	input1->Bind(wxEVT_SPINCTRL, &MainFrame::onInputChanged, this);
	gridBagSizer->Add(input1, wxGBPosition(rowCount, 1), wxGBSpan(1, 1), wxEXPAND);
	inputControls.insert(inputControls.end(), input1);

	// Inventory Control
	wxSpinCtrl *input2 = new wxSpinCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, defaultSize,
		wxSP_ARROW_KEYS | wxALIGN_RIGHT, 0, 999999999);
	input2->SetName(wxString(itemName).Lower());
	input2->Bind(wxEVT_SPINCTRL, &MainFrame::onInputChanged, this);
	gridBagSizer->Add(input2, wxGBPosition(rowCount, 2), wxGBSpan(1, 1), wxEXPAND);
	inventoryControls.insert(inventoryControls.end(), input2);

	// Label
	wxStaticText *label = new wxStaticText(panel, wxID_ANY, itemName, wxDefaultPosition, labelSize, wxALIGN_LEFT);
	gridBagSizer->Add(label, wxGBPosition(rowCount, 3), wxGBSpan(1, 1), wxEXPAND);

	// Output Control
	wxTextCtrl *output = new wxTextCtrl(panel, wxID_ANY, std::to_string(0), wxDefaultPosition, defaultSize, wxTE_READONLY | wxALIGN_RIGHT);
	output->SetBackgroundColour(*wxWHITE);
	output->SetName(wxString(itemName).Lower());
	output->Disable();
	gridBagSizer->Add(output, wxGBPosition(rowCount++, 4), wxGBSpan(1, 1), wxEXPAND);
	outputControls.insert(outputControls.end(), output);
}

void MainFrame::onInputChanged(wxCommandEvent &event) {
	std::map<std::string, int> *input = getInput();
	std::map<std::string, long long> *inventory = getInventory();
	std::map<std::string, long long> output = calculator.calculate(input, inventory);
	setOutput(&output);
	delete input;
	delete inventory;
}

std::map<std::string, int> *MainFrame::getInput() {
	std::map<std::string, int> *input = new std::map<std::string, int>();

	for (std::vector<wxSpinCtrl*>::iterator itr = inputControls.begin(); itr != inputControls.end(); itr++) {
		(*input)[(*itr)->GetName().ToStdString()] = (*itr)->GetValue();
	}

	return input;
}

void MainFrame::setOutput(std::map<std::string, long long> *output) {
	for (std::vector<wxTextCtrl*>::iterator itr = outputControls.begin(); itr != outputControls.end(); itr++) {
		long long value = (*output)[(*itr)->GetName().ToStdString()];
		(*itr)->SetValue(wxString(std::to_string(value)));
		if (value) {
			(*itr)->Enable();
		}else {
			(*itr)->Disable();
		}
	}
}

void MainFrame::onExclusionChanged(wxCommandEvent &event) {
	wxCheckBox *control = wxStaticCast(event.GetEventObject(), wxCheckBox);
	if (event.IsChecked()) {
		calculator.addToExclusions(control->GetName().ToStdString());
	}else {
		calculator.removeFromExclusions(control->GetName().ToStdString());
	}
	onInputChanged(event);
}

std::map<std::string, long long> *MainFrame::getInventory() {
	std::map<std::string, long long> *inventory = new std::map<std::string, long long>();

	for (std::vector<wxSpinCtrl *>::iterator itr = inventoryControls.begin(); itr != inventoryControls.end(); itr++) {
		(*inventory)[(*itr)->GetName().ToStdString()] = (*itr)->GetValue();
	}

	return inventory;
}
