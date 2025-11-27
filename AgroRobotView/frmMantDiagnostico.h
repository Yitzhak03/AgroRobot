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
			   // 1. COLORES Y FUENTES
			   System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(30, 61, 54);
			   System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(45, 93, 80);
			   System::Drawing::Color colorInput = System::Drawing::Color::FromArgb(60, 110, 95);
			   System::Drawing::Color colorVerdeClaro = System::Drawing::Color::FromArgb(123, 228, 149);
			   System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(242, 242, 242);

			   this->BackColor = colorFondo;
			   this->ForeColor = colorTexto;
			   this->Font = gcnew System::Drawing::Font(L"Bahnschrift", 11, FontStyle::Regular);
			   this->StartPosition = FormStartPosition::CenterScreen;

			   // =========================================================
			   // 2. PANELES SUPERIORES (BÚSQUEDA Y NUEVO)
			   // =========================================================
			   int margenLateral = 20;
			   int espacioEntreGrupos = 20;
			   int yGrupos = 20;

			   // Calcular anchos para que ocupen mitad y mitad (aprox)
			   // Ancho total disponible menos márgenes
			   int anchoTotal = this->ClientSize.Width - (margenLateral * 2) - espacioEntreGrupos;
			   int anchoGrupo1 = anchoTotal * 0.6; // Búsqueda un poco más grande
			   int anchoGrupo2 = anchoTotal * 0.4; // Nuevo Diagnóstico

			   // GroupBox 1: Búsqueda
			   this->groupBox1->Text = L"Criterio de Búsqueda";
			   this->groupBox1->Font = gcnew System::Drawing::Font(L"Bahnschrift", 12, FontStyle::Bold);
			   this->groupBox1->ForeColor = colorTexto;
			   this->groupBox1->BackColor = colorPanel;
			   this->groupBox1->Location = System::Drawing::Point(margenLateral, yGrupos);
			   this->groupBox1->Width = anchoGrupo1;
			   this->groupBox1->Height = 120; // Altura fija
			   this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right); // Se estira

			   // GroupBox 2: Nuevo (Fijo a la derecha)
			   this->groupBox2->Text = L"Nuevo Diagnóstico";
			   this->groupBox2->Font = gcnew System::Drawing::Font(L"Bahnschrift", 12, FontStyle::Bold);
			   this->groupBox2->ForeColor = colorTexto;
			   this->groupBox2->BackColor = colorPanel;
			   // Truco: Lo ponemos a la derecha y lo anclamos a la derecha
			   this->groupBox2->Width = anchoGrupo2;
			   this->groupBox2->Height = 120;
			   this->groupBox2->Location = System::Drawing::Point(this->ClientSize.Width - margenLateral - anchoGrupo2, yGrupos);
			   this->groupBox2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right);

			   // --- CENTRAR CONTROLES INTERNOS (GB1) ---
			   // Label + TextBox + BtnBuscar
			   this->label1->Location = System::Drawing::Point(20, 40);
			   this->label1->ForeColor = System::Drawing::Color::White;

			   this->textBox1->Location = System::Drawing::Point(90, 37);
			   this->textBox1->Width = 150;
			   this->textBox1->BackColor = colorInput;
			   this->textBox1->ForeColor = System::Drawing::Color::White;
			   this->textBox1->BorderStyle = BorderStyle::FixedSingle;

			   this->button1->Location = System::Drawing::Point(260, 35);
			   this->button1->Size = System::Drawing::Size(90, 30);
			   this->button1->BackColor = colorVerdeClaro;
			   this->button1->ForeColor = System::Drawing::Color::Black;
			   this->button1->FlatStyle = FlatStyle::Flat;
			   this->button1->FlatAppearance->BorderSize = 0;
			   this->button1->Cursor = Cursors::Hand;
			   this->button1->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);

			   this->button4->Location = System::Drawing::Point(260, 75); // Limpiar debajo de Buscar
			   this->button4->Size = System::Drawing::Size(90, 30);
			   this->button4->BackColor = colorVerdeClaro;
			   this->button4->ForeColor = System::Drawing::Color::Black;
			   this->button4->FlatStyle = FlatStyle::Flat;
			   this->button4->FlatAppearance->BorderSize = 0;
			   this->button4->Cursor = Cursors::Hand;
			   this->button4->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);

			   // --- CENTRAR CONTROLES INTERNOS (GB2) ---
			   this->label2->Location = System::Drawing::Point(20, 40);
			   this->label2->ForeColor = System::Drawing::Color::White;

			   this->comboBox1->Location = System::Drawing::Point(90, 37);
			   this->comboBox1->Width = 120;
			   this->comboBox1->BackColor = colorInput;
			   this->comboBox1->ForeColor = System::Drawing::Color::White;
			   this->comboBox1->FlatStyle = FlatStyle::Flat;

			   this->button2->Location = System::Drawing::Point(90, 75);
			   this->button2->Size = System::Drawing::Size(120, 30);
			   this->button2->BackColor = colorVerdeClaro;
			   this->button2->ForeColor = System::Drawing::Color::Black;
			   this->button2->FlatStyle = FlatStyle::Flat;
			   this->button2->FlatAppearance->BorderSize = 0;
			   this->button2->Cursor = Cursors::Hand;
			   this->button2->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);

			   // =========================================================
			   // 3. GRILLA (CENTRAL)
			   // =========================================================
			   int yGrilla = this->groupBox1->Bottom + 20;
			   int espacioBotonAbajo = 60;

			   this->dataGridView1->Location = System::Drawing::Point(margenLateral, yGrilla);
			   this->dataGridView1->Width = this->ClientSize.Width - (margenLateral * 2);
			   this->dataGridView1->Height = this->ClientSize.Height - yGrilla - espacioBotonAbajo;
			   this->dataGridView1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			   // Estilo Grilla
			   this->dataGridView1->BackgroundColor = colorPanel;
			   this->dataGridView1->BorderStyle = BorderStyle::None;
			   this->dataGridView1->EnableHeadersVisualStyles = false;
			   this->dataGridView1->ColumnHeadersHeight = 35;
			   this->dataGridView1->RowTemplate->Height = 30;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorFondo;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Bahnschrift", 11, FontStyle::Bold);
			   this->dataGridView1->DefaultCellStyle->BackColor = colorInput;
			   this->dataGridView1->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			   this->dataGridView1->DefaultCellStyle->SelectionBackColor = colorVerdeClaro;
			   this->dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
			   this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			   // =========================================================
			   // 4. BOTÓN ELIMINAR (ABAJO IZQUIERDA)
			   // =========================================================
			   this->button3->Location = System::Drawing::Point(margenLateral, this->ClientSize.Height - 45);
			   this->button3->Size = System::Drawing::Size(120, 35);
			   this->button3->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
			   this->button3->BackColor = System::Drawing::Color::FromArgb(220, 53, 69); // Rojo para eliminar
			   this->button3->ForeColor = System::Drawing::Color::White;
			   this->button3->FlatStyle = FlatStyle::Flat;
			   this->button3->FlatAppearance->BorderSize = 0;
			   this->button3->Cursor = Cursors::Hand;
			   this->button3->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);
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