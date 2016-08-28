/*********************************************************************
 * Name:      	main.h
 * Purpose:   	Declares simple wxWidgets application with GUI
 * 				created using wxFormBuilder.
 * Author:    
 * Created:   
 * Copyright: 
 * License:   	wxWidgets license (www.wxwidgets.org)
 * 
 * Notes:		Note that all GUI creation code is declared in
 * 				gui.h source file which is generated by wxFormBuilder.
 *********************************************************************/
 
#ifndef __main__
#define __main__

// main wxWidgets header file
#include <wx/wx.h>
// gui classes generated by wxFormBuilder
#include "gui.h"
#include "wx/report/reportdocument.h"

////////////////////////////////////////////////////////////////////////////////
// application class declaration 
////////////////////////////////////////////////////////////////////////////////

class MainApp : public wxApp
{
    public:
        virtual bool OnInit();
};

// declare global static function wxGetApp()
DECLARE_APP(MainApp)

////////////////////////////////////////////////////////////////////////////////
// main application frame declaration 
////////////////////////////////////////////////////////////////////////////////

struct Student
{
    int id;
    wxString surname;
    wxString firstName;
    wxString degree;
    wxString field;
    int year;
};

struct LessonRecord
{
    wxString year;
    wxString name;
    wxString place;
    wxString form;
    int students;
};

WX_DECLARE_OBJARRAY(Student, ArrayOfStudents);

class MainDialog : public MainDialogBase
{
    public:
        MainDialog( wxWindow *parent );
        virtual ~MainDialog();
        wxReportDocument *report;
        ArrayOfStudents arrSt;
        LessonRecord lesson;
        
    protected:
        // protected event handlers
        virtual void OnCloseDialog( wxCloseEvent& event );
        virtual void OnGen1( wxCommandEvent& event );
        virtual void OnGen2( wxCommandEvent& event ) ;
        virtual void OnGen3( wxCommandEvent& event );
        virtual void OnPreview( wxCommandEvent& event );
        virtual void OnPrint( wxCommandEvent& event );
        virtual void OnXML( wxCommandEvent& event );
        //virtual void OnCloseDialog( wxCommandEvent& event );
};

#endif //__main__
