#pragma once
#include "frmNuevoDieta.h"
#include "frmEditarDieta.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmMantDietas
	/// </summary>
	public ref class frmMantDietas : public System::Windows::Forms::Form
	{
	public:
		frmMantDietas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->dietaController = gcnew GestorNutricionalController();
			AplicarEstiloProfesional();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantDietas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button4;
	protected:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label1;

	private: GestorNutricionalController^ dietaController;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;

		   void AplicarEstiloProfesional() {
			   // =========================================================
			   // 1. PALETA DE COLORES (Reutilizada)
			   // =========================================================
			   System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248); // Blanco Menta (Fondo Principal)
			   System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240); // Menta Suave (Fondo de Paneles/Cabeceras)
			   System::Drawing::Color colorVerdeOscuro = System::Drawing::Color::FromArgb(34, 86, 70); // Texto Principal/Títulos
			   System::Drawing::Color colorTextoClaro = System::Drawing::Color::FromArgb(64, 106, 90); // Labels
			   System::Drawing::Color colorBotonPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Esmeralda (Acción Principal)
			   System::Drawing::Color colorBotonSecundario = System::Drawing::Color::White; // Fondo Secundario (Editar/Limpiar)
			   System::Drawing::Color colorBordeSuave = System::Drawing::Color::FromArgb(203, 233, 217); // Borde de Controles
			   System::Drawing::Color colorEliminar = System::Drawing::Color::FromArgb(220, 53, 69); // Rojo para Eliminar

			   // =========================================================
			   // 2. FUENTES (Aumentadas - Reutilizadas)
			   // =========================================================
			   System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 10.5, FontStyle::Bold);
			   System::Drawing::Font^ fuenteLabel = gcnew System::Drawing::Font("Microsoft Tai Le", 9.75F, FontStyle::Bold);
			   System::Drawing::Font^ fuenteGridHeader = gcnew System::Drawing::Font("Segoe UI Semibold", 11);
			   System::Drawing::Font^ fuenteGridCell = gcnew System::Drawing::Font("Microsoft Sans Serif", 10);
			   System::Drawing::Font^ fuenteBotonCRUD = gcnew System::Drawing::Font(L"Microsoft Tai Le", 11, FontStyle::Bold);

			   // =========================================================
			   // 3. CONFIGURACIÓN FORMULARIO
			   // =========================================================
			   this->BackColor = colorFondo;
			   this->StartPosition = FormStartPosition::CenterScreen;
			   this->Text = "Gestión de Órdenes de Dieta";
			   int margenLateral = 30;
			   int espaciadoY = 20;

			   // Dimensiones de los botones
			   int anchoBoton = 100;
			   int alturaBoton = 30;
			   int yControl = 45; // Posición Y dentro de los GroupBox

			   // ---------------------------------------------------------
			   // A. GROUP BOX: CRITERIOS DE BÚSQUEDA (groupBox1)
			   // Controles: ID (label1, textBox1), Buscar (button1)
			   // ---------------------------------------------------------
			   this->groupBox1->Text = "Criterios de búsqueda";
			   this->groupBox1->BackColor = colorPanel;
			   this->groupBox1->ForeColor = colorVerdeOscuro;
			   this->groupBox1->Font = fuenteTitulo;
			   this->groupBox1->Location = System::Drawing::Point(margenLateral, espaciadoY);
			   this->groupBox1->Height = 110;
			   this->groupBox1->Width = 400;
			   this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);

			   // Label ID (asumo label1)
			   label1->Text = "ID:";
			   label1->Font = fuenteLabel;
			   label1->ForeColor = colorTextoClaro;
			   label1->Location = Point(20, yControl + 4);

			   // TextBox ID (asumo textBox1)
			   textBox1->BorderStyle = BorderStyle::FixedSingle;
			   textBox1->BackColor = System::Drawing::Color::White;
			   textBox1->ForeColor = colorVerdeOscuro;
			   textBox1->Location = Point(50, yControl); textBox1->Width = 120;

			   // Botón Buscar (button1 - Primario)
			   button1->Text = "Buscar";
			   button1->BackColor = colorBotonPrimario;
			   button1->ForeColor = System::Drawing::Color::White;
			   button1->FlatStyle = FlatStyle::Flat;
			   button1->FlatAppearance->BorderSize = 0;
			   button1->Font = fuenteTitulo;
			   button1->Size = System::Drawing::Size(anchoBoton, alturaBoton);
			   button1->Location = Point(textBox1->Right + 20, yControl);


			   // ---------------------------------------------------------
			   // B. GROUP BOX: ENVÍO DE ÓRDENES (groupBox2)
			   // Controles: ID Dieta (label2, textBox2), Prioridad (label3, comboBox1), Enviar Orden (button5)
			   // ---------------------------------------------------------
			   this->groupBox2->Text = "Envío de órdenes";
			   this->groupBox2->BackColor = colorPanel;
			   this->groupBox2->ForeColor = colorVerdeOscuro;
			   this->groupBox2->Font = fuenteTitulo;
			   this->groupBox2->Location = System::Drawing::Point(groupBox1->Right + margenLateral, espaciadoY);
			   this->groupBox2->Height = 110;
			   this->groupBox2->Width = 350;
			   this->groupBox2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);

			   // Label ID Dieta (asumo label2)
			   label2->Text = "ID Dieta:";
			   label2->Font = fuenteLabel;
			   label2->ForeColor = colorTextoClaro;
			   label2->Location = Point(20, yControl);

			   // TextBox ID Dieta (asumo textBox2)
			   txtID->BorderStyle = BorderStyle::FixedSingle;
			   txtID->BackColor = System::Drawing::Color::White;
			   txtID->ForeColor = colorVerdeOscuro;
			   txtID->Location = Point(85, yControl - 5); txtID->Width = 100;

			   // Label Prioridad (asumo label3)
			   label3->Text = "Prioridad:";
			   label3->Font = fuenteLabel;
			   label3->ForeColor = colorTextoClaro;
			   label3->Location = Point(20, yControl + 35);

			   // ComboBox Prioridad (asumo comboBox1)
			   comboBox1->FlatStyle = FlatStyle::Flat;
			   comboBox1->BackColor = System::Drawing::Color::White;
			   comboBox1->ForeColor = colorVerdeOscuro;
			   comboBox1->Location = Point(85, yControl + 30); comboBox1->Width = 100;

			   // Botón Enviar Orden (button5 - Primario)
			   button5->Text = "Enviar orden";
			   button5->BackColor = colorBotonPrimario;
			   button5->ForeColor = System::Drawing::Color::White;
			   button5->FlatStyle = FlatStyle::Flat;
			   button5->FlatAppearance->BorderSize = 0;
			   button5->Font = fuenteTitulo;
			   button5->Size = System::Drawing::Size(120, alturaBoton);
			   button5->Location = Point(txtID->Right + 20, yControl + 30); // Posicionamos a la derecha


			   // ---------------------------------------------------------
			   // C. GRILLA (DATAGRIDVIEW)
			   // ---------------------------------------------------------
			   int yGrilla = System::Math::Max(groupBox1->Bottom, groupBox2->Bottom) + espaciadoY;
			   int hFooter = 70;

			   dataGridView1->Location = Point(margenLateral, yGrilla);
			   dataGridView1->Width = this->ClientSize.Width - (margenLateral * 2);
			   dataGridView1->Height = this->ClientSize.Height - yGrilla - hFooter;
			   dataGridView1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			   // Estilo Visual Grilla (reutilizado)
			   dataGridView1->BackgroundColor = System::Drawing::Color::White;
			   dataGridView1->BorderStyle = BorderStyle::FixedSingle;
			   dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			   dataGridView1->EnableHeadersVisualStyles = false;
			   dataGridView1->GridColor = System::Drawing::Color::FromArgb(220, 235, 230);

			   // Cabecera
			   dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorPanel;
			   dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = colorVerdeOscuro;
			   dataGridView1->ColumnHeadersDefaultCellStyle->Font = fuenteGridHeader;
			   dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::None;
			   dataGridView1->ColumnHeadersHeight = 45;

			   // Filas
			   dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			   dataGridView1->DefaultCellStyle->ForeColor = colorVerdeOscuro;
			   dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(183, 220, 200);
			   dataGridView1->DefaultCellStyle->SelectionForeColor = colorVerdeOscuro;
			   dataGridView1->DefaultCellStyle->Font = fuenteGridCell;
			   dataGridView1->RowTemplate->Height = 40;
			   dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(248, 252, 250);

			   dataGridView1->RowHeadersVisible = false;
			   dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			   // ---------------------------------------------------------
			   // D. BOTONES INFERIORES: AGREGAR (butto2), EDITAR (button3), ELIMINAR (button4)
			   // ---------------------------------------------------------
			   int yBotones = this->ClientSize.Height - 50;
			   anchoBoton = 120; // Redefinimos ancho para botones inferiores
			   int espaciadoBotones = 20;
			   int numBotones = 3;
			   int anchoTotalBotones = (anchoBoton * numBotones) + (espaciadoBotones * (numBotones - 1));
			   int inicioX = (this->ClientSize.Width - anchoTotalBotones) / 2; // Centrado horizontal

			   // Botón Agregar (button3 - Primario/Acción positiva)
			   button2->Text = "Agregar";
			   button2->Location = System::Drawing::Point(inicioX, yBotones);
			   button2->Size = System::Drawing::Size(anchoBoton, 40);
			   button2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::None);
			   button2->BackColor = colorBotonPrimario; // Verde Esmeralda
			   button2->ForeColor = System::Drawing::Color::White;
			   button2->FlatStyle = FlatStyle::Flat;
			   button2->FlatAppearance->BorderSize = 0;
			   button2->Cursor = Cursors::Hand;
			   button2->Font = fuenteBotonCRUD;

			   // Botón Editar (button4 - Secundario/Neutral)
			   button3->Text = "Editar";
			   button3->Location = System::Drawing::Point(inicioX + anchoBoton + espaciadoBotones, yBotones);
			   button3->Size = System::Drawing::Size(anchoBoton, 40);
			   button3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::None);
			   button3->BackColor = colorBotonSecundario; // Blanco
			   button3->ForeColor = colorVerdeOscuro;
			   button3->FlatStyle = FlatStyle::Flat;
			   button3->FlatAppearance->BorderColor = colorBordeSuave;
			   button3->FlatAppearance->BorderSize = 1;
			   button3->Cursor = Cursors::Hand;
			   button3->Font = fuenteBotonCRUD;

			   // Botón Eliminar (button5 - Advertencia)
			   button4->Text = "Eliminar";
			   button4->Location = System::Drawing::Point(button4->Right + espaciadoBotones, yBotones);
			   button4->Size = System::Drawing::Size(anchoBoton, 40);
			   button4->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::None);
			   button4->BackColor = colorEliminar; // Rojo de advertencia
			   button4->ForeColor = System::Drawing::Color::White;
			   button4->FlatStyle = FlatStyle::Flat;
			   button4->FlatAppearance->BorderSize = 0;
			   button4->Cursor = Cursors::Hand;
			   button4->Font = fuenteBotonCRUD;
		   }

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(578, 422);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 30);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantDietas::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(325, 422);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 30);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantDietas::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(42, 422);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 30);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantDietas::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 164);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(680, 235);
			this->dataGridView1->TabIndex = 7;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(24, 22);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(680, 122);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(317, 57);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantDietas::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(133, 57);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 22);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID:";
			this->label1->Click += gcnew System::EventHandler(this, &frmMantDietas::label1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(67, 141);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(172, 35);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Enviar orden";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantDietas::button5_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->txtID);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(733, 22);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(317, 183);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Envio de órdenes";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Alta", L"Media", L"Baja" });
			this->comboBox1->Location = System::Drawing::Point(157, 86);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMantDietas::comboBox1_SelectedIndexChanged);
			// 
			// txtID
			// 
			this->txtID->Location = System::Drawing::Point(157, 39);
			this->txtID->Name = L"txtID";
			this->txtID->Size = System::Drawing::Size(100, 22);
			this->txtID->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 16);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Prioridad:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"ID Dieta:";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Dieta";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"ID Animal";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Fecha Inicio";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Alimentos";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Frecuencia";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// frmMantDietas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1091, 679);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmMantDietas";
			this->Text = L"Mantenimiento de dietas";
			this->Load += gcnew System::EventHandler(this, &frmMantDietas::frmMantDietas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantDietas_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
		mostrarGrilla(listaDietas);
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

		   //================================================Nuevo============================================//
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevoDieta^ nuevaDietaForm = gcnew frmNuevoDieta(this->dietaController);
		nuevaDietaForm->ShowDialog(this);
		List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
		mostrarGrilla(listaDietas);
	}

		   //================================================Eliminar============================================//
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{

			System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
				"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (resultado == System::Windows::Forms::DialogResult::No)
			{
				return;
			}

			int selectedRowIndex = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[selectedRowIndex]->Cells[0]->Value);
			this->dietaController->eliminarDieta(id);
			List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
			mostrarGrilla(listaDietas);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   //================================================Buscar============================================//
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ textoBusqueda = textBox1->Text->Trim();

		// ?? Si no se ingresó nada, mostrar todas las dietas
		if (String::IsNullOrEmpty(textoBusqueda)) {
			List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
			if (listaDietas->Count > 0) {
				mostrarGrilla(listaDietas);
			}
			else {
				MessageBox::Show("No hay dietas registradas.", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			return;
		}

		// ?? Si sí se ingresó algo, intentar convertir a entero y buscar por ID
		int id = 0;
		try {
			id = Convert::ToInt32(textoBusqueda);
		}
		catch (FormatException^) {
			MessageBox::Show("Por favor, ingrese un ID válido (número entero).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Dieta^ dietaSeleccionada = this->dietaController->consultarDietaporId(id);

		if (dietaSeleccionada != nullptr) {
			List<Dieta^>^ listaDietas = gcnew List<Dieta^>();
			listaDietas->Add(dietaSeleccionada);
			mostrarGrilla(listaDietas);
		}
		else {
			MessageBox::Show("No se encontró la dieta con el ID especificado.", "Búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}


		   //================================================Editar============================================//
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

			Dieta^ dietaSeleccionada = this->dietaController->consultarDietaporId(id);
			if (dietaSeleccionada == nullptr)
			{
				MessageBox::Show("No se encontró la dieta seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			frmEditarDieta^ editarDietaForm = gcnew frmEditarDieta(this->dietaController, dietaSeleccionada);
			editarDietaForm->ShowDialog();
			// Llamar al m?todo para cargar la lista de maquinas nuevamente
			List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
			mostrarGrilla(listaDietas);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	public:	void mostrarGrilla(List<Dieta^>^ listaDietas)
	{
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaDietas->Count; i++)
		{
			Dieta^ dieta = listaDietas[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(dieta->Id);
			filaGrilla[1] = Convert::ToString(dieta->IdAnimal);
			filaGrilla[2] = dieta->FechaInicio;
			filaGrilla[3] = dieta->Alimentos;
			filaGrilla[4] = dieta->Frecuencia;
			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (txtID->Text->Trim() == "") {
				MessageBox::Show("Por favor, ingrese el ID de la dieta antes de enviar la orden.",
					"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int idDieta = Convert::ToInt32(txtID->Text);

			if (comboBox1->Text->Trim() == "") {
				MessageBox::Show("Seleccione una prioridad para la orden (Alta, Media, Baja).",
					"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			String^ prioridad = comboBox1->Text;

			System::Windows::Forms::DialogResult confirmacion =
				MessageBox::Show("¿Desea enviar esta orden al módulo de Almacén?",
					"Confirmar envío", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (confirmacion == System::Windows::Forms::DialogResult::No) {
				return;
			}

			this->dietaController->enviarOrdenAlimentacion(idDieta, prioridad);

			MessageBox::Show("La orden de alimentación fue enviada correctamente al módulo de Almacén.",
				"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			txtID->Clear();
			comboBox1->SelectedIndex = -1;
		}
		catch (FormatException^) {
			MessageBox::Show("El ID ingresado no tiene un formato válido. Debe ser un número entero.",
				"Error de formato", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ocurrió un error inesperado al enviar la orden:\n" + ex->Message,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
