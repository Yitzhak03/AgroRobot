#pragma once
//#include "frmNuevoDiagnostico.h"
//#include "frmEditarDiagnostico.h"

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
	/// Resumen de frmMantDiagnostico
	/// </summary>
	public ref class frmMantDiagnostico : public System::Windows::Forms::Form
	{
	public:
		frmMantDiagnostico(void)
		{
			InitializeComponent();
			this->diagnosticoController = gcnew DiagnosticoController();
			this->gestorController = gcnew GestorNutricionalController();
			this->muestraController = gcnew MuestraController();
			this->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->BackColor = System::Drawing::Color::LightGreen;
			this->button1->ForeColor = System::Drawing::Color::DarkGreen;
			this->button2->BackColor = System::Drawing::Color::LightGreen;
			this->button2->ForeColor = System::Drawing::Color::DarkGreen;
			this->button3->BackColor = System::Drawing::Color::LightGreen;
			this->button3->ForeColor = System::Drawing::Color::DarkGreen;
			this->button4->BackColor = System::Drawing::Color::LightGreen;
			this->button4->ForeColor = System::Drawing::Color::DarkGreen;
			cargarAnimalesSinDiagnostico();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantDiagnostico()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;



















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
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column7,
					this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column8
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 151);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(595, 183);
			this->dataGridView1->TabIndex = 9;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"ID Diagnóstico";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Width = 125;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Animal";
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
			this->Column3->HeaderText = L"Parásitos presentes";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Contaminación visible";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Estado de salud";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Observaciones";
			this->Column8->MinimumWidth = 6;
			this->Column8->Name = L"Column8";
			this->Column8->Width = 125;
			// 
			// groupBox1
			// 
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
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(83, 71);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(137, 23);
			this->button4->TabIndex = 30;
			this->button4->Text = L"Limpiar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button4_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(192, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(67, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Especie:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(389, 29);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(230, 100);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Nuevo Diagnóstico";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(45, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 13);
			this->label2->TabIndex = 31;
			this->label2->Text = L"Especie:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(106, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(77, 21);
			this->comboBox1->TabIndex = 30;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(48, 58);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 23);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Generar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(235, 393);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(151, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Eliminar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantDiagnostico::button3_Click);
			// 
			// frmMantDiagnostico
			// 
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

	private: void cargarAnimalesSinDiagnostico() {
		List<Animal^>^ animales = gestorController->leerArchivoAnimal();
		List<Diagnostico^>^ diagnosticos = diagnosticoController->buscarTodosDiagnosticosArchivo();

		this->comboBox1->Items->Clear();

		for each (Animal ^ a in animales) {
			bool tieneDiagnostico = false;
			for each (Diagnostico ^ d in diagnosticos) {
				if (d->IdAnimal == a->IdAnimal) {
					tieneDiagnostico = true;
					break;
				}
			}
			if (!tieneDiagnostico) {
				//this->comboBox1->Items->Add(a->Especie);
				this->comboBox1->Items->Add(a->IdAnimal.ToString() + " - " + a->Especie);

			}
		}
	}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Buscar por ID Animal (textBox1)
		String^ texto = this->textBox1->Text->Trim();
		List<Diagnostico^>^ listaFiltrada = gcnew List<Diagnostico^>();

		if (String::IsNullOrEmpty(texto)) {
			listaFiltrada = diagnosticoController->buscarTodosDiagnosticosArchivo();
		}
		else {
			listaFiltrada = diagnosticoController->buscarDiagnosticosPorEspecieArchivo(texto);
		}

		this->dataGridView1->Rows->Clear();
		if (listaFiltrada->Count == 0) {
			MessageBox::Show("No se encontraron diagnósticos para la especie ingresada.");
		}
		else {
			mostrarGrillaDiagnostico(listaFiltrada);
		}
	}

	private: void mostrarGrillaDiagnostico(List<Diagnostico^>^ listaDiagnosticos) {
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
	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->SelectedItem == nullptr) {
			MessageBox::Show("Seleccione un animal.");
			return;
		}
		// Recuperar el texto seleccionado: "IdAnimal - Especie"
		String^ seleccionado = this->comboBox1->SelectedItem->ToString();
		array<String^>^ partes = seleccionado->Split('-');

		int idAnimal = Convert::ToInt32(partes[0]->Trim());
		String^ especieSeleccionada = partes[1]->Trim();

		// Generar diagnóstico para el animal
		Diagnostico^ nuevoDiag = diagnosticoController->generarDiagnosticoParaAnimal(
			idAnimal,
			muestraController,
			gestorController
		);
		if (nuevoDiag == nullptr) {
			MessageBox::Show(
				"No se pudo generar el diagnóstico.\n" +
				"Verifique que existan muestras de Heces y Sangre para este animal.",
				"Error al generar diagnóstico",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
			return;
		}
		diagnosticoController->guardarDiagnosticoArchivo(nuevoDiag);
		// Refrescar grilla
		List<Diagnostico^>^ lista = diagnosticoController->buscarTodosDiagnosticosArchivo();
		this->dataGridView1->Rows->Clear();
		mostrarGrillaDiagnostico(lista);
		cargarAnimalesSinDiagnostico();
		MessageBox::Show("Diagnóstico generado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione un diagnóstico para eliminar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		// Confirmación antes de eliminar
		System::Windows::Forms::DialogResult resultado =
			MessageBox::Show("¿Está seguro de que desea eliminar el diagnóstico seleccionado?",
				"Confirmar eliminación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning);

		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			this->diagnosticoController->eliminarDiagnosticoArchivo(idEliminar);
			MessageBox::Show("El diagnóstico ha sido eliminado con éxito.");

			// Refrescar la grilla mostrando todos los diagnósticos restantes
			List<Diagnostico^>^ lista = this->diagnosticoController->buscarTodosDiagnosticosArchivo();
			this->dataGridView1->Rows->Clear();
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
