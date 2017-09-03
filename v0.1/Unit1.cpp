//---------------------------------------------------------------------------

#include <vcl.h>
#include <vcl\Clipbrd.hpp>
#include <string.h>
#include <iostream>
#include <locale>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

#define MAX_AMOUNT_DATA 1024
#define DATA_WIDTH 8
#define DATA_TYPES 22
#define EDT             0
#define T15             1
#define T20             2
#define XIT20           3
#define T30             4
#define XIT30           5
#define Curvature       6
#define Ts              7
#define SPL             8
#define SPLAf           9
#define SPLDirect       10
#define D50             11
#define C7              12
#define C50             13
#define C80             14
#define U50             15
#define U80             16
#define MTICorrected    17
#define LF80            18
#define LFC80           19
#define Diffusivityss   20
#define EchoDietsch     21

double dataSet[MAX_AMOUNT_DATA][DATA_WIDTH][DATA_TYPES];
int parsedCounter = 0;
int lastTypeDisplayed = -1;
char decimalPointChar;

void ProcessReadText(void);
void ClearClipboard(void);
void ParseLine(int dataType, AnsiString * inputLine);
void SetStatusText(AnsiString text);
void SetParsedCounter(int value);
void InitializeDataSet(void);
void AddNewDataRow(int dataType, AnsiString dataString);
void UpdateShownText(void);
char findDecimalPointChar(void);

char findDecimalPointChar(void)
{
    AnsiString * _testString = new AnsiString("123.45");
    char _foundDecimalChar;
    try
    {
        _testString->ToDouble();
        _foundDecimalChar = '.';
    }
    catch(Exception &ex)
    {
        _foundDecimalChar = ',';
    }
    return _foundDecimalChar;
}

void InitializeDataSet(void)
{
    for(int i = 0; i < MAX_AMOUNT_DATA; i++)
    {
        for(int j = 0; j < DATA_WIDTH; j++)
        {
            for(int k = 0; k < DATA_TYPES; k++)
            {
                dataSet[i][j][k] = 0;
            }
        }
    }
}

void ClearClipboard(void)
{
   TClipboard *pCB = Clipboard();
   pCB->Clear();
}

void CheckClipboardForText(void)
{
    try
    {
        MainForm->InputText->PasteFromClipboard();
        if(MainForm->InputText->Lines->Count > 0)
        {
            ProcessReadText();
            MainForm->InputText->Clear();
            ClearClipboard();
        }
    }
    catch(Exception &ex)
    { }
}

