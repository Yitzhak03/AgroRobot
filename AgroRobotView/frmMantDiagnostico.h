#pragma once

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

	public ref class frmMantDiagnostico : public System::Windows::Forms::Form
	{
	public:
		frmMantDiagnostico(void)
		{
			InitializeComponent();
			this->diagnosticoController = gcnew DiagnosticoController();
			this->gestorController = gcnew GestorNutricionalController();
			this->muestraController = gcnew MuestraController();

			cargarAnimalesSinDiagnostico();

			// APLICAR ESTILO Y ESCALADO AL INICIAR
			AplicarEstiloProfesional();
		}

	protected:
		~frmMantDiagnostico()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: DiagnosticoController^ diagnosticoController;
	private: GestorNutricionalController^ gestorController;
	private: MuestraController^ muestraController;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

		   // Columnas
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->groupBox1->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->SuspendLayout();
			   // dataGridView1
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^ >(7) {
				   this->Column7, this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column8
			   });
			   this->dataGridView1->Location = System::Drawing::Point(24, 151);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->Size = System::Drawing::Size(595, 183);
			   this->dataGridView1->TabIndex = 9;
			   // Columnas
			   this->Column7->HeaderText = L"ID Diagnóstico"; this->Column7->Name = L"Column7";
			   this->Column1->HeaderText = L"ID Animal"; this->Column1->Name = L"Column1";
			   this->Column2->HeaderText = L"Especie"; this->Column2->Name = L"Column2";
			   this->Column3->HeaderText = L"Parásitos"; this->Column3->Name = L"Column3";
			   this->Column4->HeaderText = L"Contaminación"; this->Column4->Name = L"Column4";
			   this->Column5->HeaderText = L"Estado Salud"; this->Column5->Name = L"Column5";
			   this->Column8->HeaderText = L"Observaciones"; this->Column8->Name = L"Column8";

			   // groupBox1 (Buscar)
			   this->groupBox1->Controls->Add(this->button4);
			   this->groupBox1->Controls->Add(this->button1);
			   this->groupBox1->Controls->Add(this->textBox1);
			   this->groupBox1->Controls->Add(this->label1);
			   this->groupBox1->Location = System::Drawing::Point(43, 29);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(303, 100);
			   this->groupBox1->TabIndex = 8;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Criterio de Búsqueda";
			   // button4 (Limpiar)
			   this->button4->Location = System::Drawing::Point(83, 71);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(137, 23);
			   this->button4->TabIndex = 30;
			   this->button4->Text = L"Limpiar";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button4_Click);
			   // button1 (Buscar)
			   this->button1->Location = System::Drawing::Point(192, 32);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(86, 23);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Buscar";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button1_Click);
			   // textBox1
			   this->textBox1->Location = System::Drawing::Point(67, 35);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(100, 20);
			   this->textBox1->TabIndex = 1;
			   // label1
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(6, 38);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(48, 13);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Especie:";
			   // groupBox2 (Nuevo)
			   this->groupBox2->Controls->Add(this->label2);
			   this->groupBox2->Controls->Add(this->comboBox1);
			   this->groupBox2->Controls->Add(this->button2);
			   this->groupBox2->Location = System::Drawing::Point(389, 29);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(230, 100);
			   this->groupBox2->TabIndex = 10;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Nuevo Diagnóstico";
			   // label2
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(45, 25);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(48, 13);
			   this->label2->TabIndex = 31;
			   this->label2->Text = L"Especie:";
			   // comboBox1
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Location = System::Drawing::Point(106, 20);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(77, 21);
			   this->comboBox1->TabIndex = 30;
			   // button2 (Generar)
			   this->button2->Location = System::Drawing::Point(48, 58);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(137, 23);
			   this->button2->TabIndex = 29;
			   this->button2->Text = L"Generar";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button2_Click);
			   // button3 (Eliminar)
			   this->button3->Location = System::Drawing::Point(235, 393);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(151, 23);
			   this->button3->TabIndex = 11;
			   this->button3->Text = L"Eliminar";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button3_Click);

			   // frmMantDiagnostico
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(661, 485);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->groupBox1);
			   this->Name = L"frmMantDiagnostico";
			   this->Text = L"AgroRobot - Gestión de Diagnósticos";
			   this->Load += gcnew System::EventHandler(this, &frmMantDiagnostico::frmMantDiagnostico_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->ResumeLayout(false);
		   }
