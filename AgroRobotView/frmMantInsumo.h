#pragma once
#include "frmNuevoInsumo.h"
#include "frmEditInsumo.h"
#include "frmPaintInsumosPorStock.h"
#include "frmNuevoStock.h"
namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; //Para List<>
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmMantInsumo
	/// </summary>
	public ref class frmMantInsumo : public System::Windows::Forms::Form {
	public:
		frmMantInsumo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			currentFilter = nullptr;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantInsumo()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button5;
	protected:

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::GroupBox^ groupBox1;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;









	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;





















		   // Nuevo campo para recordar filtro actual (si null o vacío => mostrar todos)
		   String^ currentFilter;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMantInsumo::typeid));
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // button5
			   // 
			   this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->button5->Location = System::Drawing::Point(523, 58);
			   this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(159, 39);
			   this->button5->TabIndex = 22;
			   this->button5->Text = L"Mostrar todos";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &frmMantInsumo::button5_Click);
			   // 
			   // button3
			   // 
			   this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				   static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
				   static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(217)));
			   this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->button3->Location = System::Drawing::Point(153, 635);
			   this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(117, 39);
			   this->button3->TabIndex = 20;
			   this->button3->Text = L"Editar";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &frmMantInsumo::button3_Click);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				   static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
				   static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(217)));
			   this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->button2->Location = System::Drawing::Point(24, 635);
			   this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(117, 39);
			   this->button2->TabIndex = 19;
			   this->button2->Text = L"Nuevo";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &frmMantInsumo::button2_Click);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AllowUserToAddRows = false;
			   this->dataGridView1->AllowUserToResizeColumns = false;
			   this->dataGridView1->AllowUserToResizeRows = false;
			   dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				   static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(246)));
			   dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   dataGridViewCellStyle1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				   static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::LightGreen;
			   dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)),
				   static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			   this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			   this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			   this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			   dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				   static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10));
			   dataGridViewCellStyle2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				   static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::White;
			   dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			   dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				   this->Column1,
					   this->Column2, this->Column3, this->Column5
			   });
			   dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			   dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			   dataGridViewCellStyle3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				   static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::LightGreen;
			   dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)),
				   static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			   dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			   this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			   this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(183)), static_cast<System::Int32>(static_cast<System::Byte>(220)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)));
			   this->dataGridView1->Location = System::Drawing::Point(24, 210);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->dataGridView1->MultiSelect = false;
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersVisible = false;
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->dataGridView1->Size = System::Drawing::Size(851, 405);
			   this->dataGridView1->TabIndex = 18;
			   this->dataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &frmMantInsumo::dataGridView1_UserDeletingRow);
			   // 
			   // Column1
			   // 
			   this->Column1->HeaderText = L"Id";
			   this->Column1->MinimumWidth = 6;
			   this->Column1->Name = L"Column1";
			   this->Column1->Width = 45;
			   // 
			   // Column2
			   // 
			   this->Column2->HeaderText = L"Nombre";
			   this->Column2->MinimumWidth = 6;
			   this->Column2->Name = L"Column2";
			   this->Column2->Width = 270;
			   // 
			   // Column3
			   // 
			   this->Column3->HeaderText = L"Tipo";
			   this->Column3->MinimumWidth = 6;
			   this->Column3->Name = L"Column3";
			   this->Column3->Width = 150;
			   // 
			   // Column5
			   // 
			   this->Column5->HeaderText = L"Unidad";
			   this->Column5->MinimumWidth = 6;
			   this->Column5->Name = L"Column5";
			   this->Column5->Width = 150;
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				   static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   this->groupBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox1.BackgroundImage")));
			   this->groupBox1->Controls->Add(this->comboBox1);
			   this->groupBox1->Controls->Add(this->button1);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Controls->Add(this->button5);
			   this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->groupBox1->Location = System::Drawing::Point(24, 78);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->groupBox1->Size = System::Drawing::Size(851, 119);
			   this->groupBox1->TabIndex = 17;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Criterios de Búsqueda";
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->BackColor = System::Drawing::Color::White;
			   this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->IntegralHeight = false;
			   this->comboBox1->ItemHeight = 19;
			   this->comboBox1->Location = System::Drawing::Point(25, 63);
			   this->comboBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->comboBox1->MaxDropDownItems = 15;
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(301, 27);
			   this->comboBox1->TabIndex = 22;
			   this->comboBox1->DropDown += gcnew System::EventHandler(this, &frmMantInsumo::comboBox1_DropDown);
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				   static_cast<System::Int32>(static_cast<System::Byte>(77)));
			   this->button1->FlatAppearance->BorderSize = 0;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->ForeColor = System::Drawing::Color::White;
			   this->button1->Location = System::Drawing::Point(705, 58);
			   this->button1->Margin = System::Windows::Forms::Padding(0);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(117, 39);
			   this->button1->TabIndex = 21;
			   this->button1->Text = L"Buscar";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &frmMantInsumo::button1_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->label1->Location = System::Drawing::Point(21, 37);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(38, 18);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Tipo";
			   // 
			   // button4
			   // 
			   this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				   static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
				   static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(217)));
			   this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->button4->Location = System::Drawing::Point(283, 635);
			   this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(117, 39);
			   this->button4->TabIndex = 21;
			   this->button4->Text = L"Eliminar";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &frmMantInsumo::button4_Click);
			   // 
			   // button6
			   // 
			   this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				   static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(203)),
				   static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(217)));
			   this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				   static_cast<System::Int32>(static_cast<System::Byte>(90)));
			   this->button6->Location = System::Drawing::Point(412, 635);
			   this->button6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(117, 39);
			   this->button6->TabIndex = 23;
			   this->button6->Text = L"Ver stock";
			   this->button6->UseVisualStyleBackColor = false;
			   this->button6->Click += gcnew System::EventHandler(this, &frmMantInsumo::button6_Click);
			   // 
			   // button7
			   // 
			   this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(143)),
				   static_cast<System::Int32>(static_cast<System::Byte>(77)));
			   this->button7->FlatAppearance->BorderSize = 0;
			   this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button7->ForeColor = System::Drawing::Color::White;
			   this->button7->Location = System::Drawing::Point(697, 635);
			   this->button7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(177, 39);
			   this->button7->TabIndex = 24;
			   this->button7->Text = L"Añadir stock";
			   this->button7->UseVisualStyleBackColor = false;
			   this->button7->Click += gcnew System::EventHandler(this, &frmMantInsumo::button7_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->button7);
			   this->panel1->Controls->Add(this->groupBox1);
			   this->panel1->Controls->Add(this->button6);
			   this->panel1->Controls->Add(this->dataGridView1);
			   this->panel1->Controls->Add(this->button4);
			   this->panel1->Controls->Add(this->button3);
			   this->panel1->Controls->Add(this->button2);
			   this->panel1->Location = System::Drawing::Point(16, 15);
			   this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(907, 695);
			   this->panel1->TabIndex = 25;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 17, System::Drawing::FontStyle::Bold));
			   this->label2->Location = System::Drawing::Point(17, 20);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(413, 37);
			   this->label2->TabIndex = 26;
			   this->label2->Text = L"Registro General de Insumos";
			   // 
			   // frmMantInsumo
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(251)),
				   static_cast<System::Int32>(static_cast<System::Byte>(248)));
			   this->ClientSize = System::Drawing::Size(943, 725);
			   this->Controls->Add(this->panel1);
			   this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Name = L"frmMantInsumo";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Registro General de Insumos";
			   this->Load += gcnew System::EventHandler(this, &frmMantInsumo::frmMantInsumo_Load);
			   this->Resize += gcnew System::EventHandler(this, &frmMantInsumo::frmMantInsumo_Resize);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
		   //===============================================================================
		   //==============================Nuevo============================================
		   //===============================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmNuevoInsumo^ frm = gcnew frmNuevoInsumo();
		frm->ShowDialog();
		// Después de crear, refrescar respetando el filtro actual (si hay)
		RefreshGrid();
	}
		   //===============================================================================
		   //==============================Eliminar=========================================
		   //===============================================================================
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count > 0) {
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(
				"¿Está seguro de eliminar el insumo seleccionado?",
				"Confirmar eliminación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
				InsumoController^ insumoCtrl = gcnew InsumoController();
				insumoCtrl->eliminarInsumo(id);
				// En lugar de manipular directamente las filas, volvemos a cargar la grilla
				RefreshGrid();
			}
		} else {
			MessageBox::Show(
				"Debe seleccionar una fila para eliminar.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}
		   //Método para mostrar todos los insumos en el DataGridView
	private: System::Void mostrarGrilla(List<Insumo^>^ lista)
	{
		//Limpiar el DataGridView
		dataGridView1->Rows->Clear();
		//Cargar los insumos en el DataGridView
		for each (Insumo ^ insumo in lista) {
			dataGridView1->Rows->Add(
				Convert::ToString(insumo->Id),
				insumo->Nombre,
				insumo->Tipo,
				insumo->Unidad
			);
		}
	}

		   // Nuevo método: refrescar la grilla respetando el filtro guardado
	private: System::Void RefreshGrid()
	{
		InsumoController^ insumoCtrl = gcnew InsumoController();
		List<Insumo^>^ lista;

		if (!String::IsNullOrWhiteSpace(currentFilter)) {
			// Aplica filtro guardado
			lista = insumoCtrl->buscarPorTipo(currentFilter->Trim());
		} else {
			// Muestra todos
			lista = insumoCtrl->readTxt();
		}

		mostrarGrilla(lista);
	}

		   //===============================================================================
		   //==============================Buscar===========================================
		   //===============================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//Validar campo vacio con trim
		if (String::IsNullOrWhiteSpace(comboBox1->Text->Trim())) {
			MessageBox::Show(
				"Debe ingresar un tipo para buscar.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		//Guardar filtro actual
		currentFilter = comboBox1->Text->Trim();

		//Crear el controlador
		InsumoController^ insumoCtrl = gcnew InsumoController();
		List<Insumo^>^ lista = insumoCtrl->buscarPorTipo(currentFilter);
		//Cargar los insumos en el DataGridView
		mostrarGrilla(lista);
	}
	private: System::Void dataGridView1_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e)
	{
		//Validar si realmente desea eliminar
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show(
			"¿Está seguro de eliminar el insumo?",
			"Confirmar eliminación",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);
		if (result == System::Windows::Forms::DialogResult::No) {
			e->Cancel = true; //Cancelar la eliminación
		} else {
			int id = Convert::ToInt32(e->Row->Cells[0]->Value);
			InsumoController^ insumoCtrl = gcnew InsumoController();
			insumoCtrl->eliminarInsumo(id);
			RefreshGrid();
		}

	}
		   //===============================================================================
		   //==============================Editar===========================================
		   //===============================================================================
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show(
				"Debe seleccionar una fila para editar.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		frmEditInsumo^ frm = gcnew frmEditInsumo(
			Convert::ToInt32(
				dataGridView1->SelectedRows[0]->Cells[0]->Value
			)
		);
		frm->ShowDialog();
		//Actualizar la vista respetando el filtro actual
		RefreshGrid();
	}
	private: System::Void comboBox1_DropDown(System::Object^ sender, System::EventArgs^ e)
	{
		//Cargar los tipos de insumos en el comboBox
		comboBox1->Items->Clear();
		InsumoController^ insumoCtrl = gcnew InsumoController();
		List<String^>^ tipos = insumoCtrl->obtenerTiposInsumos();
		for each (String ^ tipo in tipos) {
			comboBox1->Items->Add(tipo);
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Quitar filtro guardado y mostrar todos
		currentFilter = nullptr;
		RefreshGrid();
	}
	private: System::Void frmMantInsumo_Load(System::Object^ sender, System::EventArgs^ e)
	{
		// Al cargar el formulario, mostrar todos los insumos
		RefreshGrid();
	}
		   //===============================================================================
		   //==============================Ver stock=========================================
		   //===============================================================================
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show(
				"Debe seleccionar una fila para ver el stock.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		int idInsumo = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
		InsumoController^ insumoCtrl = gcnew InsumoController();
		Insumo^ insumo = insumoCtrl->buscarPorId(idInsumo);
		StockInsumoController^ stockCtrl = gcnew StockInsumoController();
		List<StockInsumo^>^ stocks = stockCtrl->buscarPorIdInsumo(idInsumo);
		frmPaintInsumosPorStock^ frm = gcnew frmPaintInsumosPorStock(insumo, stocks);
		frm->ShowDialog();
	}
		   //===============================================================================
		   //==============================Añadir stock=====================================
		   //===============================================================================
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show(
				"Debe seleccionar una fila para añadir stock.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		int idInsumo = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
		InsumoController^ insumoCtrl = gcnew InsumoController();
		Insumo^ insumo = insumoCtrl->buscarPorId(idInsumo);
		frmNuevoStock^ frm = gcnew frmNuevoStock(insumo);
		frm->ShowDialog();
	}

		   // Se busca centrar todo el contenido al redimensionar
	private: System::Void frmMantInsumo_Resize(System::Object^ sender, System::EventArgs^ e)
	{
		panel1->Left = (this->ClientSize.Width - panel1->Width) / 2;
		panel1->Top = (this->ClientSize.Height - panel1->Height) / 2;
	}
};
}