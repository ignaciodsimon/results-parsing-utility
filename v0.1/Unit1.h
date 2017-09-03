//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TTimer *TimerAutoPaste;
    TStatusBar *StatusBar;
        TPanel *Panel5;
        TGroupBox *GroupBoxParsedData;
        TPanel *Panel3;
        TMemo *DisplayText;
        TMemo *CopiedText;
        TPanel *Panel4;
        TButton *ClearAllButton;
        TComboBox *ComboBoxShownData;
        TButton *CopyAllButton;
        TButton *CopyPageButton;
        TSplitter *Splitter;
        TGroupBox *GroupBoxInputText;
        TPanel *Panel1;
        TCheckBox *AutoPasteCheckBox;
        TButton *PasteTextButton;
        TButton *TryParseButton;
        TPanel *Panel2;
        TLabel *Label1;
        TMemo *InputText;
        TButton *DeleteLastButton;
    void __fastcall PasteTextButtonClick(TObject *Sender);
    void __fastcall AutoPasteCheckBoxClick(TObject *Sender);
    void __fastcall TimerAutoPasteTimer(TObject *Sender);
    void __fastcall TryParseButtonClick(TObject *Sender);
    void __fastcall ClearAllButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall DisplayTextEnter(TObject *Sender);
    void __fastcall ComboBoxShownDataChange(TObject *Sender);
    void __fastcall CopyAllButtonClick(TObject *Sender);
    void __fastcall CopyPageButtonClick(TObject *Sender);
        void __fastcall DeleteLastButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
