object MainForm: TMainForm
  Left = 428
  Top = 180
  Width = 700
  Height = 500
  Caption = 
    'Results parser utility v0.1 - Joe Simon, 2017 (http://github.com' +
    '/ignaciodsimon)'
  Color = clBtnFace
  Constraints.MinHeight = 500
  Constraints.MinWidth = 700
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 454
    Width = 692
    Height = 19
    Panels = <
      item
        Text = 'Parsed: 0'
        Width = 100
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object Panel5: TPanel
    Left = 0
    Top = 0
    Width = 692
    Height = 454
    Align = alClient
    BevelOuter = bvNone
    BorderWidth = 10
    TabOrder = 1
    object Splitter: TSplitter
      Left = 10
      Top = 195
      Width = 672
      Height = 10
      Cursor = crVSplit
      Align = alTop
      Beveled = True
      Color = clBtnFace
      MinSize = 1
      ParentColor = False
      ResizeStyle = rsLine
    end
    object GroupBoxParsedData: TGroupBox
      Left = 10
      Top = 205
      Width = 672
      Height = 239
      Align = alClient
      Caption = '  Parsed data  '
      Constraints.MinHeight = 200
      Ctl3D = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 0
      object Panel3: TPanel
        Left = 2
        Top = 47
        Width = 668
        Height = 190
        Align = alClient
        BevelOuter = bvNone
        BorderWidth = 10
        TabOrder = 0
        object DisplayText: TMemo
          Left = 10
          Top = 10
          Width = 648
          Height = 170
          Align = alClient
          ParentShowHint = False
          ReadOnly = True
          ScrollBars = ssVertical
          ShowHint = False
          TabOrder = 0
          OnEnter = DisplayTextEnter
        end
        object CopiedText: TMemo
          Left = 20
          Top = 20
          Width = 33
          Height = 26
          TabOrder = 1
          Visible = False
        end
      end
      object Panel4: TPanel
        Left = 2
        Top = 15
        Width = 668
        Height = 32
        Align = alTop
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object ClearAllButton: TButton
          Left = 135
          Top = 7
          Width = 85
          Height = 20
          Caption = 'Clear all data'
          TabOrder = 0
          OnClick = ClearAllButtonClick
        end
        object ComboBoxShownData: TComboBox
          Left = 10
          Top = 7
          Width = 118
          Height = 21
          Style = csDropDownList
          Ctl3D = False
          ItemHeight = 13
          ParentCtl3D = False
          TabOrder = 1
          OnChange = ComboBoxShownDataChange
        end
        object CopyAllButton: TButton
          Left = 317
          Top = 7
          Width = 85
          Height = 20
          Caption = 'Copy all data'
          TabOrder = 2
          OnClick = CopyAllButtonClick
        end
        object CopyPageButton: TButton
          Left = 226
          Top = 7
          Width = 85
          Height = 20
          Caption = 'Copy this page'
          TabOrder = 3
          OnClick = CopyPageButtonClick
        end
        object DeleteLastButton: TButton
          Left = 408
          Top = 7
          Width = 85
          Height = 20
          Caption = 'Delete last row'
          TabOrder = 4
          OnClick = DeleteLastButtonClick
        end
      end
    end
    object GroupBoxInputText: TGroupBox
      Left = 10
      Top = 10
      Width = 672
      Height = 185
      Align = alTop
      Caption = '  Input text  '
      Constraints.MinHeight = 185
      Ctl3D = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 1
      object Panel1: TPanel
        Left = 2
        Top = 15
        Width = 668
        Height = 28
        Align = alTop
        BevelOuter = bvNone
        BorderWidth = 10
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object AutoPasteCheckBox: TCheckBox
          Left = 163
          Top = 11
          Width = 78
          Height = 13
          Caption = 'Auto paste'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = AutoPasteCheckBoxClick
        end
        object PasteTextButton: TButton
          Left = 5
          Top = 7
          Width = 74
          Height = 20
          Caption = 'Paste text'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = PasteTextButtonClick
        end
        object TryParseButton: TButton
          Left = 85
          Top = 7
          Width = 72
          Height = 20
          Caption = 'Try parse'
          TabOrder = 2
          OnClick = TryParseButtonClick
        end
      end
      object Panel2: TPanel
        Left = 2
        Top = 43
        Width = 668
        Height = 140
        Align = alClient
        BevelOuter = bvNone
        BorderWidth = 7
        TabOrder = 1
        object Label1: TLabel
          Left = 7
          Top = 7
          Width = 654
          Height = 13
          Align = alTop
          Caption = 'Paste text here:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object InputText: TMemo
          Left = 7
          Top = 20
          Width = 654
          Height = 113
          Align = alClient
          Ctl3D = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Terminal'
          Font.Style = []
          ParentCtl3D = False
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 0
        end
      end
    end
  end
  object TimerAutoPaste: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TimerAutoPasteTimer
    Left = 24
    Top = 80
  end
end
