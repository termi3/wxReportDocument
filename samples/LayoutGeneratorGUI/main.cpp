/*********************************************************************
 * Name:      	main.cpp
 * Purpose:   	Implements simple wxWidgets application with GUI
 * 				created using wxFormBuilder.
 * Author:    
 * Created:   
 * Copyright: 
 * License:   	wxWidgets license (www.wxwidgets.org)
 * 
 * Notes:		Note that all GUI creation code is implemented in
 * 				gui.cpp source file which is generated by wxFormBuilder.
 *********************************************************************/

#include "main.h"
#include <wx/arrimpl.cpp>

// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation 
////////////////////////////////////////////////////////////////////////////////

bool MainApp::OnInit()
{
    SetTopWindow( new MainDialog( NULL ) );
    GetTopWindow()->Show();
    
    // true = enter the main loop
    return true;
}

////////////////////////////////////////////////////////////////////////////////
// main application frame implementation 
////////////////////////////////////////////////////////////////////////////////

WX_DEFINE_OBJARRAY(ArrayOfStudents);

MainDialog::MainDialog(wxWindow *parent) : MainDialogBase( parent )
{
    this->report = NULL;
    
    wxInitAllImageHandlers();
}

MainDialog::~MainDialog()
{
    if(report)
        delete report;
}

void MainDialog::OnCloseDialog(wxCloseEvent& event)
{
    Destroy();
}