#pragma endregion

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
			   this->Text = "Gestión de Diagnósticos";
			   int margenLateral = 30;
			   int espaciadoY = 20;

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
			   button1->Location = Point(220, yControl - 5); button1->Width = 75;

			   // Botón Limpiar (Secundario pero en panel claro)
			   this->button4->BackColor = System::Drawing::Color::White; // Contraste sobre el panel menta
			   this->button4->ForeColor = colorVerdeOscuro;
			   this->button4->FlatStyle = FlatStyle::Flat;
			   this->button4->FlatAppearance->BorderColor = colorBordeBoton;
			   this->button4->FlatAppearance->BorderSize = 1;
			   this->button4->Font = fuenteTitulo;
			   this->button4->Cursor = Cursors::Hand;
			   this->button4->Location = Point(305, yControl - 5); button4->Width = 75;

			   /*/ Botón Generar (Secundario pero en panel claro)
			   this->button2->BackColor = System::Drawing::Color::White; // Para que tenga el mismo dieño que el botón Limpiar
			   this->button2->ForeColor = colorVerdeOscuro;
			   this->button2->FlatStyle = FlatStyle::Flat;
			   this->button2->FlatAppearance->BorderColor = colorBordeBoton;
			   this->button2->Font = fuenteTitulo;
			   this->button2->Cursor = Cursors::Hand;*/

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

			   button2->Text = "Generar";
			   button2->BackColor = colorBotonPrimario;
			   button2->ForeColor = System::Drawing::Color::White;
			   button2->FlatStyle = FlatStyle::Flat;
			   button2->FlatAppearance->BorderSize = 0;
			   button2->Font = fuenteTitulo;
			   button2->Cursor = Cursors::Hand;
			   button2->Location = Point(220, yControl - 5); button2->Width = 100;

			   /*/ Centrar controles dentro del GroupBox (Cálculo)
			   int startX = (this->groupBox1->Width - (50 + 130 + 30 + 50 + 130 + 30 + 100 + 20 + 120)) / 2;
			   if (startX < 10) startX = 10;
			   int yControl = 45;

			   label1->Location = Point(startX, yControl + 4);
			   textBox1->Location = Point(startX + 60, yControl); textBox1->Width = 130;

			   label2->Location = Point(startX + 210, yControl + 4);
			   comboBox1->Location = Point(startX + 270, yControl); comboBox1->Width = 130;

			   button1->Location = Point(startX + 430, yControl - 5);
			   button4->Location = Point(startX + 550, yControl - 5);*/

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

			   // 6. BOTONES INFERIORES (CRUD - Secundarios)
			   /*int yBotones = this->ClientSize.Height - 55;
			   array<Button^>^ botonesCRUD = { button2 };
			   int xBtn = margenLateral;

			   /*for each (Button ^ btn in botonesCRUD) {
				   btn->BackColor = colorBotonSecundario;
				   btn->ForeColor = colorVerdeOscuro;
				   btn->FlatStyle = FlatStyle::Flat;
				   btn->FlatAppearance->BorderColor = colorBordeBoton;
				   btn->Font = fuenteTitulo;
				   btn->Cursor = Cursors::Hand;
				   btn->Height = 39; // Altura estándar del diseño

				   btn->Location = Point(xBtn, yBotones);
				   btn->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);

				   xBtn += btn->Width + 15;
			   }*/

			   // =========================================================
			   // 4. BOTÓN ELIMINAR (ABAJO IZQUIERDA)
			   // =========================================================
			   button3->Text = "Eliminar Diagnóstico";
			   button3->Location = System::Drawing::Point(margenLateral, this->ClientSize.Height - 50);
			   button3->Size = System::Drawing::Size(200, 40);
			   button3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
			   button3->BackColor = colorEliminar; // Rojo de advertencia
			   button3->ForeColor = System::Drawing::Color::White;
			   button3->FlatStyle = FlatStyle::Flat;
			   button3->FlatAppearance->BorderSize = 0;
			   button3->Cursor = Cursors::Hand;
			   button3->Font = gcnew System::Drawing::Font(L"Microsoft Tai Le", 10, FontStyle::Bold);
		   }

	private: void cargarAnimalesSinDiagnostico() {
		List<Animal^>^ animales = gestorController->leerArchivoAnimal();
		List<Diagnostico^>^ diagnosticos = diagnosticoController->buscarTodosDiagnosticosArchivo();
		this->comboBox1->Items->Clear();
		for each (Animal ^ a in animales) {
			bool tieneDiagnostico = false;
			for each (Diagnostico ^ d in diagnosticos) {
				if (d->IdAnimal == a->IdAnimal) { tieneDiagnostico = true; break; }
			}
			if (!tieneDiagnostico) this->comboBox1->Items->Add(a->IdAnimal.ToString() + " - " + a->Especie);
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ texto = this->textBox1->Text->Trim();
		List<Diagnostico^>^ listaFiltrada = gcnew List<Diagnostico^>();
		if (String::IsNullOrEmpty(texto)) listaFiltrada = diagnosticoController->buscarTodosDiagnosticosArchivo();
		else listaFiltrada = diagnosticoController->buscarDiagnosticosPorEspecieArchivo(texto);

		this->dataGridView1->Rows->Clear();
		if (listaFiltrada->Count == 0) MessageBox::Show("No se encontraron diagnósticos.");
		else mostrarGrillaDiagnostico(listaFiltrada);
	}

	private: void mostrarGrillaDiagnostico(List<Diagnostico^>^ listaDiagnosticos) {
		this->dataGridView1->Rows->Clear();
		for each (Diagnostico ^ d in listaDiagnosticos) {
			array<String^>^ fila = gcnew array<String^>(7);
			fila[0] = Convert::ToString(d->IdDiagnostico);
			fila[1] = Convert::ToString(d->IdAnimal);
			fila[2] = d->Especie;
			fila[3] = d->ResultadoHeces;
			fila[4] = d->ResultadoSangre;
			fila[5] = d->EstadoSalud;
			fila[6] = d->Observaciones;
			this->dataGridView1->Rows->Add(fila);
		}
		// Asegurar ajuste de columnas
		this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->SelectedItem == nullptr) { MessageBox::Show("Seleccione un animal."); return; }
		String^ seleccionado = this->comboBox1->SelectedItem->ToString();
		array<String^>^ partes = seleccionado->Split('-');
		int idAnimal = Convert::ToInt32(partes[0]->Trim());
		Diagnostico^ nuevoDiag = diagnosticoController->generarDiagnosticoParaAnimal(idAnimal, muestraController, gestorController);
		if (nuevoDiag == nullptr) {
			MessageBox::Show("No se pudo generar el diagnóstico. Verifique muestras.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		diagnosticoController->guardarDiagnosticoArchivo(nuevoDiag);
		List<Diagnostico^>^ lista = diagnosticoController->buscarTodosDiagnosticosArchivo();
		mostrarGrillaDiagnostico(lista);
		cargarAnimalesSinDiagnostico();
		MessageBox::Show("Diagnóstico generado correctamente.");
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) { MessageBox::Show("Seleccione un diagnóstico."); return; }
		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
		System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Eliminar diagnóstico?", "Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			this->diagnosticoController->eliminarDiagnosticoArchivo(idEliminar);
			List<Diagnostico^>^ lista = this->diagnosticoController->buscarTodosDiagnosticosArchivo();
			mostrarGrillaDiagnostico(lista);
		}
		cargarAnimalesSinDiagnostico();
	}

	private: System::Void frmMantDiagnostico_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Diagnostico^>^ lista = this->diagnosticoController->buscarTodosDiagnosticosArchivo();
		mostrarGrillaDiagnostico(lista);
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Clear();
	}
	};
}