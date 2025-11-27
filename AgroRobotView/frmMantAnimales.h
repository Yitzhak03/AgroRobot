#pragma once
#include "frmNuevoAnimal.h"
#include "frmEditarAnimal.h"
#include "frmVerificarPeso.h"

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
	/// Resumen de frmMantAnimales
	/// </summary>
	public ref class frmMantAnimales : public System::Windows::Forms::Form
	{
	public:
		frmMantAnimales(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->animalController = gcnew GestorNutricionalController();
			AplicarEstiloProfesional();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantAnimales()
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
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: GestorNutricionalController^ animalController;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
		   void AplicarEstiloProfesional() {
			   // =========================================================
			   // 1. PALETA DE COLORES (Reutilizada)
			   // =========================================================
			   System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248); // Blanco Menta (Fondo Principal)
			   System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240); // Menta Suave (Fondo de Paneles/Cabeceras)
			   System::Drawing::Color colorVerdeOscuro = System::Drawing::Color::FromArgb(34, 86, 70); // Texto Principal/Títulos
			   System::Drawing::Color colorTextoClaro = System::Drawing::Color::FromArgb(64, 106, 90); // Labels
			   System::Drawing::Color colorBotonPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Esmeralda (Acción Principal)
			   System::Drawing::Color colorBotonSecundario = System::Drawing::Color::White; // Fondo Secundario (Editar)
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
			   this->Text = "Gestión de Expedientes de Animales";
			   int margenLateral = 30;
			   int espaciadoY = 20;

			   // Dimensiones base de controles
			   int anchoCampo = 120;
			   int alturaControl = 30;
			   int yControl = 45; // Posición Y dentro de los GroupBox

			   // ---------------------------------------------------------
			   // A. GROUP BOX SUPERIOR: CRITERIOS DE BÚSQUEDA (groupBox1)
			   // Controles: ID Animal (label1, textBox1), Especie (label2, textBox2), Buscar (button1)
			   // ---------------------------------------------------------
			   this->groupBox1->Text = "Criterios de búsqueda";
			   this->groupBox1->BackColor = colorPanel;
			   this->groupBox1->ForeColor = colorVerdeOscuro;
			   this->groupBox1->Font = fuenteTitulo;
			   this->groupBox1->Location = System::Drawing::Point(margenLateral, espaciadoY);
			   this->groupBox1->Height = 110;
			   this->groupBox1->Width = this->ClientSize.Width - (margenLateral * 2); // Ocupa todo el ancho
			   this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);

			   // Label ID Animal (asumo label1)
			   label1->Text = "ID Animal:";
			   label1->Font = fuenteLabel;
			   label1->ForeColor = colorTextoClaro;
			   label1->Location = Point(20, yControl + 4);

			   // TextBox ID Animal (asumo textBox1)
			   textBox1->BorderStyle = BorderStyle::FixedSingle;
			   textBox1->BackColor = System::Drawing::Color::White;
			   textBox1->ForeColor = colorVerdeOscuro;
			   textBox1->Location = Point(110, yControl); textBox1->Width = anchoCampo;

			   // Label Especie (asumo label2)
			   label2->Text = "Especie:";
			   label2->Font = fuenteLabel;
			   label2->ForeColor = colorTextoClaro;
			   label2->Location = Point(textBox1->Right + 25, yControl + 4);

			   // TextBox Especie (asumo textBox2)
			   textBox2->BorderStyle = BorderStyle::FixedSingle;
			   textBox2->BackColor = System::Drawing::Color::White;
			   textBox2->ForeColor = colorVerdeOscuro;
			   textBox2->Location = Point(label2->Right + 5, yControl); textBox2->Width = anchoCampo;

			   // Botón Buscar (button1 - Primario)
			   button1->Text = "Buscar";
			   button1->BackColor = colorBotonPrimario;
			   button1->ForeColor = System::Drawing::Color::White;
			   button1->FlatStyle = FlatStyle::Flat;
			   button1->FlatAppearance->BorderSize = 0;
			   button1->Font = fuenteTitulo;
			   button1->Size = System::Drawing::Size(100, alturaControl);
			   button1->Location = Point(textBox2->Right + 20, yControl);

			   // ---------------------------------------------------------
			   // B. GRILLA (DATAGRIDVIEW) - Se coloca justo debajo del GroupBox1
			   // ---------------------------------------------------------
			   int yGrilla = this->groupBox1->Bottom + espaciadoY;
			   int hFooter = 160; // Dejamos más espacio para el GroupBox inferior

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
			   dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorPanel;
			   dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = colorVerdeOscuro;
			   dataGridView1->ColumnHeadersDefaultCellStyle->Font = fuenteGridHeader;
			   dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::None;
			   dataGridView1->ColumnHeadersHeight = 45;
			   dataGridView1->DefaultCellStyle->Font = fuenteGridCell;
			   dataGridView1->RowTemplate->Height = 40;
			   dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(248, 252, 250);
			   dataGridView1->RowHeadersVisible = true;
			   dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			   // ---------------------------------------------------------
			   // C. BOTONES CRUD INFERIORES: AGREGAR (button2), EDITAR (button3), ELIMINAR (button4)
			   // ---------------------------------------------------------
			   int yBotonesCRUD = this->ClientSize.Height - 110;
			   int anchoBotonCRUD = 120;
			   int espaciadoBotonesCRUD = 20;
			   int numBotonesCRUD = 3;
			   int anchoTotalBotonesCRUD = (anchoBotonCRUD * numBotonesCRUD) + (espaciadoBotonesCRUD * (numBotonesCRUD - 1));
			   int inicioXCRUD = margenLateral; // A la izquierda de la grilla

			   // Botón Agregar (button2 - Primario)
			   button2->Text = "Agregar";
			   button2->Location = System::Drawing::Point(inicioXCRUD, yBotonesCRUD);
			   button2->Size = System::Drawing::Size(anchoBotonCRUD, 40);
			   button2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
			   button2->BackColor = colorBotonPrimario;
			   button2->ForeColor = System::Drawing::Color::White;
			   button2->FlatStyle = FlatStyle::Flat;
			   button2->FlatAppearance->BorderSize = 0;
			   button2->Cursor = Cursors::Hand;
			   button2->Font = fuenteBotonCRUD;

			   // Botón Editar (button3 - Secundario/Neutral)
			   button3->Text = "Editar";
			   button3->Location = System::Drawing::Point(button2->Right + espaciadoBotonesCRUD, yBotonesCRUD);
			   button3->Size = System::Drawing::Size(anchoBotonCRUD, 40);
			   button3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
			   button3->BackColor = colorBotonSecundario;
			   button3->ForeColor = colorVerdeOscuro;
			   button3->FlatStyle = FlatStyle::Flat;
			   button3->FlatAppearance->BorderColor = colorBordeSuave;
			   button3->FlatAppearance->BorderSize = 1;
			   button3->Cursor = Cursors::Hand;
			   button3->Font = fuenteBotonCRUD;

			   // Botón Eliminar (button4 - Advertencia)
			   button4->Text = "Eliminar";
			   button4->Location = System::Drawing::Point(button3->Right + espaciadoBotonesCRUD, yBotonesCRUD);
			   button4->Size = System::Drawing::Size(anchoBotonCRUD, 40);
			   button4->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
			   button4->BackColor = colorEliminar;
			   button4->ForeColor = System::Drawing::Color::White;
			   button4->FlatStyle = FlatStyle::Flat;
			   button4->FlatAppearance->BorderSize = 0;
			   button4->Cursor = Cursors::Hand;
			   button4->Font = fuenteBotonCRUD;

			   // ---------------------------------------------------------
			   // D. GROUP BOX INFERIOR: CUIDADO DE ANIMALES (groupBox2)
			   // Control: Verificar peso (button5)
			   // ---------------------------------------------------------
			   this->groupBox2->Text = "Cuidado de animales";
			   this->groupBox2->BackColor = colorPanel;
			   this->groupBox2->ForeColor = colorVerdeOscuro;
			   this->groupBox2->Font = fuenteTitulo;
			   this->groupBox2->Location = System::Drawing::Point(margenLateral, this->ClientSize.Height - 70);
			   this->groupBox2->Height = 60;
			   this->groupBox2->Width = this->ClientSize.Width - (margenLateral * 2);
			   this->groupBox2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			   // Botón Verificar peso (button5 - Primario/Acción especial)
			   button5->Text = "Verificar peso";
			   button5->BackColor = colorBotonPrimario;
			   button5->ForeColor = System::Drawing::Color::White;
			   button5->FlatStyle = FlatStyle::Flat;
			   button5->FlatAppearance->BorderSize = 0;
			   button5->Font = fuenteTitulo;
			   button5->Size = System::Drawing::Size(150, 30);

			   // Centrar el botón dentro del GroupBox2
			   int xBtnVerificar = (this->groupBox2->Width / 2) - (button5->Width / 2);
			   button5->Location = Point(xBtnVerificar, 20); // 20px de margen superior dentro del GroupBox
			   button5->Anchor = AnchorStyles::None; // No anclamos dentro del GroupBox
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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(654, 435);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 30);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantAnimales::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(381, 435);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 30);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantAnimales::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(93, 435);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 30);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantAnimales::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 174);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(801, 235);
			this->dataGridView1->TabIndex = 12;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(24, 32);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(801, 122);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(645, 55);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantAnimales::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(432, 57);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(123, 22);
			this->textBox2->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(189, 57);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 22);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(349, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Especie: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID Animal:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Location = System::Drawing::Point(24, 494);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(800, 67);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Cuidado de animales";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(328, 21);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(137, 35);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Verificar peso";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantAnimales::button5_Click);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Animal";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Visible = false;
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
			this->Column3->HeaderText = L"Peso";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Edad";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Estado de salud:";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Ultima dieta:";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 125;
			// 
			// frmMantAnimales
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(875, 603);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantAnimales";
			this->Text = L"Mantenimiento de animales";
			this->Load += gcnew System::EventHandler(this, &frmMantAnimales::frmMantAnimales_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantAnimales_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
		mostrarGrilla(listaAnimales);
	}

		//================================================Nuevo============================================//
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevoAnimal^ nuevoAnimalForm = gcnew frmNuevoAnimal(this->animalController);
		nuevoAnimalForm->ShowDialog(this);
		List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
		mostrarGrilla(listaAnimales);
	}

		   //================================================Eliminar============================================//
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{

			System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Está seguro de que desea eliminar el animal seleccionado?",
				"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (resultado == System::Windows::Forms::DialogResult::No)
			{
				return;
			}

			int selectedRowIndex = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[selectedRowIndex]->Cells[0]->Value);
			this->animalController->eliminarAnimal(id);
			List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
			mostrarGrilla(listaAnimales);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   //================================================Buscar============================================//
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = 0;
		String^ especie = "";
		if (!textBox1->Text->Equals(""))
		{
			//Obterne el id del operador a buscar
			id = Convert::ToInt32(textBox1->Text);
		}
		if (!textBox2->Text->Equals(""))
		{
			// Obtener el nombre del operador a buscar
			especie = textBox2->Text;
		}
		// Crear una instancia del controlador y buscar el operador por nombre
		List<Animal^>^ listaAnimales = this->animalController->consultarAnimalporIdEspecie(id, especie);
		// Mostrar los resultados en el DataGridView
		mostrarGrilla(listaAnimales);
	}


		   //================================================Editar============================================//
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

			Animal^ animalSeleccionado = this->animalController->consultarAnimalporId(id);
			if (animalSeleccionado == nullptr)
			{
				MessageBox::Show("No se encontró el animal seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			frmEditarAnimal^ editarAnimalForm = gcnew frmEditarAnimal(this->animalController, animalSeleccionado);
			editarAnimalForm->ShowDialog();
			// Llamar al m?todo para cargar la lista de maquinas nuevamente
			List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
			mostrarGrilla(listaAnimales);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un animal para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	public:	void mostrarGrilla(List<Animal^>^ listaAnimales)
	{
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaAnimales->Count; i++)
		{
			Animal^ animal = listaAnimales[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(animal->IdAnimal);
			filaGrilla[1] = animal->Especie;
			filaGrilla[2] = Convert::ToString(animal->Peso);
			filaGrilla[3] = Convert::ToString(animal->Edad);
			filaGrilla[4] = animal->EstadoSalud;
			filaGrilla[5] = animal->UltimaDieta;
			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}

		  //================================================Verificar peso============================================//
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione un animal para verificar su peso.", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		int fila = this->dataGridView1->SelectedRows[0]->Index;
		int idAnimal = Convert::ToInt32(this->dataGridView1->Rows[fila]->Cells[0]->Value);
		double pesoActual = Convert::ToDouble(this->dataGridView1->Rows[fila]->Cells[2]->Value);

		// Abrir formulario de verificación
		frmVerificarPeso^ frm = gcnew frmVerificarPeso();
		frm->ShowDialog();

		if (!frm->confirmado) return;

		double pesoEsperado = frm->pesoEsperado;

		String^ mensaje = this->animalController->verificarPesoAnimal(idAnimal, pesoEsperado, pesoActual);

		MessageBox::Show(mensaje, "Resultado", MessageBoxButtons::OK, MessageBoxIcon::Information);

		List<Animal^>^ listaAnimales = this->animalController->obtenerTodosAnimales();
		mostrarGrilla(listaAnimales);
	}

	};
}