void __fastcall TMainForm::PasteTextButtonClick(TObject *Sender)
{
    CheckClipboardForText();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AutoPasteCheckBoxClick(TObject *Sender)
{
    TimerAutoPaste->Enabled = AutoPasteCheckBox->Checked;    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TimerAutoPasteTimer(TObject *Sender)
{
    CheckClipboardForText();
}

void SetParsedCounter(int value)
{
    MainForm->StatusBar->Panels[0][0]->Text = (AnsiString)"Parsed: " + value;
}

void SetStatusText(AnsiString text)
{
    MainForm->StatusBar->Panels[0][1]->Text = text;
}

void ProcessReadText(void)
{
    SetStatusText("Parsing text ...");

    try
    {
        bool _parsedSuccessfully = False;

        // Check if it's a set of points
        // if a line with "Statistics for frequency parameters" is found
        int _lineNumber = MainForm->InputText->Lines->IndexOf("Statistics for frequency parameters");
        if ((_lineNumber >= 0) && (MainForm->InputText->Lines->Count >= _lineNumber +51))
        {
            // Read EDT (+7)
            _lineNumber += 7;
            ParseLine(EDT, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read T15
            _lineNumber += 11;
            ParseLine(T15, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read T20
            _lineNumber += 11;
            ParseLine(T20, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read XIT20
            _lineNumber += 11;
            ParseLine(XIT20, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read T30
            _lineNumber += 11;
            ParseLine(T30, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read XIT30
            _lineNumber += 11;
            ParseLine(XIT30, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read Curvature
            _lineNumber += 11;
            ParseLine(Curvature, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read Ts
            _lineNumber += 11;
            ParseLine(Ts, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read SPL
            _lineNumber += 11;
            ParseLine(SPL, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read SPL Af
            _lineNumber += 11;
            ParseLine(SPLAf, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read SPL Direct
            _lineNumber += 11;
            ParseLine(SPLDirect, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read D50
            _lineNumber += 11;
            ParseLine(D50, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read C7
            _lineNumber += 11;
            ParseLine(C7, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read C50
            _lineNumber += 11;
            ParseLine(C50, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read C80
            _lineNumber += 11;
            ParseLine(C80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read U50
            _lineNumber += 11;
            ParseLine(U50, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read U80
            _lineNumber += 11;
            ParseLine(U80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read MTICorrected
            _lineNumber += 11;
            ParseLine(MTICorrected, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read LF80
            _lineNumber += 11;
            ParseLine(LF80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read LFC80
            _lineNumber += 11;
            ParseLine(LFC80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read Diffusivity
            _lineNumber += 11;
            ParseLine(Diffusivityss, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            // Read EchoDietsch
            _lineNumber += 11;
            ParseLine(EchoDietsch, &(MainForm->InputText->Lines->Strings[_lineNumber]));

            _parsedSuccessfully = True;
        }
        else
        {
            // if not, maybe it's a single receiver point, try finding the
            // line with the frequency bands text
            _lineNumber = MainForm->InputText->Lines->IndexOf("Band (Hz)                   63       125       250       500      1000      2000      4000      8000");
            if((_lineNumber >= 0) && (MainForm->InputText->Lines->Count >= _lineNumber +6))
            {

                // Read EDT (+2)
                _lineNumber += 2;
                ParseLine(EDT, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read T15
                _lineNumber += 1;
                ParseLine(T15, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read T20
                _lineNumber += 1;
                ParseLine(T20, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read XIT20
                _lineNumber += 1;
                ParseLine(XIT20, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read T30
                _lineNumber += 1;
                ParseLine(T30, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read XIT30
                _lineNumber += 1;
                ParseLine(XIT30, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read Curvature
                _lineNumber += 1;
                ParseLine(Curvature, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read Ts
                _lineNumber += 1;
                ParseLine(Ts, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read SPL
                _lineNumber += 1;
                ParseLine(SPL, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read SPL Af
                _lineNumber += 1;
                ParseLine(SPLAf, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read SPL Direct
                _lineNumber += 1;
                ParseLine(SPLDirect, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read D50
                _lineNumber += 1;
                ParseLine(D50, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read C7
                _lineNumber += 1;
                ParseLine(C7, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read C50
                _lineNumber += 1;
                ParseLine(C50, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read C80
                _lineNumber += 1;
                ParseLine(C80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read U50
                _lineNumber += 1;
                ParseLine(U50, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read U80
                _lineNumber += 1;
                ParseLine(U80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read MTICorrected
                _lineNumber += 1;
                ParseLine(MTICorrected, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read LF80
                _lineNumber += 1;
                ParseLine(LF80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read LFC80
                _lineNumber += 1;
                ParseLine(LFC80, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read Diffusivity
                _lineNumber += 1;
                ParseLine(Diffusivityss, &(MainForm->InputText->Lines->Strings[_lineNumber]));

                // Read EchoDietsch
                _lineNumber += 1;
                ParseLine(EchoDietsch, &(MainForm->InputText->Lines->Strings[_lineNumber]));


                _parsedSuccessfully = True;
            }
        }

        if(_parsedSuccessfully)
        {
            parsedCounter++;
            SetParsedCounter(parsedCounter);
            UpdateShownText();
        }
        SetStatusText("");
    }
    catch (Exception &ex)
    {
        MainForm->StatusBar->SimpleText = "Exception encountered while parsing! Report bug.";
    }
}

void ParseLine(int dataType, AnsiString * inputLine)
{
    /*
    Two types of lines expected:

    "Average                  0,89      0,78      0,51      0,36      0,36      0,32      0,31      0,23 "
    "T(20)           (s)      0,78      0,68      0,38      0,35      0,35      0,36      0,26      0,20 "
    */

    // Parse line here
    if(inputLine == NULL)
        return;

    char * _returnedLine;
    _returnedLine = (char *)malloc(sizeof(char) * 256);
    if(_returnedLine == NULL)
    {
        ShowMessage("Could not allocate memory for _returnedLine");
        return;
    }
    _returnedLine[0] = '\0';

    AnsiString * _parsingString = new AnsiString();
    if(_parsingString == NULL)
    {
        ShowMessage("Could not allocate memory for _parsingString");
        return;
    }

    char * _tempString;
    _tempString = (char *)malloc(sizeof(char) * 256);
    if(_tempString == NULL)
    {
        ShowMessage("Could not allocate memory for _tempString");
        return;
    }

    unsigned int _counter;

    // Trim line for spaces
    inputLine->sprintf(inputLine->TrimLeft().c_str());
    inputLine->sprintf(inputLine->TrimRight().c_str());

    // Reverse string
    char * _reversedString;
    _reversedString = (char *)malloc(sizeof(char) * 256);
    if(_reversedString == NULL)
    {
        ShowMessage("Could not allocate memory for _reversedString");
        return;
    }

    for(int i=0; i < inputLine->Length(); i++)
    {
        _reversedString[i] = inputLine->c_str()[inputLine->Length()-1 - i];
    }
    _reversedString[inputLine->Length()] = '\0';

    // Separate the numbers
    char * _newNumber;
    int _readNumbers = 0, j = 0;
    _newNumber = (char *)malloc(sizeof(char) * 256);
    if(_newNumber == NULL)
    {
        ShowMessage("Could not allocate memory for _newNumber");
        return;
    }

    for(int i=0; i < inputLine->Length() && _readNumbers < DATA_WIDTH; i++)
    {
        // If it's not a space, save it
        if(_reversedString[i] != ' ')
        {
            // Using the locale seems to be inconsistent across different OS versions
            //char _decimalPoint = std::use_facet< std::numpunct<char> >(std::cout.getloc()).decimal_point();
            if(_reversedString[i] == ',' || _reversedString[i] == '.')
            {
                //_newNumber[j] = _decimalPoint;
                _newNumber[j] = decimalPointChar;
            }
            else
            {
                _newNumber[j] = _reversedString[i];
            }
            //_newNumber[j] = _reversedString[i];
            j++;
        }
        // If it's a space, don't save it
        else
        {
            // Is saved string empty? Continue
            if(j == 0)
            {
                // Do nothing
                    
            }
            // Is saved string full? Parse number and save it
            else
            {
                _newNumber[j] = '\0';

                for(_counter=0; _counter < strlen(_newNumber); _counter++)
                {
                    _tempString[_counter] = _newNumber[strlen(_newNumber) - _counter -1];
                }
                _tempString[_counter] = '\0';

                _parsingString->sprintf("%s", _tempString);

                // Sometimes, there is no number but asterisks, it can't be parsed
                try
                {
                    dataSet[parsedCounter][DATA_WIDTH -1 - _readNumbers][dataType] = _parsingString->ToDouble();
                }
                catch(Exception &ex)
                {
                    dataSet[parsedCounter][DATA_WIDTH -1 - _readNumbers][dataType] = 0;
                }

                _readNumbers ++;
                j = 0;
            }
        }
    }

//    return;
    free(_reversedString);
    free(_newNumber);
    free(_returnedLine);
    free(_tempString);
    free(_parsingString);
    free(_tempString);
}

void ClearAllData(void)
{
    parsedCounter = 0;
    SetParsedCounter(parsedCounter);
    InitializeDataSet();
}

void __fastcall TMainForm::TryParseButtonClick(TObject *Sender)
{
    CheckClipboardForText();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ClearAllButtonClick(TObject *Sender)
{
    ClearAllData();
    UpdateShownText();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    InitializeDataSet();

    // Prepare combo
    ComboBoxShownData->Items->Add("EDT [s]");
    ComboBoxShownData->Items->Add("T15 [s]");
    ComboBoxShownData->Items->Add("T20 [s]");
    ComboBoxShownData->Items->Add("XI(T(20)) [%/10]");
    ComboBoxShownData->Items->Add("T30 [s]");
    ComboBoxShownData->Items->Add("XI(T(30)) [%/10]");
    ComboBoxShownData->Items->Add("Curvature [%]");
    ComboBoxShownData->Items->Add("Ts [ms]");
    ComboBoxShownData->Items->Add("SPL [dB]");
    ComboBoxShownData->Items->Add("SPL (Af) [dB]");
    ComboBoxShownData->Items->Add("SPL (Direct) [dB]");
    ComboBoxShownData->Items->Add("D(50)");
    ComboBoxShownData->Items->Add("C(7) [dB]");
    ComboBoxShownData->Items->Add("C(50) [dB]");
    ComboBoxShownData->Items->Add("C(80) [dB]");
    ComboBoxShownData->Items->Add("U(50) [dB]");
    ComboBoxShownData->Items->Add("U(80) [dB]");
    ComboBoxShownData->Items->Add("MTI (Corrected");
    ComboBoxShownData->Items->Add("LF(80)");
    ComboBoxShownData->Items->Add("LFC(80)");
    ComboBoxShownData->Items->Add("Diffusivity(ss) [dB]");
    ComboBoxShownData->Items->Add("Echo (Dietsch)");
    ComboBoxShownData->ItemIndex = 0;

    decimalPointChar = findDecimalPointChar();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DisplayTextEnter(TObject *Sender)
{
    AutoPasteCheckBox->Checked = False;
    TimerAutoPaste->Enabled = AutoPasteCheckBox->Checked;
}

void UpdateShownText(void)
{
    if(parsedCounter == 0)
    {
        if(MainForm->DisplayText->Lines->Count >0)
        {
            MainForm->DisplayText->Lines->Clear();
        }
        return;
    }

    int dataType = MainForm->ComboBoxShownData->ItemIndex;
    if(dataType<0)
        return;

    AnsiString * _newLine = new AnsiString();
    *_newLine = (AnsiString)parsedCounter + (AnsiString)"\t";

    // Avoid re-writing the whole memo if it's only a new line that's needed
    if(MainForm->ComboBoxShownData->ItemIndex == lastTypeDisplayed &&
       MainForm->DisplayText->Lines->Count > 0)
    {
        // Add a new lines or remove them?
        if(parsedCounter < MainForm->DisplayText->Lines->Count)
        {
            // Remove last lines
            while(parsedCounter < MainForm->DisplayText->Lines->Count-1)
            {
                MainForm->DisplayText->Lines->Delete(MainForm->DisplayText->Lines->Count-1);
            }
        }
        else
        {
            for(int j=0; j < DATA_WIDTH-1; j++)
            {
                *_newLine += (AnsiString)dataSet[parsedCounter-1][j][dataType] + (AnsiString)"\t";
            }

            *_newLine += (AnsiString)dataSet[parsedCounter-1][DATA_WIDTH-1][dataType];
            MainForm->DisplayText->Lines->Add(_newLine->c_str());
        }
    }
    else
    {
        MainForm->DisplayText->Lines->Clear();
        MainForm->DisplayText->Lines->Add("Index\t63\t125\t250\t500\t1k\t2k\t4k\t8k");
        for(int i=0; i<parsedCounter; i++)
        {

            *_newLine = (AnsiString)(i+1) + (AnsiString)"\t";
            for(int j=0; j < DATA_WIDTH-1; j++)
            {
                *_newLine += (AnsiString)dataSet[i][j][dataType] + (AnsiString)"\t";
            }
            *_newLine += (AnsiString)dataSet[i][DATA_WIDTH-1][dataType];
            MainForm->DisplayText->Lines->Add(_newLine->c_str());
        }

        lastTypeDisplayed = MainForm->ComboBoxShownData->ItemIndex;
    }

    free(_newLine);
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::ComboBoxShownDataChange(TObject *Sender)
{
    UpdateShownText();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CopyAllButtonClick(TObject *Sender)
{
    if(parsedCounter == 0)
    {
        return;
    }

    try
    {
        SetStatusText("Copying all data ...");

        AutoPasteCheckBox->Checked = False;
        TimerAutoPaste->Enabled = AutoPasteCheckBox->Checked;

        AnsiString * _newLine = new AnsiString();
        if(_newLine == NULL)
        {
            ShowMessage("Memory allocation failed for _newLine!");
            return;
        }

        MainForm->CopiedText->Lines->Clear();

        for(int _type = 0; _type < DATA_TYPES; _type++)
        {
            MainForm->CopiedText->Lines->Add("Data for " + MainForm->ComboBoxShownData->Items[0][_type]);

            MainForm->CopiedText->Lines->Add("Index\t63\t125\t250\t500\t1k\t2k\t4k\t8k");
            for(int i=0; i<parsedCounter; i++)
            {

                *_newLine = (AnsiString)(i+1) + (AnsiString)"\t";
                for(int j=0; j < DATA_WIDTH-1; j++)
                {
                    *_newLine += (AnsiString)dataSet[i][j][_type] + (AnsiString)"\t";
                }
                *_newLine += (AnsiString)dataSet[i][DATA_WIDTH-1][_type];
                MainForm->CopiedText->Lines->Add(_newLine->c_str());
            }
            MainForm->CopiedText->Lines->Add(" ");
        }

        free(_newLine);

        MainForm->CopiedText->SelectAll();
        MainForm->CopiedText->CopyToClipboard();
        SetStatusText("All data copied to clipboard.");
    }
    catch(Exception &ex)
    {
        ShowMessage("Exception thrown while creating all text! Sorry ...");
        SetStatusText("");        
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CopyPageButtonClick(TObject *Sender)
{
    if(parsedCounter == 0)
    {
        return;
    }
  
    AutoPasteCheckBox->Checked = False;
    TimerAutoPaste->Enabled = AutoPasteCheckBox->Checked;

    CopiedText->Lines->Clear();
    CopiedText->Lines->Add("Data for " + MainForm->ComboBoxShownData->Text);
    CopiedText->Lines->AddStrings(DisplayText->Lines);
    CopiedText->SelectAll();
    CopiedText->CopyToClipboard();
    SetStatusText(MainForm->ComboBoxShownData->Text + " data copied to clipboard.");
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::DeleteLastButtonClick(TObject *Sender)
{
    if(parsedCounter > 0)
    {
        parsedCounter--;
        UpdateShownText();
    }
}
//---------------------------------------------------------------------------

