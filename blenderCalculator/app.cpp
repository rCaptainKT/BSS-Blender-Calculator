#include <wx/wx.h>

#include "app.h"
#ifndef MAINFRAME
	#include "mainframe.h"
#endif

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame *mainFrame = new MainFrame("BSS Blender Calculator");
	mainFrame->Show();
	mainFrame->SetFocus();
	return true;
}
