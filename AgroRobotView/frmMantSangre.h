#pragma once
#include "frmNuevoMuestraS.h"
#include "frmEditarMuestraS.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotModel;
	using namespace AgroRobotController;

	/// <summary>
	/// Resumen de frmMantSangre
	/// </summary>
	public ref class frmMantSangre : public System::Windows::Forms::Form
	{
	public:
		frmMantSangre(void)
		{
			InitializeComponent();
			this->muestraController = gcnew MuestraController();
			this->gestorNutricionalController = gcnew GestorNutricionalController();
			cargarAnimalesDisponibles();
			cargarAnimalesSinMuestraSangre();
			this->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->BackColor = System::Drawing::Color::LightGreen;
			this->button1->ForeColor = System::Drawing::Color::DarkGreen;
			this->button2->BackColor = System::Drawing::Color::LightGreen;
			this->button2->ForeColor = System::Drawing::Color::DarkGreen;
			this->button3->BackColor = System::Drawing::Color::LightGreen;
			this->button3->ForeColor = System::Drawing::Color::DarkGreen;
			this->button4->BackColor = System::Drawing::Color::LightGreen;
			this->button4->ForeColor = System::Drawing::Color::DarkGreen;
			this->button5->BackColor = System::Drawing::Color::LightGreen;
			this->button5->ForeColor = System::Drawing::Color::DarkGreen;
			AplicarEstiloProfesional();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantSangre()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button4;
	protected:
	private: System::Windows::Forms::Button^ button3;

	private: GestorNutricionalController^ gestorNutricionalController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: MuestraController^ muestraController;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		/// 
		// =====================================================================
		   // ESTILO PROFESIONAL Y ESCALADO
		   // =====================================================================
		void AplicarEstiloProfesional() {
			// 1. PALETA DE COLORES
			System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248); // Blanco Menta
			System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240); // Menta Suave
			System::Drawing::Color colorVerdeOscuro = System::Drawing::Color::FromArgb(64, 106, 90); // Texto Títulos
			System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(22, 53, 45);      // Texto Normal
			System::Drawing::Color colorTextoClaro = System::Drawing::Color::FromArgb(64, 106, 90); // Texto Secundario/Labels
			System::Drawing::Color colorBotonPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Esmeralda
			System::Drawing::Color colorBotonSecundario = System::Drawing::Color::FromArgb(236, 246, 240); // Menta Botón
			System::Drawing::Color colorBordeBoton = System::Drawing::Color::FromArgb(203, 233, 217);
			System::Drawing::Color colorEliminar = System::Drawing::Color::FromArgb(220, 53, 69); // Rojo para Eliminar

			// =========================================================
			// 2. FUENTES (AUMENTADAS)
			// =========================================================
			// Aumentar de 9 a 10.5
			System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 10.5, FontStyle::Bold);
			// Aumentar de 8.25 a 9.75
			System::Drawing::Font^ fuenteLabel = gcnew System::Drawing::Font("Microsoft Tai Le", 9.75F, FontStyle::Bold);
			// Aumentar de 10 a 11
			System::Drawing::Font^ fuenteGridHeader = gcnew System::Drawing::Font("Segoe UI Semibold", 11);
			// Aumentar de 9 a 10
			System::Drawing::Font^ fuenteGridCell = gcnew System::Drawing::Font("Microsoft Sans Serif", 10);
			// Aumentar el botón Eliminar de 10 a 11
			System::Drawing::Font^ fuenteBotonEliminar = gcnew System::Drawing::Font(L"Microsoft Tai Le", 11, FontStyle::Bold);

			// 3. CONFIGURACIÓN FORMULARIO
			this->BackColor = colorFondo;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Text = "Gestión de Muestras de Heces";
			int margenLateral = 30;
			int espaciadoY = 20;

			// Posición Y de los controles de entrada (Especie, TextBox, Botones)
			// int yControl = espaciadoY + 40;

			// 4. GROUP BOX (BÚSQUEDA)
			this->groupBox1->BackColor = colorPanel;
			this->groupBox1->ForeColor = colorVerdeOscuro;
			this->groupBox1->Font = fuenteTitulo;
			this->groupBox1->FlatStyle = FlatStyle::System; // Para que tome el color
			this->groupBox1->Location = System::Drawing::Point(margenLateral, espaciadoY);
			this->groupBox1->Location = System::Drawing::Point(margenLateral, 20);
			this->groupBox1->Height = 110;
			this->groupBox1->Width = 400;
			this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);

			// Controles dentro del GroupBox
			array<Label^>^ labels = { label1, label2 };
			for each (Label ^ l in labels) {
				l->Font = fuenteLabel;
				l->ForeColor = colorVerdeOscuro;
			}

			// Configuración de TextBox para entrada de texto
			textBox1->BorderStyle = BorderStyle::FixedSingle;
			textBox1->BackColor = System::Drawing::Color::White;
			textBox1->ForeColor = colorVerdeOscuro;

			// Centrado de controles en GroupBox1
			int yControl = 45;
			label1->Location = Point(20, yControl + 4);
			textBox1->Location = Point(80, yControl); textBox1->Width = 120;

			// Botón Buscar (Primario)
			this->button1->BackColor = colorBotonPrimario;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->FlatStyle = FlatStyle::Flat;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = fuenteTitulo;
			this->button1->Cursor = Cursors::Hand;
			this->button1->Location = Point(220, yControl - 5); button1->Width = 75;

			// Botón Limpiar (Secundario pero en panel claro)
			this->button5->BackColor = System::Drawing::Color::White; // Contraste sobre el panel menta
			this->button5->ForeColor = colorVerdeOscuro;
			this->button5->FlatStyle = FlatStyle::Flat;
			this->button5->FlatAppearance->BorderColor = colorBordeBoton;
			this->button5->FlatAppearance->BorderSize = 1;
			this->button5->Font = fuenteTitulo;
			this->button5->Cursor = Cursors::Hand;
			this->button5->Location = Point(305, yControl - 5); button4->Width = 75;

			// =========================================================
			// 5. GROUP BOX: NUEVO DIAGNÓSTICO
			// Asumo que tu GroupBox2 es 'Nuevo Diagnóstico' (Necesitarás agregarlo al formulario)
			// =========================================================
			this->groupBox2->Text = "Nuevo Diagnóstico";
			this->groupBox2->BackColor = colorPanel;
			this->groupBox2->ForeColor = colorVerdeOscuro;
			this->groupBox2->Font = fuenteTitulo;
			this->groupBox2->Location = System::Drawing::Point(groupBox1->Right + margenLateral, espaciadoY);
			this->groupBox2->Height = 110;
			this->groupBox2->Width = 350; // Ancho fijo para Nuevo Diagnóstico
			this->groupBox2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);

			// Controles de Nuevo Diagnóstico
			// Asumo que 'label3' es 'Especie' y 'comboBox2' es el control de selección
			label2->Text = "Especie:";
			label2->Font = fuenteLabel;
			label2->ForeColor = colorTextoClaro;

			// Configuración de ComboBox (Dropdown)
			comboBox1->FlatStyle = FlatStyle::Flat;
			comboBox1->BackColor = System::Drawing::Color::White;
			comboBox1->ForeColor = colorVerdeOscuro;

			// Centrado de controles en GroupBox2
			label2->Location = Point(20, yControl + 4);
			comboBox1->Location = Point(80, yControl); comboBox1->Width = 120;

			button2->Text = "Agregar";
			button2->BackColor = colorBotonPrimario;
			button2->ForeColor = System::Drawing::Color::White;
			button2->FlatStyle = FlatStyle::Flat;
			button2->FlatAppearance->BorderSize = 0;
			button2->Font = fuenteTitulo;
			button2->Cursor = Cursors::Hand;
			button2->Location = Point(220, yControl - 5); button2->Width = 100;

			// 5. GRILLA (DATAGRIDVIEW)
			int yGrilla = System::Math::Max(groupBox1->Bottom, groupBox2->Bottom) + espaciadoY;
			int hFooter = 70;

			dataGridView1->Location = Point(margenLateral, yGrilla);
			dataGridView1->Width = this->ClientSize.Width - (margenLateral * 2);
			dataGridView1->Height = this->ClientSize.Height - yGrilla - hFooter;
			dataGridView1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			// Estilo Visual Grilla
			dataGridView1->BackgroundColor = System::Drawing::Color::White;
			dataGridView1->BorderStyle = BorderStyle::FixedSingle; // Un borde sutil
			dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			dataGridView1->EnableHeadersVisualStyles = false;
			dataGridView1->GridColor = System::Drawing::Color::FromArgb(220, 235, 230); // Líneas verdes muy suaves

			// Cabecera
			dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorPanel; // Menta suave
			dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = colorVerdeOscuro;
			dataGridView1->ColumnHeadersDefaultCellStyle->Font = fuenteGridHeader;
			dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::None; // Borde none para un look más moderno
			dataGridView1->ColumnHeadersHeight = 45;

			// Filas
			dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			dataGridView1->DefaultCellStyle->ForeColor = colorVerdeOscuro;
			dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(183, 220, 200); // Verde suave en selección
			dataGridView1->DefaultCellStyle->SelectionForeColor = colorVerdeOscuro;
			dataGridView1->DefaultCellStyle->Font = fuenteGridCell;
			dataGridView1->RowTemplate->Height = 40;
			dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(248, 252, 250); // Alternado muy sutil

			dataGridView1->RowHeadersVisible = false;
			dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			// =========================================================
			// 4. BOTÓN ELIMINAR (ABAJO IZQUIERDA)
			// =========================================================
			int yBotones = this->ClientSize.Height - 50;
			int anchoBoton = 120;
			int espaciadoBotones = 20;
			int anchoTotalBotones = (anchoBoton * 2) + espaciadoBotones;
			int inicioX = (this->ClientSize.Width - anchoTotalBotones) / 2; // Centrado horizontal

			button4->Text = "Eliminar";
			button4->Location = System::Drawing::Point(margenLateral, this->ClientSize.Height - 50);
			button4->Size = System::Drawing::Size(200, 40);
			button4->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
			button4->BackColor = colorEliminar; // Rojo de advertencia
			button4->ForeColor = System::Drawing::Color::White;
			button4->FlatStyle = FlatStyle::Flat;
			button4->FlatAppearance->BorderSize = 0;
			button4->Cursor = Cursors::Hand;
			button4->Font = gcnew System::Drawing::Font(L"Microsoft Tai Le", 10, FontStyle::Bold);

			button3->Text = "Editar";
			button3->Location = System::Drawing::Point(inicioX + anchoBoton + espaciadoBotones, yBotones);
			button3->Size = System::Drawing::Size(200, 40);
			button3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
			button3->BackColor = colorBotonPrimario;
			button3->ForeColor = System::Drawing::Color::White;
			button3->FlatStyle = FlatStyle::Flat;
			button3->FlatAppearance->BorderSize = 0;
			button3->Cursor = Cursors::Hand;
			button3->Font = gcnew System::Drawing::Font(L"Microsoft Tai Le", 10, FontStyle::Bold);
		}
		void InitializeComponent(void)
		{
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(512, 439);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 28);
			this->button4->TabIndex = 27;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantSangre::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(232, 439);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 26;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantSangre::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(65, 30);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(424, 123);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Búsqueda";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(116, 87);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(133, 36);
			this->button5->TabIndex = 32;
			this->button5->Text = L"Limpiar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantSangre::button5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(280, 43);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 35);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantSangre::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 43);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 47);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Especie:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->dataGridView1->Location = System::Drawing::Point(45, 188);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(755, 222);
			this->dataGridView1->TabIndex = 28;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Muestra";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Especie";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Cantidad Extraída (ml)";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Presencia de Coágulos";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Contaminación Visible";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Color";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 125;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Fecha";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Width = 125;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(533, 30);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(267, 123);
			this->groupBox2->TabIndex = 29;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Nueva Muestra Sangre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 43);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 16);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Especie:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(124, 39);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(101, 24);
			this->comboBox1->TabIndex = 27;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 87);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(183, 28);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantSangre::button2_Click_1);
			// 
			// frmMantSangre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(853, 498);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmMantSangre";
			this->Text = L"AgroRobot - Gestión de Muestras de Sangre";
			this->Load += gcnew System::EventHandler(this, &frmMantSangre::frmMantSangre_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void cargarAnimalesDisponibles() {
		this->comboBox1->Items->Clear();
		List<Animal^>^ todosAnimales = gestorNutricionalController->obtenerTodosAnimales();
		List<Muestra^>^ todasMuestras = muestraController->buscarTodasMuestrasArchivo(gestorNutricionalController);

		for each (Animal ^ a in todosAnimales) {
			bool tieneSangre = false;
			for each (Muestra ^ m in todasMuestras) {
				if (m->getAnimal() != nullptr &&
					m->getAnimal()->IdAnimal == a->IdAnimal &&
					m->getTipo()->Equals("Sangre")) {
					tieneSangre = true;
					break;
				}
			}
			if (!tieneSangre) {
				this->comboBox1->Items->Add(a->IdAnimal.ToString() + " - " + a->Especie);
			}
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ texto = this->textBox1->Text->Trim();
		
		List<Muestra^>^ listaFiltrada = gcnew List<Muestra^>();

		if (String::IsNullOrEmpty(texto)) {
			// Mostrar todas las muestras de sangre
			List<Muestra^>^ todas = muestraController->buscarTodasMuestrasArchivo(gestorNutricionalController);
			for each (Muestra ^ m in todas) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
		}
		else {
			// Buscar por especie directamente
			List<Muestra^>^ todas = muestraController->buscarMuestrasPorEspecieArchivo(texto, gestorNutricionalController);
			for each (Muestra ^ m in todas) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
		}

		this->dataGridView1->Rows->Clear();
		if (listaFiltrada->Count == 0) {
			MessageBox::Show("No se encontraron muestras de sangre.");
		}
		else {
			mostrarGrilla(listaFiltrada);
		}
	}

	private: void mostrarGrilla(List<Muestra^> ^ listaMuestras) {
		for (int i = 0; i < listaMuestras->Count; i++) {
			Muestra^ m = listaMuestras[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(m->getIdMuestra());
			filaGrilla[1] = m->getEspecie();
			filaGrilla[2] = Convert::ToString(m->getCantidadExtraida());
			filaGrilla[3] = m->getCoagulos();
			filaGrilla[4] = m->getContaminacion();
			filaGrilla[5] = m->getColorSangre();
			filaGrilla[6] = m->getFechaToma();
			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}
	
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una fila para editar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idMuestraEditar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		// Usar el gestor para reconstruir la muestra correctamente
		Muestra^ muestra = this->muestraController->buscarMuestraPorIdArchivo(idMuestraEditar, this->gestorNutricionalController);

		if (muestra == nullptr || !muestra->getTipo()->Equals("Sangre")) {
			MessageBox::Show("La muestra seleccionada no es válida o no es de tipo sangre.");
			return;
		}

		// Abrir formulario de edición de muestra de sangre
		frmEditarMuestraS^ ventanaEditar = gcnew frmEditarMuestraS(muestra, this->muestraController);
		ventanaEditar->ShowDialog();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una muestra para eliminar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		// Confirmación antes de eliminar
		System::Windows::Forms::DialogResult resultado =
			MessageBox::Show("¿Está seguro de que desea eliminar la muestra seleccionada?",
				"Confirmar eliminación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning);

		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			this->muestraController->eliminarMuestraArchivo(idEliminar);
			MessageBox::Show("La muestra ha sido eliminada con éxito.");

			// Refrescar la grilla mostrando solo muestras de sangre
			List<Muestra^>^ todas = this->muestraController->buscarTodasMuestrasArchivo(this->gestorNutricionalController);
			List<Muestra^>^ listaFiltrada = gcnew List<Muestra^>();
			for each (Muestra ^ m in todas) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
			this->dataGridView1->Rows->Clear();
			mostrarGrilla(listaFiltrada);
			cargarAnimalesSinMuestraSangre();
		}
	}

	private: System::Void frmMantSangre_Load(System::Object^ sender, System::EventArgs^ e) {
		
		List<Muestra^>^ todas = this->muestraController->buscarTodasMuestrasArchivo(this->gestorNutricionalController);
		List<Muestra^>^ listaSangre = gcnew List<Muestra^>();
		for each (Muestra ^ m in todas) {
			if (m->getTipo()->Equals("Sangre")) {
				listaSangre->Add(m);
			}
		}
		this->dataGridView1->Rows->Clear();
		mostrarGrilla(listaSangre);
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Clear();
	}

	private: void cargarAnimalesSinMuestraSangre() {

		List<Animal^>^ animales = gestorNutricionalController->leerArchivoAnimal();
		List<Muestra^>^ muestras = muestraController->buscarTodasMuestrasArchivo(gestorNutricionalController);

		this->comboBox1->Items->Clear();

		for each (Animal ^ a in animales) {
			bool tieneMuestraSangre = false;
			for each (Muestra ^ m in muestras) {
				if (m->getIdAnimal() == a->IdAnimal && m->getTipo()->Equals("Sangre")) {
					tieneMuestraSangre = true;
					break;
				}
			}
			if (!tieneMuestraSangre) {
				this->comboBox1->Items->Add(a->IdAnimal.ToString() + " - " + a->Especie);
			}
		}
	}

	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->SelectedItem == nullptr) {
			MessageBox::Show("Seleccione un animal válido antes de agregar una muestra de Sangre.");
			return;
		}
		// Recuperar el texto seleccionado: "IdAnimal - Especie"
		String^ seleccionado = this->comboBox1->SelectedItem->ToString();
		array<String^>^ partes = seleccionado->Split('-');

		int idAnimalSeleccionado = Convert::ToInt32(partes[0]->Trim());
		String^ especieSeleccionada = partes[1]->Trim();

		frmNuevoMuestraS^ nuevaMuestraSangre = gcnew frmNuevoMuestraS(
			idAnimalSeleccionado,
			this->muestraController,
			this->gestorNutricionalController
		);
		nuevaMuestraSangre->ShowDialog();
		cargarAnimalesDisponibles();
	}
};
}