void MainDialog::OnGen1(wxCommandEvent& event)
{
    if(report)
        delete report;
        
    report = new wxReportDocument();
    
    wxFont fontNadpis(16,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    wxFont fontNadpis1(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    wxFont fontText(12,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false);
    wxReportTextStyle nadpis(wxT(""),fontNadpis);
    wxReportTextStyle nadpis1(wxT(""),fontNadpis1);
    wxReportTextStyle textStyle(wxT(""),fontText);
    
    report->InsertPageNumbering(wxT("~%d~"), nadpis, wxRP_CENTER, 280);
    
    wxReportImageItem img(wxT(""), wxT("../../res/utb.png"), 0, 0, 300);
    report->AddItem(img);
    
    wxReportTextItem text;
    text.SetTextAlign(wxRP_RIGHTALIGN);
    text.SetPosition(0, 10);
    text.SetActiveTextStyle(nadpis1);
    text.SetSize(200, 10);
    text.AddText(wxT("Testovací stránka"));
    report->AddItem(text);
            
    wxReportLineShape line(0, 30, 220, 30);
    report->AddItem(line);
    
    text.ClearAllText();
    text.SetActiveTextStyle(textStyle);
    text.SetSize(80, 10);
    text.SetPosition(20, 40);
    text.SetTextAlign(wxRP_LEFTALIGN);
    text.AddText(wxT("Zarovnání zarovnán doleva Zarovnání doleva. Zarovnání doleva. doleva Zarovnání Text zarovnán doleva Zarovnání doleva. Zarovnání doleva. Text doleva Zarovnání zarovnán doleva."));
    text.AddNewLine();
    text.AddText(wxT("Zarovnání doleva. Text doleva Zarovnání doleva Zarovnání zarovnán doleva. Zarovnání doleva Zarovnání doleva. doleva Zarovnání Text zarovnán doleva. doleva Zarovnání Zarovnání doleva. Text zarovnán doleva."));
    report->AddItem(text);
    
    text.ClearAllText();
    text.SetFontColor(*wxBLUE);
    text.SetTextAlign(wxRP_RIGHTALIGN);
    text.SetPosition(-20, 40);
    text.SetSize(80, 10);
    text.AddText(wxT("Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava."));
    text.AddNewLine();
    text.AddText(wxT("Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava."));
    report->AddItem(text);
    
    wxReportLineShape line1(10, 125, 195, 125, 0.8, *wxRED);
    report->AddItem(line1);
    
    text.ClearAllText();
    text.SetPosition(wxRP_CENTER, 130);
    wxReportParagraphStyle parStyle;
    parStyle.SetBorder(wxRP_ALLBORDER, *wxBLACK, 0.25);
    text.SetActiveTextStyle(nadpis);
    text.SetActiveParagraphStyle(parStyle);
    text.SetTextAlign(wxRP_CENTERALIGN);
    text.AddText(wxT("Orámovaný text. ABCD EFGH abcd"));
    report->AddItem(text);
    
    text.ClearAllText();
    text.SetFontColor(*wxBLACK);
    parStyle.SetBorder(wxRP_ALLBORDER, *wxGREEN, 0.5);
    text.SetActiveParagraphStyle(parStyle);
    text.SetTextAlign(wxRP_RIGHTALIGN);
    text.SetPosition(wxRP_CENTER, 150);
    text.SetSize(80, 10);
    text.AddText(wxT("Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava."));
    text.AddNewLine();
    text.AddText(wxT("Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava. Zarovnání doprava. Text zarovnán doprava."));
    report->AddItem(text);
    
    report->AddPage();

    report->AddItem(img);
    
    wxReportTextItem text1;
    text1.SetTextAlign(wxRP_RIGHTALIGN);
    text1.SetPosition(0, 10);
    text1.SetActiveTextStyle(nadpis1);
    text1.SetSize(200, 10);
    text1.AddText(wxT("Tabulky"));
    report->AddItem(text1);
    report->AddItem(line);
    
    wxReportTableItem table;
    wxReportTextStyle cellsStyle;
    cellsStyle.SetBorder(wxRP_ALLBORDER);
    cellsStyle.SetFont(wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Times New Roman")));
    cellsStyle.SetBackgroundColor(wxColour(200, 200, 200));	
    table.SetCellsStyle(cellsStyle);
    table.SetPosition(wxRP_CENTER, 40);
    
    table.AddRow();
    for(int c=0; c<5; ++c)
        table.AddCellToRow(wxString::Format(wxT("Header %d"), c));
    
    cellsStyle.SetBackgroundColor(wxNullColour);
    table.SetCellsStyle(cellsStyle);
    for(int r=0; r<15; ++r)
    {
        table.AddRow();
        for(int c=0; c<5; ++c)
            table.AddCellToRow(wxString::Format(wxT("Cell %d.%d"), r+1, c+1));
    }
    
    for(int c=0; c<5; ++c)
        table.SetColumnWidth(c, 30);
    
    report->AddItem(table);
    
    wxReportTableItem table1;
    cellsStyle.SetBorder(wxRP_BOTTOMBORDER);
    cellsStyle.SetBorderColor(wxColour(200, 200, 200));
    cellsStyle.SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial")));
    cellsStyle.SetTextColor(*wxBLACK);
    cellsStyle.SetBackgroundColor(wxColour(200, 200, 200));	
    table1.SetCellsStyle(cellsStyle);
    table1.SetPosition(wxRP_CENTER, 150);
    table1.SetTextAlign(wxRP_CENTERALIGN);
    
    table1.AddRow();
    for(int c=0; c<5; ++c)
        table1.AddCellToRow(wxString::Format(wxT("Header %d"), c));
        
    //cellsStyle.SetBackgroundColor(wxNullColour);
    cellsStyle.SetBorder(0);
    cellsStyle.SetBorderColor(wxColour(210, 230, 160));
    cellsStyle.SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Times New Roman")));
    
    table1.SetCellsStyle(cellsStyle);
    for(int r=0; r<10; ++r)
    {
        if(r % 2 != 0)
        {
            cellsStyle.SetBackgroundColor(wxColour(210, 230, 160));
        }
        else
        {
            cellsStyle.SetBackgroundColor(wxNullColour);
        }
        
        table1.SetCellsStyle(cellsStyle);
        
        table1.AddRow();
        for(int c=0; c<5; ++c)
            table1.AddCellToRow(wxString::Format(wxT("Cell %d.%d"), r+1, c+1));
    }
    
    table1.SetColumnWidth(25);
    
    report->AddItem(table1);		
}

void MainDialog::OnGen2(wxCommandEvent& event)
{
    if(report)
        delete report;
        
    report = new wxReportDocument();
    
    for(int s=0; s<100; ++s)
    {
        Student st;
        st.id = s+1;
        st.firstName =wxT("John");
        st.surname = wxT("Doe");
        st.year = 2;
        st.degree = wxT("MSc.");
        st.field = wxT("IT");
        arrSt.Add(st);
    }
    
    lesson.year=wxT("2011/2012");
    lesson.place=wxT("Zlin");
    lesson.form=wxT("Daily");
    lesson.name=wxT("Artificial intelligence");
    lesson.students=arrSt.GetCount();
    
    wxReportPageStyle pageStyle;
    pageStyle.SetMargins(10, 10, 65, 20);
    report->SetPageStyle(pageStyle);
    
    wxFont font(18, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
    
    // creates the next text item object
    wxReportTextItem textHeader;
    
    // sets the current used font
    textHeader.SetFont(font);
    
    
    // adds text to the headers
    textHeader.SetTextAlign(wxRP_CENTERALIGN);
    textHeader.AddText(wxT("LIST OF STUDENTS"));
    report->AddItemToHeader(textHeader);
    
    font.SetPointSize(12);
    wxReportTextStyle numberingStyle(wxT(""), font);
    report->InsertPageNumbering(wxT("-%d-"), numberingStyle, wxRP_CENTER, 280);
    
    wxReportTextItem text;
    
    text.SetTextAlign(wxRP_LEFTALIGN);
    font.SetPointSize(12);
    text.SetFont(font);
    text.SetPosition(10, 20);
    text.AddText(wxT("Academical year:"));
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.AddVariable(lesson.year, wxT("Year"));
    text.SetPosition(50, 20);
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.SetPosition(10, 30);
    text.AddText(wxT("Lesson:"));
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.AddVariable(lesson.name, wxT("Lesson"));
    text.SetPosition(50, 30);
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.SetPosition(10, 40);
    text.AddText(wxT("Place of learning:"));
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.AddVariable(lesson.place, wxT("Place"));
    text.SetPosition(50, 40);
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.SetPosition(100, 40);
    text.AddText(wxT("Form"));
    report->AddItemToHeader(text);
        
    text.ClearAllText();
    text.AddVariable(lesson.form, wxT("Form"));
    text.SetPosition(120, 40);
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.SetPosition(150, 40);
    text.AddText(wxT("Students:"));
    report->AddItemToHeader(text);
    
    text.ClearAllText();
    text.AddVariable(lesson.students, wxT("Students"));
    text.SetPosition(170, 40);
    report->AddItemToHeader(text);
    
    wxReportLineShape line(10, 50, 200, 50);
    report->AddItemToHeader(line);
    
    //report->AddPage();
    
    wxReportTableItem tableHeaders;
    
    tableHeaders.CellsStyle().SetBorder(wxRP_ALLBORDER, *wxBLACK, 0.25);
    tableHeaders.SetTextAlign(wxRP_CENTERALIGN);
    tableHeaders.SetPosition(wxRP_CENTER, 55);
    tableHeaders.AddRow();
    tableHeaders.AddCellToRow(wxT("No."));
    tableHeaders.AddCellToRow(wxT("First name"));
    tableHeaders.AddCellToRow(wxT("Surname"));
    tableHeaders.AddCellToRow(wxT("Degree"));
    tableHeaders.AddCellToRow(wxT("Field of study"));
    tableHeaders.AddCellToRow(wxT("Semester"));
    tableHeaders.SetColumnWidth(30);
        
    report->AddItemToHeader(tableHeaders);
    
    wxReportTableItem table(wxT("StudentsTable"));
    font.SetPointSize(10);
    table.CellsStyle().SetFont(font);
    table.SetTextAlign(wxRP_CENTERALIGN);
    
    int sC = arrSt.GetCount();
    for(int s=0; s<sC; ++s)
    {
        if(s % 2 == 0)
        {
            table.CellsStyle().SetBackgroundColor(wxColour(210, 230, 160));
        }
        else
            table.CellsStyle().SetBackgroundColor(wxNullColour);//table.CellsStyle().SetBorder(0);
            
        Student st = arrSt[s];
        table.AddRow();
        table.AddCellToRow(s+1);
        table.AddCellToRow(st.firstName);
        table.AddCellToRow(st.surname);
        table.AddCellToRow(st.degree);
        table.AddCellToRow(st.field);
        table.AddCellToRow(st.year);
    }
    table.SetColumnWidth(30);
        
    table.CellsStyle().SetBackgroundColor(wxNullColour);
        
    table.SetPosition(wxRP_CENTER, 0);
    table.SynchronizeCellsSizes();
    report->AddItem(table);
    
    lesson.place=wxT("Praha");
    lesson.form=wxT("Combined");
    
    //now saves the content to an external file and erase them from the memory
    report->SaveLayoutToXML(wxT("out.xml"));
    delete report;
    //creates a new document and loads previously stored content
    report=new wxReportDocument();
    report->LoadLayoutFromXML(wxT("out.xml"));
    //connects variable values
    report->SetVariable(lesson.form, wxT("Form"));
    report->SetVariable(lesson.year, wxT("Year"));
    report->SetVariable(lesson.students, wxT("Students"));
    report->SetVariable(lesson.name, wxT("Lesson"));
    report->SetVariable(lesson.place, wxT("Place"));
}

void MainDialog::OnGen3(wxCommandEvent& event)
{
    if(report)
        delete report;
        
    report = new wxReportDocument();
    
    wxReportTextStyle txtStyle(wxT(""),wxFont(18, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Times New Roman")));
    txtStyle.SetTextColor(*wxBLUE);
    //txtStyle.SetBorder(wxRP_ALLBORDER, *wxGREEN, 0.6);
    //txtStyle.SetBackgroundColor(*wxRED);
    //wxReportStyle txtItemStyle;
    //txtItemStyle.SetBorder(wxRP_ALLBORDER, *wxBLUE, 0.7);
    wxReportTextItem txt;
    wxReportStyle itemStyle;
    itemStyle.SetBorder(wxRP_ALLBORDER, *wxGREEN, 0.6);
    itemStyle.SetBackgroundColor(*wxRED);
    //txt.SetSize(35, 0);
    txt.SetStyle(itemStyle);
    txt.SetActiveTextStyle(txtStyle);
    txt.SetTextAlign(wxRP_CENTERALIGN);
    txt.SetPosition(0, wxRP_BOTTOM);
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewLine();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    txt.AddNewParagraph();
    txt.AddText(wxT("ZKOUSKA ZKOUSKA ZKOUSKA ZKOUSKA"));
    report->AddItem(txt);
    
    /*// page settings 
    wxReportStyle rs;
    rs.SetBorder( wxRP_ALLBORDER );
    
    wxReportPageStyle pgs;
    pgs.SetWidth( 210 );
    pgs.SetHeight( 297 );
    pgs.SetMargins( 30, 10, 50, 10 );
    pgs.SetBorder( wxRP_ALLBORDER );
    
    report->SetPageStyle( pgs );
    
    // text items
    wxReportTextStyle ts( wxT("ts_title"), wxFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD) );
    
    wxReportParagraphStyle ps;
    ps.SetBorder( wxRP_ALLBORDER );
    ps.SetBorderColor( wxColour( 230, 230, 230) );
    ps.SetBackgroundColor( wxColour( 230, 230, 230) );
        
    wxReportTextItem ti;
    ti.SetStyle( rs );
    ti.SetActiveTextStyle( ts );
    ti.SetActiveParagraphStyle( ps );
    ti.SetSize( 100, 10 );
    ti.SetTextAlign( wxRP_CENTERALIGN );
    ti.SetPosition( wxRP_RIGHT, wxRP_TOP );
    ti.AddText( wxT("Hello World") );
    ti.AddNewLine();
    ti.AddText( wxT("Hello World Again") );
    ti.AddNewLine();
    ti.AddNewLine();
    ti.AddNewLine();
    ti.AddText( wxT("Hello World Again 2") );

    ti.AddNewParagraph();
    ps.SetBorder( wxRP_NOBORDER );
    ti.SetActiveParagraphStyle( ps );
    ti.SetTextAlign( wxRP_LEFTALIGN );
    ti.AddNewLine();
    ti.AddText( wxT("ID_VAR1") );
    
    report->AddItem( ti );
    
    ti.SetPosition( wxRP_LEFT, wxRP_BOTTOM );
    
    report->AddItem( ti );
    
    ti.SetPosition( wxRP_CENTER, wxRP_CENTER );
    
    report->AddItem( ti );
    
    // table items
    wxReportTableItem table;
    table.CellsStyle().SetBorder( wxRP_ALLBORDER, *wxBLACK, 0.25 );
    table.SetTextAlign( wxRP_CENTERALIGN );
    table.SetPosition( wxRP_CENTER, 110 );
    table.AddRow();
    table.AddCellToRow( wxT("First name") );
    table.AddCellToRow( wxT("Surname") );
    table.SetColumnWidth( 30 );
    
    report->AddItem( table );
    
    // images
    wxReportImageStyle is;
    is.SetBorder( wxRP_ALLBORDER, wxColour(100, 100, 100), 0.35 );
    
    wxReportImageItem img;
    img.SetPath( wxT("../../res/utb.png") );
    img.SetPosition( 0, 0 );
    img.SetPPI( 400 );
    img.SetStyle( is );
    
    report->AddItem( img );
    
    // shapes
    wxReportCircleShape circle;
    circle.SetCentreCoord( 20, 45 );
    circle.SetRadius( 20 );
    circle.SetFillColor( *wxRED );
    
    report->AddItem( circle );
    
    wxReportRectangleShape rect;
    rect.SetTopLeftCorner( 0, 70 );
    rect.SetWidth( 100 );
    rect.SetHeight( 50 );
    rect.SetFillColor( *wxGREEN );
    rect.SetLineThickness( 0.3 );
    
    report->AddItem( rect );
    
    wxReportLineShape line;
    wxRealPoint target = pgs.GetSize() - wxRealPoint( pgs.GetLeftMargin() + pgs.GetRightMargin(),
                                                    pgs.GetTopMargin() + pgs.GetBottomMargin() );
    line.SetPoints( wxRealPoint(0, 0), target );
    line.SetLineStyle( wxDOT_DASH );
    
    report->AddItem( line );*/
    
}

void MainDialog::OnPreview(wxCommandEvent& event)
{
    if(report)
        report->ShowPrintPreview(this);
}

void MainDialog::OnPrint(wxCommandEvent& event)
{
    if(report)
        report->Print(this);
}

void MainDialog::OnXML(wxCommandEvent& event)
{
    wxFileDialog dlg(this, wxT("Save file"), wxEmptyString, wxEmptyString, wxT("XML files (*.xml)|*.xml"), wxFD_SAVE);
    
    if(report)
        if(dlg.ShowModal() == wxID_OK)
        {
            report->SaveLayoutToXML(dlg.GetPath());
        }	
}

